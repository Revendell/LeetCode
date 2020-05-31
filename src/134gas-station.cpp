#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//基本思想：贪心法一次遍历，时间复杂度O(N)
		//车能开完全程需要满足两个条件：车从i站能开到i + 1。所有站里的油总量要 >= 车子的总耗油量。
		//车从编号为0站开始，一直到i站都正常，在开往i+1站时车子没油了。这时，应该将起点设置为i+1站。
		int rest = 0, run = 0, start = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			run += (gas[i] - cost[i]);
			rest += (gas[i] - cost[i]);
			if (run < 0)
			{
				start = i + 1;
				run = 0;
			}
		}
		if (rest < 0)
			return -1;
		else
			return start;
	}
};
class Solution1 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//基本思想：检查每一个加油站：选择该加油站为出发站，模拟汽车环路行驶，
		//在每一个加油站检查我们还剩多少升汽油。时间复杂度O(N^2)
		//学会延迟满足，在用O(N^2)时间复杂度解决后想想O(N)实现
		int pos, flag, rest, len = gas.size();
		for (int i = 0; i < len; i++)
		{
			if (gas[i] - cost[i] < 0)
				continue;
			else
			{
				flag = 0;
				rest = gas[i] - cost[i];
				pos = (i + 1) % len;
				while (pos != i)
				{
					if (rest + gas[pos] - cost[pos] < 0)
					{
						flag = 1;
						break;
					}
					else
					{
						rest += gas[pos] - cost[pos];
						pos = (pos + 1) % len;
					}
				}
				if (flag == 0)
					return i;
			}
		}
		return -1;
	}
};
int main()
{
	Solution1 solute;
	vector<int> gas = { 5,1,2,3,4 };
	vector<int> cost = { 4,4,1,5,1 };
	cout << solute.canCompleteCircuit(gas, cost) << endl;
	return 0;
}