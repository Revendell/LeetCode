#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //基本思想：大小堆，将nums分成两部分大顶堆和小顶堆，小顶堆的所有元素大于大顶堆所有元素
        //然后将大顶堆和小顶堆两部分的数据穿插入nums，大顶堆中元素从0开始依次间隔一位插入nums
        //小顶堆中元素从最后一个元素开始依次间隔一位插入nums
        //时间复杂度O(nlogk) 空间复杂度O(n)
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto num:nums)
        {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
            if(min_heap.size()>max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        int left=0;
        int right=nums.size()%2==0?nums.size()-1:nums.size()-2;
        while(!min_heap.empty()||!max_heap.empty())
        {
            if(left<nums.size())
            {
                nums[left]=max_heap.top();
                max_heap.pop();
                left+=2;
            }
            if(right>=0)
            {
                nums[right]=min_heap.top();
                min_heap.pop();
                right-=2;
            }
        }
    }
};
class Solution1 {
public:
    void wiggleSort(vector<int>& nums) {
        //基本思想：快速选择算法+荷兰旗算法，时间复杂度O(n)，空间复杂度O(n)
        //第一步快速选择算法nth_element求第n/2大元素值即中位数，时间复杂度O(n)
        //第二步荷兰旗算法三指针将比中位数小的放中位数左边，比中位数大的放中位数右边，时间复杂度O(n)
        //第三步将大小部分的元素间隔插入nums中，空间复杂度O(n)

        //第一步找出中位数
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        int midnum=*(nums.begin()+nums.size()/2);
        //第二步三指针将比中位数小的放中位数左边，比中位数大的放中位数右边
        int left=0,right=nums.size()-1,cur=0;
        while(cur<=right)
        {
            if(nums[cur]==midnum)
                cur++;
            else if(nums[cur]<midnum)
            {
                swap(nums[left],nums[cur]);
                left++;
                cur++;
            }
            else
            {
                swap(nums[right],nums[cur]);
                right--;
            }
        }
        //第三步将大小部分的元素间隔插入nums，这里要注意大小部分的元素倒序间隔插入到nums
        //比如nums={4,5,5,6}，得到minnums={4,5} maxnums={5,6}
        //如果正序间隔插入到nums就成了{4,5,5,6}，这显然不准确，应该倒序依次间隔插入{5,6,4,5}
        vector<int> minnums(nums.begin(),nums.begin()+(nums.size()+1)/2);
        vector<int> maxnums(nums.begin()+(nums.size()+1)/2,nums.end());
        for(int i=0;i<nums.size();i++)
            nums[i]=i%2==0?minnums[minnums.size()-1-i/2]:maxnums[maxnums.size()-1-i/2];
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={4,5,5,6};
    solute.wiggleSort(nums);
    for_each(nums.begin(),nums.end(),[](auto v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
