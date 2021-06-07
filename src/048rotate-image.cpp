#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		//先上下翻转然后对角翻转
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++)
            swap(matrix[i],matrix[n-1-i]);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//基本思想：找规律，模拟旋转过程，从外往内一层一层循转总共层数为matrix.size()/2，每一层数字个数为(k-2)*4，循环k-2次，每次循转4个数字
		int i, j, temp, k;
		if (matrix.size() == 1 || matrix.size() == 0)
			return;
		//从外往内一层一层循转总共层数为matrix.size()/2，每一层数字个数为(k-2)*4
		for (i = 0, k = matrix.size(); i != matrix.size() - 1 && i != matrix.size(); i = i + 2, k = k - 2)
		{
			//每一层数字个数为(k-2)*4，对每一层循环k-2次
			for (j = 0; j < k-1; j++)
			{
				//每次循转4个数字，四个数字坐标如下i/2为层数，j为该层第几个数字
				temp = matrix[i / 2][i / 2 + j];
				matrix[i / 2][i / 2 + j] = matrix[matrix.size() - 1 - i / 2 - j][i / 2];
				matrix[matrix.size() - 1 - i / 2 - j][i / 2] = matrix[matrix.size() - 1 - i / 2][matrix.size() - 1 - i / 2 - j];
				matrix[matrix.size() - 1 - i / 2][matrix.size() - 1 - i / 2 - j] = matrix[i / 2 + j][matrix.size() - 1 - i / 2];
				matrix[i / 2 + j][matrix.size() - 1 - i / 2] = temp;
			}
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} };
	solute.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}