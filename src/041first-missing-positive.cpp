#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//�򻯰棺������Ϊ��ϣ��
		int n=nums.size();
		for(auto& num:nums)
		{
			if(num<=0)
				num=n+1;
		}
		for(auto num:nums)
		{
			int tmp=abs(num);
			if(tmp<=n)
				nums[tmp-1]=-abs(nums[tmp-1]);
		}
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]>0)
				return i+1;
		}
		return n+1;
	}
};
class Solution1 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i, flag, temp;
		flag = 0;
		//�������Ƿ���ֵ����⣬��ֱ�۵��뵽��ϣ��ʹ��һ����ǣ���¼�Ƿ���֣���ȻҲ����ֱ��ʹ�ü��ϣ����ж��Ƿ����
		//����˼�룺������Ϊ��ϣ����Ϊ��ĿҪ��ʱ�临�Ӷ�O(n)���ռ临�Ӷȳ����������ռ䣬����ֻ��ʹ���Ѹ�����nums��ΪHashMap
		//ʹ���Ѹ�����nums��ΪHashMap��ѭ��һ��ɨ��nums��ÿ��Ԫ�أ�Ȼ��Ը�Ԫ��Ϊ�±��µ�ֵȡ���ţ���˵����Ԫ�ش��ڣ������Ȳ��ı��Ԫ��Ϊ�±��µ�ֵ�������±��Ǹ�Ԫ�ش���
		
		//ѭ��һ��ɨ��nums�����Ƿ����1
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				flag = 1;
				break;
			}
		}
		//���������1��ֱ�ӷ���1��1����С������
		if (flag == 0)
			return 1;
		//ѭ��һ��ɨ��nums��������С�ڵ���0�ʹ���nums.size��Ԫ�ظ�ֵΪ1����Ϊ���Ƕ�������С����
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0 || nums[i]>nums.size())
				nums[i] = 1;
		}
		//ѭ��һ��ɨ��nums��ÿ��Ԫ�أ�Ȼ��Ը�Ԫ��Ϊ�±��µ�ֵȡ���ţ������±�˵����Ԫ�ش��ڣ������Ȳ��ı��Ԫ��Ϊ�±��µ�ֵ�������±��Ǹ�Ԫ�ش���
		for (i = 0; i < nums.size(); i++)
		{
			temp = abs(nums[i]);
			if (nums[temp - 1] > 0)
				nums[temp - 1] = -nums[temp - 1];
		}
		//ѭ��һ��ɨ��nums����һ��Ϊ������Ԫ�ص��±�+1���ǵ�һ����������Ϊ������Ӧ���±��Ǵ��ڵ�
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				return i + 1;
		}
		//����������ɨ��һ��nums��û�з���ֵ��˵��nums�Ǵ�1��nums.size()����������������nums.size()+1
		return nums.size() + 1;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,3,3 };
	cout << solute.firstMissingPositive(nums) << endl;
	return 0;
}