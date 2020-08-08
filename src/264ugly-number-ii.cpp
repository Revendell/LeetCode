#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> num;
	vector<int> dict = { 2,3,5 };
	int nthUglyNumber(int n) {
		//基本思想：递归，递归遍历所有2,3,5质因数组合成的丑数
		//递归函数传入的cnt表示当前得到的丑数的质因数个数
		num = { 1 };
		int cnt = 1;
		while(num.size() < 1690)
		{
			long cur = 1;
			Recursion(0, cur, 0, cnt);
			cnt += 1;
		}
		sort(num.begin(), num.end());
		return num[n - 1];
	}
	void Recursion(int pos, long cur, int i, int cnt)
	{
		if (i == cnt)
		{
			num.push_back(cur);
			return;
		}
		for (int j = pos; j < 3; j++)
		{
			cur *= dict[j];
			if (cur > INT_MAX)
				return;
			Recursion(j, cur, i + 1, cnt);
			cur /= dict[j];
		}
		return;
	}
};
class Solution1 {
public:
	int nthUglyNumber(int n) {
		//基本思想：动态规划三指针，这个想法充分解决了上面递归产生的问题
		//1.不需要求出全部丑数是按顺序求出丑数
		//2.求当前丑数是在之前丑数的基础上乘质因数所得，不需要从头开始计算得到
		vector<int> num = { 1 };
		int index2 = 0, index3 = 0, index5 = 0;
		int cur;
		for (int i = 1; i < n; i++)
		{
			cur = min(num[index2] * 2, min(num[index3] * 3, num[index5] * 5));
			num.push_back(cur);
			//这三个判断必须分开独立，这是因为有可能当前num[index2]=3，num[index3]=2，
			//此时num[index2]*2和num[index3]*3两个都是最小值，那么index2和index3所指下标都要++
			if (cur == num[index2] * 2)
				index2++;
			if (cur == num[index3] * 3)
				index3++;
			if (cur == num[index5] * 5)
				index5++;
		}
		return num.back();
	}
};
int main()
{
	Solution1 solute;
	int n = 10;
	cout << solute.nthUglyNumber(n) << endl;
	return 0;
}