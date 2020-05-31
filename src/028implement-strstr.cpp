#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int len1 = haystack.size(), len2 = needle.size();
		int i = 0;
		int j = 0;
		vector<int> next;
		//如果模式串和主串都为空，也匹配了，返回0
		if (len1 == 0 && len2 == 0)
			return 0;
		//如果主串为空，模式串不为空，匹配不了返回-1
		if (len1 == 0)
			return -1;
		//计算模式串的next值
		get_next(needle, next);
		//如果匹配成功模式串的下标j就等于len2循环结束，或者主串下标i等于len1结束循环
		while (i < len1 && j < len2)
		{
			//当模式串下标j回溯到第一个字符的next值时，说明没有匹配成功，重新匹配j++=0模式串从头开始 i++主串从下一个字符开始
			//或者当模式串字符等于主串字符haystack[i]=needle[j]时，继续看下一个字符是否匹配j++ i++
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			//当模式串第j个字符与主串第i个字符不匹配时，i不回溯，j回溯到该字符下的next值即next[j]，也就是j字符之前字符串的后缀与主串i字符之前后缀是相同的，又因为j字符之前字符串的前缀与后缀相同，所以j字符之前字符串的前缀与主串i字符之前后缀是相同的(算作已匹配)，所以j回溯到相同前缀的下一个字符，也就是相同前缀的个数
			else
				j = next[j];
		}
		//最后如果模式串的下标j就等于len2，表示匹配成功，返回主串开始匹配字符的下标值i-j
		if (j == len2)
			return i - j;
		else
			return -1;
	}
	void get_next(string T, vector<int> &next)
	{
		int i, j;  //j指向前缀下标，i指向后缀下标
		i = 0;  //i初始为0
		j = -1;  //j初始为-1
		next.push_back(-1);  //next数组第一个字符next值为-1，next[0]=-1
		//循环扫描模式串，给模式串每个字符算出一个next数值，next值的含义是该字符之前的字符串中前缀和后缀相等的最长串的字符个数，也就是前缀串的下一个字符下标。
		//当模式串第j个字符与主串第i个字符不匹配时，i不回溯，j回溯到该字符下的next值即next[j]，也就是j字符之前字符串的后缀与主串i字符之前后缀是相同的，又因为j字符之前字符串的前缀与后缀相同，所以j字符之前字符串的前缀与主串i字符之前后缀是相同的(算作已匹配)，所以j回溯到相同前缀的下一个字符，也就是相同前缀的个数
		while (i < T.size())
		{
			//当j回溯到第一个字符的next值时，重新匹配j++=0前缀从头开始i++后缀从下一个字符开始
			//或者当前缀字符等于后缀字符T[j]=T[i]时，继续看下一个字符是否匹配j++ i++，同时给下一个字符i的next值赋值，next等于i字符之前的字符串中前缀和后缀相等的最长串的字符个数，也就是前缀串的下一个字符下标即next[i]=j++
			if (j == -1 || T[j] == T[i])
			{
				j++;
				i++;
				next.push_back(j);
			}
			//如果当前缀字符与后缀字符不相等，j通过next值回溯到适当位置，也就是回溯到j字符之前的字符串中前缀和后缀相等的最长串的字符个数
			//也就是前缀串的下一个字符下标处，也就是j字符之前字符串的后缀与i字符之前后缀是相同的，又因为j字符之前字符串的前缀与后缀相同，所以j字符之前字符串的前缀与主串i字符之前后缀是相同的(算作已匹配)，所以j回溯到相同前缀的下一个字符，也就是相同前缀的个数
			else
				j = next[j];
		}
	}
};
int main()
{
	string haystack = "hello";
	string needle = "lo";
	Solution solute;
	cout << solute.strStr(haystack, needle) << endl;
	return 0;
}