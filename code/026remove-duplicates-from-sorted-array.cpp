#include<iostream>
#include<vector>
using namespace std;
//双指针法
class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j;  //两个指针i和j，i是慢指针，j是快指针
		int len = nums.size();
		if (len == 0)
			return 0;
		//循环扫描整个nums数组，遇到重复项j++跳过，遇到不重复项nums[j]复制到nums[i+1]，所以最后0到i都是不重复项
		for (j = 1; j < len; j++)
		{
			//nums[i]!=nums[j]时，就遇到不重复项nums[j]，就把nums[j]复制到nums[i+1]
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
			//只要nums[i]=nums[j]，就增加j以跳过重复项
		}
		//返回i+1个不重复项的个数
		return i + 1;
	}
};
//删除元素法
class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		if (nums.size() == 0)
			return 0;
		while (i < nums.size() - 1)
		{
			//遇到重复项用erase函数删除重复项
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
			{
				nums.erase(nums.begin() + i);
			}
			i++;
		}
		return nums.size();
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,1,2,2,3 };
	int len = solute.removeDuplicates(nums);
	for (int i = 0; i < len; i++)
		cout << nums[i] << endl;
	return 0;
}