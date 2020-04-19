#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		//����˼�룺�ֵ��� (����������) ��ϣ����ֵ����˳����ȫ����ϣ���һ����Ϊ11000�����һ����Ϊ00011
		vector<int> cur;
		vector<vector<int>> res;
		int cnt = 0, pos, i, j, flag = 1, carry = 1;
		vector<int> vec(n, 0);
		for (i = 0; i < k; i++)
			vec[i] = 1;
		do
		{
			for (i = 0; i < vec.size(); i++)
			{
				if (vec[i] == 1)
					cur.push_back(i + 1);
			}
			res.push_back(cur);    
			cur.clear();
			//prev_permutation()������[first,last]�����е�����ת��Ϊ�ֵ������һ�����С�
			//�����һ�����д��ڷ���true�������һ�����в����ڣ���ú�������false����������ת��Ϊ�ֵ�������һ�����С�
		} while (prev_permutation(vec.begin(), vec.end()));
		return res;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> combine(int n, int k) {
		//����˼�룺�ݹ���ݷ�
		vector<int> cur;
		Recursion(n, k, 1, 0, cur);
		return res;
	}
	void Recursion(int n, int k, int pos, int cnt, vector<int> cur)
	{
		if (cnt == k)
		{
			res.push_back(cur);
			return;
		}
		for (int i = pos; i <= n; i++)
		{
			cur.push_back(i);
			Recursion(n, k, i + 1, cnt + 1, cur);
			cur.pop_back();
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> res;
	int n = 5, k = 2;
	res = solute.combine(n, k);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}