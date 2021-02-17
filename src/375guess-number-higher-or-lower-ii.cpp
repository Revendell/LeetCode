#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        //基本思想：动态规划，区间动态规划，矩阵链乘法，和312戳气球题目类似
        //dp[i][j]表示从[i,j]中猜出正确数字所需要的最少花费金额
        //当i==j时，只有一个数字，不用猜，花费金额为0
        //当i+1==j时，两个数字，只要猜小的那个数字，剩下的就是大的数字，花费金额为i
        //当其他情况，dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]))
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
