#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//����˼�룺˫ָ�룬һ����ָ��leftһ����ָ��right����ָ��right���Ҳ�������������Ԫ��������ָ��left��
		int left, right, prenum;
		if (nums.size() <= 2)
			return nums.size();
		left = right = 2;
		while(right < nums.size())
		{
			//���right��������ͬ���������֣����뵽��ָ��left�У�����rightһֱ������
			if (nums[right]!=nums[left-2])
			{
				nums[left++] = nums[right];
			}
			right++;
		}
		return left;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 0,0,1,1,1,1,2,3,3,3,4,5,6 };
	int res = solute.removeDuplicates(nums);
	for (int i = 0; i < res; i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}