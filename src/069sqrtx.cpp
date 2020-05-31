#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		//基本思想：牛顿迭代法求平方根，迭代公式Xn+1=(Xn^2+N)/2Xn=(Xn+N/Xn)/2，初始Xn可以设置为N或者N/2
		//初始Xn设置为N/2时要考虑特殊情况1
		if (x == 1)
			return 1;
		//防止求root*root时溢出，用long long
		long long root = x / 2;
		//精度只要满足1即可
		while (root * root - x >= 1)
		{
			root = (root + x / root) / 2;
		}
		return root;
	}
};
int main()
{
	Solution solute;
	int x = 2147395599;
	cout << solute.mySqrt(x) << endl;
	return 0;
}