#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		int number[100];
		int ret = 0;
		int i, j, t, k = 0;
		if (x == 0)  //���x=0��ֱ�ӷ���0
			return x;
		//������x�����ÿһλ���ְ��ӵ�λ����λ���δ�������number����
		while (x != 0)
		{
			t = x % 10;
			number[k++] = t;
			x = x / 10;
		}
		//������number�Ӹ�λk-1����λ0������ӱ��浽ret��ÿ����һλ���һ��0:ret+=number[i]*pow(10,k-1-i)
		for (i = k-1; i >= 0; i--)
		{
			//int��32λ���з������ͣ���ֵ��Χ[-2^31,2^31-1]����ֹ��ת����ֵ�����Ҫ�ж�
			if ((ret+ number[i] * pow(10, k - 1 - i)) > pow(2, 31) - 1 || (ret+ number[i] * pow(10, k - 1 - i)) < pow(-2, 31))
				return 0;
			ret += number[i] * pow(10, k-1-i);
		}
		return ret;
	}
};
int main()
{
	Solution solute;
	int x = -4321;
	cout << solute.reverse(x) << endl;
	return 0;
}