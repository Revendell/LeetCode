#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		unsigned int reverse = 0, origin = x;  //reverse��x��ת���ֵ�������ת��reverse��Ȼ����x����˵��x�ǻ�������reverse���޷���������Ϊ�˷�ֹ��ת�����int�з������ͷ�Χ
		int t, i = 0, j = 0;
		//���x�Ǹ�����һ�����ǻ�����
		if (x < 0)
			return false;
		//���xΪ��λ����һ���ǻ�����
		if (x / 10 == 0)
			return true;
		while (x != 0)
		{
			t = x % 10;
			reverse = reverse * 10 + t;
			x = x / 10;
		}
		//x��ת�����ֵreverse��Ȼ����x����˵��x�ǻ�����
		return reverse == origin;
	}
};
int main()
{
	Solution solute;
	int x =1221;
	cout << solute.isPalindrome(x) << endl;
	return 0;
}