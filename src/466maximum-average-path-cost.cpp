#include<iostream>
#include<vector>
using namespace std;
int M,N;
struct Node{
    int steps;
    int sum;
};
vector<vector<int>> compute_cost;
int res=0;
void dfs(int i,int j,vector<vector<int>> visited,vector<vector<Node>> dp)
{
    if(visited[i][j]==1)
        return;
    visited[i][j]=1;
    if(i==M-1&&j==N-1)
    {
        res=max(res,dp[i][j].sum/dp[i][j].steps);
        return;
    }
    int cursum,cursteps;
    if(i-1>=0)
    {
        dp[i-1][j].sum=dp[i][j].sum+compute_cost[i-1][j];
        dp[i-1][j].steps=dp[i][j].steps+1;
        dfs(i-1,j,visited,dp);
    }
    if(i+1<M)
    {
        dp[i+1][j].sum=dp[i][j].sum+compute_cost[i+1][j];
        dp[i+1][j].steps=dp[i][j].steps+1;
        dfs(i+1,j,visited,dp);
    }
    if(j-1>=0)
    {
        dp[i][j-1].sum=dp[i][j].sum+compute_cost[i][j-1];
        dp[i][j-1].steps=dp[i][j].steps+1;
        dfs(i,j-1,visited,dp);
    }
    if(j+1<N)
    {
        dp[i][j+1].sum=dp[i][j].sum+compute_cost[i][j+1];
        dp[i][j+1].steps=dp[i][j].steps+1;
        dfs(i,j+1,visited,dp);
    }  
}
int main()
{ 
    cin>>M>>N;
    vector<vector<Node>> dp;
    vector<vector<int>> visited(M,vector<int>(N,0));
    for(int i=0;i<M;i++)
    {
        vector<int> tmp;
        vector<Node> tmp1;
        for(int j=0;j<N;j++)
        {
            int x;
            Node y;
            y.steps=1;
            y.sum=0;
            cin>>x;
            tmp.push_back(x);
            tmp1.push_back(y);
        }
        compute_cost.push_back(tmp);
        dp.push_back(tmp1);
    }
    dp[0][0].sum=compute_cost[0][0];
    dp[0][0].steps=1;
    dfs(0,0,visited,dp);
    cout<<res<<endl;
}