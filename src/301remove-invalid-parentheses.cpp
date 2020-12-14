#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		//基本思想：广度优先搜索BFS，BFS对当前层的所有string遍历，对每个string中删除一个括号当做下一层的string
		//遍历当前层的所有string的时候，判断string是否满足条件，如果满足置flag=true且加入res，结束
		//优化点：第一对于当前层的string删除一个括号当做下一层的string这个过程可能产生重复的string所以利用set去重，时间复杂度O(logn)一开始使用vector时间复杂度O(n)超时
		//第二对于去除某个括号不要使用erase函数时间复杂度较高，使用substr拼接更快
		vector<string> res;
		queue<string> queues;
		bool flag = false;
		queues.push(s);
		while (!queues.empty())
		{
			if (flag)  break;
			int len = queues.size();
			set<string> level;
			while (len--)
			{
				string cur = queues.front();
				if (checkParentheses(cur))
				{
					flag = true;
					res.push_back(cur);
				}
				for (int i = 0; i < cur.size(); i++)
				{
					if (cur[i] == '(' || cur[i] == ')')
					{
						string temp = cur.substr(0,i)+cur.substr(i+1, cur.size()-i-1);
						if (level.find(temp) == level.end())
						{
							level.insert(temp);
							queues.push(temp);
						}
					}
				}
				queues.pop();
			}
		}
		return res;
	}
	bool checkParentheses(string s)
	{
		vector<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				st.push_back('(');
			else if (s[i] == ')')
			{
				if (st.empty())
					return false;
				st.pop_back();
			}
		}
		return st.empty();
	}
};
int main()
{
	Solution solute;
	string s = ")()()i)())b(())h))))";
	vector<string> res = solute.removeInvalidParentheses(s);
	for_each(res.begin(), res.end(), [](const string& v) {cout << v << endl; });
	return 0;
}
