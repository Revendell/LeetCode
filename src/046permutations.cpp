#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> permute(vector<int>& nums) {
		//����˼�룺���͵ĵݹ���ݷ����ݹ������Ѱ���п��ܽ�����浽res
		//����ÿһ����ǰλ��i�����ǿ��Խ�����֮�������λ�ý�����Ȼ���������λ��i+1��ֱ���������һλ��
		Recursion(nums, 0);
		return res;
	}
	void Recursion(vector<int> nums, int cnt)
	{
		//cnt����cur��Ԫ�ظ�����������nums.size()������ǰ��һ�����cur���浽res
		if (cnt == nums.size())
		{
			res.push_back(nums);
			return;
		}
		//ѭ��nums����Ԫ��
		for (int i = cnt; i < nums.size(); i++)
		{
			swap(nums[i],nums[cnt]);
			Recursion(nums, cnt + 1);
			swap(nums[i],nums[cnt]);	
		}
		return;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> permute(vector<int>& nums) {
		//����˼�룺���͵ĵݹ���ݷ����ݹ������Ѱ���п��ܽ�����浽res
		//cur���浱ǰĳһ�ֿ��ܵ���������cnt����cur��Ԫ�ظ�����������nums.size()������ǰ��һ�����cur���浽res
		vector<int> cur;
		Recursion(nums, cur, 0);
		return res;
	}
	void Recursion(vector<int> nums, vector<int> cur,int cnt)
	{
		//cnt����cur��Ԫ�ظ�����������nums.size()������ǰ��һ�����cur���浽res
		if (cnt == nums.size())
		{
			res.push_back(cur);
			return;
		}
		//ѭ��nums����Ԫ��
		for (int i = 0; i < nums.size(); i++)
		{
			int flag = 0;
			//����ǰnums�е�Ԫ��nums[i]�Ƿ����cur�У�������cur��flag=1����ѭ����nums��һ��Ԫ�أ��������ڼ���cur��cnt+1���ݹ�����һ��Ԫ��
			for (auto& r : cur)
			{
				if (r == nums[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cur.push_back(nums[i]);
				Recursion(nums, cur, cnt + 1);
				//���ݵ����ոռ����Ԫ��nums[i]
				cur.pop_back();
			}	
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> res;
	vector<int> nums = { 1,2,3 };
	res = solute.permute(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}