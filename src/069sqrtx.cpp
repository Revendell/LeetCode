#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		//����˼�룺ţ�ٵ�������ƽ������������ʽXn+1=(Xn^2+N)/2Xn=(Xn+N/Xn)/2����ʼXn��������ΪN����N/2
		//��ʼXn����ΪN/2ʱҪ�����������1
		if (x == 1)
			return 1;
		//��ֹ��root*rootʱ�������long long
		long long root = x / 2;
		//����ֻҪ����1����
		while (root * root - x >= 1)
		{
			root = (root + x / root) / 2;
		}
		return root;
	}
};
int main()
{
	Solution solute;
	int x = 2147395599;
	cout << solute.mySqrt(x) << endl;
	return 0;
}