#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numTrees(int n) {
		//基本思想：迭代法求解卡特兰数
		//n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数，则
		//G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)
		//当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，则
		//f(i)=G(i−1)∗G(n−i)
		//综合两个公式可以得到卡特兰数公式:
		//G(n)=G(0)∗G(n−1)+G(1)∗G(n−2)+...+G(n−1)∗G(0)
		vector<int> G(n + 1, 0);
		G[0] = 1;
		G[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				G[i] += G[j - 1] * G[i - j];
			}
		}
		return G[n];

	}
};
class Solution1 {
public:
	int numTrees(int n) {
		//基本思想：递归法求解卡特兰数
		//G(n)=G(0)∗G(n−1)+G(1)∗G(n−2)+...+G(n−1)∗G(0)
		return Recursion(1, n);
	}
	int Recursion(int start, int end)
	{
		if (start > end)
			return 1;
		if (start == end)
			return 1;
		int res = 0;
		//当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i
		for (int i = start; i <= end; i++)
		{
			//f(i)=G(i−1)∗G(n−i)
			int left = Recursion(start, i - 1);
			int right = Recursion(i + 1, end);
			//G(n)=f(1)+f(2)+f(3)+f(4)+...+f(n)
			res += left * right;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 9;
	cout << solute.numTrees(n) << endl;
	return 0;
}