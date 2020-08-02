#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//基本思想：敏锐的观察力，从从左下上角出发会发现每次都是向上数字会变小，向右数字会变大
		//有点和二分查找树相似,时间复杂度O(m+n)
		int n = matrix.size() - 1, m = 0;
		while (n >= 0 && m < matrix[0].size())
		{
			if (matrix[n][m] == target)
				return true;
			else if (matrix[n][m] > target)
				n--;
			else
				m++;
		}
		return false;
	}
};
class Solution1 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//基本思想：二分查找，时间复杂度O(nlogn)
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[i].size()>0 && target>matrix[i].back())
				continue;
			if (binarySearch(matrix[i], target))
				return true;
		}
		return false;
	}
	bool binarySearch(vector<int> vec, int target)
	{
		int low = 0, high = vec.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (vec[mid] == target)
				return true;
			else if (vec[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}
};
int main()
{
	Solution1 solute;
	vector<vector<int>> matrix = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	int target = 12;
	cout << solute.searchMatrix(matrix, target) << endl;
	return 0;
}