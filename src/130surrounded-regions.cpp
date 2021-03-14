#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int flag = 0;  //�����ͨ��O�Ƿ�X��Χ��0�ǰ�Χ��1��û�а�Χ(����ͨ��O���ڱ߽���ʱflag=1)
	vector<vector<int>> pos;  //��¼��ͨ��O��λ�ã����flag=0����Щλ�õ�O��λX
	void solve(vector<vector<char>>& board) {
		//�򻯰棺�����������
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				if (board[i][j] == 'O' && !visited[i][j])
				{
					Recursion(board, i, j, visited);
					if (flag == 0)
					{
						for(auto v:pos)
							board[v[0]][v[1]] = 'X';
					}
					flag = 0;
					pos.clear();
				}
			}
		}
	}
	void Recursion(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
	{
		if(i<0||i>=board.size()||j<0||j>=board[i].size())
			return;
		if(board[i][j] != 'O' || visited[i][j])
			return;
		pos.push_back({ i,j });
		visited[i][j] = true;
		if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)
			flag = 1;
		Recursion(board, i - 1, j, visited);
		Recursion(board, i + 1, j, visited);
		Recursion(board, i, j - 1, visited);
		Recursion(board, i, j + 1, visited);
	}
};
class Solution1 {
public:
	int flag = 0;  //�����ͨ��O�Ƿ�X��Χ��0�ǰ�Χ��1��û�а�Χ(����ͨ��O���ڱ߽���ʱflag=1)
	vector<vector<int>> pos;  //��¼��ͨ��O��λ�ã����flag=0����Щλ�õ�O��λX
	void solve(vector<vector<char>>& board) {
		//����˼�룺dfs�������Ǳ߽����е�O��Ȼ��dfs�жϲ�����ͨ��O�Ƿ����λ�ڱ߽��O�����ڵĻ�flag=1
		if (board.size() == 0)
			return;
		//��¼O�Ƿ񱻷��ʹ�
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		//�����Ǳ߽����е�O
		for (int i = 1; i < board.size() - 1; i++)
		{
			for (int j = 1; j < board[i].size() - 1; j++)
			{
				if (board[i][j] == 'O' && !visited[i][j])
				{
					Recursion(board, i, j, visited);
					//flag=0��pos���¼����ͨ��O��X��Χ����ΪX
					if (flag == 0)
					{
						for (int k = 0; k < pos.size(); k++)
						{
							board[pos[k][0]][pos[k][1]] = 'X';
						}
					}
					flag = 0;
					pos.clear();
				}
			}
		}
	}
	void Recursion(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited)
	{
		pos.push_back({ i,j });
		visited[i][j] = true;
		//����ͨ��O���ڱ߽���ʱ��flag=1
		if (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)
		{
			flag = 1;
		}
		if (i - 1 >= 0 && board[i - 1][j] == 'O' && !visited[i - 1][j])
			Recursion(board, i - 1, j, visited);
		if (i + 1 < board.size() && board[i + 1][j] == 'O' && !visited[i + 1][j])
			Recursion(board, i + 1, j, visited);
		if (j - 1 >= 0 && board[i][j - 1] == 'O' && !visited[i][j - 1])
			Recursion(board, i, j - 1, visited);
		if (j + 1 < board[i].size() && board[i][j + 1] == 'O' && !visited[i][j + 1])
			Recursion(board, i, j + 1, visited);
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> board = {
		{'O', 'O', 'O' },
		{'O', 'O', 'O' },
		{'O', 'O', 'O' }
	};
	solute.solve(board);
	for (int i = 0; i < board.size(); i++)
	{
		for_each(board[i].begin(), board[i].end(), [](const char c) {cout << c << " "; });
		cout << endl;
	}
	return 0;
}