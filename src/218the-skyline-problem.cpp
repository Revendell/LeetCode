#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//����˼�룺ɨ�����㷨������Ľ���Ĺؼ��ǽ������ʵ����ݽṹ
		//һ��multiset���潨���ĹսǼ���Ӧ�߶ȣ�һ��multiset���浱ǰɨ�����ϵ����н����߶�
		//maxheight����ɨ���������߶ȣ������ǰɨ������maxheight�����ı䣬˵�������յ���뵽res
		//1.��buildings���н��������ҹյ�(�������������ҹյ�)����Ӧ�߶ȱ�����corners
		//2.ɨ��corners�����йյ㣬������յ㣬ɨ����ɨ���ý�������ǰ�����߶ȼ���ɨ���߸߶�heights
		//�����ҹյ㣬ɨ�����뿪�ý�����ɨ���߸߶�heightsȥ����ǰ�����߶�
		//�����ǰɨ���߸߶�Ϊ�գ�˵��û�н����߶��ˣ�Ҳ�ǲ����˹յ㣬ͬʱ����maxheight
		//������Ϊheights�ǰ���С��������õģ������ǰɨ����maxheight������heights���һ���߶ȣ�˵�������յ���뵽res��ͬʱ����maxheight
		vector<vector<int>> res;
		multiset<pair<int, int>> corners;  //corner���潨���ĹսǼ���Ӧ�߶ȣ�����¥�Ĺսǿ����غ�������multiset
		multiset<int> heights;  //heights���浱ǰɨ�����ϵ����н����߶�
		int maxheight;  //����ɨ���������߶�
		for (auto building : buildings)
		{
			corner.insert({ building[0],-building[2] });  //���ֽ��������ҹս�
			corner.insert({ building[1],building[2] });
		}
		maxheight = 0;
		for (auto corner : corners)
		{
			if (corner.second < 0)
				heights.insert(-corner.second);  //������յ㣬ɨ����ɨ���ý�������ǰ�����߶ȼ���ɨ���߸߶�
			else
				heights.erase(heights.find(corner.second));  //�����ҹյ㣬ɨ�����뿪�ý�����ɨ���߸߶�ȥ����ǰ�����߶�
		    //�����ǰɨ���߸߶�Ϊ�գ�˵��û�н����߶��ˣ�Ҳ�ǲ����˹յ㣬ͬʱ����maxheight
			if (heights.begin() == heights.end())
			{
				maxheight = 0;
				res.push_back({ corner.first,maxheight });
			}
			//��Ϊmultiset�ǰ���С��������õģ������ǰɨ����maxheight�����ı䣬˵�������յ���뵽res��ͬʱ����maxheight
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