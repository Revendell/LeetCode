#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		//����˼�룺��ѧ+λ���㣬��������0��0������ֻ��Ҫ������mΪ1��λ
		//��Ϊ32λ��ÿһλ01�����pow(2,i)���������m�ĵ�iλ��1����ô����m��n�ľ������������pow(2,i)
		//˵��m��n֮��϶�������0�������õ�iλλ0�����m�ĵ�iλ��0���Ͳ��ñ����Բ���Ҫ����
		bitset<32> res(m);
		int interval = n - m;
		for (int i = 0; i < 32; i++)
		{
			if (res[i])
			{
				int power = static_cast<int>(pow(2.0, i));
				int r = m % power;
				if (r + interval >= power)
					res.reset(i);
			}
		}
		return static_cast<int>(res.to_ulong());
	}
};
class Solution1 {
public:
	int rangeBitwiseAnd(int m, int n) {
		//����˼�룺λ�ƣ��������Ʋ��ҹ���ǰ׺
		//���������������ƶ���ֱ��������ȣ������ֱ�����Ϊ���ǵĹ���ǰ׺��
		//Ȼ��ͨ��������ǰ׺�����ƶ������㸽�ӵ�����ǰ׺�Ի�����ս����
		int shift = 0;
		while (m < n) {
			m >>= 1;
			n >>= 1;
			++shift;
		}
		return m << shift;
	}
};
int main()
{
	Solution solute;
	int m = 5, n = 7;
	cout << solute.rangeBitwiseAnd(m, n) << endl;
	return 0;
}