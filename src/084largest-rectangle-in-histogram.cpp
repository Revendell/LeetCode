#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		//基本思想：单调栈，单调递增栈的作用就是为了以栈顶元素为中心，向两边延伸找到小于栈顶元素的左右边界(left,i)，res = max(res, (i - left - 1) * heights[cur])
		//当前heights[i]元素大于栈顶，则元素入栈，否则开始计算以栈顶元素为矩形的高往两侧延伸
		//直到遇到左右两侧第一个比这个矩形条的高度更小的矩形条，此时以栈顶元素为矩形的宽度就是该矩形最大宽度
		//寻找右边界，很明显，就是当前heights[i]元素右边界为i，如果heights[i]大于等于栈顶元素就入栈了
		//寻找左边界，显然就是栈顶下一个元素，如果栈顶没有下一个元素，说明栈顶元素是整个前i个元素最小的了，左边界就是-1
		//只要当前heights[i]元素小于栈顶元素，就计算以栈顶元素为矩形的高情况下矩形最大面积，确定左右边界
		int res = 0, i, cur, left;
		stack<int> st;
		//遍历heights每个元素
		for (i = 0; i <= heights.size(); i++)
		{
			//当前heights[i]元素小于栈顶元素或者当前下标已经到底了，计算以栈顶元素为矩形的高情况下矩形最大面积
			while (!st.empty() && (i==heights.size() || heights[i] < heights[st.top()]))
			{
				cur = st.top();
				st.pop();
				//寻找左边界
				left=!st.empty()?st.top():-1;
				res = max(res, (i - left - 1) * heights[cur]);
			}
			st.push(i);
		}
		return res;
	}
};
class Solution1 {
public:
	int largestRectangleArea(vector<int>& heights) {
		//基本思想：分治法，时间复杂度O(nlogn)，超时
		//确定了最矮柱子以后，矩形的宽尽可能往两边延伸
		//在最矮柱子左边的最大面积矩形（子问题）
		//在最矮柱子右边的最大面积矩形（子问题）
		return calculateArea(heights, 0, heights.size() - 1);
	}
	int calculateArea(vector<int>& heights, int start, int end)
	{
		if (start > end)
			return 0;
		int lower = start;
		for (int i = start; i <= end; i++)
		{
			if (heights[i] < heights[lower])
				lower = i;
		}
		return max(heights[lower] * (end - start + 1), max(calculateArea(heights, start, lower - 1), calculateArea(heights, lower + 1, end)));
	}
};
class Solution2 {
public:
	int largestRectangleArea(vector<int>& heights) {
		//基本思想：暴力法，时间复杂度O(n^2)空间复杂度O(1)超时，两重循环分别作为矩形的左右边界遍历所有可能矩形，计算出最大面积
		int res = 0, i, j, k, cur, lower;
		for (i = 0; i < heights.size(); i++)
		{
			lower = heights[i];
			for (j = i; j < heights.size(); j++)
			{
				lower = min(lower, heights[j]);
				cur = lower * (j - i + 1);
				if (cur > res)
					res = cur;
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> heights = { 2,1,2 };
	cout << solute.largestRectangleArea(heights) << endl;
	return 0;
}