#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		//基本思想：数学，没有可整除因子的数为素数，因此遍历2到n之间每一个数，判断是否有可整除因子
		//用primes保存所有素数，判断当前数i是否为素数，只要判断i在[2,sqrt(i)] 区间是否有可整除因子
		//也就是说遍历primes中的素数，是否能把i整除
		//这个过程中会发现遍历2到n之间每一个数i，都需要判断是否能被2、3、5、7整除，相当于重复计算了
		//我们可以采用排除法，也就是找到了一个素数，那么该素数以后的倍数都不是素数了，避免重复计算
		if (n <= 2)
			return 0;
		if (n <= 3)
			return 1;
		if (n <= 5)
			return 2;
		int i = 5, j, flag;
		vector<int> primes{ 2,3 };
		while (i < n)
		{
			flag = 0;
			//如果在[2,sqrt(i)] 这个区间没有发现可整除因子，就可以断定i是素数
			for (j = 0; j < primes.size(); j++)
			{
				if(primes[j]> sqrt(i))
					break;
				if (i % primes[j] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				primes.push_back(i);	
			i += 2;
		}
		return primes.size();
	}
};
class Solution1 {
public:
	int countPrimes(int n) {
		//基本思想：埃拉托斯特尼筛法，Sieve of Eratosthenes，时间复杂度O(N * loglogN)
		//采用排除法，也就是每找到了一个素数，那么该素数以后的倍数都不可能是素数了，可以避免重复计算
		vector<bool> prime(n, true);
		//如果在[2,sqrt(n)] 这个区间没有发现可整除因子，就可以断定n是素数
		for (int i = 2; i < sqrt(n); i++)
		{
			if (prime[i])
			{
				//优化：起始j=2*i改成j=i*i，存在计算冗余从2*i到i*i之间的数都被2、3、5标记过了
				for (int j = i * i; j < n; j += i)
					prime[i] = false;
			}
		}
		int res = 0;
		for (int i = 2; i < n; i++)
		{
			if (prime[i])
				res++;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	int n = 10;
	cout << solute.countPrimes(n) << endl;
	return 0;
}