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
		if (x == 0)  //如果x=0，直接返回0
			return x;
		//将数字x里面的每一位数字按从低位到高位依次存入数组number里面
		while (x != 0)
		{
			t = x % 10;
			number[k++] = t;
			x = x / 10;
		}
		//将数组number从高位k-1到低位0依次相加保存到ret，每降低一位多乘一个0:ret+=number[i]*pow(10,k-1-i)
		for (i = k-1; i >= 0; i--)
		{
			//int是32位的有符号整型，数值范围[-2^31,2^31-1]，防止反转后数值溢出需要判断
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