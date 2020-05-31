#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		//����˼�룺̰�ķ���ѭ������nums��Ԫ�أ�ÿ�μ�������ܵ�����±�λ��
		//���max_pos���ڵ�������±꣬����true�������ǰ�±����max_pos��˵������ǰ����ͣ�Ͳ�ǰ������false
		int max_pos = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			max_pos = max(max_pos, i + nums[i]);
			if (max_pos >= nums.size() - 1)
				return true;
			if (i==max_pos)
				return false;
		}
		//Ϊ�˱���ͨ��
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,2,1,0,4 };
	cout << solute.canJump(nums) << endl;
	return 0;
}