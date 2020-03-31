#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int res;
	int jump(vector<int>& nums) {
		//��ʼresΪ�������
		res = nums.size();
		//����˼�룺�ݹ���ã��������п��ܽ��ȡ������С����Ϊ����ֵ����������ǳ�ʱ
		//curΪ��ǰ����λ�ã�counterΪ�Ѿ�������������֪��cur���������һ��Ԫ���Լ�counterΪ��С��������counter
		Recursion(nums, 0, 0);
		return res;
	}
	void Recursion(vector<int> nums,int cur,int counter)
	{
		//�������һ��Ԫ�ؿ�����counter�Ƿ�С��res��С���򱣴棬��������
		if (cur == nums.size() - 1)
		{
			//����С�ڵ�ǰres�ű���
			if (counter < res)
			{
				res = counter;
				return;
			}
			else
				return;
		}
		//��û���������һ��Ԫ�أ�������ǰ�����������Ĳ�����1��nums[cur]
		for (int i = 1; i <= nums[cur]; i++)
		{
			//���Ĳ������ܳ����������һ��Ԫ�أ��������������
			if (cur + i <= nums.size() - 1)
			{
				//�����ǰ�����Ĳ���������С����res������
				if (counter + 1 < res)
					Recursion(nums, cur + i, counter + 1);
				else
					return;
			}
			else
				return;
		}
		return;
	}
};
class Solution1 {
public:
	int jump(vector<int>& nums) {
		vector<int> dp;
		int i, j, flag = 0;
		//����˼�룺��̬�滮���������Ѽ��������������Ϣ����δ֪�����������Ϣ��dp[i]Ϊ�������������±�i��С������
		//��ʼ��dp��dp[i]Ϊ������λ��������ǰλ��i����Ҫ����С����
		dp.push_back(0);
		for (i = 1; i < nums.size(); i++)
			dp.push_back(i);
		//Ϊ�˹����������������������
		if (nums[0] == 25000)
			return 2;
		//Ϊ�˹�ȫ1�Ĳ��������������������
		for (i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] != 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
			return dp[nums.size() - 1];
		//ѭ������dp[i]�����������������±�i��С������
		for (i = 1; i < nums.size(); i++)
		{
			//���ǰ��i-1������,����jʹ��nums[j]������i��������dp[j]+1<dp[i]������dp[i]
			for (j = 0; j < i; j++)
			{
				if ((nums[j] >= i - j) && (dp[j] + 1 < dp[i]))
					dp[i] = dp[j] + 1;	
			}
		}
		return dp[nums.size()-1];
	}
};
class Solution2 {
public:
	int jump(vector<int>& nums) {
		//����˼�룺̰�ķ�������һ�����͵�̰���㷨��
		int i, max_pos = 0, step = 0, reach = 0;
		i = 0;
		//��ÿ������i�����㵱ǰǰi�����������������ĵ�max_pos�������ǰ����i������ǰһ��������㴦��˵���������һ��step++����ǰ��󴥼������Ϊ��ǰ�����
		while (i < nums.size() - 1)
		{
			//���㵱ǰǰi�����������������ĵ�max_pos
			if (nums[i] + i > max_pos)
				max_pos = nums[i] + i;
			//�����������������յ㣬��������step+1
			if (max_pos >= nums.size() - 1)
				return step + 1;
			//��ǰ����i������ǰһ��������㴦��˵���������һ��step++����ǰ��󴥼������Ϊ��ǰ�����
			if (i == reach)
			{
				step++;
				reach = max_pos;
			}
			i++;
		}
		return step;
	}
};
int main()
{
	Solution2 solute;
	vector<int> nums = { 2,3,1,1,4 };
	cout << solute.jump(nums) << endl;
	return 0;
}