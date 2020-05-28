#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct Bucket
{
	bool used = false;
	int maxVal = INT_MIN;
	int minVal = INT_MAX;
};
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		//基本思想：桶排序，时间复杂度O(n)空间复杂度O(b)
		//最大间距不会出现在桶内：如果nums是均匀分布的，那么最大间距就是桶的大小；
		//如果不是均匀分布，最大间距一定大于桶的大小，所以最大间距不会出现在桶内。
		if (nums.size() < 2)
			return 0;
		int res = 0;
		//nums里面最大最小值
		int maxNum = *max_element(nums.begin(), nums.end());
		int minNum = *min_element(nums.begin(), nums.end());
		//桶容量大小
		int bucketSize = (maxNum - minNum) / (nums.size() - 1);
		//对于bucketSize=0情况，桶大小为0，每个桶里一个元素都存不满，是因为nums中存在大量重复元素
		if (bucketSize == 0)
			bucketSize = 1;
		//桶个数
		int bucketCount = (maxNum - minNum) / bucketSize + 1;
		//每个桶里只保存桶中最大元素和最小元素
		vector<Bucket> buckets(bucketCount);
		for (auto& v : nums)
		{
			int pos = (v - minNum) / bucketSize;
			buckets[pos].used = true;
			buckets[pos].maxVal = max(buckets[pos].maxVal, v);
			buckets[pos].minVal = min(buckets[pos].minVal, v);
		}
		int pre = minNum;
		//遍历每个桶，最大间距出现在两个桶里的元素差值里
		for (int i = 0; i < buckets.size(); i++)
		{
			if (!buckets[i].used)
				continue;
			//当前桶里最小值和前一个桶里最大值的差值可能是nums的最大间距
			res = max(res, buckets[i].minVal - pre);
			//前一个桶的最大值
			pre = buckets[i].maxVal;
		}
		return res;
	}
};
class Solution1 {
public:
	int maximumGap(vector<int>& nums) {
		//基本思想：set，时间复杂度O(n)空间复杂度O(n)
		if (nums.size() < 2)
			return 0;
		set<int> dict(nums.begin(), nums.end());
		int res = 0;
		auto pre = dict.begin();
		auto i = pre;
		for (i++; i != dict.end(); i++)
		{
			res = max(res, *i - *pre);
			pre = i;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,9,2,1,6 };
	cout << solute.maximumGap(nums) << endl;
	return 0;
}