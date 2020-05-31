#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		//����˼�룺��̬�滮���������������Ϣ����δ�����Ϣ
		//��̬����dp[i]=dp[i-1]+dp[i-2]����Ϊ������1�׻���2�ף����Ե�ǰ�����������Ͻ����������Ͻ�����֮��
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
		//����˼�룺�ݹ���ݷ�����Ϊ�ü��εݹ鶼��ʱ���������������ˣ�������泬ʱ��
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