#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string str = "";
		//最长公共前缀就是字符串数组strs中所有字符串的前缀相同
		//双指针法：指针i指向每个字符串的同一个位置的字符，指针j用来遍历所有字符串用c=strs[0][i]表示第一个字符串中下标i的字符
		//i从0出发不断+1，直到其他所有字符串在下标i位置字符strs[j][i]与第一个字符串下标i位置字符不相同，返回str
		int i, j;
		char c;
		int len = strs.size();
		//当字符串数组strs为空时，返回""
		if (len == 0)
			return str;
		//当字符串数组strs中任一字符串为空，返回""
		for (int j = 0; j < len; j++)
		{
			if (strs[j] == "")
				return str;
		}
		int str_len = strs[0].size();
		//指针i遍历每个字符串的同一个位置的字符
		for (i = 0; i < str_len; i++)
		{
			c = strs[0][i];  //表示第一个字符串中下标i的字符
			//指针j用来遍历所有字符串，看其他所有字符串在i位置上的字符是否与第一个字符串i位置字符相同
			for (j = 0; j < len; j++)
			{
				//其他字符串中有一个字符串与第一个字符串i位置字符不相同，返回str
				if (c != strs[j][i])
					return str;
			}
			str += c;
		}
		return str;
	}
};
int main()
{
	Solution solute;
	vector<string> strs = { "flower","flow","flight" };
	cout << solute.longestCommonPrefix(strs) << endl;
	return 0;
}
