#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0;  //最大窗口长度
		int l = 0, r = -1;  //因为s[r + 1]作为当前遍历的字符，r+1范围从0到s.size()-1，所以右边界r初始化-1最大为s.size()-2，左边界初始化0
		int freq[256] = { 0 };    //建立字符和其出现位置之间的映射，字符从a到z对应的ASCLL码97到122，出现一次则加1，保证窗口内字符只出现过一次，映射值都为0
		while (l < s.size())
		{
			//如果窗口外下一个字符s[r + 1]在窗口内没有出现过，则扩大窗口的右边界r++；因为需要判断窗口外下一个字符是否出现过，所以r + 1 < s.size()，否则边界溢出
			if (r + 1 < s.size() && freq[s[r + 1]] == 0)
			{
				r++;
				freq[s[r]]++;
			}
			//如果窗口外下一个字符s[r + 1]在窗口内出现过，则缩小窗口的右边界l++
			else {
				freq[s[l]]--;
				l++;

			}
			//如果当前窗口长度大于最大窗口长度，更新最大窗口长度
			if (r-l+1 > length)
				length = r-l+1;
		}
		return length;
	}
};
int main()
{
	Solution solute;
	string s = "abcabcbb";
	cout<<solute.lengthOfLongestSubstring(s);
	return 0;
}