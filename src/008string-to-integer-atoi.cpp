#include<iostream>
#include<math.h>
#include<cctype>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
		//简化版：四步走，忽略前导空格、确定正负号、检查输入是否合法、检查是否溢出
        int sign = 1, i = 0;
		long  num = 0;
        while(s[i] == ' ')    //1.忽略前导空格
			i++;    
        if(s[i] == '+' || s[i] == '-')    //2.确定正负号
		{
			sign=s[i]=='+'?1:-1;
			i++;
		}
        while(isdigit(s[i]))   //3.检查输入是否合法
        {
            num = num * 10 + (s[i++] - '0');
            if((sign==1&&num>=INT_MAX) || (sign==-1&&num-1>=INT_MAX))    //4.是否溢出
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return num * sign;
    }
};
class Solution1 {
public:
	int myAtoi(string str) {
		int number[1000];
		int i, j = 0, flag, len;  //len为字符串str的长度，flag用来标记整数是否有符号flag=1(转换从下标1开始)整数前面有-或+，j用来标记整数的位数
		int ret = 0;  //ret为要返回的字符串转整数的结果
		if (str == "0")  //如果字符串为"0"直接返回
			return 0;
		//丢弃开头无用的空格字符
		while (str[0] == ' ')
			str.erase(0, 1);
		//如果第一个字符是-或+第二个字符为数字或者第一个字符为数字
		if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]) || isdigit(str[0]))
		{
			//整数前面有-或+flag=1转换从下标1开始,整数前面没有符号flag=0转换从下标0开始
			if (isdigit(str[0]))
				flag = 0;
			else
				flag = 1;
			//丢弃开头无用的0字符
			while (str[flag] == '0')
				str.erase(flag, 1);
			len = str.size();
			//将整数字符转换为数字并保存到number数组中
			for (i = flag; i < len; i++)
			{
				if (isdigit(str[i]))
					number[j++] = str[i] - '0';
				//如果不是数字字符停止循环只转换前面的数字字符
				else
					break;
			}
			//将数组number从高位k-1到低位0依次相加/减保存到ret，每降低一位多乘一个0:ret+/-=number[i]*pow(10,k-1-i)，同时判断是否越界int范围
			for (i = j - 1; i >= 0; i--)
			{
				//如果是负数就是相减保存到ret
				if (str[0] == '-')
					if (ret - number[i] * pow(10, j - 1 - i) < pow(-2, 31))
						return  pow(-2, 31);
					else
						ret -= number[i] * pow(10, j - 1 - i);
				//如果是正数就是相加保存到ret
				else
					if (ret + number[i] * pow(10, j - 1 - i) > (pow(2, 31) - 1))
						return  pow(2, 31) - 1;
					else
						ret += number[i] * pow(10, j - 1 - i);

			}
			return ret;
		}
		else
			return 0;
	}
};
int main()
{
	Solution solute;
	string str1 = "4193 with words";
	string str2 = "   +42";
	string str3 = "   -42";
	string str4 = "words and 987";
	string str5 = "-91283472332";
	string str6 = "000002332";
	string str7 = "-000000000000001";
	string str8 = "0-1";
	cout << solute.myAtoi(str8) << endl;
	return 0;
}