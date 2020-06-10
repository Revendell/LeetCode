#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//����˼�룺�������򣬸���һ������n���ڵ������ͼG���������Ľڵ��ŵ�һ�����У�������㣺
		//����ͼG�е�����һ�������(u,v)��u�������ж�������v��ǰ�棬�Ƹ�������ͼG����������
		//����˼�룺�����������
		//����һ������queue�����������Ϊ0�Ľڵ����
		//��queue�ǿ�ʱ�����ν����׽ڵ�cur����ͬʱ����res��ִ��numCourses--������cur�����к�̽ڵ����� - 1�������̽ڵ�����Ϊ0��Ҳ��ӡ�
		//�������γ̰���ͼ�������޻�ͼ�������нڵ�һ������Ӳ����ӹ������numCourses = 0��������������򷵻�res��
		//���γ̰���ͼ�д��ڻ�·��һ���нڵ�����ʼ�ղ�Ϊ0�����numCourses > 0������������������򷵻ؿա�
		vector<int> res;
		deque<int> queue;
		multimap<int, int> HashMap;
		vector<int> inDegree(numCourses, 0);
		int cur;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			inDegree[prerequisites[i][1]]++;
			HashMap.insert({ prerequisites[i][0] ,prerequisites[i][1] });
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (inDegree[i] == 0)
				queue.push_front(i);
		}
		while (!queue.empty())
		{
			cur = queue.back();
			res.push_back(cur);
			queue.pop_back();
			numCourses--;
			int cnt = HashMap.count(cur);
			auto iter = HashMap.find(cur);
			while (cnt--)
			{
				inDegree[iter->second]--;
				if (inDegree[iter->second] == 0)
					queue.push_front(iter->second);
				iter++;
			}
		}
		reverse(res.begin(), res.end());
		return (numCourses == 0) ? res : vector<int>{};
	}
};
class Solution1 {
public:
	multimap<int, int> HashMap;    //����ͼ�нڵ��ϵ
	vector<int> res;    //��󷵻ص���������
	vector<int> inDegree;    //����ڵ�����
	vector<int> flags;    //���ÿ���ڵ�i��״̬
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//����˼�룺��������������ж�ͼ���Ƿ��л���ͬʱ�������򱣴���res��
		//����ͼ�нڵ����ȣ������Ϊ0�Ľڵ㿪ʼ����������������������һ���ڵ����εݹ���ýڵ㷵�ر�����res
		//����һ����־�б�flags�������ж�ÿ���ڵ�i��״̬��
		//δ�� DFS ���ʣ�i=0��
		//�ѱ������ڵ������� DFS ���ʣ�i=-1��
		//�ѱ���ǰ�ڵ������� DFS ���ʣ�i=1��
		for (int i = 0; i < numCourses; i++)
		{
			inDegree.push_back(0);
			flags.push_back(0);
		}
		//�������нڵ����ȣ�������HashMap����ڵ��ϵ������ٲ��ҵ�ǰ�ڵ�ĺ�̽ڵ�
		for (int i = 0; i < prerequisites.size(); i++)
		{
			inDegree[prerequisites[i][1]]++;
			HashMap.insert({ prerequisites[i][0],prerequisites[i][1] });
		}
		for (int i = 0; i < numCourses; i++)
		{
			if (inDegree[i] == 0)
			{
				if (dfs(i) == false)
					return {};
			}
		}
		return (res.size() == numCourses) ? res : vector<int>();
	}
	bool dfs(int cur)
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
			if (dfs(iter->second) == false)
				return false;
			iter++;
		}
		res.push_back(cur);
		flags[cur] = -1;
		return true;
	}
};
int main()
{
	Solution1 solute;
	int numCourses = 3;
	vector<vector<int>> prerequisites = { {1,0},{2,0 } };
	vector<int> res = solute.findOrder(numCourses, prerequisites);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}