#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<int> grayCode(int n) {
		//基本思想：由二进制转换为格雷码公式G(n) = B(n) XOR B(n-1)，res[i]保存当前格雷码对应十进制数
		vector<int> res(pow(2, n), 0);
		for (int i = 0; i < pow(2, n); i++)
		{
			//二进制转换为格雷码公式G(n) = B(n) XOR B(n-1)
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