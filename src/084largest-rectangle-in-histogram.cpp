#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		//����˼�룺����ջ����������ջ�����þ���Ϊ����ջ��Ԫ��Ϊ���ģ������������ҵ�С��ջ��Ԫ�ص����ұ߽�(left,i)��res = max(res, (i - left - 1) * heights[cur])
		//��ǰheights[i]Ԫ�ش���ջ������Ԫ����ջ������ʼ������ջ��Ԫ��Ϊ���εĸ�����������
		//ֱ���������������һ��������������ĸ߶ȸ�С�ľ���������ʱ��ջ��Ԫ��Ϊ���εĿ�Ⱦ��Ǹþ��������
		//Ѱ���ұ߽磬�����ԣ����ǵ�ǰheights[i]Ԫ���ұ߽�Ϊi�����heights[i]���ڵ���ջ��Ԫ�ؾ���ջ��
		//Ѱ����߽磬��Ȼ����ջ����һ��Ԫ�أ����ջ��û����һ��Ԫ�أ�˵��ջ��Ԫ��������ǰi��Ԫ����С���ˣ���߽����-1
		//ֻҪ��ǰheights[i]Ԫ��С��ջ��Ԫ�أ��ͼ�����ջ��Ԫ��Ϊ���εĸ�����¾�����������ȷ�����ұ߽�
		int res = 0, i, cur, left;
		stack<int> st;
		//����heightsÿ��Ԫ��
		for (i = 0; i <= heights.size(); i++)
		{
			//��ǰheights[i]Ԫ��С��ջ��Ԫ�ػ��ߵ�ǰ�±��Ѿ������ˣ�������ջ��Ԫ��Ϊ���εĸ�����¾���������
			while (!st.empty() && (i==heights.size() || heights[i] < heights[st.top()]))
			{
				cur = st.top();
				st.pop();
				//Ѱ����߽�
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
		//����˼�룺���η���ʱ�临�Ӷ�O(nlogn)����ʱ
		//ȷ����������Ժ󣬾��εĿ���������������
		//���������ߵ����������Σ������⣩
		//��������ұߵ����������Σ������⣩
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
		//����˼�룺��������ʱ�临�Ӷ�O(n^2)�ռ临�Ӷ�O(1)��ʱ������ѭ���ֱ���Ϊ���ε����ұ߽�������п��ܾ��Σ������������
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