#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		//基本思想：字符串从右往左遍历，去掉末尾空格，再计数出现空格前的非空格字符个数，就是最后一个单词长度
		int res = 0, i = s.length() - 1;
		while (i >= 0 && s[i] == ' ')
			i--;
		while (i >= 0 && s[i--] != ' ')
			res++;
		return res;
	}
};
int main()
{
	Solution solute;
	string s = "  hello world   ";
	cout << solute.lengthOfLastWord(s) << endl;
	return 0;
}