#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //�򻯰棺��̬�滮������̬�滮��dp[i][j]��ʾ[i,j]��Χ����������ע���һ��ѭ��������j����������j�ķ�Χ������i�����j-2������ǰ��0���ȼ����nums[i]*nums[k]*nums[j]
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int j=2;j<nums.size();j++)
        {
            for(int i=j-2;i>=0;i--)
            {
                for(int k=i+1;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
            }
        }
        return dp[0][nums.size()-1];
    }
};
class Solution1 {
public:
    int maxCoins(vector<int>& nums) {
        //����˼�룺��̬�滮������һ�����䶯̬�滮���õ��Ƿ��ε�˼�룬��������С������£��������뵽dfs+���仯���������Ե�����dp�Ƴ����ġ�ʯ�Ӻϲ���Floyd�㷨����һ���⡣
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        //dp[i][j]��ʾ�ڿ�����(i,j)��Χ�ڽ�������ֵ��dp[i][j]��ʾi~j���ֵ��i��j�����ơ�
        //����������Ϊ���Ҷ˵㣬�ҳ����Ž��������м��Ǹ����Ƶ������м����������������з�Ϊ��2���֣�
        //Ҫ�����м���������2���˵㿿��һ�𣬾���Ҫ�Ȱѷֿ���2���ֵ�������ơ�
        //����k������i,j֮��ʱ(i,k,j)�����ƣ���ôҪ�ȴ���i,k��k,j֮�������
        //����dp[i][j]=dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),0));
        for(int i=nums.size()-2;i>=0;i--)
        {
            for(int j=i+2;j<nums.size();j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};
int main()
{
    vector<int> nums={3,2,1,2,3,2,1};
    Solution solute;
    cout<<solute.maxCoins(nums)<<endl;
    return 0;
}
