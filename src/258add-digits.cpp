#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int addDigits(int num) {
		//基本思想：迭代
		int res;
		while (num / 10 != 0)
		{
			res = 0;
			while (num / 10 != 0)
			{
				res += num % 10;
				num = num / 10;
			}
			res += num % 10;
			num = res;
		}
		return num;
	}
};
class Solution1 {
public:
	int addDigits(int num) {
		//基本思想：数学，num=x*100+y*10+z=x*99+y*9+x+y+z，所以x*99+y*9=num-x+y+z差值被9整除，取余9
		return (num - 1) % 9 + 1;
	}
};
int main()
{
	Solution solute;
	int num = 38195;
	cout << solute.addDigits(num) << endl;
	return 0;
}