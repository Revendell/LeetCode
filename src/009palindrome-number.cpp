#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		unsigned int reverse = 0, origin = x;  //reverse是x反转后的值，如果反转后reverse仍然等于x，则说明x是回文数，reverse用无符号整型是为了防止反转后大于int有符号整型范围
		int t, i = 0, j = 0;
		//如果x是负数，一定不是回文数
		if (x < 0)
			return false;
		//如果x为个位数，一定是回文数
		if (x / 10 == 0)
			return true;
		while (x != 0)
		{
			t = x % 10;
			reverse = reverse * 10 + t;
			x = x / 10;
		}
		//x反转后的数值reverse仍然等于x，则说明x是回文数
		return reverse == origin;
	}
};
int main()
{
	Solution solute;
	int x =1221;
	cout << solute.isPalindrome(x) << endl;
	return 0;
}