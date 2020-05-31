#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		//基本思想：数学高效计算因子，时间复杂度O(logn)
		//要想末尾产生0，该数必须有因子5，产生0的个数就是该数因子5的个数
		//从1到n这n个数里面，计算每个数存在因子5的个数
		//不断除以5, 是因为每间隔5个数有一个数可以被5整除, 然后在这些可被5整除的数中,
		//每间隔5个数又有一个可以被25整除, 故要再除一次...直到结果为0, 表示没有能继续被5整除的数了
		int count = 0;
		while (n > 0)
		{
			count += n / 5;
			n /= 5;
		}
		return count;
	}
};
class Solution1 {
public:
	int trailingZeroes(int n) {
		//基本思想：数学高效计算因子，时间复杂度O(logn)
		//要想末尾产生0，该数必须有因子5，产生0的个数就是该数因子5的个数
		//从1到n这n个数里面，计算每个数存在因子5的个数
		//每间隔5个数有一个数可以被5整除该数至少有1个5因子，每间隔25个数有一个数可以被25整除该数至少有2个5因子...
		int count = 0;
		long long i = 5;
		while (i <= n)
		{
			count += n / i;
			i *= 5;
		}
		return count;
	}
};
class Solution2 {
public:
	int trailingZeroes(int n) {
		//基本思想：数学计算因子，时间复杂度O(logn)
		//要想末尾产生0，该数必须有因子5，产生0的个数就是该数因子5的个数
		//因此计算从1到n这n个数里面，计算每个数存在因子5的个数，因为只有以5和0结尾的数才有因子5，所以每次加5
		int count = 0;
		long long i = 5;
		while (i <= n)
		{
			int q = i;
			while (q % 5 == 0)
			{
				q /= 5;
				count++;
			}
			i += 5;
		}
		return count;
	}
};
int main()
{
	Solution solute;
	int n = 456;
	cout << solute.trailingZeroes(n) << endl;
	return 0;
}