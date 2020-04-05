#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	int res = 0;
	int totalNQueens(int n) {
		//基本思想：递归回溯法，每次在每行加入一个Q，循环n次检查因为一行n个位置哪个位置加入Q，然后调用check函数是否满足N皇后条件，满足的话cnt+1继续递归加入下一个Q直到cnt=n结束；如果不满足回溯剔除刚加入的Q
		//HashMap记录加入的Q的二维坐标，HashMap[0]=1表示在0行1列有一个Q，cnt记录已经加入的Q个数，当cnt=n结束递归res++
		map<int, int> HashMap;
		Recursion(n, 0, HashMap);
		return res;
	}
	void Recursion(int n, int cnt, map<int, int> HashMap)
	{
		//如果当前加入的Q的个数cnt等于n结束递归，此情况可以res++
		if (cnt == n)
		{
			res++;
			return;
		}
		//循环n次检查因为一行n个位置哪个位置可以加入Q，然后调用check函数是否满足N皇后条件
		for (int i = 0; i < n; i++)
		{
			HashMap[cnt] = i;
			//满足的话cnt+1继续递归加入下一个Q直到cnt=n结束
			if (check(HashMap, cnt))
				Recursion(n, cnt + 1, HashMap);
			//如果不满足回溯剔除刚加入的Q
			HashMap.erase(cnt);
		}
		return;
	}
	//check函数是否满足N皇后条件，皇后横、竖、斜位置都不允许出现其他皇后
	bool check(map<int, int> HashMap, int cnt)
	{
		//检查竖是否已经有皇后
		for (auto it = HashMap.begin(); it != HashMap.end(); it++)
		{
			if (it->second == HashMap[cnt] && it->first != cnt)
				return false;
		}
		//检查斜是否已经有皇后
		for (int i = cnt - 1, j = 1; i >= 0; i--, j++)
		{
			if (HashMap[i] + j == HashMap[cnt])
				return false;
			if (HashMap[i] - j == HashMap[cnt])
				return false;
		}
		//横、竖、斜都没有皇后，此位置可以加入皇后Q返回true
		return true;
	}
};
int main()
{
	Solution solute;
	int n = 4;
	cout << solute.totalNQueens(n) << endl;
	return 0;
}