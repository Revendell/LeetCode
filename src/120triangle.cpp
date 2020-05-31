#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		//pre是为了防止数据被覆盖而保存的前一个节点值，也可以从右往左遍历不存在覆盖数据问题
		int cur, pre;
		//res用来保存到当前行的每个数据的最小路径的最和，最后返回res中最小值就是全局最小路径和
		//因为triangle传入的是引用，所以最好不要改变triangle的值，所以申请O(n)的额外空间
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