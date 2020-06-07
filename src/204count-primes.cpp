#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		//����˼�룺��ѧ��û�п��������ӵ���Ϊ��������˱���2��n֮��ÿһ�������ж��Ƿ��п���������
		//��primes���������������жϵ�ǰ��i�Ƿ�Ϊ������ֻҪ�ж�i��[2,sqrt(i)] �����Ƿ��п���������
		//Ҳ����˵����primes�е��������Ƿ��ܰ�i����
		//��������лᷢ�ֱ���2��n֮��ÿһ����i������Ҫ�ж��Ƿ��ܱ�2��3��5��7�������൱���ظ�������
		//���ǿ��Բ����ų�����Ҳ�����ҵ���һ����������ô�������Ժ�ı��������������ˣ������ظ�����
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
			//�����[2,sqrt(i)] �������û�з��ֿ��������ӣ��Ϳ��Զ϶�i������
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
		//����˼�룺������˹����ɸ����Sieve of Eratosthenes��ʱ�临�Ӷ�O(N * loglogN)
		//�����ų�����Ҳ����ÿ�ҵ���һ����������ô�������Ժ�ı������������������ˣ����Ա����ظ�����
		vector<bool> prime(n, true);
		//�����[2,sqrt(n)] �������û�з��ֿ��������ӣ��Ϳ��Զ϶�n������
		for (int i = 2; i < sqrt(n); i++)
		{
			if (prime[i])
			{
				//�Ż�����ʼj=2*i�ĳ�j=i*i�����ڼ��������2*i��i*i֮���������2��3��5��ǹ���
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