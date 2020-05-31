#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> res;  //返回值，由所有情况s组成
	//数字与字母的映射表，数字减2即对应
	vector<vector<char>> letter = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'} ,{'m','n','o'} ,{'p','q','r','s'} ,{'t','u','v'} ,{'w','x','y','z'} };
	vector<string> letterCombinations(string digits) {
		int i = 0;  //i指向字符串digits的下标
		string s;  //s为组合的一种情况
		if (digits == "")  //如果不对这种情况特殊考虑，则返回的res=[""]，而正确结果应该是res为空res=[]
			return res;
		Recursion(digits, i, s);  //递归调用，直到i不断加1从0加到len遍历完digits，递归结束
		return res;
	}
	void Recursion(string digits, int i, string s)
	{
		//当i==len，遍历完digits，将本次递归的结果放入res中
		if (i == digits.size())
		{
			res.push_back(s);
		}
		else
		{
			int digit = digits[i] - '0' - 2;
			//对于字符串digits中的字符digits[i]有多种情况，每种情况letter[digit][j]加到s后面，继续递归调用，直到i==len遍历完digits，将本次递归的一种结果放入res中
			for (int j = 0; j < letter[digit].size(); j++)
			{
				Recursion(digits, i + 1, s + letter[digit][j]);
			}
		}
	}
};
int main()
{
	Solution solute;
	string digits = "2";
	vector<string> res;
	res = solute.letterCombinations(digits);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}