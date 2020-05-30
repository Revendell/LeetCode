#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		//基本思想：HashMap，HashMap为余数和当前余数对应商所在res位置的映射
		//当在HashMap中找到出现过的余数时，说明有小数开始循环，通过余数找到对应开始循环的位置加入左括号(
		if (numerator == 0)
			return "0";
		string res;
		unordered_map<int, int> HashMap;
		//q为两数相除的商，r为两数相除的余数
		long long q, r, x, y;  //防止-INT_MIN/1的情况，因为INT_MIN的范围大于INT_MAX
		int pos;
		//算术显示强制转换效率更高
		x = static_cast<long long>(numerator);
		y = static_cast<long long>(denominator);
		if ((x > 0) ^ (y > 0))    //x和y不同号加入负号
			res += "-";
		x = llabs(x);
		y = llabs(y);
		q = x / y;
		r = x % y;
		res += to_string(q);
		if (r == 0)
			return res;
		res += ".";
		while (HashMap.find(r) != HashMap.end())
		{
			HashMap[r] = res.size();
			q = r;
			q *= 10;
			r = q % y;
			q = q / y;
			res += to_string(q);
			if (r == 0)
				return res;
		}
		res.insert(HashMap[r], "(");
		res += ')';
		return res;
	}
};
int main()
{
	Solution solute;
	int numerator = -2147483648, denominator = 1;
	cout << solute.fractionToDecimal(numerator, denominator) << endl;
	return 0;
}