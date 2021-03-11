#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution{
public:
	void nextPermutation(vector<int>& nums) {
		//�򻯰棺STL�е�next_permutation�㷨
		//����β�˿�ʼ��ǰѰ�����ڵ�����Ԫ��*i��*ii����*i<*ii���ҵ�����һ������Ԫ�غ�
		//�ٴ�β�˿�ʼ��ǰ���飬�ҳ���һ������*i��Ԫ��*j������i��j��ֵ���ٽ�ii֮�������Ԫ�صߵ����򣬼���
		int n=nums.size();
		int i,ii,j;
		for(int k=n-1;k>0;k--)
		{
			if(nums[k-1]<nums[k])
			{
				i=k-1,ii=k;
                break;
			}
		}
		for(int k=n-1;k>i;k--)
		{
			if(nums[k]>nums[i])
			{
				swap(nums[k],nums[i]);
				break;
			}
		}
		reverse(nums.begin()+ii,nums.end());
		return;
	}
};
class Solution1{
public:
	//����������һ�������õ��Ľ��Ӧ���Ǹ����������ұ�������������������Ѿ���󣬾ͷ�����ϵ���С��
	void nextPermutation(vector<int>& nums) {
		//flag���ڱ���Ƿ񽻻����֣�pos1����ұ�i���±꣬pos2������j���±�
		int nums_len, i, flag, j, pos1, pos2;
		nums_len = nums.size();
		flag = 0;
		//��ʼ��pos1��pos2
		pos1 = nums_len - 1;
		pos2 = 0;
		//����˼�룺��������ѭ���Ƿ�������ڽ����ұ��±�Ϊpos1������±�Ϊpos2������֣���������򽻻�������֮�����pos2֮��������ǴӴ�С���У�Ҫ�����������������ָ�ԭ������ұ�����������ͱ����pos2֮��������Ǵ�С��������
		for (i = nums_len - 1; i > 0; i--)
		{
			//����ѭ���ҵ����ڽ����ұ߱���ߴ�����֣������ߺ��ұߵ��±�pos2��pos1
			for (j = i - 1; j >= 0; j--)
			{
				//Ҫ���ҵ����ڽ����ұ߱���ߴ�����֣��͵ò�����pos2��pos1���м俿�����������������һ�ν�������flag=0��ʱ���Ѿ����������ֵ���θ��ӽ�i<=pos1&&j>pos2
				if (nums[i] > nums[j] && ((i <= pos1 && j > pos2)||flag==0))
				{
					pos1 = i;
					pos2 = j;
					flag = 1;
				}
			}
		}
		//�����ͷ��βû�����ֽ����Ĺ��̣���˵���������ɵ��������������ô���������ǴӴ�С���еģ����Է�����С�����������е�����С��������
		if (flag == 0)
		{
			for (i = 0; i < nums_len / 2; i++)
			{
				swap(nums[i], nums[nums_len - 1 - i]);
			}
		}
		//�����ͷ��β�����ֽ����Ĺ��̣���ô����֮�����pos2֮������������ǴӴ�С���У�Ҫ�����������������ָ�ԭ������ұ����󣬾ͱ����pos2֮��������Ǵ�С��������
		else
		{
			//������ǵ���������
			swap(nums[pos1], nums[pos2]);
			//����֮�����pos2֮������������ǴӴ�С���У�Ҫ�����������������ָ�ԭ������ұ����󣬾ͱ����pos2֮��������Ǵ�С��������
			if (pos2 + 1 != nums_len - 1)
			{
				for (i = pos2 + 1, j = 0; i <= (nums_len + pos2) / 2; i++, j++)
				{
					swap(nums[i], nums[nums_len -1 - j]);
				}
			}		
		}
	}
	//swap�������ڽ���nums���������Ԫ��
	void swap(int& i, int& j)
	{
		int temp;
		temp = i;
		i = j;
		j = temp;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,3,2 };
	solute.nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << endl;
	return 0;
}