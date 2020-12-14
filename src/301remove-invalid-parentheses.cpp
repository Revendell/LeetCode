#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		//����˼�룺�����������BFS��BFS�Ե�ǰ�������string��������ÿ��string��ɾ��һ�����ŵ�����һ���string
		//������ǰ�������string��ʱ���ж�string�Ƿ��������������������flag=true�Ҽ���res������
		//�Ż��㣺��һ���ڵ�ǰ���stringɾ��һ�����ŵ�����һ���string������̿��ܲ����ظ���string��������setȥ�أ�ʱ�临�Ӷ�O(logn)һ��ʼʹ��vectorʱ�临�Ӷ�O(n)��ʱ
		//�ڶ�����ȥ��ĳ�����Ų�Ҫʹ��erase����ʱ�临�ӶȽϸߣ�ʹ��substrƴ�Ӹ���
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
