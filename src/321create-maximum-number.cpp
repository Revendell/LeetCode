#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //基本思想：单调栈+归并思想
        //假设我们从nums1中取了k1个，从num2中取了k2个，其中k1+k2=k。
        //而k1和k2这两个子问题我们是会解决的。由于这两个子问题是相互独立的，
        //因此我们只需要分别求解，然后将结果合并即可。
        //如何从num中取n个数组成最大的数呢？
        //使用单调栈，如果当前数字比栈顶大，并且当前数字之后还有足够的数字组成为n位数，
        //则栈顶数字出栈，当前数字入栈，替换掉了栈顶数字
        vector<int> res;
        if(k==0) return {};
        for(int i=0;i<=k&&i<=nums1.size();i++)
        {
            if(k-i>nums2.size())
                continue;
            vector<int> temp1=maxPick(nums1,i);
            vector<int> temp2=maxPick(nums2,k-i);
            vector<int> cur=mergeNums(temp1,temp2);
            res=max(res,cur);
        }
        return res;
    }
    //单调栈，从num中取n个数组成最大的数
    vector<int> maxPick(vector<int> num,int n)
    {
        vector<int> st;
        if(n==0) return st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty()&&st.back()<num[i]&&n-int(st.size())<=int(num.size())-1-i)
                st.pop_back();
            if(st.size()<n)
                st.push_back(num[i]);
        }
        return st;
    }
    //将nums1和nums2中取出的数合并成最大数
    vector<int> mergeNums(vector<int> nums1,vector<int> nums2)
    {
        vector<int> nums;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            //这里注意当nums1[i]==nums2[j]的时候，需要比较i和j后序的数字大小才能确定到底push_back
            //比如nums1={6,7} nums2={6,0,4}，因为6==6，所以比较{7}和{0,4}的大小，大的那个才会push_back
            if(nums1[i]>nums2[j])
                nums.push_back(nums1[i++]);
            else if(nums1[i]<nums2[j])
                nums.push_back(nums2[j++]);
            else
            {
                vector<int> nums1copy(nums1.begin()+i+1,nums1.end());
                vector<int> nums2copy(nums2.begin()+j+1,nums2.end());
                if(nums1copy>nums2copy)
                    nums.push_back(nums1[i++]);
                else
                    nums.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size())
            nums.push_back(nums1[i++]);
        while(j<nums2.size())
            nums.push_back(nums2[j++]);
        return nums;
    }
};
int main()
{
    Solution solute;
    vector<int> nums1={3, 4, 6, 5};
    vector<int> nums2={9, 1, 2, 5, 8, 3};
    int k=5;
    vector<int> res=solute.maxNumber(nums1,nums2,k);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
