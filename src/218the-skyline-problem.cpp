#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//基本思想：扫描线算法，问题的解决的关键是建立合适的数据结构
		//一个multiset保存建筑的拐角及对应高度，一个multiset保存当前扫描线上的所有建筑高度
		//maxheight保存扫描线上最大高度，如果当前扫描线上maxheight发生改变，说明产生拐点加入到res
		//1.将buildings所有建筑中左右拐点(用正负区分左右拐点)及对应高度保存至corners
		//2.扫描corners中所有拐点，遇到左拐点，扫描线扫到该建筑，当前建筑高度加入扫描线高度heights
		//遇到右拐点，扫描线离开该建筑，扫描线高度heights去除当前建筑高度
		//如果当前扫描线高度为空，说明没有建筑高度了，也是产生了拐点，同时更新maxheight
		//或者因为heights是按从小到大排序好的，如果当前扫描线maxheight不等于heights最后一个高度，说明产生拐点加入到res，同时更新maxheight
		vector<vector<int>> res;
		multiset<pair<int, int>> corners;  //corner保存建筑的拐角及对应高度，两栋楼的拐角可能重合所以用multiset
		multiset<int> heights;  //heights保存当前扫描线上的所有建筑高度
		int maxheight;  //保存扫描线上最大高度
		for (auto building : buildings)
		{
			corner.insert({ building[0],-building[2] });  //区分建筑的左右拐角
			corner.insert({ building[1],building[2] });
		}
		maxheight = 0;
		for (auto corner : corners)
		{
			if (corner.second < 0)
				heights.insert(-corner.second);  //遇到左拐点，扫描线扫到该建筑，当前建筑高度加入扫描线高度
			else
				heights.erase(heights.find(corner.second));  //遇到右拐点，扫描线离开该建筑，扫描线高度去除当前建筑高度
		    //如果当前扫描线高度为空，说明没有建筑高度了，也是产生了拐点，同时更新maxheight
			if (heights.begin() == heights.end())
			{
				maxheight = 0;
				res.push_back({ corner.first,maxheight });
			}
			//因为multiset是按从小到大排序好的，如果当前扫描线maxheight发生改变，说明产生拐点加入到res，同时更新maxheight
			else if(maxheight != *heights.rbegin())
			{
				maxheight = *heights.rbegin();
				res.push_back({ corner.first,maxheight });
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> buildings = {
		{2, 9, 10} ,{3, 7, 15},{5, 12, 12},{15, 20, 10},{19, 24, 8}
	};
	vector<vector<int>> res = solute.getSkyline(buildings);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v.front() << " " << v.back() << endl; });
	return 0;
}