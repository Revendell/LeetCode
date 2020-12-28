#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //基本思想：递归DFS深度优先搜索+备忘录，遍历二维数组matrix每一个元素，以该元素出发能得到的最大递增序列长度len，如果比res大则更新res
        //优化点：遍历当前元素得到最大递增路径长度len后，保存该值到dp中
        //这样下次其他元素走到该元素的时候就可以直接返回以当前元素出发的最大递增路径长度，减少递归次数
        int res=0;
        if(matrix.size()==0)  return res;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                //以matrix[i][j]出发得到的最大递增序列长度，如果比res大则更新res
                res=max(res,Recursion(matrix,dp,i,j));
        return res;
    }
    int Recursion(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j)
    {
        //以matrix[i][j]位置元素出发，计算出最大递增路径长度保存至dp[i][j]并返回
        //如果dp[i][j]!=0说明已经计算出了最大递增路径长度，直接返回
        if(dp[i][j]!=0)  return dp[i][j];
        int len1=0,len2=0,len3=0,len4=0;
        if(i+1<matrix.size()&&matrix[i+1][j]>matrix[i][j])
            len1=Recursion(matrix,dp,i+1,j);
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j])
            len2=Recursion(matrix,dp,i-1,j);
        if(j+1<matrix[i].size()&&matrix[i][j+1]>matrix[i][j])
            len3=Recursion(matrix,dp,i,j+1);
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j])
            len4=Recursion(matrix,dp,i,j-1);
        dp[i][j]=max(len1,max(len2,max(len3,len4)))+1;
        return dp[i][j];
    }
};
int main()
{
    Solution solute;
    vector<vector<int>> matrix={
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    cout<<solute.longestIncreasingPath(matrix)<<endl;
    return 0;
}
