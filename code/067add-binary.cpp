#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		//����˼�룺��λ���㣬��ĩλһֱ��ǰ��λ��ӣ���2��λ
		int i, carry = 0;
		//���Ȳ����Ĵ���ǰ�油0
		if (a.size() < b.size())
			a.insert(0, b.size() - a.size(), '0');
		else
			b.insert(0, a.size() - b.size(), '0');
		//ѭ����ĩλһֱ��ǰ��λ��ӣ���2��λ
		for (i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] - '0' + b[i] - '0' + carry >= 2)
			{
				a[i] = a[i] - '0' + b[i] - '0' + carry - 2 + '0';
				carry = 1;
			}
			else
			{
				a[i] = a[i] - '0' + b[i] - '0' + carry + '0';
				carry = 0;
			}
		}
		//�������н�λ����ǰ����1
		if (carry == 1)
			a.insert(0,"1");
		return a;
	}
};
int main()
{
	Solution solute;
	string a = "11", b = "1";
	cout << solute.addBinary(a, b) << endl;
	return 0;
}