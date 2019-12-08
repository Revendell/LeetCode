#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		int i, j, k;
		int res, closest;  //res���صĽ����closest��res��target�����ֵ����Сֵ
		sort(nums.begin(), nums.end());  //��nums����Ԫ������
		//��ʼһ����ʼֵ
		closest = abs(nums[0] + nums[1] + nums[2] - target);
		res = nums[0] + nums[1] + nums[2];
		//����˫ָ�뷨�������������֮�ͣ��ȶ�nums��������Ȼ���nums��ÿ��Ԫ����������֮��ԭ��
		//��nums��ÿ��Ԫ��nums[k]���������������֮����target��ֵ�Ƚϣ�������ָ��i��j��iָ��k���һ��Ԫ�أ�jָ��k�����һ��Ԫ�أ�Ȼ��ͨ��i++��j--ʹ������֮�Ͳ��ϱƽ�target
		for (k = 0; k < len - 2; k++)
		{
			i = k + 1;  //i=k+1ָ��k���һ��Ԫ��
			j = len - 1;  //j=len-1ָ��k�����һ��Ԫ��
			while (i < j)
			{
				//�������֮����target��ֵС��closest������closest��res
				if (abs(nums[i] + nums[j] + nums[k] - target) < closest)
				{
					closest = abs(nums[i] + nums[j] + nums[k] - target);
					res = nums[i] + nums[j] + nums[k];
				}
				if (nums[i] + nums[j] + nums[k] > target)
					j--;
				else if (nums[i] + nums[j] + nums[k] < target)
					i++;
				else
					return target;
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { -3,-2,-5,3,-4 };
	int target = -1;
	cout << solute.threeSumClosest(nums, target) << endl;
	return 0;
}