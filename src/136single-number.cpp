#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//����˼�룺λ���㣬��Ϊ����Ҫ���ص�Ԫ�أ�����ÿ��Ԫ�ض��������Σ���ͬԪ��������0
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
			res = res ^ nums[i];
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,1,2,1,2 };
	cout << solute.singleNumber(nums) << endl;
	return 0;
}