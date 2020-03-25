#include<iostream>
#include<vector>
#include <cstring>
using namespace std;
class Solution {
public:
	int row[9][10] = { 0 };  //row[i][curent]��ʾ��i�г�������curent��curent��1-9�����±굽10
	int col[9][10] = { 0 };  //col[j][curent]��ʾ��j�г�������curent
	int box[9][10] = { 0 };  //box[i/3*3+j/3][curent]��ʾ��i/3*3+j/3����������curent
	void solveSudoku(vector<vector<char>>& board) {
		int i, j, curent;
		//����˼�룺���õݹ���ݵ�˼�룬����ÿһ�������������������������Ƿ�����������9*9���ӣ����������ʧ�ܣ�����ԭ��״̬������һ������
		//��ʼ������������ÿһ�С�ÿһ�С�ÿһ���ָ��� 3x3 ����ֻ�ܳ���һ������1-9������Ѿ������˵�����
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
		//�ݹ���ݾ�������bool����ֵ���ͣ���board[0][0]��board[8][8]���һֱ���������֣���ɹ�
		Shudu(board, 0, 0);
	}
	bool Shudu(vector<vector<char>>& board,int i,int j)
	{
		int cur;
		//�ж����Ƿ񵽴�߽磬�������߽��д�0��ʼ��+1�������Ҳ����߽磬��˵��9*9���Ӷ��������֣�����true
		if (j==9)
		{
			j=0;
			i++;
			if (i == 9)
				return true;
		}
		//�������'.'��Ҫ��������
		if (board[i][j] == '.')
		{
			for (cur = 1; cur <= 9; cur++)
			{
				//�������cur��ÿһ�С�ÿһ�С�ÿһ����û�г��ֹ����������������cur
				if (row[i][cur] == 0 && col[j][cur] == 0 && box[i / 3 * 3 + j / 3][cur] == 0)
				{
					board[i][j] = cur + '0';
					box[i / 3 * 3 + j / 3][cur] = 1;
					row[i][cur] = 1;
					col[j][cur] = 1;
					//��������cur���ݹ�����������ڴ�����¼�������һ��������ʲô���֣����������·���true��˵����������cur��ȷ�����Ǵ����
					if (Shudu(board, i, j + 1))
						return true;
					//�����������������ִ�����󷵻�false����Ҫ����Ĩȥ������������֣�����ѭ������һ�������Ƿ�����
					board[i][j] = '.';
					box[i / 3 * 3 + j / 3][cur] = 0;
					row[i][cur] = 0;
					col[j][cur] = 0;	
				}
			}
		}
		//����������ּ�����һ�����ж�
		else
			return Shudu(board, i, j + 1);
		//������Ҫ����������û�и�ͨ�������������꣬����'.'ȴû�������������������룬�������ʧ�ܣ�����false
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