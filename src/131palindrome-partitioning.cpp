#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> partition(string s) {
		//基本思想：递归分治法，超时，先将每个单独字母看成一个回文串，然后不断递归合并成更长的回文串
		//每次合并后，将新的分割形式加入res，直到不能合并出更大的回文串
		vector<string> cur;
		//先将s中每个字母分割是一种答案
		for (int i = 0; i < s.size(); i++)
			cur.push_back(s.substr(i, 1));
		Recursion(cur);
		return res;
	}
	void Recursion(vector<string> cur)
	{
		//如果当前的分割形式cur已经出现在res中返回
		for (auto& v : res)
		{
			if (v == cur)
				return;
		}
		res.push_back(cur);
		//遍历cur中每个字符串，看是否存在可以合并的回文情况a+a或者a+b+a
		for (int i = 0; i < cur.size(); i++)
		{
			//可以合并的回文情况a+a
			if (i + 1 < cur.size() && cur[i] == cur[i + 1])
			{
				vector<string> temp;
				temp.insert(temp.end(),cur.begin(),cur.begin()+i);
				temp.push_back(cur[i] + cur[i + 1]);
				temp.insert(temp.end(),cur.begin()+i+2,cur.end());
				Recursion(temp);
			}
			//可以合并的回文情况a+b+a
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
		//基本思想：递归回溯法，遍历s中的每一个可以组成回文串的子串加入cur中，直到下标pos结束
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
		//判断子串是否是回文串
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