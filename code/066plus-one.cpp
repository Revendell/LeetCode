#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		//基本思想：进位加一，开始设置进位carry=1，表示一开始就有进位等于1，如果加上进位小于10，进位carry设置为0
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