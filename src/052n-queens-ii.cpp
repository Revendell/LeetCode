#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	int res = 0;
	int totalNQueens(int n) {
		//����˼�룺�ݹ���ݷ���ÿ����ÿ�м���һ��Q��ѭ��n�μ����Ϊһ��n��λ���ĸ�λ�ü���Q��Ȼ�����check�����Ƿ�����N�ʺ�����������Ļ�cnt+1�����ݹ������һ��Qֱ��cnt=n�������������������޳��ռ����Q
		//HashMap��¼�����Q�Ķ�ά���꣬HashMap[0]=1��ʾ��0��1����һ��Q��cnt��¼�Ѿ������Q��������cnt=n�����ݹ�res++
		map<int, int> HashMap;
		Recursion(n, 0, HashMap);
		return res;
	}
	void Recursion(int n, int cnt, map<int, int> HashMap)
	{
		//�����ǰ�����Q�ĸ���cnt����n�����ݹ飬���������res++
		if (cnt == n)
		{
			res++;
			return;
		}
		//ѭ��n�μ����Ϊһ��n��λ���ĸ�λ�ÿ��Լ���Q��Ȼ�����check�����Ƿ�����N�ʺ�����
		for (int i = 0; i < n; i++)
		{
			HashMap[cnt] = i;
			//����Ļ�cnt+1�����ݹ������һ��Qֱ��cnt=n����
			if (check(HashMap, cnt))
				Recursion(n, cnt + 1, HashMap);
			//�������������޳��ռ����Q
			HashMap.erase(cnt);
		}
		return;
	}
	//check�����Ƿ�����N�ʺ��������ʺ�ᡢ����бλ�ö���������������ʺ�
	bool check(map<int, int> HashMap, int cnt)
	{
		//������Ƿ��Ѿ��лʺ�
		for (auto it = HashMap.begin(); it != HashMap.end(); it++)
		{
			if (it->second == HashMap[cnt] && it->first != cnt)
				return false;
		}
		//���б�Ƿ��Ѿ��лʺ�
		for (int i = cnt - 1, j = 1; i >= 0; i--, j++)
		{
			if (HashMap[i] + j == HashMap[cnt])
				return false;
			if (HashMap[i] - j == HashMap[cnt])
				return false;
		}
		//�ᡢ����б��û�лʺ󣬴�λ�ÿ��Լ���ʺ�Q����true
		return true;
	}
};
int main()
{
	Solution solute;
	int n = 4;
	cout << solute.totalNQueens(n) << endl;
	return 0;
}