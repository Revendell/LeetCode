#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> num;
	vector<int> dict = { 2,3,5 };
	int nthUglyNumber(int n) {
		//����˼�룺�ݹ飬�ݹ��������2,3,5��������ϳɵĳ���
		//�ݹ麯�������cnt��ʾ��ǰ�õ��ĳ���������������
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
		//����˼�룺��̬�滮��ָ�룬����뷨��ֽ��������ݹ����������
		//1.����Ҫ���ȫ�������ǰ�˳���������
		//2.��ǰ��������֮ǰ�����Ļ����ϳ����������ã�����Ҫ��ͷ��ʼ����õ�
		vector<int> num = { 1 };
		int index2 = 0, index3 = 0, index5 = 0;
		int cur;
		for (int i = 1; i < n; i++)
		{
			cur = min(num[index2] * 2, min(num[index3] * 3, num[index5] * 5));
			num.push_back(cur);
			//�������жϱ���ֿ�������������Ϊ�п��ܵ�ǰnum[index2]=3��num[index3]=2��
			//��ʱnum[index2]*2��num[index3]*3����������Сֵ����ôindex2��index3��ָ�±궼Ҫ++
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