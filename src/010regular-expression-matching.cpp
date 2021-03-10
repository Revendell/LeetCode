#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//简化版：动态规划，初始化dp[i][j]=false，
		//如果s[i-1]==p[j-1]||p[j-1]=='.'，则dp[i][j]=dp[i-1][j-1]
		//如果p[j-1]=='*'，可以选择匹配0次则dp[i][j]=dp[i][j-2]，可以选择匹配一次这时候必须s当前字符和p前一个字符匹配，匹配完因为*可以继续匹配字符，所以相当于忽略了s中的当前字符(也可以想成是s中增长了一个字符，此时p中*匹配了这个字符所以要看dp[i-1][j]增长这个字符之前是否匹配)，所以还必须满足dp[i-1][j]
		vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
		dp[0][0]=true;
		for(int i=2;i<=p.size();i++)
		{
			if(p[i-1]=='*')
				dp[0][i]=dp[0][i-2];
		}
		for(int i=1;i<=s.size();i++)
		{
			for(int j=1;j<=p.size();j++)
			{
				if(s[i-1]==p[j-1]||p[j-1]=='.')
					dp[i][j]=dp[i-1][j-1];
				else if(p[j-1]=='*')
					dp[i][j]=dp[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j];
			}
		}
		return dp[s.size()][p.size()];	
	}
};
//递归回溯法：容易理解，空间时间复杂度高
class Solution1 {
public:
	bool isMatch(string s, string p) {
		//采用从后往前匹配，因为如果我们从前往后匹配，每个字符我们都得判断是否后面跟着'*'还是字母，但是从后往前没这个问题，一旦j遇到'*'，j-1必然有个字符
		return recursionMatch(s, s.size() - 1, p, p.size() - 1);
	}
	bool recursionMatch(string s, int i, string p, int j)
	{
		//如果j已经<0了说明p已经匹配完了，这时候，如果s也匹配完了说明正确，如果s没匹配完说明错误
		//如果i已经<0了说明s已经匹配完，这时候，p可以没匹配完，只要它还有'*'存在，继续执行代码，所以这种情况不用单独拿出来考虑
		if (j == -1)
			if (i == -1)
				return true;
			else
				return false;
		//总共两种匹配方式p[j]=='.'||s[i]==p[j]或者p[j]=='*'时可以匹配，所以有两个if单独处理
		if (p[j] == '*')  //当p[j]='*'时有三种处理情况，第一种是p[j-1]=='.'||s[i]==p[j-1]情况匹配1个元素i-1，第二种是p[j-1]=='.'||s[i]==p[j-1]情况但是不匹配直接跳过j-2，第三种情况是p[j-1]！='.'&&s[i]！=p[j-1]不匹配跳过j-2
		{
			if (i >= 0 && (p[j - 1] == '.' || s[i] == p[j - 1]))  //对于一情况可以匹配直接匹配字符串s中的一个元素i-1，j不变'*'可以继续匹配使用
				if(recursionMatch(s, i - 1, p, j))  //用if而不是直接return是因为尝试这种情况能不能完全匹配，如果这种情况不行并不代表其他情况也不行
				    return true;
			return recursionMatch(s, i, p, j - 2);  //对于二、三情况都是跳过j-2无论是可以匹配主动跳过还是不可以匹配被动跳过，都是j-2一起考虑
		}
		if (i >= 0 && (p[j] == '.' || s[i] == p[j]))  //当p[j]!='*' 即p[j]=='.'||s[i]==p[j]情况时，直接匹配，i-1，j-1
		{
			return recursionMatch(s, i - 1, p, j - 1);
		}
		//以上两种情况都不匹配，返回false
		return false;
	}
};
//动态规划法：难理解，时间空间复杂度低
class Solution2 {
public:
	bool isMatch(string s, string p) {
		int s_len = s.size(), p_len = p.size();
		bool dp[100][100];  //dp[i][j]表示s[0,i-1]前i个字符与p[0,j-1]前j个字符是否匹配，true匹配，false不匹配
		int i, j;  //i表示字符串s的下标，j表示字符串p的下标
		bool temp = false;
		dp[0][0] = true;  //当s和p同时为空时，匹配成功
		//初始化dp，dp[i][0]=false，当j=0即p为空时，s只有i=0为空时才匹配，其他情况都无法匹配
		for (i = 1; i <= s_len; i++)
			dp[i][0] = false;
		//初始化dp，只有a*能匹配空串，如果p有*(p[j-1]='*')，那么dp[0][j]一定和dp[0][j-2]的相同
		for (j = 2; j <= p_len; j++)  //因为'*'在字符串p中出现的位置最前是下标1所以j-1>=1并且dp中j-2>=0，所以j从2开始
		{
			if (p[j - 1] == '*')  //dp的j下标在字符串p中下标是j-1
				dp[0][j] = dp[0][j - 2];
			else
				dp[0][j] = false;
		}
		for (i = 1; i <= s_len; i++)
		{
			for (j = 1; j <= p_len; j++)
			{
				//总共两种匹配方式p[j]=='.'||s[i]==p[j]或者p[j]=='*'时可以匹配
				//当p[j]='*'时有三种处理情况，第一种是p[j-1]=='.'||s[i]==p[j-1]情况匹配1个元素i-1，第二种是p[j-1]=='.'||s[i]==p[j-1]情况但是不匹配直接跳过j-2，第三种情况是p[j-1]！='.'&&s[i]！=p[j-1]不匹配跳过j-2
				if (p[j - 1] == '*')
				{
					//对于二、三情况都是跳过*符号匹配0次，或者对于一情况j不动可以多次用*符号，dp[i]不断等于dp[i-1]相当于多次利用*匹配
					dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);	
				}
				else
				{    //dp[i][j]表示s[0,i-1]与p[0,j-1]是否匹配取决于p[j-1]=='.'||s[i-1]==p[j-1]字符匹配且dp[i-1][j-1]=true
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
				}
			}
		}
		//返回dp[s_len][p_len]，s[0,s_len-1]前s_len个字符与p[0,p_len-1]前p_len个字符是否匹配
		return dp[s_len][p_len];
	}
};
int main()
{
	Solution1 solute1;
	Solution2 solute2;
	//考虑最特殊的一个样例，a*可能直接跳过，也可能用于匹配s[1]=a，所以采用递归回溯的方法，如果匹配不成功回溯
	string s = "aaaa";
	string p = "aa*aa";
	cout << solute1.isMatch(s, p) << endl;
	cout << solute2.isMatch(s, p) << endl;
	return 0;
}
