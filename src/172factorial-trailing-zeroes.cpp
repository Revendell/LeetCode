#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		//����˼�룺��ѧ��Ч�������ӣ�ʱ�临�Ӷ�O(logn)
		//Ҫ��ĩβ����0����������������5������0�ĸ������Ǹ�������5�ĸ���
		//��1��n��n�������棬����ÿ������������5�ĸ���
		//���ϳ���5, ����Ϊÿ���5������һ�������Ա�5����, Ȼ������Щ�ɱ�5����������,
		//ÿ���5��������һ�����Ա�25����, ��Ҫ�ٳ�һ��...ֱ�����Ϊ0, ��ʾû���ܼ�����5����������
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
		//����˼�룺��ѧ��Ч�������ӣ�ʱ�临�Ӷ�O(logn)
		//Ҫ��ĩβ����0����������������5������0�ĸ������Ǹ�������5�ĸ���
		//��1��n��n�������棬����ÿ������������5�ĸ���
		//ÿ���5������һ�������Ա�5��������������1��5���ӣ�ÿ���25������һ�������Ա�25��������������2��5����...
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
		//����˼�룺��ѧ�������ӣ�ʱ�临�Ӷ�O(logn)
		//Ҫ��ĩβ����0����������������5������0�ĸ������Ǹ�������5�ĸ���
		//��˼����1��n��n�������棬����ÿ������������5�ĸ�������Ϊֻ����5��0��β������������5������ÿ�μ�5
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