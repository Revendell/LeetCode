#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
	    //基本思想：贪心算法
	    //把所有孩子的糖果数初始化为 1；
        //先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的糖果数加 1；
        //再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1
        if (ratings.size() < 2) return ratings.size();
        vector<int> nums(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1])
                nums[i] = nums[i-1] + 1;
        }
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i] < ratings[i-1])
                nums[i-1] = max(nums[i-1], nums[i] + 1);
        }
		int sum = 0;
		//最后返回nums元素之和
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
};
class Solution1 {
public:
	int candy(vector<int>& ratings) {
		//基本思想：单调递减栈，因为当前孩子给的糖果数取决于相邻的孩子评分，对于评分递减的情况就暂时不确定给当前孩子几个糖果
		//利用单调递减栈，如果当前孩子评分大于下一个孩子入栈，直到当前孩子评分小于下一个孩子出栈
		if (ratings.size() <= 1)
			return ratings.size();
		//nums保存对应下标孩子的糖果数，最后返回nums元素之和
		vector<int> nums(ratings.size(), 0);
		stack<int> st;    //单调递减栈
		int i = 0;
		while (i < ratings.size() || !st.empty())
		{
			//当前孩子评分大于下一个孩子，孩子评分开始下坡递减全都入栈
			if (i + 1<= ratings.size() - 1 && ratings[i] > ratings[i + 1])
			{
				st.push(i);
			}
			//当前孩子评分小于下一个孩子，孩子评分开始上坡递增
			else
			{
				//当前孩子评分大于上一个孩子直接糖果数+1，孩子评分上坡递增
				if (i < ratings.size() && i - 1 >= 0 && ratings[i] > ratings[i - 1])
					nums[i] = nums[i - 1] + 1;
				//当前孩子评分是左右两边最低评分，位于坡脚情况
				else
				    nums[i] = 1;
				while (!st.empty())
				{
					int pos = st.top();
					st.pop();
					//如果当前孩子评分是左右两边最高评分，位于坡顶
					if (pos - 1 >= 0 && ratings[pos] > ratings[pos - 1])
						nums[pos] = max(nums[pos + 1], nums[pos - 1]) + 1;
					else
						nums[pos] = nums[pos + 1] + 1;
				}
			}
			i++;
		}
		int sum = 0;
		//最后返回nums元素之和
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
};
class Solution2 {
public:
	vector<int> nums;
	int candy(vector<int>& ratings) {
		//基本思想：递归，超时
		if (ratings.size() <= 1)
			return ratings.size();
		for (int i = 0; i < ratings.size(); i++)
			nums.push_back(0);
		for (int i = 0; i < ratings.size(); i++)
		{
			if (nums[i] == 0)
				dfs(ratings, i);
		}
		int sum = 0;
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
	int dfs(vector<int>& ratings, int pos)
	{
		//右边界
		if (pos == ratings.size() - 1)
		{
			nums[pos] = ratings[pos] <= ratings[pos - 1] ? 1 : dfs(ratings, pos - 1) + 1;
			return nums[pos];
		}
		//左边界
		if (pos == 0)
		{
			nums[pos] = ratings[pos] <= ratings[pos + 1] ? 1 : dfs(ratings, pos + 1) + 1;
			return nums[pos];
		}
		//同时小于两边值
		if (ratings[pos] <= ratings[pos + 1] && ratings[pos] <= ratings[pos - 1])
		{
			nums[pos] = 1;
			return  nums[pos];
		}
		//同时大于两边值
		if (ratings[pos] > ratings[pos + 1] && ratings[pos] > ratings[pos - 1])
		{
			nums[pos] = max(dfs(ratings, pos + 1), dfs(ratings, pos - 1)) + 1;
			return nums[pos];
		}
		//小于一边值大于一边值
		nums[pos] = ratings[pos] > ratings[pos + 1] ? dfs(ratings, pos + 1) + 1 : dfs(ratings, pos - 1) + 1;
		return nums[pos];
	}
};
int main()
{
	Solution solute;
	vector<int> ratings = { 1,2,2 };
	cout << solute.candy(ratings) << endl;
	return 0;
}
