#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    int substrmatching(string s,string p)
    {
        //基本思想：动态规划
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,9999));
        dp[0][0]=0;
        for(int i=1;i<=s.size();i++)
            dp[i][0]=0;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                if(s[i-1]==p[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            }
        }
        int res=9999;
        for(int i=p.size();i<=s.size();i++)
            res=min(res,dp[i][p.size()]);
        return res;
    }
};
int main()
{
    string s="axb",p="ab";
    Solution solute;
    cout<<solute.substrmatching(s,p)<<endl;
    return 0;
}