#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//����˼�룺�������������ɨ��matrix������ÿһ��Ԫ��
		//�����1�������������������������������������������������Ԫ���Ƿ�Ϊ1������������Ԫ������У���������
		int res = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
				{
					int len = 1;
					res = max(res, len);
					deque<pair<int, int>> queue;
					queue.push_front({ i,j });
					while (!queue.empty())
					{
						int queuelen = queue.size();
						while(queuelen)
						{
							pair<int, int> temp = queue.back();
							queue.pop_back();
							if (check(matrix, temp.first, temp.second))
							{
								queue.push_front({ temp.first + 1,temp.second });
								queue.push_front({ temp.first,temp.second + 1 });
								queue.push_front({ temp.first + 1,temp.second + 1 });
							}
							else
								break;
							queuelen--;
						}
						if (queuelen == 0)
						{
							len++;
							res = max(res, len);
						}
						else
							break;		
					}
				}
			}
		}
		return res * res;
	}
	bool check(vector<vector<char>>& matrix, int i, int j)
	{
		if (j + 1 < matrix[0].size() && matrix[i][j + 1] == '1' && i + 1 < matrix.size() && matrix[i + 1][j] == '1'&& matrix[i + 1][j+1] == '1')
			return true;
		return false;
	}
};
class Solution1 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		//����˼�룺��̬�滮��dp[i][j]��ʾ�����ǰλ�ü�����ɵ������εı߳�
		//�����λ�õ�ֵ��1����dp(i,j) ��ֵ�����Ϸ����󷽺����Ϸ�����������λ�õ�dpֵ������
		//��ǰλ�õ�Ԫ��ֵ������������λ�õ�Ԫ���е���Сֵ��1��״̬ת�Ʒ������£�
		//dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
		if (matrix.size() == 0)
			return 0;
		int res = 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
				{
					if (i == 0 || j == 0)
						dp[i][j] = 1;
					else
					    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					res = max(res, dp[i][j]);
				}
			}
		}
		return res * res;
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> matrix = {
		{'0', '0', '0', '1'},
		{'1', '1', '0', '1'},
		{'1', '1', '1', '1'},
		{'0', '1', '1', '1'},
		{'0', '1', '1', '1'}
	};
	cout << solute.maximalSquare(matrix) << endl;
	return 0;
}