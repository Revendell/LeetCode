#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //����˼�룺�ݹ�DFS�����������+����¼��������ά����matrixÿһ��Ԫ�أ��Ը�Ԫ�س����ܵõ������������г���len�������res�������res
        //�Ż��㣺������ǰԪ�صõ�������·������len�󣬱����ֵ��dp��
        //�����´�����Ԫ���ߵ���Ԫ�ص�ʱ��Ϳ���ֱ�ӷ����Ե�ǰԪ�س�����������·�����ȣ����ٵݹ����
        int res=0;
        if(matrix.size()==0)  return res;
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                //��matrix[i][j]�����õ������������г��ȣ������res�������res
                res=max(res,Recursion(matrix,dp,i,j));
        return res;
    }
    int Recursion(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j)
    {
        //��matrix[i][j]λ��Ԫ�س����������������·�����ȱ�����dp[i][j]������
        //���dp[i][j]!=0˵���Ѿ��������������·�����ȣ�ֱ�ӷ���
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
