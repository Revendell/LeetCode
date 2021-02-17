#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        //����˼�룺��̬�滮�����䶯̬�滮���������˷�����312��������Ŀ����
        //dp[i][j]��ʾ��[i,j]�в³���ȷ��������Ҫ�����ٻ��ѽ��
        //��i==jʱ��ֻ��һ�����֣����ò£����ѽ��Ϊ0
        //��i+1==jʱ���������֣�ֻҪ��С���Ǹ����֣�ʣ�µľ��Ǵ�����֣����ѽ��Ϊi
        //�����������dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]))
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                if(i==j)
                    dp[i][j]=0;
                else if(i+1==j)
                    dp[i][j]=i;
                else
                {
                    for(int k=i+1;k<=j-1;k++)
                        dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
int main()
{
    Solution solute;
    int n=15;
    cout<<solute.getMoneyAmount(n)<<endl;
    return 0;
}
