#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		//ʱ�临�Ӷ�O(logn)
		if (n <= 0)
			return false;
		while (n != 1)
		{
			if (n % 2 == 1)
				return false;
			n = n >> 1;
		}
		return true;
	}
};
class Solution1 {
public:
	bool isPowerOfTwo(int n) {
		//����˼�룺λ���㣬ʱ�临�Ӷ�O(1)�������⣬û�����Ͳ��ᣬ�����ͻ���
		//���n��2���ݴΣ���ôn�����λ��1����λΪ0����n-1�����λλ0����λΪ1������n&(n-1)==0
		if (n <= 0)
			return false;
		return (n & (n - 1)) == 0;
	}
};
int main()
{
	Solution1 solute;
	int n = 128;
	cout << solute.isPowerOfTwo(n) << endl;
	return 0;
}