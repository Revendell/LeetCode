#include<iostream>
#include<math.h>
#include<cctype>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
		//�򻯰棺�Ĳ��ߣ�����ǰ���ո�ȷ�������š���������Ƿ�Ϸ�������Ƿ����
        int sign = 1, i = 0;
		long  num = 0;
        while(s[i] == ' ')    //1.����ǰ���ո�
			i++;    
        if(s[i] == '+' || s[i] == '-')    //2.ȷ��������
		{
			sign=s[i]=='+'?1:-1;
			i++;
		}
        while(isdigit(s[i]))   //3.��������Ƿ�Ϸ�
        {
            num = num * 10 + (s[i++] - '0');
            if((sign==1&&num>=INT_MAX) || (sign==-1&&num-1>=INT_MAX))    //4.�Ƿ����
                return sign == 1 ? INT_MAX : INT_MIN;
        }
        return num * sign;
    }
};
class Solution1 {
public:
	int myAtoi(string str) {
		int number[1000];
		int i, j = 0, flag, len;  //lenΪ�ַ���str�ĳ��ȣ�flag������������Ƿ��з���flag=1(ת�����±�1��ʼ)����ǰ����-��+��j�������������λ��
		int ret = 0;  //retΪҪ���ص��ַ���ת�����Ľ��
		if (str == "0")  //����ַ���Ϊ"0"ֱ�ӷ���
			return 0;
		//������ͷ���õĿո��ַ�
		while (str[0] == ' ')
			str.erase(0, 1);
		//�����һ���ַ���-��+�ڶ����ַ�Ϊ���ֻ��ߵ�һ���ַ�Ϊ����
		if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]) || isdigit(str[0]))
		{
			//����ǰ����-��+flag=1ת�����±�1��ʼ,����ǰ��û�з���flag=0ת�����±�0��ʼ
			if (isdigit(str[0]))
				flag = 0;
			else
				flag = 1;
			//������ͷ���õ�0�ַ�
			while (str[flag] == '0')
				str.erase(flag, 1);
			len = str.size();
			//�������ַ�ת��Ϊ���ֲ����浽number������
			for (i = flag; i < len; i++)
			{
				if (isdigit(str[i]))
					number[j++] = str[i] - '0';
				//������������ַ�ֹͣѭ��ֻת��ǰ��������ַ�
				else
					break;
			}
			//������number�Ӹ�λk-1����λ0�������/�����浽ret��ÿ����һλ���һ��0:ret+/-=number[i]*pow(10,k-1-i)��ͬʱ�ж��Ƿ�Խ��int��Χ
			for (i = j - 1; i >= 0; i--)
			{
				//����Ǹ�������������浽ret
				if (str[0] == '-')
					if (ret - number[i] * pow(10, j - 1 - i) < pow(-2, 31))
						return  pow(-2, 31);
					else
						ret -= number[i] * pow(10, j - 1 - i);
				//���������������ӱ��浽ret
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