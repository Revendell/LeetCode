#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//����˼�룺̰�ķ�һ�α�����ʱ�临�Ӷ�O(N)
		//���ܿ���ȫ����Ҫ������������������iվ�ܿ���i + 1������վ���������Ҫ >= ���ӵ��ܺ�������
		//���ӱ��Ϊ0վ��ʼ��һֱ��iվ���������ڿ���i+1վʱ����û���ˡ���ʱ��Ӧ�ý��������Ϊi+1վ��
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
		//����˼�룺���ÿһ������վ��ѡ��ü���վΪ����վ��ģ��������·��ʻ��
		//��ÿһ������վ������ǻ�ʣ���������͡�ʱ�临�Ӷ�O(N^2)
		//ѧ���ӳ����㣬����O(N^2)ʱ�临�ӶȽ��������O(N)ʵ��
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