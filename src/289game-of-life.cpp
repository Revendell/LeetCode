
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0)  return;
		vector<int> row = { 0,1,-1 };
		vector<int> col = { 0,1,-1 };
		int n = board.size();
		int m = board[0].size();
		//����ÿ��λ�õ�ϸ����������״̬
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int livecells = 0;
				//���㵱ǰλ��ϸ����Χ8��λ�õĻ�ϸ������
				for (int k1 = 0; k1 < 3; k1++)
				{
					for (int k2 = 0; k2 < 3; k2++)
					{
						if (k1 == 0 && k2 == 0)
							continue;
						//ÿ��ϸ��&1�õ����ǵ�ǰ״̬
						if (i + row[k1] >= 0 && i + row[k1] < n && j + col[k2] >= 0 && j + col[k2] < m)
							livecells += board[i + row[k1]][j + col[k2]] & 1;
					}
				}
				//���ݻ�ϸ���������µ�ǰλ��ϸ��״̬
				if (board[i][j] == 0)
					board[i][j] = livecells == 3 ? 2 : 0;
				else
					board[i][j] = livecells >= 2 && livecells <= 3 ? 3 : 1;
			}
		}
		//ÿ��ϸ������1λ�õ�������һ��״̬
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] >>= 1;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> board = {
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};
	solute.gameOfLife(board);
	for (int i = 0; i < board.size(); i++)
	{
		for_each(board[i].begin(), board[i].end(), [](const int v) {cout << v << " "; });
		cout << endl;
	}
	return 0;
}
