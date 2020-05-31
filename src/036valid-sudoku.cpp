#include <iostream>
#include <vector>
using namespace std;
//������
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, row, col;
        //����˼�룺����ѭ����9*9������ÿһ�����ֱ���һ�飬Ȼ��Ƚϸ�������ÿһ�С�ÿһ�С�ÿһ���Ƿ����ظ����֣����򷵻�false
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
                        //������board[i][j]����ͬһ���ж��Ƿ����ظ�
                        if (k != j && board[i][k] == board[i][j])
                            return false;
                        //������board[i][j]����ͬһ���ж��Ƿ����ظ�
						if (k != i && board[k][j] == board[i][j])
							return false;
                    }
                    //������board[i][j]����ͬһ���ж��Ƿ����ظ�
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
//HashMap��
class Solution1 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int i, j, k;
		//��������ÿһ��ֻ�ܳ���һ�Ρ�ÿһ��ֻ�ܳ���һ�Ρ�ÿһ���ָ��� 3x3 ����ֻ�ܳ���һ������1-9
        int row[9][10] = { 0 };  //row[i][curent]��ʾ��i�г�������curent��curent��1-9�����±굽10
        int col[9][10] = { 0 };  //col[j][curent]��ʾ��j�г�������curent
        int box[9][10] = { 0 };  //box[i/3*3+j/3][curent]��ʾ��i/3*3+j/3����������curent
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					if (board[i][j] > '9' || board[i][j] < '1')
						return false;

                    int curent = board[i][j] - '0';
                    //���֮ǰ�Ѿ�����������curent���򷵻�false
                    if (row[i][curent] == 1)
                        return false;
					if (col[j][curent] == 1)
						return false;
					if (box[i/3*3+j/3][curent] == 1)
						return false;
                    //֮ǰû�г�������curent����ÿһ�С�ÿһ�С�ÿһ���������curent����
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