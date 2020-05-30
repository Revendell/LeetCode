#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		//����˼�룺HashMap��HashMapΪ�����͵�ǰ������Ӧ������resλ�õ�ӳ��
		//����HashMap���ҵ����ֹ�������ʱ��˵����С����ʼѭ����ͨ�������ҵ���Ӧ��ʼѭ����λ�ü���������(
		if (numerator == 0)
			return "0";
		string res;
		unordered_map<int, int> HashMap;
		//qΪ����������̣�rΪ�������������
		long long q, r, x, y;  //��ֹ-INT_MIN/1���������ΪINT_MIN�ķ�Χ����INT_MAX
		int pos;
		//������ʾǿ��ת��Ч�ʸ���
		x = static_cast<long long>(numerator);
		y = static_cast<long long>(denominator);
		if ((x > 0) ^ (y > 0))    //x��y��ͬ�ż��븺��
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