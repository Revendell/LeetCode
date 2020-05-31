#include <iostream>
#include <vector>
using namespace std;
//暴力法
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, row, col;
        //基本思想：两次循环对9*9的数独每一个数字遍历一遍，然后比较该数字在每一行、每一列、每一宫是否有重复数字，有则返回false
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (board[i][j] > '9' || board[i][j] < '1')
                        return false;
                    for (k = 0; k < 9; k++)
                    {
                        //对数字board[i][j]所在同一行判断是否有重复
                        if (k != j && board[i][k] == board[i][j])
                            return false;
                        //对数字board[i][j]所在同一列判断是否有重复
						if (k != i && board[k][j] == board[i][j])
							return false;
                    }
                    //对数字board[i][j]所在同一宫判断是否有重复
                    for (row = i / 3 * 3; row < i / 3 * 3 + 3; row++)
                    {
                        for (col = j / 3 * 3; col < j / 3 * 3 + 3; col++)
                        {
                            if (row != i && col != j && board[i][j] == board[row][col])
								return false;
                        }
                    }
                }
            }
        }
        return true;
	}
};
//HashMap法
class Solution1 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int i, j, k;
		//数独必须每一行只能出现一次、每一列只能出现一次、每一个分隔的 3x3 宫内只能出现一次数字1-9
        int row[9][10] = { 0 };  //row[i][curent]表示第i行出现数字curent，curent从1-9所以下标到10
        int col[9][10] = { 0 };  //col[j][curent]表示第j列出现数字curent
        int box[9][10] = { 0 };  //box[i/3*3+j/3][curent]表示第i/3*3+j/3宫出现数字curent
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					if (board[i][j] > '9' || board[i][j] < '1')
						return false;

                    int curent = board[i][j] - '0';
                    //如果之前已经出现了数字curent，则返回false
                    if (row[i][curent] == 1)
                        return false;
					if (col[j][curent] == 1)
						return false;
					if (box[i/3*3+j/3][curent] == 1)
						return false;
                    //之前没有出现数字curent，在每一行、每一列、每一宫标记数字curent出现
                    row[i][curent] = 1;
                    col[j][curent] = 1;
                    box[i / 3 * 3 + j / 3][curent] = 1;
				}
			}
		}
		return true;
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
    cout << solute.isValidSudoku(board) << endl;
    return 0;
}