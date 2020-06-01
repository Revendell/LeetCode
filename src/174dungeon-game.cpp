#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//����˼�룺����̬�滮��dp[i][j]��ʾ�ӵ�i�е�j��λ�ÿ�ʼ�����½��������С����ֵ
		//�����Ŀ�����뵽��Ӧ�þ��Ƕ�̬�滮����������̬�滮���ֵ�ǰλ���������С����ֵȡ���ں���ķ���ֵ
		//���統ǰʣ������33����С����ֵ-7�����ұ߷���ʣ������ֵ-6����С����ֵ-6������˵����ߵ��ұ߷��䲻��Ҫ������С����ֵ
		//��Ϊ-7С��-6�������С����ֵ�󣬵���������һ������ֵ��-9����ô���յ���С����ֵ��-15
		//���������С����ֵ����ô���յ���С����ֵ��-7
		//�������뵽����̰��+��̬�滮���ȱ���ʣ������ֵ����·���Լ�������С����ֵ��С��·��������ʵ���ǲ�����
		//���ʱ��Ӧ���뵽��Ȼ��ǰ������С����ֵȡ���ں���ģ�����ʹ������̬�滮�����յ��������¶�̬����
		int row, col;
		row = dungeon.size();
		col = dungeon[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		dp[row - 1][col - 1] = dungeon[row - 1][col - 1] > 0 ? 1 : 1 - dungeon[row - 1][col - 1];
		for (int i = row - 2; i >= 0; i--)
		{
			dp[i][col - 1] = max(dp[i + 1][col - 1] - dungeon[i][col - 1], 1);
		}
		for (int j = dungeon[0].size() - 2; j >= 0; j--)
		{
			dp[row - 1][j] = max(dp[row - 1][j + 1] - dungeon[row - 1][j], 1);
		}
		for (int i = row- 2; i >= 0; i--)
		{
			for (int j = col - 2; j >= 0; j--)
			{
				int down = max(dp[i + 1][j] - dungeon[i][j], 1);
				int right = max(dp[i][j + 1] - dungeon[i][j], 1);
				dp[i][j] = min(down, right);
			}
		}
		return dp[0][0];
	}
};
class Solution1 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//����˼�룺����̬�滮��ֻͨ����42����������
		vector<vector<vector<int>>> dp(dungeon.size() + 1, vector<vector<int>>(dungeon[0].size() + 1, vector<int>(4, 0)));
		for (int i = 0; i <= dungeon.size(); i++)
		{
			dp[i][0][0] = -999999;
			dp[i][0][1] = 999999;
			dp[i][0][2] = -999999;
			dp[i][0][3] = 999999;
		}
		for (int j = 0; j <= dungeon[0].size(); j++)
		{
			dp[0][j][0] = -999999;
			dp[0][j][1] = 999999;
			dp[0][j][2] = -999999;
			dp[0][j][3] = 999999;
		}
		for (int i = 0; i < dungeon.size(); i++)
		{
			for (int j = 0; j < dungeon[i].size(); j++)
			{
				if (i == 0 && j == 0)
				{
					dp[i + 1][j + 1][0] = dungeon[i][j];
					dp[i + 1][j + 1][1] = min(0,dungeon[i][j]);
					dp[i + 1][j + 1][2] = dungeon[i][j];
					dp[i + 1][j + 1][3] = min(0,dungeon[i][j]);
				}
				else
				{
					int left_rest, up_rest, left_min, up_min;
					left_rest = dp[i + 1][j][0] + dungeon[i][j];
					up_rest = dp[i][j + 1][0] + dungeon[i][j];
					left_min = min(left_rest, dp[i + 1][j][1]);
					up_min = min(up_rest, dp[i][j + 1][1]);
					if (up_min > left_min)
					{
						dp[i + 1][j + 1][0] = up_rest;
						dp[i + 1][j + 1][1] = up_min;
					}
					else
					{
						dp[i + 1][j + 1][0] = left_rest;
						dp[i + 1][j + 1][1] = left_min;
					}
					left_rest = dp[i + 1][j][2] + dungeon[i][j];
					up_rest = dp[i][j + 1][2] + dungeon[i][j];
					left_min = min(left_rest, dp[i + 1][j][3]);
					up_min = min(up_rest, dp[i][j + 1][3]);
					if (up_rest > left_rest)
					{
						dp[i + 1][j + 1][2] = up_rest;
						dp[i + 1][j + 1][3] = up_min;
					}
					else
					{
						dp[i + 1][j + 1][2] = left_rest;
						dp[i + 1][j + 1][3] = left_min;
					}
				}	
			}
		}
		if (dp[dungeon.size()][dungeon[0].size()][1] >= 0 || dp[dungeon.size()][dungeon[0].size()][3] >= 0)
			return 1;
		else
			return 1 - max(dp[dungeon.size()][dungeon[0].size()][1], dp[dungeon.size()][dungeon[0].size()][3]);
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> dungeon = {
		{-2,-3,3 }, { -5,-10,1 }, { 10,30,-5 }, { -7,-8,1 }
	};
	cout << solute.calculateMinimumHP(dungeon) << endl;
	return 0;
}