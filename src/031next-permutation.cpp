#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution{
public:
	void nextPermutation(vector<int>& nums) {
		//简化版：STL中的next_permutation算法
		//从最尾端开始往前寻找相邻的两个元素*i和*ii满足*i<*ii，找到这样一组相邻元素后，
		//再从尾端开始往前检验，找出第一个大于*i的元素*j，交换i和j的值，再将ii之后的所有元素颠倒排序，即可
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
	//把数组连成一个数，得到的结果应该是跟这个数最近且比他大的数，如果这个数已经最大，就返回组合的最小数
	void nextPermutation(vector<int>& nums) {
		//flag用于标记是否交换数字，pos1标记右边i的下标，pos2标记左边j的下标
		int nums_len, i, flag, j, pos1, pos2;
		nums_len = nums.size();
		flag = 0;
		//初始化pos1和pos2
		pos1 = nums_len - 1;
		pos2 = 0;
		//基本思想：从右往左循环是否存在最邻近的右边下标为pos1比左边下标为pos2大的数字，如果存在则交换，交换之后对于pos2之后的数字是从大到小排列，要想数组连起来的数字跟原数最近且比他大的数，就必须对pos2之后的数字是从小到大排列
		for (i = nums_len - 1; i > 0; i--)
		{
			//两次循环找到最邻近的右边比左边大的数字，标记左边和右边的下标pos2和pos1
			for (j = i - 1; j >= 0; j--)
			{
				//要想找到最邻近的右边比左边大的数字，就得不断往pos2和pos1的中间靠，所以两种情况，第一次交换数字flag=0的时候，已经交换过数字但这次更接近i<=pos1&&j>pos2
				if (nums[i] > nums[j] && ((i <= pos1 && j > pos2)||flag==0))
				{
					pos1 = i;
					pos2 = j;
					flag = 1;
				}
			}
		}
		//如果从头到尾没有数字交换的过程，则说明数组连成的数是最大数，那么这个数组就是从大到小排列的，所以返回最小数就是数组中的数从小到大排列
		if (flag == 0)
		{
			for (i = 0; i < nums_len / 2; i++)
			{
				swap(nums[i], nums[nums_len - 1 - i]);
			}
		}
		//如果从头到尾有数字交换的过程，那么交换之后对于pos2之后的数字现在是从大到小排列，要想数组连起来的数字跟原数最近且比他大，就必须对pos2之后的数字是从小到大排列
		else
		{
			//交换标记的两个数字
			swap(nums[pos1], nums[pos2]);
			//交换之后对于pos2之后的数字现在是从大到小排列，要想数组连起来的数字跟原数最近且比他大，就必须对pos2之后的数字是从小到大排列
			if (pos2 + 1 != nums_len - 1)
			{
				for (i = pos2 + 1, j = 0; i <= (nums_len + pos2) / 2; i++, j++)
				{
					swap(nums[i], nums[nums_len -1 - j]);
				}
			}		
		}
	}
	//swap函数用于交换nums里面的两个元素
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