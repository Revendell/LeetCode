#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		//基本思想：数学，关键的一步就是先将n-1，这样使得Excel表计数从0开始
		//然后记得每次q/26得到的商要减一，这是因为1-26是一个字母，而27开始是两个字母开始计数27/26=1但是从A开始，之前不算
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