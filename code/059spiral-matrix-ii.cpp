#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		//基本思想：模拟旋转过程，从外往内按层模拟旋转输出，每一层输出四条边。
		//对于这种螺旋遍历的方法，重要的是要确定上下左右四条边的位置，上边界和左边界都为layer也是层数，右边界和下边界都为n-layer。
		vector<vector<int>> res(n, vector<int>(n, 0));
		//cnt为填入的数字从1到n^2
		int cnt = 1, layer = 0, i, m = n;
		//从外往内按层模拟旋转输出，每一层输出四条边
		while (m > 0)
		{
			//输出上边界
			for (i = layer; i < n - layer; i++)
				res[layer][i] = cnt++;
			//输出右边界
			for (i = layer + 1; i < n - layer; i++)
				res[i][n - layer - 1] = cnt++;
			//输出下边界
			for (i = n - layer - 2; i >= layer; i--)
				res[n - layer - 1][i] = cnt++;
			//输出左边界
			for (i = n - layer - 2; i > layer; i--)
				res[i][layer] = cnt++;
			layer++;
			m -= 2;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 5;
	vector<vector<int>> res;
	res = solute.generateMatrix(n);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}