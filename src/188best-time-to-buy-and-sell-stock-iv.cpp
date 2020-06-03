#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		//����˼�룺̰��+��̬�滮
		if (prices.size() == 0)
			return 0;
		int res = 0;
		//�������׵Ĵ������ڽ�������ʱ���൱���ǿ������޽��ף�ʹ��̰���㷨
		//����k����dp���䲻����ô���ڴ�ռ�
		if (k > prices.size()/2)
		{
			for (int i = 1; i < prices.size(); i++)
			{
				if (prices[i] > prices[i - 1])
					res += prices[i] - prices[i - 1];
			}
			return res;
		}
		//dp[i][k][0 or 1]��ʾ��i�죬�Ѿ����״���k�������Ƿ���й�Ʊ״̬�µ��������
		vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, 0)));
		//��ʼ״̬����
		dp[0][0][0] = 0;
		dp[0][0][1] = -prices[0];
		for (int i = 1; i < k + 1; i++)
		{
			dp[0][i][0] = -999999;
			dp[0][i][1] = -999999;
		}
		//������1��֮���ÿ���Ʊ���������ÿһ���2*(k+1)��״̬�µ��������
		for (int i = 1; i < prices.size(); i++)
		{
			for (int j = 0; j < k + 1; j++)
			{
				//��i�죬�Ѿ����״���j������û�й�Ʊ�µ�����������max(1���޲�����ǰһ���״̬�µ����棻2��������Ʊ��ǰһ��ĳ��й�Ʊ�µ��������+�����Ʊ�۸���Ϊ������Ʊ������j+1)
				if (j != 0)
					dp[i][j][0] = max(dp[i - 1][j - 1][1] + prices[i], dp[i - 1][j][0]);
				//��i�죬�Ѿ����״���j�����г��й�Ʊ״̬�µ�����������max(1���޲�����ǰһ���״̬�µ����棻2�������Ʊ��ǰһ���û�й�Ʊ�µ�������� - �����Ʊ�۸���Ϊ�����Ʊ��û����������������)
				dp[i][j][1] = max(dp[i - 1][j][0] - prices[i], dp[i - 1][j][1]);
			}
		}
		//����������һ�������в����й�Ʊ�����Է������һ�첻���й�Ʊ��k+1��״̬�µ��������
		for (int i = 0; i < k + 1; i++)
			res = max(res, dp[prices.size() - 1][i][0]);
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> prices = { 3,2,6,5,0,3 };
	int k = 2;
	cout << solute.maxProfit(k, prices) << endl;
	return 0;
}