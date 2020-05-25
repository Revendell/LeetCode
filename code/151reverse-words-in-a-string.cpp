#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		//����˼�룺������
		//s�ĵ�һ������ǰ���һ���ո�ʹ�÷�ת���һ��������ڶ������ʼ���ڿո�
		if (s[0] != ' ')
			s.insert(0, 1, ' ');
		string res;
		int i = s.size() - 1, pos;
		//�Ӻ���ǰ�����ַ���s
		while (i >= 0)
		{
			//�������ʣ����ո�+�õ���ƴ�ӵ�res��ʹ��ÿ�����ʼ���ڿո�
			if (s[i] != ' ')
			{
				pos = i;
				while (i >= 0 && s[i] != ' ')
					i--;
				res += s.substr(i, pos - i + 1);
			}
			i--;
		}
		//ȥ�����һ���ո�
		if (res[0] == ' ')
			res.erase(0, 1);
		return res;
	}
};
class Solution1 {
public:
	string reverseWords(string s) {
		//����˼�룺��stringstream��
		istringstream words(s);    //words����s��һ������
		string res, word;
		//����words�ж�ȡ����
		while (words >> word)
		{
			res = " " + word + res;
		}
		//ȥ�����һ���ո�
		if (res[0] == ' ')
			res.erase(0, 1);
		return res;
	}
};
int main()
{
	Solution1 solute;
	string s = "the sky is blue";
	cout << solute.reverseWords(s) << endl;
	return 0;
}