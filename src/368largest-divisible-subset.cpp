#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //����˼�룺�ݹ飬��ʱ��������Ŀһ���ݹ鳬ʱ���ö�̬�滮
        vector<int> cur;
        sort(nums.begin(),nums.end());
        Recursion(nums,cur,0);
        vector<int> ans;
        int len=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i].size()>len)
            {
                ans=res[i];
                len=res[i].size();
            }
        }
        return ans;
    }
    void Recursion(vector<int>& nums,vector<int> cur,int pos)
    {
        res.push_back(cur);
        for(int i=pos;i<nums.size();i++)
        {
            if(cur.empty()||nums[i]%cur.back()==0)
            {
                cur.push_back(nums[i]);
                Recursion(nums,cur,i+1);
                cur.pop_back();
            }
        }
    }
};
class Solution1 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //����˼�룺��̬�滮
        //dp[i]: ��nums[i]��β��������󳤶ȣ���ʼ״̬��Ϊ1�����ٳ���Ϊ1
        //pre[i]: ����������� nums[i]����һ��Ԫ����nums���ֵ��±�
        //len��¼dp[i]�����ĳ��ȣ�endi��¼��󳤶��µ����һ��nums���±꣬ͨ��pre[endi]����׷�ٵõ�res
        //ʹ�ö���ѭ��������ÿһ��nums[i]�������Խ���֮ǰ���ĸ�����dp[j]�ϣ�ʹ��dp[i]�
        //nums[i]%nums[j] == 0�ǿ��Խӵ�������dp[i]<=dp[j]��ʹ��dp[i]�䳤������
        vector<int> dp(nums.size(),1);
        vector<int> pre(nums.size(),-1);
        vector<int> res;
        int len=0,endi;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[i]>len)
            {
                len=dp[i];
                endi=i;
            }
        }
        res.push_back(nums[endi]);
        while(pre[endi]!=-1)
        {
            res.push_back(nums[pre[endi]]);
            endi=pre[endi];
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    vector<int> res=solute.largestDivisibleSubset(nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
