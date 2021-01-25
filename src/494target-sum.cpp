#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<math.h>
using namespace std;
class Solution {
public:
    int res=0;
    int findTargetSumWays(vector<int>& nums, int S) {
        //����˼�룺�ݹ飬����ת��Ϊ�Ӽ�������⼴01�������⣬��nums�е�Ԫ�����+��-���������S���൱����nums���ҵ�Ԫ�غ�Ϊ(sum-S)/2
        //������ΪS+(sum-S)/2-(sum-S)/2=S��S+(sum-S)/2+(sum-S)/2=sum
        //ע�⣺
        //1����Ϊ+0��-0����Ӱ������ȥ��nums�����е�0�����������*2^zero
        //2�����sum-S��������˵��nums�е�Ԫ��ͨ��+��-���ܵõ�S����0
        int zero=0;
        for(int i=0;i<nums.size();i++)
        {
            while(i<nums.size()&&nums[i]==0)
            {
                zero+=1;
                nums.erase(nums.begin()+i);
            }
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=S;
        if(sum<0||sum&1)  return res;
        Recursion(nums,sum/2,0);
        return res*pow(2,zero);
    }
    void Recursion(vector<int>& nums, int sum,int pos)
    {
        if(sum<=0)
        {
            if(sum==0) res+=1;
            return;
        }
        for(int i=pos;i<nums.size();i++)
        {
            Recursion(nums,sum-nums[i],i+1);
        }
        return;
    }
};
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //����˼�룺��̬�滮������ת��Ϊ�Ӽ�������⼴01�������⣬��nums�е�Ԫ�����+��-���������S���൱����nums���ҵ�Ԫ�غ�Ϊ(sum-S)/2
        //dp[i]��ʾ�������Ϊi�ķ�������
        //ע�⣺���sum-S��������˵��nums�е�Ԫ��ͨ��+��-���ܵõ�S����0
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum-=S;
        if(sum<0||sum&1)  return 0;
        int w=sum/2;  //��������
        vector<int> dp(w+1,0);  //dp[i]��ʾ�������Ϊi�ķ�������
        dp[0]=1;
        for(auto num:nums)
        {
            for(int j=w;j>=num;j--)
            {
                dp[j]+=dp[j-num];
            }
        }
        return dp[w];
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,1,1,1,1};
    int S=3;
    cout<<solute.findTargetSumWays(nums,S)<<endl;
    return 0;
}
