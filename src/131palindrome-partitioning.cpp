#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		//����˼�룺�ݹ���η�����ʱ���Ƚ�ÿ��������ĸ����һ�����Ĵ���Ȼ�󲻶ϵݹ�ϲ��ɸ����Ļ��Ĵ�
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
				temp.insert(temp.end(),cur.begin(),cur.begin()+i);
				temp.push_back(cur[i] + cur[i + 1]);
				temp.insert(temp.end(),cur.begin()+i+2,cur.end());
				Recursion(temp);
			}
			//���Ժϲ��Ļ������a+b+a
			if (i + 2 < cur.size() && cur[i] == cur[i + 2])
			{
				vector<string> temp;
				temp.insert(temp.end(),cur.begin(),cur.begin()+i);
				temp.push_back(cur[i] + cur[i + 1] + cur[i + 2]);
				temp.insert(temp.end(),cur.begin()+i+3,cur.end());
				Recursion(temp);
			}
		}
	}
};
class Solution1 {
public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		//����˼�룺�ݹ���ݷ�������s�е�ÿһ��������ɻ��Ĵ����Ӵ�����cur�У�ֱ���±�pos����
		vector<string> cur;
		Recursion(s,cur,0);
		return res;
	}
	void Recursion(string& s,vector<string> cur,int pos)
	{
		if(pos==s.size())
			res.push_back(cur);
		for(int i=pos;i<s.size();i++)
		{
			if(checkPalind(s.substr(pos,i-pos+1)))
			{
				cur.push_back(s.substr(pos,i-pos+1));
				Recursion(s,cur,i+1);
				cur.pop_back();
			}
		}
	}
	bool checkPalind(string s)
	{
		//�ж��Ӵ��Ƿ��ǻ��Ĵ�
		int i=0,j=s.size()-1;
		while(i<j)
		{
			if(s[i]!=s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};
int main()
{
	Solution1 solute;
	string s = "abbaaba";
	vector<vector<string>> res = solute.partition(s);
	for (int i = 0; i < res.size(); i++)
	{
		for_each(res[i].begin(), res[i].end(), [](const string s) {cout << s << " "; });
		cout << endl;
	}
	return 0;
}