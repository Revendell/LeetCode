#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class NumMatrix {
public:
	NumMatrix(vector<vector<int>>& matrix) {
		//基本思想：新建一个矩阵sum，sum[i][j]存储matrix中从(0,0)到(i,j)的元素的总和
		//计算(row1, col1)到(row2, col2)区域的元素和就等于sum[row2][col2]-sum[row2][col1-1]-sum[row1-1][col2]+sum[row1-1][col1-1]
		if (matrix.size() == 0) return;
		sum.resize(matrix.size(), vector<int>(matrix[0].size()));
		sum[0][0] = matrix[0][0];
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (i == 0 && j == 0) continue;
				if (i == 0)
					sum[i][j] = sum[i][j - 1] + matrix[i][j];
				else if (j == 0)
					sum[i][j] = sum[i - 1][j] + matrix[i][j];
				else
					sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 == 0 && col1 == 0)
			return sum[row2][col2];
		else if (row1 == 0)
			return sum[row2][col2] - sum[row2][col1 - 1];
		else if (col1 == 0)
			return sum[row2][col2] - sum[row1 - 1][col2];
		else
			return sum[row2][col2] + sum[row1-1][col1-1] - sum[row2][col1-1] - sum[row1-1][col2];
	}
private:
	vector<vector<int>> sum;
};
int main()
{
	vector<vector<int>> matrix = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};
	NumMatrix* obj = new NumMatrix(matrix);
	int row1 = 0, col1 = 2, row2 = 4, col2 = 3;
	cout << obj->sumRegion(row1, col1, row2, col2) << endl;
}
