#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		//����˼�룺�ݹ���η����Ƚ�ÿ��������ĸ����һ�����Ĵ���Ȼ�󲻶ϵݹ�ϲ��ɸ����Ļ��Ĵ�
		//ÿ�κϲ��󣬽��µķָ���ʽ����res��ֱ�����ܺϲ�������Ļ��Ĵ�
		vector<string> cur;
		//�Ƚ�s��ÿ����ĸ�ָ���һ�ִ�
		for (int i = 0; i < s.size(); i++)
			cur.push_back(s.substr(i, 1));
		Recursion(cur);
		return res;
	}
	void Recursion(vector<string> cur)
	{
		//�����ǰ�ķָ���ʽcur�Ѿ�������res�з���
		for (auto& v : res)
		{
			if (v == cur)
				return;
		}
		res.push_back(cur);
		//����cur��ÿ���ַ��������Ƿ���ڿ��Ժϲ��Ļ������a+a����a+b+a
		for (int i = 0; i < cur.size(); i++)
		{
			//���Ժϲ��Ļ������a+a
			if (i + 1 < cur.size() && cur[i] == cur[i + 1])
			{
				vector<string> temp;
				for (int k = 0; k < i; k++)
					temp.push_back(cur[k]);
				temp.push_back(cur[i] + cur[i + 1]);
				for (int k = i + 2; k < cur.size(); k++)
					temp.push_back(cur[k]);
				Recursion(temp);
			}
			//���Ժϲ��Ļ������a+b+a
			if (i + 2 < cur.size() && cur[i] == cur[i + 2])
			{
				vector<string> temp;
				for (int k = 0; k < i; k++)
					temp.push_back(cur[k]);
				temp.push_back(cur[i] + cur[i + 1] + cur[i + 2]);
				for (int k = i + 3; k < cur.size(); k++)
					temp.push_back(cur[k]);
				Recursion(temp);
			}
		}
	}
};
int main()
{
	Solution solute;
	string s = "abbaaba";
	vector<vector<string>> res = solute.partition(s);
	for (int i = 0; i < res.size(); i++)
	{
		for_each(res[i].begin(), res[i].end(), [](const string s) {cout << s << " "; });
		cout << endl;
	}
	return 0;
}