#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//˫ָ�뷨
class Solution1 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int i=0, j=len-1;  //ָ��i��ͷ��ʼɨ�裬ָ��j��β��ʼɨ��
		int max_area=0,min_height; 
		while (i < j)
		{
			min_height = min(height[i], height[j]);
			if (min_height * (j - i) > max_area)
				max_area = min_height * (j - i);  //�������������̵��߶�*�����߶�֮��ľ���
			//��ָ��϶��߶ε�ָ�����ڲ��ƶ�������˾��ο�ȵļ�С����ȴ���ܻ����������������
			if (height[i] > height[j])
				j--;
			else
				i++;
		}
		return max_area;
	}
};
//������ٷ�
class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int i, j;
		int max_area = 0, min_height;
		//������п��ܵľ������������
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