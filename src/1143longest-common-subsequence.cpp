#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //基本思想：动态规划，dp[i][j]表示text1前i个字符与text2前j个字符时最长公共子序列的大小
        //dp初始化全为0，因为dp[0][j]=0 dp[i][0]=0当某个字符串为空就没有公共子序列
        //如果text1[i]==text2[j]，则dp[i+1][j+1]=dp[i][j]+1
        //如果text1[i]!=text2[j]，则dp[i+1][j+1]=max(dp[i][j],dp[i][j+1],dp[i+1][j])
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<text1.size();i++)
        {
            for(int j=0;j<text2.size();j++)
            {
                if(text1[i]==text2[j])
                    dp[i+1][j+1]=dp[i][j]+1;
                else
                    dp[i+1][j+1]=max(dp[i][j],max(dp[i][j+1],dp[i+1][j]));
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
int main()
{
    Solution solute;
    string text1 = "abcde", text2 = "adcbe";
    cout<<solute.longestCommonSubsequence(text1,text2)<<endl;
    return 0;
}
