#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		//基本思想：暴力模拟竖式乘法计算过程，两重循环第一重循环读取num2中某个数与第二重循环读取num1所有数相乘这就是一层结果layer，然后将每一层结果加到res最后返回res的逆序
		//layer为num2中某个数与num1所有数相乘结果也就是一层结果，将每一层结果加到res就是最后返回结果
		string res, layer;
		//cur是num1中某个数字和num2某个数字相乘得到结果的个位数
		char cur;
		//temp临时num1和num2某两个数字对应相乘结果，carry是结果的十位数也就是进位数
		int i, j, carry, temp, k;
		//如果num1和num2中有一个是0，结果返回0
		if (num1 == "0" || num2 == "0")
			return "0";
		//第一重循环读取num2中某个数
		for (i = num2.size() - 1; i >= 0; i--)
		{
			//每一层layer初始化为空
			layer = "";
			//根据num2中读取数所在的位数，layer添加相应个数的0
			for (k = 0; k < num2.size() - 1 - i; k++)
				layer.push_back('0');
			//进位数carry初始化为0
			carry = 0;
			//第二重循环读取num1所有数与num2读取的数num2[i]相乘得到这一层结果layer
			for (j = num1.size() - 1; j >= 0; j--)
			{
				temp = (num2[i] - '0') * (num1[j] - '0') + carry;
				cur = temp % 10 + '0';
				carry = temp / 10;
				layer.push_back(cur);		
			}
			//如果num2[i]与num1所有数相乘后还有进位，加到layer后面
			if (carry > 0)
				layer.push_back(carry + '0');
			carry = 0;
			//然后将每一层结果layer加到res上
			for (k = 0; k < res.size() && k < layer.size(); k++)
			{
				temp = (res[k] - '0') + (layer[k] - '0') + carry;
				res[k] = temp % 10 + '0';
				carry = temp / 10;
			}
			//可能layer的长度大于res的长度，layer大于res长度的部分加到res后面
			while (k < layer.size())
			{
				temp = layer[k] - '0' + carry;
				res.push_back(temp % 10 + '0');
				carry = temp / 10;
				k++;
			}
			//考虑可能最后还有进位
			if (carry == 1)
				res.push_back('1');
		}
		//最后返回res的逆序
		reverse(res.begin(), res.end());
		return res;
	}
};
int main()
{
	Solution solute;
	string nums1 = "23";
	string nums2 = "112";
	cout << solute.multiply(nums1, nums2) << endl;
	return 0;
}