#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		//����˼�룺��ѧ���ؼ���һ�������Ƚ�n-1������ʹ��Excel�������0��ʼ
		//Ȼ��ǵ�ÿ��q/26�õ�����Ҫ��һ��������Ϊ1-26��һ����ĸ����27��ʼ��������ĸ��ʼ����27/26=1���Ǵ�A��ʼ��֮ǰ����
		string res;
		int q, r;
		q = n - 1;
		while (q >= 0)
		{
			r = q % 26;
			char ch = static_cast<char>('A' + r);
			res.push_back(ch);
			q = q / 26;
			q--;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 53;
	cout << solute.convertToTitle(n) << endl;
	return 0;
}