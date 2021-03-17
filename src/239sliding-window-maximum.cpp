#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//基本思想：单调队列，一开始的想法来自于155题最小栈使用的辅助栈思想
		//维护一个队列，队列的头为当前滑动窗口的最大值，也就是滑动窗口右边界加入一个值nums[right]
		//就将nums[right]与队列的尾所有值比较，比nums[right]小的都变为nums[right]，这样就使得队列头永远是滑动窗口的最大值
		//但这种方法不是最优，因为可能不断出现比队列的尾大的值，就需要不断修改，时间复杂度变高
		//最佳的方法是nums[right]与队列的尾所有值比较比nums[right]小的全部弹出队列
		//这样做使得队列中的值个数不确定了，不一定是k个值，所以队列保存的是nums下标，这样就能保证队列中是k个值
		vector<int> res;
		deque<int> queue;
		int right = 0;
		while (right < nums.size())
		{
			if (queue.size() == k)
				queue.pop_front();
			if (!queue.empty() && nums[right] > queue.back())
			{
				for (auto iter = queue.rbegin(); iter != queue.rend() && nums[right] > * iter; iter++)
					*iter = nums[right];
			}
			queue.push_back(nums[right]);
			if (queue.size() == k)
				res.push_back(queue.front());
			right++;
		}
		return res;
	}
};
class Solution1 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//基本思想：单调队列，一开始的想法来自于155题最小栈使用的辅助栈思想
		//维护一个队列，队列的头为当前滑动窗口的最大值，也就是滑动窗口右边界加入一个值nums[i]
		//就将nums[i]与队列的尾所有值比较，比nums[i]小的都变为nums[i]，这样就使得队列头永远是滑动窗口的最大值
		//但这种方法不是最优，因为可能不断出现比队列的尾大的值，就需要不断修改，时间复杂度变高
		//最佳的方法是nums[i]与队列的尾所有值比较比nums[i]小的全部弹出队列
		//这样做使得队列中的值个数不确定了，不一定是k个值，所以队列保存的是nums下标，这样就能保证队列中是k个值
		vector<int> res;
        deque<int> queue;
        for(int i=0;i<nums.size();i++)
        {
            if(!queue.empty()&&i-queue.front()>=k)
                queue.pop_front();
            while(!queue.empty()&&nums[i]>nums[queue.back()])
                queue.pop_back();
            queue.push_back(i);
            if(i>=k-1)
                res.push_back(nums[queue.front()]);
        }
        return res;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = solute.maxSlidingWindow(nums, k);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}