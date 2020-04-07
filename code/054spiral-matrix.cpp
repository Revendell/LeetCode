#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		//基本思想：模拟旋转过程，从外往内按层模拟旋转输出，每一层输出四条边
		//对于这种螺旋遍历的方法，重要的是要确定上下左右四条边的位置，上边界和左边界都为cnt也是层数，右边界为col-cnt，下边界row-cnt
		vector<int> res;
		if (matrix.size() == 0)
			return res;
		int row = matrix.size(), col = matrix[0].size();
		int j, m = row, n = col, cnt = 0;
		//从外往内按层模拟旋转输出，每一层输出四条边
		while (m > 0 && n > 0)
		{
			//输出上边界
			for (j = cnt; j <= col - 1 - cnt; j++)
				res.push_back(matrix[cnt][j]);
			//输出右边界
			for (j = cnt + 1; j <= row - 1 - cnt; j++)
				res.push_back(matrix[j][col - 1 - cnt]);
			if (res.size() == col * row)
				return res;
			//输出下边界
			for (j = col - 2 - cnt; j >= cnt; j--)
				res.push_back(matrix[row - 1 - cnt][j]);
			//输出左边界
			for (j = row - 2 - cnt; j > cnt; j--)
				res.push_back(matrix[j][cnt]);
			//层数cnt++
			cnt++;
			m -= 2;
			n -= 2;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = {
		{1, 2, 3,4,0} ,
		{5, 6, 7,8,0} ,
		{1, 2, 3,4,0} ,
		{5, 6, 7,8,0} ,
		{9,10,11,12,0} };
	vector<int> res = solute.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}