#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//����˼�룺̰���㷨�����͵�����������һ������������ʼ������������ô��ǰԪ��Ϊ�������ҵ�ǰԪ�ؼ�����һ��Ԫ��ҲΪ������������Ԫ�غʹ�����һ��Ԫ��λ����Ҳ���Ǿֲ����Ž⣬��󷵻��������ֵ����ȫ�����Ž�
		//��������Ϊ1,2,3,-5,1,2,5������ֲ����Ž����1,3,6,1,2,4,9��ȫ�����Ž����9
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] > 0 && nums[i] + nums[i + 1] > 0)
				nums[i + 1] += nums[i];	
		}
		return *max_element(nums.begin(),nums.end());
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,-5,1,2,5 };
	cout << solute.maxSubArray(nums) << endl;
	return 0;
}