#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> solveNQueens(int n) {
		//����˼�룺�ݹ���ݷ���ÿ����ÿ�м���һ��Q��ѭ��n�μ����Ϊһ��n��λ���ĸ�λ�ü���Q��Ȼ�����check�����Ƿ�����N�ʺ�����������Ļ�cnt+1�����ݹ������һ��Qֱ��cnt=n�������������������޳��ռ����Q
		//HashMap��¼�����Q�Ķ�ά���꣬HashMap[0]=1��ʾ��0��1����һ��Q��cnt��¼�Ѿ������Q��������cnt=n�����ݹ鱣����res
		map<int, int> HashMap;
		Recursion(n, 0, HashMap);
		return res;
	}
	void Recursion(int n, int cnt, map<int, int> HashMap)
	{
		//�����ǰ�����Q�ĸ���cnt����n�����ݹ飬��������浽res
		if (cnt == n)
		{
			vector<string> cur;
			string temp;
			for (int j = 0; j < n; j++)
				temp += '.';
			for (int i = 0; i < n; i++)
			{
				temp[HashMap[i]] = 'Q';
				cur.push_back(temp);
				temp[HashMap[i]] = '.';
			}
			res.push_back(cur);
			return;
		}
		//ѭ��n�μ����Ϊһ��n��λ���ĸ�λ�ÿ��Լ���Q��Ȼ�����check�����Ƿ�����N�ʺ�����
		for (int i = 0; i < n; i++)
		{
			HashMap[cnt] = i;
			//����Ļ�cnt+1�����ݹ������һ��Qֱ��cnt=n����
			if (check(HashMap,cnt))
				Recursion(n, cnt + 1, HashMap);
			//�������������޳��ռ����Q
			HashMap.erase(cnt);
		}
		return;
	}
	//check�����Ƿ�����N�ʺ��������ʺ�ᡢ����бλ�ö���������������ʺ�
	bool check(map<int, int> HashMap,int cnt)
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
		//�ᡢ����б��û�лʺ󣬴�λ�ÿ��Լ���ʺ�Q
		return true;
	}
};
int main()
{
	Solution solute;
	vector<vector<string>> res;
	int n = 4;
	res = solute.solveNQueens(n);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << endl;
		cout << endl;
	}
	return 0;
}