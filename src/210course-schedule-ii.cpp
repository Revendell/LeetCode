#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//基本思想：拓扑排序，给定一个包含n个节点的有向图G，给出它的节点编号的一种排列，如果满足：
		//对于图G中的任意一条有向边(u,v)，u在排列中都出现在v的前面，称该排列是图G的拓扑排序。
		//基本思想：广度优先搜索
		//借助一个队列queue，将所有入度为0的节点入队
		//当queue非空时，依次将队首节点cur出队同时加入res，执行numCourses--，并将cur的所有后继节点的入度 - 1，如果后继节点的入度为0则也入队。
		//若整个课程安排图是有向无环图，则所有节点一定都入队并出队过，最后numCourses = 0，即完成拓扑排序返回res。
		//若课程安排图中存在环路，一定有节点的入度始终不为0，最后numCourses > 0，即不能完成拓扑排序返回空。
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
	multimap<int, int> HashMap;    //保存图中节点关系
	vector<int> res;    //最后返回的拓扑排序
	vector<int> inDegree;    //计算节点的入度
	vector<int> flags;    //标记每个节点i的状态
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		//基本思想：深度优先搜索，判断图中是否有环的同时拓扑排序保存至res。
		//计算图中节点的入度，从入度为0的节点开始深度优先搜索，搜索到最后一个节点依次递归调用节点返回保存至res
		//借助一个标志列表flags，用于判断每个节点i的状态：
		//未被 DFS 访问：i=0；
		//已被其他节点启动的 DFS 访问：i=-1；
		//已被当前节点启动的 DFS 访问：i=1。
		for (int i = 0; i < numCourses; i++)
		{
			inDegree.push_back(0);
			flags.push_back(0);
		}
		//计算所有节点的入度，并建立HashMap保存节点关系方便快速查找当前节点的后继节点
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