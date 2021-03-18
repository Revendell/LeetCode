#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //快速排序——递归
        QuickSort(nums,0,int(nums.size())-1);
        return nums;
    }
    void QuickSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return;
        int pivot=Partition(nums,low,high);
        QuickSort(nums,low,pivot-1);
        QuickSort(nums,pivot+1,high);
    }
    int Partition(vector<int>& nums,int low,int high)
    {
        int pivot=nums[low];
        while(low<high)
        {
            while(low<high&&pivot<=nums[high])
                high--;
            swap(nums[low],nums[high]);
            while(low<high&&pivot>=nums[low])
                low++;
            swap(nums[low],nums[high]);
        }
        return low;
    }
};
class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums) {
        //快速排序——非递归
        QuickSort(nums,0,int(nums.size())-1);
        return nums;
    }
    void QuickSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return;
        stack<pair<int,int>> st;
        st.push({low,high});
        while(!st.empty())
        {
            pair<int,int> cur=st.top();
            low=cur.first;
            high=cur.second;
            st.pop();
            int pivot=Partition(nums,low,high);
            if(low<pivot-1)
                st.push({low,pivot-1});
            if(pivot+1<high)
                st.push({pivot+1,high});
        }
    }
    int Partition(vector<int>& nums,int low,int high)
    {
        int pivot=nums[low];
        while(low<high)
        {
            while(low<high&&pivot<=nums[high])
                high--;
            swap(nums[low],nums[high]);
            while(low<high&&pivot>=nums[low])
                low++;
            swap(nums[low],nums[high]);
        }
        return low;
    }
};
class Solution2 {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        //归并排序——递归
        tmp.resize(nums.size(),0);
        MergeSort(nums,0,int(nums.size())-1);
        return nums;
    }
    void MergeSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return;
        int mid=(low+high)/2;
        MergeSort(nums,low,mid);
        MergeSort(nums,mid+1,high);
        Merge(nums,low,mid,high);
    }
    void Merge(vector<int>& nums,int low,int mid,int high)
    {
        int i=low,j=mid+1,k=low;
        while(i<=mid&&j<=high)
        {
            if(nums[i]<=nums[j])
                tmp[k++]=nums[i++];
            else
                tmp[k++]=nums[j++];
        }
        while(i<=mid)
            tmp[k++]=nums[i++];
        while(j<=high)
            tmp[k++]=nums[j++];
        for(int t=low;t<=high;t++)
            nums[t]=tmp[t];
    }
};
class Solution3 {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        //归并排序——非递归
        tmp.resize(nums.size(),0);
        MergeSort(nums,0,int(nums.size())-1);
        return nums;
    }
    void MergeSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
            return;
        for(int len=1;len<=nums.size();len*=2)
        {
            low=0;
            while(low<nums.size()-len)
            {
                int mid=low+len-1;
                high=mid+len;
                if(high>=nums.size())
                    high=nums.size()-1;
                Merge(nums,low,mid,high);
                low=high+1;
            }
        }
    }
    void Merge(vector<int>& nums,int low,int mid,int high)
    {
        int i=low,j=mid+1,k=low;
        while(i<=mid&&j<=high)
        {
            if(nums[i]<=nums[j])
                tmp[k++]=nums[i++];
            else
                tmp[k++]=nums[j++];
        }
        while(i<=mid)
            tmp[k++]=nums[i++];
        while(j<=high)
            tmp[k++]=nums[j++];
        for(int t=low;t<=high;t++)
            nums[t]=tmp[t];
    }
};
int main()
{
    vector<int> nums{7,4,2,9,0,1};
    Solution3 solute;
    vector<int> res=solute.sortArray(nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}