#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		//����˼�룺ģ����ת���̣��������ڰ���ģ����ת�����ÿһ�����������
		//�����������������ķ�������Ҫ����Ҫȷ���������������ߵ�λ�ã��ϱ߽����߽綼ΪcntҲ�ǲ������ұ߽�Ϊcol-cnt���±߽�row-cnt
		vector<int> res;
		if (matrix.size() == 0)
			return res;
		int row = matrix.size(), col = matrix[0].size();
		int j, m = row, n = col, cnt = 0;
		//�������ڰ���ģ����ת�����ÿһ�����������
		while (m > 0 && n > 0)
		{
			//����ϱ߽�
			for (j = cnt; j <= col - 1 - cnt; j++)
				res.push_back(matrix[cnt][j]);
			//����ұ߽�
			for (j = cnt + 1; j <= row - 1 - cnt; j++)
				res.push_back(matrix[j][col - 1 - cnt]);
			if (res.size() == col * row)
				return res;
			//����±߽�
			for (j = col - 2 - cnt; j >= cnt; j--)
				res.push_back(matrix[row - 1 - cnt][j]);
			//�����߽�
			for (j = row - 2 - cnt; j > cnt; j--)
				res.push_back(matrix[j][cnt]);
			//����cnt++
			cnt++;
			m -= 2;
			n -= 2;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = {
		{1, 2, 3,4,0} ,
		{5, 6, 7,8,0} ,
		{1, 2, 3,4,0} ,
		{5, 6, 7,8,0} ,
		{9,10,11,12,0} };
	vector<int> res = solute.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}