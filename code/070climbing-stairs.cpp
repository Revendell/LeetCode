#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		//基本思想：动态规划法，利用已求的信息计算未求的信息
		//动态方程dp[i]=dp[i-1]+dp[i-2]，因为可以跳1阶或者2阶，所以当前阶跳数等于上阶跳数与上上阶跳数之和
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		vector<int> dp(n, 0);
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n-1];
	}
};
class Solution1 {
public:
	int res = 0;
	int climbStairs(int n) {
		//基本思想：递归回溯法，因为好几次递归都超时，所以现在慎用了，结果还真超时了
		Recursion(0, n);
		return res;
	}
	void Recursion(int i, int n)
	{
		if (i == n - 1)
		{
			++res;
			return;
		}
		else if (i < n - 1)
		{
			Recursion(i + 1, n);
			Recursion(i + 2, n);
		}
		return;
	}
};
int main()
{
	Solution solute;
	int n = 9;
	cout << solute.climbStairs(n) << endl;
	return 0;
}