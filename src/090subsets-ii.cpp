#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		//����˼�룺�ֵ����򣨶����������Ӽ������ֵ����˳����ȫ����ϣ���һ����Ϊ000�����һ����Ϊ111����ӦnumsԪ�أ�vec[i]=1��nums[i]����cur
		vector<vector<int>> res;
		vector<int> cur;
		vector<int> binary(nums.size(), 0);
		sort(nums.begin(), nums.end());
		int i, j, carry, flag;
		for (i = 0; i < pow(2, nums.size()); i++)
		{
			for (j = 0; j < nums.size(); j++)
			{
				if (binary[j] == 1)
					cur.push_back(nums[j]);
			}
			//ȥ���ظ����Ӽ�
			flag = 0;
			for (auto& v : res)
			{
				if (v == cur)
					flag = 1;
			}
			if(flag==0)
			    res.push_back(cur);
			cur.clear();
			carry = 1;
			for (j = 0; j < nums.size(); j++)
			{
				if (binary[j] + carry == 2)
				{
					binary[j] = 0;
					carry = 1;
				}
				else
				{
					binary[j] = 1;
					break;
				}
			}
		}
		return res;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		//�ݹ���ݷ��������78�Ӽ���������ȥ���ظ����
		vector<int> cur;
		sort(nums.begin(), nums.end());
		Recursion(nums, 0, cur);
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		return res;
	}
	void Recursion(vector<int>& nums, int pos, vector<int> cur)
	{
		res.push_back(cur);
		for (int i = pos; i < nums.size(); i++)
		{
			cur.push_back(nums[i]);
			Recursion(nums, i + 1, cur);
			cur.pop_back();
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,4,4,1,4 };
	vector<vector<int>> res = solute.subsetsWithDup(nums);
	for (int i = 0; i < res.size(); i++)
	{
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}