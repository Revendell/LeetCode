#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		//�����·�תȻ��ԽǷ�ת
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++)
            swap(matrix[i],matrix[n-1-i]);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//����˼�룺�ҹ��ɣ�ģ����ת���̣���������һ��һ��ѭת�ܹ�����Ϊmatrix.size()/2��ÿһ�����ָ���Ϊ(k-2)*4��ѭ��k-2�Σ�ÿ��ѭת4������
		int i, j, temp, k;
		if (matrix.size() == 1 || matrix.size() == 0)
			return;
		//��������һ��һ��ѭת�ܹ�����Ϊmatrix.size()/2��ÿһ�����ָ���Ϊ(k-2)*4
		for (i = 0, k = matrix.size(); i != matrix.size() - 1 && i != matrix.size(); i = i + 2, k = k - 2)
		{
			//ÿһ�����ָ���Ϊ(k-2)*4����ÿһ��ѭ��k-2��
			for (j = 0; j < k-1; j++)
			{
				//ÿ��ѭת4�����֣��ĸ�������������i/2Ϊ������jΪ�ò�ڼ�������
				temp = matrix[i / 2][i / 2 + j];
				matrix[i / 2][i / 2 + j] = matrix[matrix.size() - 1 - i / 2 - j][i / 2];
				matrix[matrix.size() - 1 - i / 2 - j][i / 2] = matrix[matrix.size() - 1 - i / 2][matrix.size() - 1 - i / 2 - j];
				matrix[matrix.size() - 1 - i / 2][matrix.size() - 1 - i / 2 - j] = matrix[i / 2 + j][matrix.size() - 1 - i / 2];
				matrix[i / 2 + j][matrix.size() - 1 - i / 2] = temp;
			}
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> matrix = { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} };
	solute.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}