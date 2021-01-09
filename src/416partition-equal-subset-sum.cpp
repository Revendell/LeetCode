#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //����˼�룺��̬�滮��01�������⣬�õݹ���ݱس�ʱ
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1)  return false;
        //dp[i]��ʾ�ܷ���������Ϊi�ı���
        vector<bool> dp(sum/2+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum/2;j>=nums[i];j--)
                dp[j]=dp[j]||dp[j-nums[i]];
        }
        return dp[sum/2];
    }
};
int main()
{
    Solution solute;
    vector<int> nums={1,2,3,4,6,7,8,9};
    cout<<solute.canPartition(nums)<<endl;
    return 0;
}
