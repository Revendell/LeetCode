#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		//基本思想：递归分治法，该问题牵涉到括号的组合问题，一般使用递归分治法。
		//解法：碰到运算符号，递归求解前一半的值和后一半的值，然后根据运算符号，计算两者构成的值。
		//技巧：使用istringstream提取出数字和运算符保存至num和flag
		vector<int> nums;
		vector<char> flag;
		vector<int> res;
		istringstream s(input);
		int num;
		char sign;
		s >> num;
		nums.push_back(num);
		while (s >> sign)
		{
			flag.push_back(sign);
			s >> num;
			nums.push_back(num);
		}
		res = Recursion(nums,flag);
		return res;
	}
	vector<int> Recursion(vector<int> nums, vector<char> flag)
	{
		vector<int> res;
		//以运算符flag[i]为分割点，分割成前半部分数字nums1运算符flag1和后半部分数字nums2运算符flag2
		for (int i = 0; i < flag.size(); i++)
		{
			vector<int> nums1;
			vector<char> flag1;
			vector<int> nums2;
			vector<char> flag2;
			for (int j = 0; j <= i; j++)
				nums1.push_back(nums[j]);
			for (int j = 0; j < i; j++)
				flag1.push_back(flag[j]);
			for (int j = i + 1; j < nums.size(); j++)
				nums2.push_back(nums[j]);
			for (int j = i + 1; j < flag.size(); j++)
				flag2.push_back(flag[j]);
			//递归求解前一半的值和后一半的值，然后根据运算符号，计算两者构成的值
			vector<int> res1 = Recursion(nums1, flag1);
			vector<int> res2 = Recursion(nums2, flag2);
			for (auto r1 : res1)
			{
				for (auto r2 : res2)
				{
					if (flag[i] == '+')
						res.push_back(r1 + r2);
					else if (flag[i] == '-')
						res.push_back(r1 - r2);
					else
						res.push_back(r1 * r2);
				}
			}
		}
		if (flag.empty())
			res.push_back(nums[0]);
		return res;
	}
};
int main()
{
	Solution solute;
	string input = "2*3-4*5";
	vector<int> res = solute.diffWaysToCompute(input);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}