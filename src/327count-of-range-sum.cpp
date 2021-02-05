#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //����˼�룺�߶�������ʱ��ʱ�临�Ӷ�O(n^2)
        //�����߶���tree��Ȼ��˫��ѭ���ֱ�����������ʼ����ֹ
        //�����߶������[i,j]����ĺ�sum���������[lower,upper]����res++
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
    vector<long> temp;  //�鲢����������
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //����˼�룺ǰ׺��+�鲢�����ȼ���õ�nums��ǰ׺��presum��presum[i+1]-presum[i]=nums[i]���ٶ�presum���й鲢����
        //�鲢����ϲ�����������ʱ������nums1={2,5,8} nums2={1,7,9}
        //����nums2�е�ÿ��Ԫ�ؼ�ȥnums1�е�ÿ��Ԫ�أ��͵õ�nums�����з�Χ�����Ԫ�غ�
        //ֻҪnums2ÿ��Ԫ��-nums1ÿ��Ԫ�ص�ֵ��[lower,upper]��res++
        //������Ϊnums1��nums2��������ģ����Զ��ڵ�ǰnums1�е�Ԫ��presum[i]��ֻҪpresum[l]-presum[i]<lower�õ�nums2���������������
        //presum[r]-presum[i]<=upper�õ�nums2�������������յ㣬���res+=r-l������Ż��������˺ܶ��������
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
