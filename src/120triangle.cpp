#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//pre��Ϊ�˷�ֹ���ݱ����Ƕ������ǰһ���ڵ�ֵ��Ҳ���Դ���������������ڸ�����������
		int cur, pre;
		//res�������浽��ǰ�е�ÿ�����ݵ���С·������ͣ���󷵻�res����Сֵ����ȫ����С·����
		//��Ϊtriangle����������ã�������ò�Ҫ�ı�triangle��ֵ����������O(n)�Ķ���ռ�
		vector<int> res(triangle.size(), 0);
		int i, j;
		for (i = 0; i < triangle.size(); i++)
		{
			for (j = 0; j < triangle[i].size(); j++)
			{
				cur = res[j];
				if (j == 0)
					res[j] += triangle[i][j];
				else if (j == triangle[i].size() - 1)
					res[j] = triangle[i][j] + pre;
				else
					res[j] = min(res[j], pre) + triangle[i][j];
				pre = cur;
			}
		}
		return *min_element(res.begin(), res.end());
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> triangle = {
		{2} ,
        {3,4},
        {6,5,7},
        {40,100,80,3}
	};
	cout << solute.minimumTotal(triangle) << endl;
	return 0;
}