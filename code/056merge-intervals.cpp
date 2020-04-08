#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//����˼�룺����+˫ָ�룬����������ռ��Ͻ��и��ֲ�������Ŀ��һ���������˫ָ����н��
		//��������intervals��ָ��iָ����ǰԪ�ز��ܺϲ���Ԫ���±꣬ͨ��ָ��jѰ��i��������i�ϲ���Ԫ�أ�Ѱ�ҹ����в��ϸ������Χ[left,right]��ֱ���Ҳ������Ժϲ���Ԫ����j��ֵ��i��Ϊ��һ����ǰԪ�ز��ܺϲ���Ԫ���±꣬[left,right]������res
		vector<vector<int>> res;
		int i, j, left, right;
		sort(intervals.begin(), intervals.end());
		i = 0;
		while (i < intervals.size())
		{			
			left = intervals[i][0];
			right = intervals[i][1];
			j = i + 1;
			while (j < intervals.size())
			{
				if (intervals[i][1] >= intervals[j][0])
				{
					left = min(left, intervals[j][0]);
					right = max(left, intervals[j][1]);
				}
				else
					break;
				j++;
			}
			res.push_back({ left,right });
			i = j;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> intervals = {
		{1,3},{2,6},{8,10},{15,18}
	};
	vector<vector<int>> res;
	res = solute.merge(intervals);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}