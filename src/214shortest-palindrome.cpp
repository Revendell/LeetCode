#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		//����˼�룺KMP�㷨��������Լ�Ϊ��s�Ŀ�ͷѰ�����Ļ����Ӵ���Ȼ��ʣ�µĺ��沿�ַ�ת��ӵ�s��ǰ�档
		//��������ַ���aacecaaba���ӿ�ͷ�ҵ������Ļ����Ӵ���aacecaa��ʣ�²�����ba��ת��ab��ƴ�ӵ�s��ǰ���abaacecaaba
		//��һ��˼·��s=aacecaaba��ת���s_reverse=abaacecaa��ô�����ַ���ƴ��һ���ǻ��Ĵ�������һ������̵Ļ��Ĵ���
		//Ҫ��õ���̵Ļ��Ĵ���ֻ��Ҫ��s��ǰ׺��s_reverse�ĺ�׺����ظ����ֺϲ��͵õ���̻��Ĵ�
		//������뵽KMP�㷨�е�next���飬������������һ���ַ�����ǰ׺�ͺ�׺��ͬ�ĳ��ȵ����ֵ
		//���Խ�s��s_reverseƴ�ӵõ��´���Ȼ������´���next���鼴��
		//�������������ǰ׺�ǲ��ܳ����е�ģ������һ�������ַ�����
		string s_reverse(s), s_new;
		reverse(s_reverse.begin(), s_reverse.end());
		s_new = s + "#" + s_reverse;
		int i = -1, j = 0;  //iָ��ǰ׺�±��ʼ-1��jָ���׺�±��ʼ0
		//next[j]��ʾj֮ǰ���ַ������ǰ׺�ͺ�׺��ȵ��ַ����������ǰ׺����һ���ַ��±�
		vector<int> next(s_new.size() + 1, 0);
		next[0] = -1;
		//ѭ��ɨ���ַ���s_new
		while (j < s_new.size())
		{
			if (i == -1 || s_new[i] == s_new[j])
			{
				i++;
				j++;
				next[j] = i;
			}
			else
				i = next[i];
		}
		//��s_new��s_reverse����s���ظ��ظ����ֽ�ȡƴ����s������̻��Ĵ����
		return s_new.substr(s.size() + 1, s.size() - next[s_new.size()]) + s;
	}
};
int main()
{
	Solution solute;
	string s = "aacecaaa";
	cout << solute.shortestPalindrome(s) << endl;
	return 0;
}