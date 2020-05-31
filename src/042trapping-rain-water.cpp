#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		//基本思想：暴力法，直观想法，找到所有储存水的凹槽，记录下两边的墙left和right，凹槽储水量为min(height[left],height[right])*(right-left-1)减去left与right之间的所有墙占空间
		int left, right, i, j, k, res = 0, cur;
		//元素少于三个接不到雨水，返回0
		if (height.size() < 3)
			return 0;
		i = 0;
		//第一层循环i确定left位置凹槽的左边
		while (i < height.size() - 2)
		{
			//找到凹槽的左边，满足的条件是不为0且凹槽的左边界大于它的左边否则存不了水
			if (height[i] == 0 || height[i + 1] >= height[i])
			{
				i++;
				continue;
			}
			left = i;
			right = i + 2;
			//第二层循环j确定right位置凹槽的右边
			for (j = i + 2; j < height.size(); j++)
			{
				//如果此时j高度大于凹槽左边left的高度，直接确定j为右边界，就可以存水，不用再找更高的高度了
				if (height[j] >= height[left])
				{
					right = j;
					break;
				}
				//如果此时j高度小于凹槽左边left的高度，那就要继续找到右边最高的高度存水
				else
				{
					if (height[j] >= height[right])
					{
						right = j;
					}
				}
			}
			//上面确定的凹槽左边left和右边right还需要确定真实的left，因为对于3,2,0,1，这种情况真实的左边界应该是left
			k = left + 1;
			while (k < right)
			{
				//如果左边left比右边right高，一直找到最接近右边right高度的左边left才是真实的left，上述例子就是2
				if (height[k] > height[right])
				{
					left = k;
					k++;
				}
				//如果左边left比右边right低不用担心上述问题，left就是真实的left
				else
					break;
			}
			//最后终于确定了凹槽的left和right，所以凹槽储水面积为min(height[left],height[right])*(right-left-1)减去left和right之间的墙占面积
			cur = min(height[left], height[right]) * (right - left - 1);
			for (k = left + 1; k < right; k++)
				cur -= height[k];
			//将该凹槽面积加入最后的总面积res
			res += cur;
			//下一个凹槽的左边从上一个凹槽的右边开始
			i = right;;
		}
		return res;
	}
};
class Solution1 {
public:
	int trap(vector<int>& height) {
		//基本思想：暴力法，按列求求每一列的水会含多少水，只需要关注当前列，以及左边最高的墙，右边最高的墙就够了
		//如果较矮的墙的高度大于当前列的墙的高度，当前列含水量等于较矮的墙的高度减去当前列的高度
		//如果较矮的墙的高度小于当前列的墙的高度，当前列不会储水
		//如果较矮的墙的高度等于当前列的墙的高度，当前列也不会储水
		int max_left, max_right, i, j, k, res = 0, cur;
		//元素少于三个接不到雨水，返回0
		if (height.size() < 3)
			return 0;
		//最外的两列不可能储水，所以不考虑，i从1到height.size()-2
		for (i = 1; i < height.size() - 1; i++)
		{
			max_left = 0;
			max_right = height.size() - 1;
			//从当前列向左边出发，找到左边最高的墙
			for (j = i - 1; j >= 0; j--)
			{
				if (height[j] > height[max_left])
					max_left = j;
			}
			//从当前列出发，找到右边最高墙
			for (j = i + 1; j < height.size() - 1; j++)
			{
				if (height[j] > height[max_right])
					max_right = j;
			}
			cur = min(height[max_left], height[max_right]);
			//只有较矮的墙的高度大于当前列的墙的高度才能储水，含水量等于较矮的墙的高度减去当前列的高度
			if (height[i] < cur)
				res += cur - height[i];
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> height = { 9,6,8,8,5,6,3 };
	cout << solute.trap(height) << endl;
	return 0;
}