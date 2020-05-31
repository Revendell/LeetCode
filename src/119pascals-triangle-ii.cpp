#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1, 1);
		int cur, pre;
		for (int i = 0; i <= rowIndex; i++)
		{
			pre = 1;
			for (int j = 1; j < i; j++)
			{
				cur = res[j];
				res[j] += pre;
				pre = cur;
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int rowIndex = 5;
	vector<int> res = solute.getRow(rowIndex);
	for_each(res.begin(), res.end(), [](const int& v) {cout << v << endl; });
	return 0;
}