#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    int integersplit(int n)
    {
        //基本思想：动态规划，dp[i][j]表示数字i拆分出最大值j的拆分可能的情况数
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1||j==1)
                    dp[i][j]=1;
                else if(i==j)
                    dp[i][j]=dp[i][j-1]+1;
                else if(i<j)
                    dp[i][j]=dp[i][i];
                else if(i>j)
                    dp[i][j]=dp[i-j][j]+dp[i][j-1];
            }
        }
        return dp[n][n];
    }
};
int main()
{
    Solution solute;
    int n=50;
    cout<<solute.integersplit(n)<<endl;
    return 0;
}