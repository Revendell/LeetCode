#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//基本思想：使用HashMap，HashMap记录当前排序后的元素存在res中的下标，如果不存在则新添加入res，下标cnt++
		//循环遍历strs中所有元素，对每个元素str排序后temp看是否存在HashMap中
		//如果不存在加入res和HashMap中，HashMap[temp]=cnt，cnt++，cnt记录排序后元素位于res中的位置下标
		//如果存在就能通过cnt很快找到该元素放入res的位置
		vector<vector<string>> res;
		int cnt = 0;
		string temp;
		map<string, int> HashMap;
		//循环遍历strs中所有元素
		for (auto& str : strs)
		{
			temp = str;
			sort(temp.begin(), temp.end());
			//如果存在HashMap中就能通过cnt很快找到该元素放入res的位置
			if (HashMap.find(temp) != HashMap.end())
			{
				res[HashMap[temp]].push_back(str);
			}
			//如果不存在HashMap中则加入res和HashMap中，HashMap[temp]=cnt，cnt++
			else
			{
				res.push_back({ str });
				HashMap[temp] = cnt++;
			}				
		}
		return res;
	}
};
int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution solute;
	vector<vector<string>> res;
	res = solute.groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}