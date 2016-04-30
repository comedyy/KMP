/*
KMP�㷨

��Ŀ���ַ������з������ҳ�Ŀ���ַ�����һЩ���ɣ�
������Щ���ɣ��Ż�����Ч�ʡ�

����Դ�ַ��������Ŀ���ַ�����ͬ�ַ����Ƶ���һ���ַ����бȽϣ�
�����ͬ����ƥ���ַ����ƶ�������ǰ׺λ�ã�����֤����ǰλ�ø�����ǰ׺λ�ã�������ȫƥ��Դ�ַ����ģ�

�ҳ�Ŀ���ַ�������λ�ö�Ӧ��ǰ׺�������λ��ƥ��ʧ�ܵĻ���
ѡ�������ǰ׺����ƥ�䣬

ʲô��ǰ׺ �����ַ��� ABCDABCE�����һ���ַ�E��ǰ׺����E��Ҳ����˵��������E��ʱ��
��ƥ��Դ�ַ�������ô��Ҫ��D��ʼƥ���ˣ���Ϊ����֮ǰ��ABC����һ�����ܱ�֤��Դ�ַ���ƥ�䣬
��ô���D�ַ����ǲ�ƥ�䣬��ô��ΪDû��ǰ׺����ôֻ�����¿�ʼƥ�䡣

��ô�ٿ���һ�������ABCABCD���������ַ�C��ǰ׺�ǵ������ַ�C��
����ǵĻ����������ַ�Cƥ��ʧ��֮���õ�����Cƥ�䣬Ҳ�ض�ʧ�ܡ�
Ҫһֱ��ǰ���������ֵ�����C��û��ǰ׺�������߸�D��ǰ׺�ǵ��ĸ��ַ�A

*/

#include <iostream>
#include <string>

using namespace std;

// ȡnext����
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