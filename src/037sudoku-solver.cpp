#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
class Solution {
public:
	int row[9][10] = { 0 };  //row[i][curent]表示第i行出现数字curent，curent从1-9所以下标到10
	int col[9][10] = { 0 };  //col[j][curent]表示第j列出现数字curent
	int box[9][10] = { 0 };  //box[i/3*3+j/3][curent]表示第i/3*3+j/3宫出现数字curent
	void solveSudoku(vector<vector<char>>& board) {
		int i, j, curent;
		//基本思想：采用递归回溯的思想，对于每一个数字填入情况深度搜索，看是否能完整填满9*9格子，如果不能则失败，回溯原来状态填入下一个数字
		//初始化，数独必须每一行、每一列、每一个分隔的 3x3 宫内只能出现一次数字1-9，标记已经出现了的数字
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					curent = board[i][j] - '0';
					row[i][curent] = 1;
					col[j][curent] = 1;
					box[i / 3 * 3 + j / 3][curent] = 1;
				}
			}
		}
		//递归回溯尽量设置bool返回值类型，从board[0][0]到board[8][8]如果一直能填满数字，则成功
		Shudu(board, 0, 0);
	}
	bool Shudu(vector<vector<char>>& board,int i,int j)
	{
		int cur;
		//判断列是否到达边界，如果到达边界列从0开始行+1，如果行也到达边界，则说明9*9格子都填满数字，返回true
		if (j==9)
		{
			j=0;
			i++;
			if (i == 9)
				return true;
		}
		//如果遇到'.'需要填入数字
		if (board[i][j] == '.')
		{
			for (cur = 1; cur <= 9; cur++)
			{
				//如果数字cur在每一行、每一列、每一宫都没有出现过，则可以填入数字cur
				if (row[i][cur] == 0 && col[j][cur] == 0 && box[i / 3 * 3 + j / 3][cur] == 0)
				{
					board[i][j] = cur + '0';
					box[i / 3 * 3 + j / 3][cur] = 1;
					row[i][cur] = 1;
					col[j][cur] = 1;
					//填入数字cur，递归深度搜索，在此情况下继续看下一个格子填什么数字，如果此情况下返回true，说明所填数字cur正确，就是此情况
					if (Shudu(board, i, j + 1))
						return true;
					//如果上诉情况所填数字错误，最后返回false，需要回溯抹去上诉填入的数字，继续循环看下一个数字是否满足
					board[i][j] = '.';
					box[i / 3 * 3 + j / 3][cur] = 0;
					row[i][cur] = 0;
					col[j][cur] = 0;	
				}
			}
		}
		//如果遇到数字继续下一格子判断
		else
			return Shudu(board, i, j + 1);
		//极其重要，就是这里没有搞通，最后程序运行完，遇到'.'却没有满足条件的数字填入，这种情况失败，返回false
		return false;
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> board = {
	{ '5','3','.','.','7','.','.','.','.' },
	{ '6','.','.','1','9','5','.','.','.' },
	{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },
	{ '4','.','.','8','.','3','.','.','1' },
	{ '7','.','.','.','2','.','.','.','6' },
	{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },
	{ '.','.','.','.','8','.','.','7','9' } };
	solute.solveSudoku(board);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}