#include<iostream>
#include<vector>
using namespace std;
//ɾ��Ԫ�ط�
class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		//ѭ��ɨ��nums���飬����val��ȵ�ֵ��erase����ɾ��
		while (i < nums.size())
		{
			if (nums[i] == val)
				nums.erase(nums.begin() + i);
			else
				i++;
		}
		return nums.size();
	}
};
//˫ָ�뷨
class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0, j;  // i����ָ�룬j�ǿ�ָ��
		//ɨ������������Ԫ�أ����nums[j]!=val(����Ҫ�����ֵ)�Ͱ����Ԫ�ط���nums[i]�У�Ȼ��i++
		for (j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int val = 2, len;
	len = solute.removeElement(nums, val);
	for (int i = 0; i < len; i++)
		cout << nums[i] << endl;
	return 0;
}