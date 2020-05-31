#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		//����˼�룺�ɶ�����ת��Ϊ�����빫ʽG(n) = B(n) XOR B(n-1)��res[i]���浱ǰ�������Ӧʮ������
		vector<int> res(pow(2, n), 0);
		for (int i = 0; i < pow(2, n); i++)
		{
			//������ת��Ϊ�����빫ʽG(n) = B(n) XOR B(n-1)
			res[i] = i ^ (i >> 1);	
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 3;
	vector<int> res = solute.grayCode(n);
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
	return 0;
}