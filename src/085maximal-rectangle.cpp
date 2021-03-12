#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		//����˼�룺����ջ�����õ�84�����״ͼ��������������������������Կ���matrix.size����״ͼ���������
		//ѭ������matrix.size�У���ÿһ�α������е�����״ͼ�ĵױ����ϴ�������1������״ͼ�ĸߣ�ʱ�临�Ӷ�O(n*m)�ռ临�Ӷ�O(m)
		//�ܽ᣺��ʱ��������԰�������ѽ�������⵱��ȥ�����Դ��ļ�����
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
		//����˼�룺����ջ����������ջ�����þ���Ϊ����ջ��Ԫ��Ϊ���ģ������������ҵ�С��ջ��Ԫ�ص����ұ߽�
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
			while (!st.empty() && (i == heights.size() || heights[i] < heights[st.top()]))
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