#include<iostream>
#include<vector>
using namespace std;
//递归回溯法
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s;
		vector<string> res;  //最后返回的结果，传引用比全局变量效率更高effective C++
		int i = 0, j = 0;  //i标记左括号个数i<=n，j标记右括号个数j<=n
		if (n < 1)
			return res;
		//递归回溯生成括号字符串
		Recursion(res, s, n, i, j);
		return res;
	}
	void Recursion(vector<string> &res, string s, int n, int i, int j)
	{
		if (j == n)
			res.push_back(s);
		//生成的括号字符串永远满足两个条件：j<=i i<=n
		//当i<n时可以添加左括号i+1(也可以选择不添加，递归回溯)，当j<i时可以添加右括号j+1，当j==n生成的括号字符串s结束，将s存入返回值res中，res.push_back(s)
		if (i < n)
		{
			Recursion(res, s + '(', n, i + 1, j);
		}
		if (j < i)
		{
			Recursion(res, s + ')', n, i, j + 1);
		}
	}
};
int main()
{
	int n = 3;
	Solution solute;
	vector<string> res;
	res = solute.generateParenthesis(n);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}