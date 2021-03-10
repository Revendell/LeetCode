#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
		//简化版本：增倍除数法
        long res=0,a=abs(dividend),b=abs(divisor);        
        while(a>=b){
            long cnt=1,base=b;
            while(a>=base)
			{
				res+=cnt;
				a-=base;
				cnt<<=1;
				base<<=1;
			}	
        }
        res=((dividend<0)^(divisor<0))?-res:res;
        return (INT_MAX<res||res<INT_MIN)?INT_MAX:res;
    }
};
class Solution1 {
public:
	int divide(int dividend, int divisor) {
		int ret = 0;  //返回的结果值商
		int flag = -1;
		//对最后的商符号判断flag=1商为正数，flag=-1商为负数
		if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0)
			flag = 1;
		//-pow(2, 31)除以-1等于pow(2, 31)超过整数最大范围溢出，返回整数最大值
		if (dividend == -pow(2, 31) && divisor == -1)
			return pow(2, 31) - 1;
		//-pow(2, 31)除以1等于-pow(2, 31)，因为转为负数计算-pow(2, 31)除以-1等于pow(2, 31)溢出
		if (dividend == -pow(2, 31) && divisor == 1)
			return -pow(2, 31);	
		//将dividend和divisor都转换为负数计算，因为负数最小值是-pow(2,31)比正数最大值是pow(2,31)-1范围要大，如果转为正数计算-pow(2,31)转不了pow(2,31)
		if (dividend > 0)
			dividend = -dividend;
		if (divisor > 0)
			divisor = -divisor;
		//记录原始divisor，因为divisor在计算过程中不断翻倍，当divisor>dividend，divisor还原为原始值divisor_
		int divisor_ = divisor;
		//如果dividend>divisor，商为0
		if (dividend > divisor)
			return 0;
		//multiple记录divisor的倍数，通过dividend减multiple倍的divisor，商ret+=multiple
		int multiple = 1;
		//不断循环，一直减到dividend>divisor_，此时dividend为余数
		while (dividend <= divisor_)
		{
			if (dividend <= divisor)
			{
				dividend = dividend - divisor;
				ret += multiple;  //商等于所有除数的倍数之和
				//防止溢出，-1100540749除以-1090366779，除数翻倍就会溢出				
				if (divisor < -pow(2, 30))
					divisor = -pow(2, 31);
				else
					divisor += divisor;  //除数翻倍，可以divisor<<=1左移一位数值翻倍
				multiple += multiple;  //除数翻倍，multiple为除数的倍数，也翻倍，可以multiple<<=1左移一位数值翻倍
				
			}
			//当divisor>dividend，divisor还原为原始值divisor_，multiple为divisor的倍数也初始为1
			else
			{
				divisor = divisor_;
				multiple = 1;
			}
		}
		//flag=1商为正数，flag=-1商为负数
		if (flag == 1)
			return ret;
		else
			return -ret;
	}
};
int main()
{
	int dividend = -pow(2,31);
	int divisor = 2;
	Solution solute;
	cout << solute.divide(dividend, divisor) << endl;
	return 0;
}