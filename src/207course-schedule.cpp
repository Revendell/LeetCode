#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<deque>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//����˼�룺�������򣬱����Ϊ�γ̰������Ƿ��������޻�ͼ(DAG)���Ƿ���ڻ�·
		//��������ԭ�� ��DAG�Ķ����������ʹ�ö�ÿһ�������(u,v)������u��v�ȳ��֡�
		//������Ϊ��ĳ��v���ԣ�ֻ�е�v������Դ���������v���ܳ��֡�
		//����˼�룺��ȱ�����������������һ������queue�����������Ϊ0�Ľڵ���ӣ�
		//�� queue�ǿ�ʱ�����ν����׽ڵ�cur���ӣ�ִ��numCourses--
		//����cur�����к�̽ڵ�post�����-1�����post�����Ϊ0��post���
		//�������γ̰���ͼ�������޻�ͼ�������нڵ�һ������Ӳ����ӹ������numCourses=0���������������
		//���γ̰���ͼ�д��ڻ�·��һ���нڵ�����ʼ�ղ�Ϊ0�����numCourses>0�������������������
		multimap<int, int> HashMap;
		unordered_map<int, int> inDegree;
		deque<int> queue;
		//�������нڵ����ȣ�������HashMap����ڵ��ϵ������ٲ��ҵ�ǰ�ڵ�ĺ�̽ڵ�
		for (int i = 0; i < prerequisites.size(); i++)
		{
			++inDegree[prerequisites[i][1]];
			HashMap.insert({prerequisites[i][0],prerequisites[i][1]});
		}
		//���������Ϊ0�Ľڵ������
		for (int i = 0; i < numCourses; i++)
		{
			if (inDegree.find(i) == inDegree.end())
				queue.push_front(i);
		}
		//curΪ��ǰ���Ϊ0�Ľڵ㣬postΪcur�ĺ�̽ڵ�
		int cur, post;
		while (!queue.empty())
		{
			cur = queue.back();
			queue.pop_back();
			numCourses--;
			int cnt = HashMap.count(cur);
			auto iter = HashMap.find(cur);
			while (cnt--)
			{
				post = iter->second;
				inDegree[post]--;
				if (inDegree[post] == 0)
					queue.push_front(post);
				iter++;
			}
		}
		return numCourses == 0;
	}
};
class Solution1 {
public:
	multimap<int, int> HashMap;
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//����˼�룺��������������ж�ͼ���Ƿ��л���
		//һ��ʼ���뷨��ͨ��set�ж�ͼ���Ƿ��л����������нڵ㣬�Ըýڵ�Ϊ��㣬���������������set
		//��������set�����ظ��ڵ�˵���л������ʱ�临�ӶȺܸ�O(n^2)����Ϊ�����˺ܶ��ظ�������
		//�Ż�����������һ����־�б�flags�������ж�ÿ���ڵ�i��״̬��
		//δ�� DFS ���ʣ�i=0��
		//�ѱ������ڵ������� DFS ���ʣ�i=-1��
		//�ѱ���ǰ�ڵ������� DFS ���ʣ�i=1��
		vector<int> flags(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); i++)
		{
			HashMap.insert({ prerequisites[i][0],prerequisites[i][1] });
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (dfs(flags, i) == false)
				return false;
		}
		return true;
	}
	bool dfs(vector<int> &flags,int cur)
	{
		if (flags[cur] == -1)
			return true;
		if (flags[cur] == 1)
			return false;
		flags[cur] = 1;
		int cnt = HashMap.count(cur);
		auto iter = HashMap.find(cur);
		while (cnt--)
		{
			if (dfs(flags, iter->second) == false)
				return false;
			iter++;
		}
		flags[cur] = -1;
		return true;
	}
};
int main()
{
	Solution1 solute;
	int numCourses = 5;
	vector<vector<int>> prerequisites = { {0,1}, {4,2},{1,2},{1,3}, {2,3},{3,0} };
	cout << solute.canFinish(numCourses, prerequisites) << endl;
	return 0;
}