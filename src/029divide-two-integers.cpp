#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
		//�򻯰汾������������
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
		int ret = 0;  //���صĽ��ֵ��
		int flag = -1;
		//�������̷����ж�flag=1��Ϊ������flag=-1��Ϊ����
		if (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0)
			flag = 1;
		//-pow(2, 31)����-1����pow(2, 31)�����������Χ����������������ֵ
		if (dividend == -pow(2, 31) && divisor == -1)
			return pow(2, 31) - 1;
		//-pow(2, 31)����1����-pow(2, 31)����ΪתΪ��������-pow(2, 31)����-1����pow(2, 31)���
		if (dividend == -pow(2, 31) && divisor == 1)
			return -pow(2, 31);	
		//��dividend��divisor��ת��Ϊ�������㣬��Ϊ������Сֵ��-pow(2,31)���������ֵ��pow(2,31)-1��ΧҪ�����תΪ��������-pow(2,31)ת����pow(2,31)
		if (dividend > 0)
			dividend = -dividend;
		if (divisor > 0)
			divisor = -divisor;
		//��¼ԭʼdivisor����Ϊdivisor�ڼ�������в��Ϸ�������divisor>dividend��divisor��ԭΪԭʼֵdivisor_
		int divisor_ = divisor;
		//���dividend>divisor����Ϊ0
		if (dividend > divisor)
			return 0;
		//multiple��¼divisor�ı�����ͨ��dividend��multiple����divisor����ret+=multiple
		int multiple = 1;
		//����ѭ����һֱ����dividend>divisor_����ʱdividendΪ����
		while (dividend <= divisor_)
		{
			if (dividend <= divisor)
			{
				dividend = dividend - divisor;
				ret += multiple;  //�̵������г����ı���֮��
				//��ֹ�����-1100540749����-1090366779�����������ͻ����				
				if (divisor < -pow(2, 30))
					divisor = -pow(2, 31);
				else
					divisor += divisor;  //��������������divisor<<=1����һλ��ֵ����
				multiple += multiple;  //����������multipleΪ�����ı�����Ҳ����������multiple<<=1����һλ��ֵ����
				
			}
			//��divisor>dividend��divisor��ԭΪԭʼֵdivisor_��multipleΪdivisor�ı���Ҳ��ʼΪ1
			else
			{
				divisor = divisor_;
				multiple = 1;
			}
		}
		//flag=1��Ϊ������flag=-1��Ϊ����
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