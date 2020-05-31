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
		//HashMap���ظ����ֵĵ����
		map<vector<int>, int> HashMap;
		for (int i = 0; i < points.size(); i++)
			++HashMap[points[i]];
		int max_points = 0;
		//����ѭ������������ѭ������ȷ��ֱ�ߣ�������һ��ѭ�������������еĵ��Ƿ�������ֱ����
		for (auto i = HashMap.begin(); i != HashMap.end(); i++)
		{
			//����points���е㶼�ظ������
			max_points = max(max_points, (*i).second);
			auto j = i;
			for (j++; j != HashMap.end(); j++)
			{
				int count = (*i).second + (*j).second;
				auto k = j;
				for (k++; k != HashMap.end(); k++)
				{
					//����б���ںܴ����������о�����ʧ���ó˷����ó���
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