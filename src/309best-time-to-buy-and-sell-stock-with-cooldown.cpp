
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //����˼�룺��̬�滮��dp[i][0 or 1 or 2]��ʾ��i�������Ƿ���й�Ʊ���䶳��״̬�µ��������
        //dp[i][0]��ʾ��i�����в����й�Ʊ״̬�µ��������
        //dp[i][1]��ʾ��i�����г��й�Ʊ״̬�µ��������
        //dp[i][2]��ʾ��i���䶳��״̬�µ��������
        if(prices.size()<2)  return 0;
        //dp[i][0 or 1 or 2]��ʾ��i�죬�����Ƿ���й�Ʊ���䶳��״̬�µ��������
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        //��ʼ����0��״ֵ̬
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        dp[0][2]=0;
        //������1��֮���ÿ���Ʊ���
        for(int i=1;i<prices.size();i++)
        {
            //��i������û�й�Ʊ�µ�����������max(1��ǰһ��û�й�Ʊ״̬�µ����棻2��ǰһ���䶳��״̬�µ�����)
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            //��i�������й�Ʊ�µ�����������max(1�������Ʊ��ǰһ���û�й�Ʊ�µ��������-�����Ʊ�۸�2���޲�����ǰһ���й�Ʊ״̬�µ�����)
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
            //��i���䶳���µ��������ǰһ���й�Ʊ״̬����������Ʊ�µ����棬Ҳ����ǰһ��ĳ��й�Ʊ�µ�����+�����Ʊ�۸�
            dp[i][2] = dp[i-1][1]+prices[i];
        }
        //����������һ�������в����й�Ʊ�����Է������һ�첻���й�Ʊ״̬�º��䶳��״̬���е����ֵ
        return max(dp[prices.size()-1][0],dp[prices.size()-1][2]);
    }
};
int main()
{
    vector<int> prices={1,2,3,0,2};
    Solution solute;
    cout<<solute.maxProfit(prices)<<endl;
    return 0;
}
