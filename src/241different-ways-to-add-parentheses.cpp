#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		//����˼�룺�ݹ���η���������ǣ�浽���ŵ�������⣬һ��ʹ�õݹ���η���
		//�ⷨ������������ţ��ݹ����ǰһ���ֵ�ͺ�һ���ֵ��Ȼ�����������ţ��������߹��ɵ�ֵ��
		//���ɣ�ʹ��istringstream��ȡ�����ֺ������������num��flag
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
		//�������flag[i]Ϊ�ָ�㣬�ָ��ǰ�벿������nums1�����flag1�ͺ�벿������nums2�����flag2
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
			//�ݹ����ǰһ���ֵ�ͺ�һ���ֵ��Ȼ�����������ţ��������߹��ɵ�ֵ
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