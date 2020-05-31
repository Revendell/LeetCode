#include<iostream>
#include<vector>
using namespace std;
//�ݹ���ݷ�
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s;
		vector<string> res;  //��󷵻صĽ���������ñ�ȫ�ֱ���Ч�ʸ���effective C++
		int i = 0, j = 0;  //i��������Ÿ���i<=n��j��������Ÿ���j<=n
		if (n < 1)
			return res;
		//�ݹ�������������ַ���
		Recursion(res, s, n, i, j);
		return res;
	}
	void Recursion(vector<string> &res, string s, int n, int i, int j)
	{
		if (j == n)
			res.push_back(s);
		//���ɵ������ַ�����Զ��������������j<=i i<=n
		//��i<nʱ�������������i+1(Ҳ����ѡ����ӣ��ݹ����)����j<iʱ�������������j+1����j==n���ɵ������ַ���s��������s���뷵��ֵres�У�res.push_back(s)
		if (i < n)
		{
			Recursion(res, s + '(', n, i + 1, j);
		}
		if (j < i)
		{
			Recursion(res, s + ')', n, i, j + 1);
		}
	}
};
int main()
{
	int n = 3;
	Solution solute;
	vector<string> res;
	res = solute.generateParenthesis(n);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}