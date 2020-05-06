#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		vector<int> cur;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (j == 0)
					cur.push_back(1);
				else if (j == i)
					cur.push_back(1);
				else
					cur.push_back(res[i - 1][j - 1] + res[i - 1][j]);
			}
			res.push_back(cur);
			cur.clear();
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int numRows = 5;
	vector<vector<int>> res = solute.generate(numRows);
	for (int i = 0; i < res.size(); i++)
	{
		for_each(res[i].begin(), res[i].end(), [](const int& v) {cout << v << " "; });
		cout << endl;
	}
}