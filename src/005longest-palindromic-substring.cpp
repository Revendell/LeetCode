#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		//简化版：动态规划+中心扩展法，dp[i][j]表示s中[i,j]范围字符是否构成回文串
		int start, max_len = 0;
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));	
		for(int len=1;len<=s.size();len++)
		{
			for(int i=0;i<=s.size()-len;i++)
			{
				int j=i+len-1;
				if(s[i]==s[j]&&(i==j||i+1==j||dp[i+1][j-1]))
				{
					dp[i][j]=true;
					start=i;
					max_len=len;
				}		
			}
		}
		return max_len==0?s.substr(0,1):s.substr(start,max_len);
	}
};
//中心扩展法
class Solution1 {
public:
	string longestPalindrome(string s) {
		int start, max_len = 0;  //最大回文子串开始的下标start，最大回文子串长度max_len
		int i, j, center;  //center作为回文子串的中心，i标记回文子串的左边，j标记回文子串的右边，通过s[i] == s[j]不断从中心center向外扩展i--,j++
		int len = s.length();  //len为字符串s的长度
		if (len == 1 || len == 0)  //如果字符串为空或者只有一个字符，直接返回s
			return s;
		//若最大回文子串长度为奇数，i和j同时从center扩展开
		for (center = 0; center < len; center++)
		{
			i = center;
			j = i;
			while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
				i--;
				j++;
			}
			if ((j - i + 1) - 2 > max_len)
			{
				max_len = j - i + 1 - 2;
				start = i + 1;
			}
		}
		//若最大回文子串长度为偶数，i从center扩展开，j从center+1扩展开
		for (center = 0; center < len; center++)
		{
			i = center;
			j = i + 1;
			while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
				i--;
				j++;
			}
			if ((j - i + 1) - 2 > max_len)
			{
				max_len = j - i + 1 - 2;
				start = i + 1;
			}
		}
		//max_len=0说明没有回文串，所以返回第一个字符就可以了
		if (max_len == 0)
			return s.substr(0, 1);
		else  //返回截取s的回文串开始下标start长度为max_len
			return s.substr(start, max_len);
	}
};
//动态规划法
class Solution2 {
public:
	string longestPalindrome(string s) {
		int start, max_len = 0;
		int i, j;  //i标记子串的起始下标，j标记子串的终止下标，子串长度len=j-i+1
		int s_len = s.length();  //s_len为字符串s的长度
		int len;
		bool dp[1000][1000] = { false };  //pd[i][j]=true表示从下标i到下标j的字符子串为回文串
		if (s_len == 1 || s_len == 0)  //如果字符串为空或者只有一个字符，直接返回s
			return s;
		//初始化pd
		for (i = 0; i < s_len - 1; i++)
		{
			dp[i][i] = true;  //单个字符属于回文串，是长度最小的回文串
			j = i + 1;
			//相连的两个字符相同，则这两个字符组成回文串
			if (s[i] == s[j])
			{
				dp[i][j] = true;
				max_len = j - i + 1;
				start = i;
			}

		}
		//循环判断字符串s中子串长度len从3到s_len中是否存在回文串，子串下标从0到s_len - len，如果dp[i+1][j-1]=true&&s[i] == s[j]则长度len的子串(下标从i到j)为回文串，dp[i][j]=true
		for (len = 3; len <= s_len; len++)
		{
			for (i = 0; i <= s_len - len; i++)
			{
				j = i + len - 1;
				//如果dp[i+1][j-1]=true && s[i]=s[j]，则长度len的子串(下标从i到j)为回文串
				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					max_len = len;  //因为子串长度len从3到s_len中是否存在回文串，所以如果存在回文串，回文串的长度是越来越大的，即max_len就等于len，不用判断len是否大于max_len
					start = i;
				}
			}
		}
		//max_len=0说明没有回文串，所以返回第一个字符就可以了
		if (max_len == 0)
			return s.substr(0, 1);
		else  //返回截取s的回文串开始下标start长度为max_len
			return s.substr(start, max_len);
	}
};
int main()
{
	Solution solute;
	string s;
	s = "abbbcd";
	cout << solute.longestPalindrome(s) << endl;
	return 0;
}