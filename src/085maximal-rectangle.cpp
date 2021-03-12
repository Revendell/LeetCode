#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		//基本思想：单调栈，利用第84题的柱状图最大矩形面积，最大矩形这个问题可以看成matrix.size个柱状图最大矩形面积
		//循环遍历matrix.size行，将每一次遍历的行当做柱状图的底边往上存在连续1就是柱状图的高，时间复杂度O(n*m)空间复杂度O(m)
		//总结：有时候，如果可以把题抽象到已解决的问题当中去，可以大大的简化问题
		if (matrix.size() == 0)
			return 0;
		int i, j, res = 0;
		vector<int> heights(matrix[0].size(), 0);
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
					heights[j] += 1;
				else
					heights[j]=0;
			}
			res = max(res, largestRectangleArea(heights));
		}
		return res;
	}
	int largestRectangleArea(vector<int>& heights) {
		//基本思想：单调栈，单调递增栈的作用就是为了以栈顶元素为中心，向两边延伸找到小于栈顶元素的左右边界
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
			while (!st.empty() && (i == heights.size() || heights[i] < heights[st.top()]))
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
int main()
{
	Solution solute;
	vector<vector<char>> matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	cout << solute.maximalRectangle(matrix) << endl;
	return 0;
}