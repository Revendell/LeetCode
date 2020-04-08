#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//基本思想：排序+双指针，这种在数组空间上进行各种操作的题目，一般可以利用双指针进行解决
		//对排序后的intervals，指针i指向与前元素不能合并的元素下标，通过指针j寻找i后面能与i合并的元素，寻找过程中不断更新最大范围[left,right]，直到找不到可以合并的元素则j赋值给i作为下一个与前元素不能合并的元素下标，[left,right]保存至res
		vector<vector<int>> res;
		int i, j, left, right;
		sort(intervals.begin(), intervals.end());
		i = 0;
		while (i < intervals.size())
		{			
			left = intervals[i][0];
			right = intervals[i][1];
			j = i + 1;
			while (j < intervals.size())
			{
				if (intervals[i][1] >= intervals[j][0])
				{
					left = min(left, intervals[j][0]);
					right = max(left, intervals[j][1]);
				}
				else
					break;
				j++;
			}
			res.push_back({ left,right });
			i = j;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> intervals = {
		{1,3},{2,6},{8,10},{15,18}
	};
	vector<vector<int>> res;
	res = solute.merge(intervals);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}