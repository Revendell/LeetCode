#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//基本思想：快速选择算法，只要n-k的左边是小于nums[n-k]的值，n-k的右边是大于nums[n-k]的值
		//那么n-k就是我们要找的Top k,问题转化为如何切割左右数组，并找到 Top k 对应的 pivot
		int target=nums.size()-k;
		int left=0,right=nums.size()-1;
		while(left<right)
        {
            int mid=Partition(nums,left,right);
            if(mid==target)
                return nums[mid];
            if(mid<target)
                left=mid+1;
            else
                right=mid-1;
        }
		return nums[left];
	}
	int Partition(vector<int>& nums,int left,int right)
	{
        int pivot=nums[left];
	    while(left<right)
        {
            while(left<right&&pivot<=nums[right])
                right--;
            swap(nums[left],nums[right]);
            while(left<right&&nums[left]<=pivot)
                left++;
            swap(nums[left],nums[right]);
        }
        return left;
	}
};
class Solution1 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//基本思想：构造前k个最大元素小顶堆，取堆顶，堆顶元素最小
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto num : nums)
		{
			if(q.size() == k && num < q.top())
				continue;
			q.push(num);
			if (q.size() > k)
				q.pop();
		}
		return q.top();
	}
};
class Solution2 {
public:
	int findKthLargest(vector<int>& nums, int k) {
		//基本思想：手动实现堆排序，构造大顶堆，因为大顶堆最后得到的是从小到大的顺序
		//构造大顶堆后，从堆尾先得到最大元素依次得到第k大元素即可
		HeapSort(nums, k);
		return nums[nums.size() - k];
	}
	//调整大顶堆，保持节点nums[start]大于孩子节点，调整范围在[start+1,end]之间
	void HeapAdjust(vector<int>& nums, int start, int end)
	{
		int temp = nums[start];    //保存nums[start]值
		int i = 2 * start + 1;    //start的一个孩子节点nums[2*start+1]另一个是nums[2*start+2]
		while (i <= end)
		{
			//对于堆节点nums[start]进行调整，若小于两个孩子节点nums[i]nums[i+1]中最大的则调整，否则break
			if (i + 1 <= end && nums[i] < nums[i + 1])
				i = i + 1;
			if (temp > nums[i])
				break;
			nums[start] = nums[i];    //nums[start]大于两个孩子节点中最小的，调整
			start = i;   //看调整后start的孩子节点i是否大于i的孩子节点，因此更新start和i
			i = 2 * start + 1;
		}
		nums[start] = temp;
	}
	void HeapSort(vector<int>& nums,int k)
	{
		//堆排序第一步建立大顶堆，从下面节点往上面节点建立，就是保证当前节点i值大于两个孩子节点2*i+1和2*i+1值
		for (int i = nums.size() / 2 - 1; i >= 0; i--)
		{
			HeapAdjust(nums, i, nums.size() - 1);
		}
		//堆排序第二步依次交换堆顶和堆底， 这样堆底就是排序后的最大值，该节点也去除堆中，大顶堆被破坏重新建立堆
		int i = nums.size() - 1;
		while(k--)
		{
			swap(nums[0], nums[i]);
			HeapAdjust(nums, 0, i - 1);
			i--;
		}
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
	int k = 4;
	cout << solute.findKthLargest(nums,k) << endl;
	return 0;
}
