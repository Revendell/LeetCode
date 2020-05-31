#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		//����˼�룺ģ����ת���̣��������ڰ���ģ����ת�����ÿһ����������ߡ�
		//�����������������ķ�������Ҫ����Ҫȷ���������������ߵ�λ�ã��ϱ߽����߽綼ΪlayerҲ�ǲ������ұ߽���±߽綼Ϊn-layer��
		vector<vector<int>> res(n, vector<int>(n, 0));
		//cntΪ��������ִ�1��n^2
		int cnt = 1, layer = 0, i, m = n;
		//�������ڰ���ģ����ת�����ÿһ�����������
		while (m > 0)
		{
			//����ϱ߽�
			for (i = layer; i < n - layer; i++)
				res[layer][i] = cnt++;
			//����ұ߽�
			for (i = layer + 1; i < n - layer; i++)
				res[i][n - layer - 1] = cnt++;
			//����±߽�
			for (i = n - layer - 2; i >= layer; i--)
				res[n - layer - 1][i] = cnt++;
			//�����߽�
			for (i = n - layer - 2; i > layer; i--)
				res[i][layer] = cnt++;
			layer++;
			m -= 2;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	int n = 5;
	vector<vector<int>> res;
	res = solute.generateMatrix(n);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}