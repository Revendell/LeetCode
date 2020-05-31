#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//基本思想：递归法，尽管有优化还是超时，但这是一种思想记录一下
		string p1;
		int i = 0;
		//剪枝优化，去除重复的*
		p1 = Remove_stars(p);
		//递归调用
		return Recursion(s, p1, 0, 0);
	}
	//剪枝优化，去除重复的*
	string Remove_stars(string &p)
	{
		string p1;
		int i;
		if (p.size() == 0)
			return "";
		while (i < p.size() - 1)
		{
			if (p[i] == '*' && p[i + 1] == '*')
			{
				i++;
				continue;
			}
			else
				p1 += p[i];
			i++;
		}
		p1 += p[p.size() - 1];
		return p1;
	}
	bool Recursion(string s, string p, int m, int n)
	{
		//如果s的下标m和p的下标n都已经到头，说明匹配成功
		if (m == s.size() && n == p.size())
			return true;
		//如果s的下标m到头p的下标n没有到头，且p剩余字符不是*，说明匹配不成功
		if (m == s.size() && n < p.size() && p[n] != '*')
			return false;
		//如果s的下标m到头p的下标n没有到头，且p下一字符是*，继续递归调用看剩余字符是否是*
		if (m == s.size() && n < p.size() && p[n] == '*')
		{
			return Recursion(s, p, m, n + 1);
		}
		//如果s的下标m没有到头p的下标n到头，说明匹配不成功
		if (m < s.size() && n == p.size())
			return false;
		//如果当前s所指字符和p所指字符相同，递归调用s和p下标都+1
		if (s[m] == p[n])
		{
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//如果p所指字符为*，则可能有三种匹配情况，*匹配空字符串，*匹配多个字符，*匹配完当前字符不再匹配
		else if (p[n] == '*')
		{
			if (Recursion(s, p, m, n + 1))
				return true;
			if (Recursion(s, p, m + 1, n))
				return true;
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//如果当前p所指字符为？，递归调用s和p下标都+1
		else if (p[n] == '?')
		{
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//如果当前s所指字符和p所指字符不相等，说明匹配不成功
		else if (s[m] != p[n])
		{
			return false;
		}
		//最后一定要返回false，因为上面进入if后调用Recursion，但如果成功返回true但如果不成功，会退出if执行下一条语句，而这个bool函数没有语句运行了，返回的是随机数
		return false;
	}
};
class Solution1 {
public:
	bool isMatch(string s, string p) {
		//基本思想：动态规划法，所有字符串匹配问题都可以用动态规划法，利用已匹配的信息计算未匹配的信息。
		int m = s.size(), n = p.size(), i, j;
		//dp[i][j]表示s[0,i-1]前i个字符与p[0,j-1]前j个字符是否匹配
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		//当s和p都为空时匹配成功
		dp[0][0] = true;
		//当s不为空p为空时不匹配
		for (i = 1; i < m; i++)
			dp[i][0] = false;
		//当s为空j开头都为*，*可以匹配空串，开头都能匹配成功
		for (j = 0; j < n; j++)
		{
			if (p[j] == '*')
				dp[0][j + 1] = true;
			else
				break;
		}
		//两重循环给二维数组dp赋值
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				//若当前p[j]为*，如果*算作空串则s前i个串与p前j个串是否匹配取决于s前i个串p前j-1个串是否匹配
				//如果*匹配当前s[i]字符则s前i个串与p前j个串是否匹配取决于s前i-1个串p前j个串是否匹配
				if (p[j] == '*')
				{
					dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
				}
				//若当前s[i]字符与当前p[j]字符相等，或者当前p[j]为？，s前i个串与p前j个串是否匹配取决于s前i-1个串p前j-1个串是否匹配
				else if (s[i] == p[j] || p[j] == '?')
				{
					dp[i + 1][j + 1] = dp[i][j];
				}
				//上述情况都不满足，s前i个串与p前j个串不匹配
				else
					dp[i + 1][j + 1] = false;
			}
		}
		return dp[m][n];

	}
};
class Solution2 {
public:
	bool isMatch(string s, string p) {
		//基本思想：贪心回溯法
		int m = s.size(), n = p.size(), i, j, flag_i, flag_j;
		i = 0;
		j = 0;
		//初始化标记点为-1，如果标记点大于等于0，说明有标记才能回溯
		flag_j = -1;
		flag_i = -1;
		//一重循环对s每个字符尝试匹配
		while (i < m)
		{
			//当前s[i]字符与当前p[j]字符相等，s和p的下标都后移一位
			if (j < n && (s[i] == p[j] || p[j] == '?'))
			{
				i++;
				j++;
			}
			//当前p[j]为*，标记当前s中字符的位置，标记p中*所在位置为flag_j，j后移一位到*的下一个字符，说明*匹配空串
			else if (j < n && p[j] == '*')
			{

				flag_i = i;
				flag_j = j;
				j++;
			}
			//如果*匹配空串后，p中*的后一位与标记处的s字符不匹配，说明*不能匹配空串，*匹配s当前字符，i后移一位，j继续指向*的下一个字符
			else if (flag_i >= 0)
			{
				flag_i++;
				i = flag_i;
				j = flag_j + 1;
			}
			//如果上述都不匹配，返回false匹配不成功，可能是p到头了而s中还有字符，可能是当前s所指字符和p所指字符不相等
			else
				return false;
		}
		//s已经到头了，去除p后多余的*，如果最后j能到p的头说明匹配成功，否则说明不匹配成功除了*还多了其他字符
		while (j < n && p[j] == '*')
			j++;
		return j==n;

	}
};
int main()
{
	Solution2 solute;
	string s = "aa";
	string p = "*";
	cout << solute.isMatch(s, p) << endl;
	return 0;
}