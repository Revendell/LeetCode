#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		//基本思想：暴力法
		//s的第一个单词前面填补一个空格，使得翻转后第一个单词与第二个单词间存在空格
		if (s[0] != ' ')
			s.insert(0, 1, ' ');
		string res;
		int i = s.size() - 1, pos;
		//从后往前遍历字符串s
		while (i >= 0)
		{
			//遇到单词，将空格+该单词拼接到res，使得每个单词间存在空格
			if (s[i] != ' ')
			{
				pos = i;
				while (i >= 0 && s[i] != ' ')
					i--;
				res += s.substr(i, pos - i + 1);
			}
			i--;
		}
		//去掉多的一个空格
		if (res[0] == ' ')
			res.erase(0, 1);
		return res;
	}
};
class Solution1 {
public:
	string reverseWords(string s) {
		//基本思想：用stringstream做
		istringstream words(s);    //words保存s的一个拷贝
		string res, word;
		//从流words中读取单词
		while (words >> word)
		{
			res = " " + word + res;
		}
		//去掉多的一个空格
		if (res[0] == ' ')
			res.erase(0, 1);
		return res;
	}
};
int main()
{
	Solution1 solute;
	string s = "the sky is blue";
	cout << solute.reverseWords(s) << endl;
	return 0;
}