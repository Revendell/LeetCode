#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//简化版：贪心算法，找到最大的差值
		int res = 0, minprice = INT_MAX;
		for (int i = 0; i < prices.size(); i++)
		{
			res=max(res,prices[i] - minprice);
			minprice=min(minprice,prices[i]);				
		}
		return res;
	}
};
class Solution1 {
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