#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	double myPow(double x, int n) {
		//����˼�룺�������㷨����n���ɶ�������������nΪ11��3^11=3^1011=3^1000*3^10*3^1��Ҳ���Ǵӵ�λ����λ����ѭ������һλ�ҵ�ǰxֵΪx*=x�����λ����1Ҳ���ǵ�ǰΪ����res�˵�ǰx��res*=x
		double res = 1.0;
		if (n == 0 || x==1.0)
			return 1.0;
		long long N = n;
		//��Ϊint��Χ��[-2^31,2^31-1]�����ı�ʾ��Χ�����������Բ��ܼ�ȡ����ֵ����long long����
		if (n < 0)
			N = -N;
		else
			N = N;
		//��n���ɶ����������ӵ�λ����λ����ѭ������һλ�ҵ�ǰxֵΪx*=x�����λ����1Ҳ���ǵ�ǰΪ����res�˵�ǰx��res*=x
		for (long long i = N; i != 0; i = i >> 1)
		{
			if (i % 2 == 1)
				res *= x;
			x *= x;
		}
		if (n > 0)
			return res;
		else
			return 1.0 / res;
	}
};
int main()
{
	Solution solute;
	double x = 2.00000;
	int n = 10;
	cout << solute.myPow(x, n) << endl;
	return 0;
}