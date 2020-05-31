#include<iostream>
#include<vector>
using namespace std;
//删除元素法
class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		//循环扫描nums数组，遇到val相等的值用erase函数删除
		while (i < nums.size())
		{
			if (nums[i] == val)
				nums.erase(nums.begin() + i);
			else
				i++;
		}
		return nums.size();
	}
};
//双指针法
class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0, j;  // i是慢指针，j是快指针
		//扫描数组中所有元素，如果nums[j]!=val(就是要保存的值)就把这个元素放入nums[i]中，然后i++
		for (j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int val = 2, len;
	len = solute.removeElement(nums, val);
	for (int i = 0; i < len; i++)
		cout << nums[i] << endl;
	return 0;
}