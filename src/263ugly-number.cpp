#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isUgly(int num) {
		//����˼�룺��ѧ�����ϳ������������������������ȻΪ1
		if (num == 0)
			return false;
		while (num != 1)
		{
			if (num % 2 == 0)
				num /= 2;
			else if (num % 3 == 0)
				num /= 3;
			else if (num % 5 == 0)
				num /= 5;
			else
				return false;
		}
		return true;
	}
};
int main()
{
	Solution solute;
	int num = 81;
	cout << solute.isUgly(num) << endl;
	return 0;
}