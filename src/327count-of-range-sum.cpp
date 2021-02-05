#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //基本思想：线段树，超时，时间复杂度O(n^2)
        //建立线段树tree，然后双重循环分别遍历区间的起始和终止
        //利用线段树求出[i,j]区间的和sum，如果满足[lower,upper]区间res++
        int res=0;
        vector<long long> tree(nums.size()*2,0);
        for(int i=0;i<nums.size();i++)
            tree[nums.size()+i]=nums[i];
        for(int i=nums.size()-1;i>=1;i--)
            tree[i]=tree[2*i]+tree[2*i+1];
        for(int i=nums.size();i<tree.size();i++)
        {
            for(int j=i;j<tree.size();j++)
            {
                int left=i,right=j;
                long long sum=0;
                while(left<=right)
                {
                    if(left%2==1)
                    {
                        sum+=tree[left];
                        left++;
                    }
                    if(right%2==0)
                    {
                        sum+=tree[right];
                        right--;
                    }
                    left/=2;
                    right/=2;
                }
                if(sum>=lower && sum<=upper)
                    res++;
            }
        }
        return res;
    }
};
class Solution1 {
public:
    int res=0;
    vector<long> temp;  //归并排序辅助数组
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //基本思想：前缀和+归并排序，先计算得到nums的前缀和presum，presum[i+1]-presum[i]=nums[i]，再对presum进行归并排序
        //归并排序合并的两个数组时，比如nums1={2,5,8} nums2={1,7,9}
        //遍历nums2中的每个元素减去nums1中的每个元素，就得到nums中所有范围区间的元素和
        //只要nums2每个元素-nums1每个元素的值在[lower,upper]，res++
        //但是因为nums1和nums2都是有序的，所以对于当前nums1中的元素presum[i]，只要presum[l]-presum[i]<lower得到nums2满足条件的左起点
        //presum[r]-presum[i]<=upper得到nums2满足条件的右终点，最后res+=r-l，大大优化，减少了很多遍历次数
        long sum=0;
        vector<long> presum(nums.size()+1,0);
        temp.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            presum[i+1]=sum;
        }
        mergeSort(presum,0,int(presum.size())-1,lower,upper);
        return res;
    }
    void mergeSort(vector<long>& presum, int left, int right, int lower, int upper)
    {
        if(left>=right)  return;
        int mid=(left+right)/2;
        mergeSort(presum,left,mid,lower,upper);
        mergeSort(presum,mid+1,right,lower,upper);
        Merge(presum,left,mid,right,lower,upper);
    }
    void Merge(vector<long>& presum, int left, int mid, int right, int lower, int upper)
    {
        int i=left,j=mid+1,k=left;
        int l=mid+1,r=mid+1;
        while(i<=mid)
        {
            while(l<=right&&presum[l]-presum[i]<lower)
                l++;
            while(r<=right&&presum[r]-presum[i]<=upper)
                r++;
            res+=r-l;
            i++;
        }
        i=left;
        j=mid+1;
        while(i<=mid&&j<=right)
        {
            if(presum[i]<presum[j])
                temp[k++]=presum[i++];
            else
                temp[k++]=presum[j++];
        }
        while(i<=mid)
            temp[k++]=presum[i++];
        while(j<=right)
            temp[k++]=presum[j++];
        for(int t=left;t<=right;t++)
            presum[t]=temp[t];
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={-2,5,-1};
    int lower=-2,upper=2;
    cout<<solute.countRangeSum(nums,lower,upper)<<endl;
}
