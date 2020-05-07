#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//基本思想：一次遍历
		int res = 0, minprice = 1e9;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] - minprice > res)
				res = prices[i] - minprice;
			if (prices[i] < minprice)
				minprice = prices[i];				
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