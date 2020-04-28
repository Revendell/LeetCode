#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		//基本思想：递归回溯法，Ip地址总共由四部分组成，cnt计数已经加进来几部分了，当pos到尾且cnt=4，则是正确分割
		//Ip地址每一部分可能是一位数0-9，可能是两位数10-99，也可能是三位数100-255
		if (s.size() > 12)
			return res;
		//cur为当前分割的一种情况，pos当前s下标，cnt计数
		string cur;
		Recursion(s, cur, 0, 0);
		return res;
	}
	void Recursion(string &s, string cur, int pos, int cnt)
	{
		if (pos == s.size())
		{
			//当pos到尾且cnt=4，则是正确分割，否则返回
			if (cnt == 4)
			{
				cur.pop_back();
				res.push_back(cur);
			}	
			return;
		}
		//Ip地址每一部分可能是一位数0-9
		cur += s.substr(pos, 1) + '.';
		Recursion(s, cur, pos + 1, cnt + 1);
		cur.erase(cur.size() - 2, 2);
		//Ip地址每一部分可能是两位数10-99
		if (pos + 1 < s.size() && s[pos] != '0')
		{
			cur += s.substr(pos, 2) + '.';
			Recursion(s, cur, pos + 2, cnt + 1);
			cur.erase(cur.size() - 3, 3);
		}
		//Ip地址每一部分可能是三位数100-255
		if (pos + 2 < s.size() && (s[pos] == '1'|| (s[pos]=='2' && s.substr(pos,3)<="255")))
		{
			cur += s.substr(pos, 3) + '.';
			Recursion(s, cur, pos + 3, cnt + 1);
			cur.erase(cur.size() - 4, 4);
		}
		return;
	}
};
int main()
{
	Solution solute;
	string s = "172162541";
	vector<string> res = solute.restoreIpAddresses(s);
	copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}