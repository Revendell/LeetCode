#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int countDigitOne(int n)
	{
		//基本思想：数学
		//个位出现1的情况:每增加10个数，产生一个1
		//十位出现1的情况:每增加100个数，产生一个10个1
		//百位出现1的情况:每增加1000个数，产生100个1
		//循环依次算出个位、十位、百位到最高位1的个数
		//例如：分析百位上1的个数
		//当百位上为0时，如53015，个数由高位数字决定，53*100
		//当百位上为1时，如53115，个数还需考虑低位的情况，因为从100到115百位上还都有1，共116个
		//当百位上大于1时，如53215，共(53+1)*100，个数由高位数字决定（高位+1）
		int res = 0, num = n;
		long i = 1;
		while (num)
		{
			if (num % 10 == 0)  //该位为0，个数由高位数字决定
				res += num / 10 * i;
			if (num % 10 == 1)  //该位为1，个数还需考虑低位的情况，低位个数为n%i+1
				res += num / 10 * i + n % i + 1;
			if (num % 10 > 1)  //该位大于1，个数由高位数字决定（高位+1）
				res += (num / 10 + 1) * i;
			num = num / 10;
			i = i * 10;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 16;
	cout << solute.countDigitOne(n) << endl;
	return 0;
}