#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	int permuteUnique(vector<int>& nums) {
		int res=1;
		for(int i=1;i<=nums.size();i++)
			res*=i;
		sort(nums.begin(),nums.end());
		int cnt=1,sum=1;
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]==nums[i-1])
			{
				cnt++;
				sum*=cnt;
			}
			else
			{
				res/=sum;
				sum=1;
				cnt=1;
			}
		}
		res/=sum;
		return res;
	}
};
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//����˼�룺�ݹ���ݷ����ݹ������Ѱ���п��ܽ�����浽res
		//��Ϊnums�����ظ�Ԫ�أ�Ҫ�����cur�������ظ�������ͬ�ظ�Ԫ���±�˳��̶����������������Ҳ��������һ��numsԪ�أ�����ǰ���cur���Ƿ���Ԫ����ͬ�������ͬ����ǰԪ���±���������ͬԪ���±꣬������֤��res��û���ظ�
		//cur���浱ǰĳһ�ֿ��ܵ��±���������cnt����cur��Ԫ�ظ�����������nums.size()������ǰ��һ���±����cur��ӦԪ�ر��浽res
		vector<int> cur;
		Recursion(nums, cur, 0);
		return res;
	}
	void Recursion(vector<int> nums, vector<int> cur, int cnt)
	{
		//cnt����cur��Ԫ�ظ�����������nums.size()������ǰ��һ���±����cur��ӦԪ�ر��浽res
		if (cnt == nums.size())
		{
			vector<int> temp;
			for (auto& r : cur)
				temp.push_back(nums[r]);
			res.push_back(temp);
			return;
		}
		//ѭ������nums����Ԫ��
		for (int i = 0; i < nums.size(); i++)
		{
			int flag = 0;
			//����ǰnums�е��±�i�Ƿ����cur�У�������cur�л��߿���ǰ����±�cur�ж�ӦԪ����nums[i]��ͬ��ǰԪ���±�i���������ͬԪ���±�r����flag=1�������ѭ����nums��һ��Ԫ��
			for (auto& r : cur)
			{
				if (r == i || (nums[r] == nums[i] && i < r))
				{
					flag = 1;
					break;
				}
			}
			//��flag=0����ǰ�±�i�����±����cur����cnt+1���ݹ�����һ��Ԫ��
			if (flag == 0)
			{
				cur.push_back(i);
				Recursion(nums, cur, cnt + 1);
				//���ݵ����ոռ�����±�i
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
	vector<int> nums = { 1,1,0,0,1,-1,-1,1 };
	res = solute.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << res.size() << endl;
	return 0;
}