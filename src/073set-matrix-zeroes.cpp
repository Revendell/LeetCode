#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�����������ֵ
#define inf -1000000
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//����˼�룺����ռ�O(2)������matrix���һ�к����һ�б�ǵ�ǰ�к͵�ǰ���Ƿ���0
		//�����ǰ����0�ڸ������һ��λ�ñ��Ϊinf�������ǰ����0�ڸ������һ��λ�ñ��Ϊinf
		//���һ�к����һ���Ƿ����0����last_col��last_row���
		//ѭ������matrix�������Ԫ�������л��е����һ��λ��Ϊinf����Ԫ�ر��Ϊ0�����һ�к����һ��Ԫ�ص�������
		if (matrix.size() == 0)
			return;
		int i, j;
		bool last_col = false, last_row = false;
		//���һ�к����һ���Ƿ����0����last_col��last_row���
		for (i = 0; i < matrix.size(); i++)
			if (matrix[i][matrix[0].size() - 1] == 0)
				last_col = true;
		for (j = 0; j < matrix[0].size(); j++)
			if (matrix[matrix.size() - 1][j] == 0)
				last_row = true;
		//�����ǰ����0�ڸ������һ��λ�ñ��Ϊinf�������ǰ����0�ڸ������һ��λ�ñ��Ϊinf
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][matrix[0].size() - 1] = inf;
					matrix[matrix.size() - 1][j] = inf;
				}
			}
		}
		//ѭ������matrix�������Ԫ�������л��е����һ��λ��Ϊinf����Ԫ�ر��Ϊ0�����һ�к����һ��Ԫ�ص�������
		for (i = 0; i < matrix.size() - 1; i++)
		{
			for (j = 0; j < matrix[i].size() - 1; j++)
			{
				if (matrix[i][matrix[i].size() - 1] == inf || matrix[matrix.size() - 1][j] == inf)
				{
					matrix[i][j] = 0;
				}
			}
		}
		//���һ�к����һ��Ԫ�ص�������
		for (j = 0; j < matrix[0].size(); j++)
		{
			if (last_row)
				matrix[matrix.size() - 1][j] = 0;
			if (matrix[matrix.size() - 1][j] == inf)
				matrix[matrix.size() - 1][j] = 0;
		}
		for (i = 0; i < matrix.size(); i++)
		{
			if (last_col)
				matrix[i][matrix[0].size() - 1] = 0;
			if (matrix[i][matrix[0].size() - 1] == inf)
				matrix[i][matrix[0].size() - 1] = 0;
		}
	}
};
class Solution1 {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		//����˼�룺����ռ�O(M+N)����������row��col�ֱ���M�к�N�����Ƿ����0�����ڴ���0���к���Ԫ��ȫ����0
		if (matrix.size() == 0)
			return;
		vector<bool> row(matrix.size(), false);
		vector<bool> col(matrix[0].size(), false);
		int i, j;
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == 0)
				{
					row[i] = true;
					col[j] = true;
				}
			}
		}
		for (i = 0; i < matrix.size(); i++)
		{
			for (j = 0; j < matrix[i].size(); j++)
			{
				if (row[i]||col[j])
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = {
		{1,1,1},{0,1,2}
	};
	solute.setZeroes(matrix);
	int i, j;
	for (i = 0; i < matrix.size(); i++)
	{
		for (j = 0; j < matrix[0].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}