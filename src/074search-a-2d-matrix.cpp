#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//�򻯰棺�����½ǳ�������target������ƣ���targetС������
		int n = matrix.size(), m = matrix[0].size();
		int i=n-1,j=0;
		while(i<0||j>=m)
		{
			if(matrix[i][j]==target)
				return true;
			else if(matrix[i][j]>target)
				i--;
			else
				j++;
		}
		return false;
	}
};
class Solution1 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//����˼�룺���ֲ��ң�����ά����matrix����һά���飬�±�Ϊmid��ֵ�ڶ�ά�����ӦֵΪmatrix[mid/m][mid%m]
		if (matrix.size() == 0)
			return false;
		int low, mid, high;
		int n = matrix.size(), m = matrix[0].size();
		low = 0;
		high = n * m - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (target == matrix[mid / m][mid % m])
				return true;
			else if (target > matrix[mid / m][mid % m])
			{
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = {
		{1,   3,  5,  7} ,
		{10, 11, 16, 20} ,
		{23, 30, 34, 50}
	};
	int target = 3;
	cout << solute.searchMatrix(matrix, target) << endl;
	return 0;
}