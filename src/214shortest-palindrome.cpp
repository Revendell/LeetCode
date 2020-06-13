#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		//基本思想：KMP算法，问题可以简化为从s的开头寻找最大的回文子串，然后将剩下的后面部分翻转后接到s的前面。
		//例如对于字符串aacecaaba，从开头找到的最大的回文子串是aacecaa，剩下部分是ba翻转得ab，拼接到s的前面得abaacecaaba
		//另一种思路：s=aacecaaba翻转后得s_reverse=abaacecaa那么两个字符串拼接一定是回文串，但不一定是最短的回文串，
		//要想得到最短的回文串，只需要将s的前缀和s_reverse的后缀最大重复部分合并就得到最短回文串
		//这就联想到KMP算法中的next数组，就是用来查找一个字符串的前缀和后缀相同的长度的最大值
		//所以将s和s_reverse拼接得到新串，然后求得新串的next数组即可
		//但是我们所求的前缀是不能超过中点的，因此用一个特殊字符隔开
		string s_reverse(s), s_new;
		reverse(s_reverse.begin(), s_reverse.end());
		s_new = s + "#" + s_reverse;
		int i = -1, j = 0;  //i指向前缀下标初始-1，j指向后缀下标初始0
		//next[j]表示j之前的字符串的最长前缀和后缀相等的字符个数，即最长前缀的下一个字符下标
		vector<int> next(s_new.size() + 1, 0);
		next[0] = -1;
		//循环扫描字符串s_new
		while (j < s_new.size())
		{
			if (i == -1 || s_new[i] == s_new[j])
			{
				i++;
				j++;
				next[j] = i;
			}
			else
				i = next[i];
		}
		//将s_new的s_reverse的与s非重复重复部分截取拼接上s就是最短回文串结果
		return s_new.substr(s.size() + 1, s.size() - next[s_new.size()]) + s;
	}
};
int main()
{
	Solution solute;
	string s = "aacecaaa";
	cout << solute.shortestPalindrome(s) << endl;
	return 0;
}