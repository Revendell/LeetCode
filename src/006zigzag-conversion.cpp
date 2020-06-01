#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();  //�ַ���s�ĳ���
		int m = numRows;  //������к�
		int n = 2 * m - 2;  //Z��ѭ������С��Ԫ����
		if (m == 1)  //������к�Ϊ1��ֱ�ӷ���s
			return s;
		int i, j, stride = 0;  //strideΪ�ַ���s���±갴Z�������ΰڷŵ��ַ�λ��
		string ret;
		//��Z�ְڷţ����ζ�ȡm��
		for (i = 1; i <= m; i++)
		{
			stride = i - 1;
			//����ÿһ�У����ζ�ȡ�ڷŵ��ַ����ַ�λ��s��λ����s[stride]�����ӵ��ַ���ret�ĺ��棬stride�±�С���ַ���s�ĳ���len
			while (stride < len)
			{
				//��һ�к͵�m���ַ��ڷŵĹ������ַ�����s��λ���±�ÿ��nȡһ�ΰڷ�
				if (i == 1 || i == m)
				{
					ret.push_back(s[stride]);
					stride += n;
				}
				//�������ַ��ڷŵĹ������ַ�����s��λ���±�ÿ��n-2*(i-1)��2*(i-1)ȡ���ΰڷţ�n��ѭ������С��Ԫ���ȣ�i���к�
				else
				{
					ret.push_back(s[stride]);
					stride += n - 2 * (i - 1);
					if (stride < len)
						ret.push_back(s[stride]);
					stride += 2 * (i - 1);
				}
			}
		}
		return ret;
	}
};
int main()
{
	Solution solute;
	string s = "LEETCODEISHIRING";
	int numRows = 4;
	cout << solute.convert(s, numRows) << endl;
	return 0;
}