#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<climits>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //����˼�룺����ջ��ά��һ������ջ
        //���ջ��Ԫ�ش��ڵ�ǰԪ�أ�˵��λ����Ҫ���������µ���λ�õĽ���λ�þ��ǵ�ǰλ�ã���upper_bound�ҵ�����λ�õ���ʼλ��
        //���������ջ
        vector<int> st;
        int start=nums.size(),finish=0;
        for(int i=0;i<nums.size();i++)
        {
            if(!st.empty()&&st.back()>nums[i])
            {
                finish=i;
                auto iter=upper_bound(st.begin(),st.end(),nums[i]);
                start=min(start,int(iter-st.begin()));
                st.insert(iter,nums[i]);
            }
            else
                st.push_back(nums[i]);
        }
        return max(finish-start+1,0);
    }
};
class Solution1 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //����˼�룺���α�����ʱ�临�Ӷ�O(n)
        //������ѭ������¼���ֵΪmaxv����nums[i]<maxv, �����λ��i��Ҫ����, ��¼��Ҫ���������λ��right=i;
        //���ҵ���ѭ������¼��СֵΪminv, ��nums[i]>minv, �����λ��i��Ҫ��������¼��Ҫ��������Сλ��left=i.
        int right=0,left=nums.size()-1,maxv=INT_MIN,minv=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<maxv)
                right=i;
            maxv=max(maxv,nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>minv)
                left=i;
            minv=min(minv,nums[i]);
        }
        return right==left?0:max(right-left+1,0);
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={2,6,4,8,10,9,15};
    cout<<solute.findUnsortedSubarray(nums)<<endl;
    return 0;
}
