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
		//基本思想：拓扑排序，本题简化为课程安排中是否是有向无环图(DAG)，是否存在环路
		//拓扑排序原理： 对DAG的顶点进行排序，使得对每一条有向边(u,v)，均有u比v先出现。
		//亦可理解为对某点v而言，只有当v的所有源点均出现了v才能出现。
		//基本思想：入度表广度优先搜索，借助一个队列queue，将所有入度为0的节点入队，
		//当 queue非空时，依次将队首节点cur出队，执行numCourses--
		//并将cur的所有后继节点post的入度-1，如果post的入度为0则post入队
		//若整个课程安排图是有向无环图，则所有节点一定都入队并出队过，最后numCourses=0，即完成拓扑排序。
		//若课程安排图中存在环路，一定有节点的入度始终不为0，最后numCourses>0，即不能完成拓扑排序。
		multimap<int, int> HashMap;
		unordered_map<int, int> inDegree;
		deque<int> queue;
		//计算所有节点的入度，并建立HashMap保存节点关系方便快速查找当前节点的后继节点
		for (int i = 0; i < prerequisites.size(); i++)
		{
			++inDegree[prerequisites[i][1]];
			HashMap.insert({prerequisites[i][0],prerequisites[i][1]});
		}
		//将所有入度为0的节点入队列
		for (int i = 0; i < numCourses; i++)
		{
			if (inDegree.find(i) == inDegree.end())
				queue.push_front(i);
		}
		//cur为当前入度为0的节点，post为cur的后继节点
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
		//基本思想：深度优先搜索，判断图中是否有环。
		//一开始的想法是通过set判断图中是否有环，遍历所有节点，以该节点为起点，深度优先搜索加入set
		//如果最后发现set出现重复节点说明有环，这个时间复杂度很高O(n^2)，因为产生了很多重复的搜索
		//优化方法：借助一个标志列表flags，用于判断每个节点i的状态：
		//未被 DFS 访问：i=0；
		//已被其他节点启动的 DFS 访问：i=-1；
		//已被当前节点启动的 DFS 访问：i=1。
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