#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//����˼�룺��λ��һ����ʼ���ý�λcarry=1����ʾһ��ʼ���н�λ����1��������Ͻ�λС��10����λcarry����Ϊ0
		int i, carry = 1;
		for (i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] + carry >= 10)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i] += carry;
				carry = 0;
			}
		}
		if (carry == 1)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};
int main()
{
	Solution solute;
	vector<int> digits = { 9,9,9,9 };
	vector<int> res = solute.plusOne(digits);
	for (int i =0;  i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}