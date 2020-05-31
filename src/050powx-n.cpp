#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		//基本思想：快速幂算法，将n看成二进制数，比如n为11，3^11=3^1011=3^1000*3^10*3^1，也就是从低位往高位不断循环右移一位且当前x值为x*=x，最低位遇到1也就是当前为奇数res乘当前x即res*=x
		double res = 1.0;
		if (n == 0 || x==1.0)
			return 1.0;
		long long N = n;
		//因为int范围是[-2^31,2^31-1]负数的表示范围比正数大，所以不能简单取绝对值，用long long代替
		if (n < 0)
			N = -N;
		else
			N = N;
		//将n看成二进制数，从低位往高位不断循环右移一位且当前x值为x*=x，最低位遇到1也就是当前为奇数res乘当前x即res*=x
		for (long long i = N; i != 0; i = i >> 1)
		{
			if (i % 2 == 1)
				res *= x;
			x *= x;
		}
		if (n > 0)
			return res;
		else
			return 1.0 / res;
	}
};
int main()
{
	Solution solute;
	double x = 2.00000;
	int n = 10;
	cout << solute.myPow(x, n) << endl;
	return 0;
}