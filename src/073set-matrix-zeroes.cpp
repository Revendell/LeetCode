#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//定义最大负虚拟值
#define inf -1000000
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//基本思想：额外空间O(2)，利用matrix最后一行和最后一列标记当前行和当前列是否有0
		//如果当前行有0在改行最后一个位置标记为inf，如果当前列有0在改列最后一个位置标记为inf
		//最后一行和最后一列是否存在0，用last_col和last_row标记
		//循环遍历matrix，如果该元素所在行或列的最后一个位置为inf，该元素标记为0，最后一行和最后一列元素单独考虑
		if (matrix.size() == 0)
			return;
		int i, j;
		bool last_col = false, last_row = false;
		//最后一行和最后一列是否存在0，用last_col和last_row标记
		for (i = 0; i < matrix.size(); i++)
			if (matrix[i][matrix[0].size() - 1] == 0)
				last_col = true;
		for (j = 0; j < matrix[0].size(); j++)
			if (matrix[matrix.size() - 1][j] == 0)
				last_row = true;
		//如果当前行有0在该行最后一个位置标记为inf，如果当前列有0在该列最后一个位置标记为inf
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][matrix[0].size() - 1] = inf;
					matrix[matrix.size() - 1][j] = inf;
				}
			}
		}
		//循环遍历matrix，如果该元素所在行或列的最后一个位置为inf，该元素标记为0，最后一行和最后一列元素单独考虑
		for (i = 0; i < matrix.size() - 1; i++)
		{
			for (j = 0; j < matrix[i].size() - 1; j++)
			{
				if (matrix[i][matrix[i].size() - 1] == inf || matrix[matrix.size() - 1][j] == inf)
				{
					matrix[i][j] = 0;
				}
			}
		}
		//最后一行和最后一列元素单独考虑
		for (j = 0; j < matrix[0].size(); j++)
		{
			if (last_row)
				matrix[matrix.size() - 1][j] = 0;
			if (matrix[matrix.size() - 1][j] == inf)
				matrix[matrix.size() - 1][j] = 0;
		}
		for (i = 0; i < matrix.size(); i++)
		{
			if (last_col)
				matrix[i][matrix[0].size() - 1] = 0;
			if (matrix[i][matrix[0].size() - 1] == inf)
				matrix[i][matrix[0].size() - 1] = 0;
		}
	}
};
class Solution1 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//基本思想：额外空间O(M+N)，利用数组row和col分别标记M行和N列中是否存在0，对于存在0的行和列元素全部置0
		if (matrix.size() == 0)
			return;
		vector<bool> row(matrix.size(), false);
		vector<bool> col(matrix[0].size(), false);
		int i, j;
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = true;
					col[j] = true;
				}
			}
		}
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[i].size(); j++)
			{
				if (row[i]||col[j])
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = {
		{1,1,1},{0,1,2}
	};
	solute.setZeroes(matrix);
	int i, j;
	for (i = 0; i < matrix.size(); i++)
	{
		for (j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}