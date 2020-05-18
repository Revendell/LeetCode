#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//����˼�룺ͳ��nums����intԪ����int32λ��ÿһλ��1�ĸ���sumȻ��%3�͵õ�ֻ������һ�ε�Ԫ�ظ�λ�ϵ�ֵ
		//���32λintƴ�ӳ�һ������͵õ�ֻ������һ�ε�Ԫ��
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			int sum = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				sum += (nums[j] >> i) & 1;
			}
			res = res ^ (sum % 3) << i;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 0,1,0,1,0,1,99 };
	cout << solute.singleNumber(nums) << endl;
	return 0;
}