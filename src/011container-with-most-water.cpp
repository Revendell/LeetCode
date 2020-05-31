#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//双指针法
class Solution1 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int i=0, j=len-1;  //指针i从头开始扫描，指针j从尾开始扫描
		int max_area=0,min_height; 
		while (i < j)
		{
			min_height = min(height[i], height[j]);
			if (min_height * (j - i) > max_area)
				max_area = min_height * (j - i);  //矩形面积等于最短的线段*两个线段之间的距离
			//将指向较短线段的指针向内侧移动，造成了矩形宽度的减小，但却可能会有助于面积的增大
			if (height[i] > height[j])
				j--;
			else
				i++;
		}
		return max_area;
	}
};
//暴力穷举法
class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int i, j;
		int max_area = 0, min_height;
		//穷举所有可能的矩形求出最大面积
		for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				min_height = min(height[i], height[j]);
				if (min_height * (j - i) > max_area)
					max_area = min_height * (j - i);
			}
		}
		return max_area;
	}
};
int main()
{
	Solution1 solute1;
	Solution2 solute2;
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	cout << solute1.maxArea(height) << endl;
	cout << solute2.maxArea(height) << endl;
	return 0;
}