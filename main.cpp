/*
KMP算法

对目标字符串进行分析，找出目标字符串的一些规律，
利用这些规律，优化查找效率。

遍历源字符串，如果目标字符串相同字符，移到下一个字符进行比较，
如果不同，把匹配字符串移动到它的前缀位置（可以证明当前位置跟他的前缀位置，都是完全匹配源字符串的）

找出目标字符串各个位置对应的前缀，当这个位置匹配失败的话，
选择出它的前缀进行匹配，

什么是前缀 比如字符串 ABCDABCE，最后一个字符E的前缀就是E，也就是说当搜索到E的时候，
不匹配源字符串，那么就要从D开始匹配了，因为他们之前的ABC都是一样，能保证和源字符串匹配，
那么如果D字符还是不匹配，那么因为D没有前缀，那么只能重新开始匹配。

那么再考虑一种情况，ABCABCD，第六个字符C的前缀是第三个字符C？
如果是的话，第六个字符C匹配失败之后，用第三个C匹配，也必定失败。
要一直往前遍历，发现第六个C并没有前缀。而第七个D的前缀是第四个字符A

*/

#include <iostream>
#include <string>

using namespace std;

// 取next数组
int* GetNext(string strTarget){
	int nLen = (int)(strTarget.size());
	int* next = new int[nLen];
	next[0] = -1;
	int j = 0;
	int k = -1;

	while (j < nLen)
	{
		if (k == -1 || strTarget[j] == strTarget[k])
		{
			k++;
			j++;

			if (strTarget[k] != strTarget[j])
			{
				next[j] = k;
			}
			else{
				next[j] = next[k];
			}
		}
		else{
			k = next[k];
		}
	}

	return next;
}


int KMP(string strSource, string strTarget){
	int * next = GetNext(strTarget);

	int i = 0; 
	int j = -1;

	while (i < (int)strSource.size() && j < (int)strTarget.size())
	{
		if (j == -1 || strSource[i] == strTarget[j])
		{
			i++;
			j++;
		}
		else{
			j = next[j];
		}
	}

	if (j == strTarget.size())
	{
		return i - j;
	}
	else{
		return -1;
	}
}

int main(){

	string strSource = "ABCABCABD2ABCDE";
	string strTarget = "ABCDE";

	cout<<KMP(strSource, strTarget);
}