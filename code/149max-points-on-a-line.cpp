#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() <= 2)
			return points.size();
		//HashMap对重复出现的点计数
		map<vector<int>, int> HashMap;
		for (int i = 0; i < points.size(); i++)
			++HashMap[points[i]];
		int max_points = 0;
		//三重循环，外面两重循环两点确定直线，最里面一重循环遍历其他所有的点是否在这条直线上
		for (auto i = HashMap.begin(); i != HashMap.end(); i++)
		{
			//对于points所有点都重复的情况
			max_points = max(max_points, (*i).second);
			auto j = i;
			for (j++; j != HashMap.end(); j++)
			{
				int count = (*i).second + (*j).second;
				auto k = j;
				for (k++; k != HashMap.end(); k++)
				{
					//避免斜率在很大的数相除会有精度损失，用乘法不用除法
					if (long(((*i).first.back() - (*j).first.back()) * ((*k).first.front() - (*i).first.front())) == long(((*i).first.front() - (*j).first.front()) * ((*k).first.back() - (*i).first.back())))
						count += (*k).second;
				}
				max_points = max(max_points, count);
			}
		}
		return max_points;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> points = {{0,0},{0,-1},{0,-1}};
	cout << solute.maxPoints(points) << endl;
	return 0;
}