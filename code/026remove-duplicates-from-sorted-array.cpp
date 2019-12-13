#include<iostream>
#include<vector>
using namespace std;
//˫ָ�뷨
class Solution1 {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j;  //����ָ��i��j��i����ָ�룬j�ǿ�ָ��
		int len = nums.size();
		if (len == 0)
			return 0;
		//ѭ��ɨ������nums���飬�����ظ���j++�������������ظ���nums[j]���Ƶ�nums[i+1]���������0��i���ǲ��ظ���
		for (j = 1; j < len; j++)
		{
			//nums[i]!=nums[j]ʱ�����������ظ���nums[j]���Ͱ�nums[j]���Ƶ�nums[i+1]
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
			//ֻҪnums[i]=nums[j]��������j�������ظ���
		}
		//����i+1�����ظ���ĸ���
		return i + 1;
	}
};
//ɾ��Ԫ�ط�
class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0;
		if (nums.size() == 0)
			return 0;
		while (i < nums.size() - 1)
		{
			//�����ظ�����erase����ɾ���ظ���
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
			{
				nums.erase(nums.begin() + i);
			}
			i++;
		}
		return nums.size();
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,1,2,2,3 };
	int len = solute.removeDuplicates(nums);
	for (int i = 0; i < len; i++)
		cout << nums[i] << endl;
	return 0;
}