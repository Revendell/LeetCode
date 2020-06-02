#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		//基本思想：排序，将先将nums中数字转为字符串保存到ans，然后对ans排序
		//排序算法是将两个字符串正反拼接后比较大小，这正好是题目所要求的返回最大拼接的字符串
		string res;
		vector<string> ans;
		for (auto num : nums)
			ans.push_back(to_string(num));
		sort(ans.begin(), ans.end(), [](const string& a, const string& b) {return a + b > b + a; });
		for (int i = 0; i < ans.size(); i++)
			res.append(ans[i]);
		if (res[0] == '0')
			return "0";
		return res;
	}
};
class Solution1 {
public:
	string largestNumber(vector<int>& nums) {
		//基本思想：暴力，用二维数组vec保存nums中每个数字的每一位
		//然后进行排序比如3,31,34的顺序是34,3,31，比较每一位数字如果vec[i][k]<vec[j][k]直接交换
		//如果vec[i][k]==vec[j][k]，这个时候如果vec[i]到最后一位数字了，那就比较vec[j]当前位数字和vec[i]第一位数字的大小如果小于交换
		//如果vec[i][0]==vec[j][k+1]且k+1是vec[j]最后一位数字，对于830,8308和898,89的情况如果vec[i][temp]>vec[i][temp + 1]交换
		string res;
		vector<vector<int>> vec;
		for (auto num : nums)
		{
			vector<int> cur;
			while (num / 10 != 0)
			{
				cur.push_back(num % 10);
				num = num / 10;
			}
			cur.push_back(num);
			reverse(cur.begin(), cur.end());
			vec.push_back(cur);
		}
		for (int i = 0; i < vec.size() - 1; i++)
		{
			for (int j = i + 1; j < vec.size(); j++)
			{
				int k = 0;
				while (k < vec[i].size() && k < vec[j].size())
				{
					if (vec[i][k] < vec[j][k])
					{
						swap(vec[i], vec[j]);
						break;
					}
					else if (vec[i][k] > vec[j][k])
					{
						break;
					}
					else
					{
						if (k == vec[i].size() - 1 && k < vec[j].size() - 1)
						{
							while (k < vec[j].size() - 1)
							{
								if (vec[i][0] < vec[j][k + 1])
								{
									swap(vec[i], vec[j]);
									break;
								}
								else if (vec[i][0] == vec[j][k + 1])
								{
									if (k + 1 == vec[j].size() - 1)
									{
										int temp = 0;
										while (temp < vec[i].size() - 1)
										{
											if (vec[i][temp] > vec[i][temp + 1])
											{
												swap(vec[i], vec[j]);
												break;
											}
											else if (vec[i][temp] < vec[i][temp + 1])
												break;
											else
												temp++;
										}
									}
									k++;
								}	
								else
									break;
							}
							break;
						}
						else if (k == vec[j].size() - 1 && k < vec[i].size() - 1)
						{
							while (k < vec[i].size() - 1)
							{
								if (vec[j][0] > vec[i][k + 1])
								{
									swap(vec[i], vec[j]);
									break;
								}
								else if (vec[j][0] == vec[i][k + 1])
								{
									if (k + 1 == vec[i].size()-1)
									{
										int temp = 0;
										while (temp < vec[j].size() - 1)
										{
											if (vec[j][temp] < vec[j][temp + 1])
											{
												swap(vec[i], vec[j]);
												break;
											}
											else if (vec[j][temp] > vec[j][temp + 1])
												break;
											else
												temp++;
										}
									}	
									k++;
								}	
								else
									break;
							}
							break;
						}
					}
					k++;
				}
			}
		}
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
				res.push_back('0' + vec[i][j]);
		}
		if (res[0] == '0')
			return "0";
		else
		    return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 824,8248 };
	cout << solute.largestNumber(nums) << endl;
	return 0;
}