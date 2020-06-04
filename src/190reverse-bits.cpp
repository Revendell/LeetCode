#include<iostream>
#include<vector>
#include<deque>
#include<bitset>
#include<algorithm>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		//����˼�룺λ����+����˼�룬��32λ��Ϊ�ߵͽ������԰��ظ������������ظ���ֱ������ÿһλ����
		//���Կ����ʵ���Ҫ��ʹ��ѭ��ʵ��
		n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};
class Solution1 {
public:
	uint32_t reverseBits(uint32_t n) {
		//����˼�룺λ���㣬ʱ�临�Ӷ�O(32)�ռ临�Ӷ�O(1)
		uint32_t res = 0;
		int power = 31;
		while (n != 0)
		{
			//����n���λ��0����1��Ȼ�����ƶԳƵ�λ�����Ƿ�ת���Ӧ��ֵ��Ҳ����n%2
			res += (n & 1) << power;
			n >>= 1;
			power--;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	uint32_t n = 4294967293;
	cout << solute.reverseBits(n) << endl;
	return 0;
}