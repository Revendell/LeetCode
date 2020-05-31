#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<bool>> visited;
	bool exist(vector<vector<char>>& board, string word) {
		//����˼�룺�ݹ���ݷ��������÷���ʱ��������board[i][j]���ҵ�word[0]��
		//Ȼ����board[i][j]�ĸ������ϵݹ��������һ��word[cnt]��ֱ��cnt=word.size������true
		//ע��㣺ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�ã������ö�ά����visited�жϸõ�Ԫ���Ƿ���ʹ�
		int i, j, cnt = 0;
		visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
		//��board[i][j]���ҵ�word[0]
		for (i = 0; i < board.size(); i++)
		{
			for (j = 0; j < board[i].size(); j++)
			{
				if (!visited[i][j] && board[i][j] == word[0])
				{
					visited[i][j] = true;
					if (Recursion(board, i, j, word, cnt + 1))
						return true;
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
	bool Recursion(vector<vector<char>>& board, int i, int j, string &word, int cnt)
	{
		if (cnt == word.size())
			return true;
		//��board[i][j]�ĸ������ϵݹ��������һ��word[cnt]��ֱ��cnt=word.size������true
		if (i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == word[cnt])
		{
			visited[i - 1][j] = true;
			if (Recursion(board, i - 1, j, word, cnt + 1))
				return true;
			visited[i - 1][j] = false;
		}
		if (i + 1 < board.size() && !visited[i + 1][j] && board[i + 1][j] == word[cnt])
		{
			visited[i + 1][j] = true;
			if (Recursion(board, i + 1, j, word, cnt + 1))
				return true;
			visited[i + 1][j] = false;
		}	
		if (j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == word[cnt])
		{
			visited[i][j - 1] = true;
			if (Recursion(board, i, j - 1, word, cnt + 1))
				return true;
			visited[i][j - 1] = false;
		}	
		if (j + 1 < board[i].size() && !visited[i][j + 1] && board[i][j + 1] == word[cnt])
		{
			visited[i][j + 1] = true;
			if (Recursion(board, i, j + 1, word, cnt + 1))
				return true;
			visited[i][j + 1] = false;
		}	
		return false;
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> board = {
		{'A'} ,
		{'A'} 
	};
	string word = "AAA";
	cout << solute.exist(board, word) << endl;
	return 0;
}