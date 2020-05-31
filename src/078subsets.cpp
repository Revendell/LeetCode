#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		//����˼�룺�ֵ����򣨶����������Ӽ������ֵ����˳����ȫ����ϣ���һ����Ϊ000�����һ����Ϊ111����ӦnumsԪ�أ�vec[i]=1��nums[i]����cur
		vector<vector<int>> res;
		vector<int> cur;
		vector<int> vec(nums.size(), 0);
		int i, carry = 1;
		do
		{
			for (i = 0; i < nums.size(); i++)
			{
				if (vec[i] == 1)
					cur.push_back(nums[i]);
			}
			res.push_back(cur);
			cur.clear();
			for (i = 0; i < nums.size(); i++)
			{
				if (vec[i] + carry == 2)
				{
					vec[i] = 0;
					carry = 1;
				}
				else
				{
					vec[i] = 1;
					break;
				}
			}
		} while (vec != vector<int>(nums.size(), 0));
		return res;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsets(vector<int>& nums) {
		//����˼�룺�ݹ���ݷ����Ӽ���Ԫ�ظ���subset_len��0��nums.size��ѭ�������ݹ����
		vector<int> cur;
		int cnt = 0, subset_len, pos = 0;
		for (subset_len = 0; subset_len <= nums.size(); subset_len++)
		{
			Recursion(nums, pos, cnt, subset_len, cur);
		}
		return res;
	}
	void Recursion(vector<int>& nums, int pos, int cnt, int subset_len, vector<int> cur)
	{
		if (cnt == subset_len)
		{
			res.push_back(cur);
			return;
		}
		for (int i = pos; i < nums.size(); i++)
		{
			cur.push_back(nums[i]);
			Recursion(nums, i + 1, cnt + 1, subset_len, cur);
			cur.pop_back();
		}
		return;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> res = solute.subsets(nums);
	for (int i = 0; i < res.size(); i++)
	{
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}
	