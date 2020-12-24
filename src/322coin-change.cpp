
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //����˼�룺��̬�滮��dp[i]��ʾ�ܽ��Ϊiʱ����Ӳ��������1��amount����ÿһ���ܽ���µ�Ӳ����
        //��̬����dp[i]=min(dp[i],dp[i-coins[j]]+1)
        //����Ȿ�ʺ�70��¥�����ƣ���¥��ÿ������1����2��¥�ݣ�����n��¥�ݶ����ַ���dp[i]=dp[i-1]+dp[i-2]���������n��¥�����ٵĲ�������dp[i]=min(dp[i-1]+1,dp[i-2]+1)
        //���������ÿ�����Ľ�����Ϊcoins[0:n-1]��������amount����Ҫ�����ٲ�����dp[i]=min(dp[i],dp[i-coins[j]]+1)
        //dp��ʼ��Ϊ-1��ʾӲ��ƴ�ղ�����ǰ���
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0&&dp[i-coins[j]]!=-1)
                    dp[i]=dp[i]==-1?dp[i-coins[j]]+1:min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount];
    }
};
int main()
{
    Solution solute;
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<solute.coinChange(coins,amount)<<endl;
    return 0;
}
