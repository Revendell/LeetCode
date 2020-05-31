#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//基本思想：一次遍历
		int res = 0, minprice = 1e9;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
				res += prices[i] - prices[i - 1];
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << solute.maxProfit(prices) << endl;
	return 0;
}