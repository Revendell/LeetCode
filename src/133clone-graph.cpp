#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
void InitGraph(Node* node, vector<int> vec)
{
	vector<Node*> graph;
	graph.push_back(node);
	for (int i = 1; i < vec.size(); i++)
	{
		Node* n = new Node(vec[i]);
		graph.push_back(n);
	}
	graph[0]->neighbors = { graph[1],graph[3] };
	graph[1]->neighbors = { graph[0],graph[2] };
	graph[2]->neighbors = { graph[1],graph[3] };
	graph[3]->neighbors = { graph[0],graph[2] };
}
class Solution {
public:
	unordered_map<Node*, bool> visited;    //标记旧图中节点是否访问过
	unordered_map<int, Node*> HashMap;    //保存生成的新节点，val和node映射
	Node* cloneGraph(Node* node) {
		//基本思想：递归+HashMap，先递归生成新节点保存在HashMap中，然后递归将生成的新节点连接起来成新图
		if (node == NULL)
			return NULL;
		//递归生成新节点保存在HashMap中
		CreateHashMap(node);
		Node* newNode = HashMap[node->val];
		//递归将生成的新节点连接起来成新图
		CloneNode(node, &newNode);
		return newNode;
	}
	void CreateHashMap(Node* node)
	{
		if (visited.find(node) == visited.end())
		{
			visited[node] = false;
			Node* temp = new Node(node->val);
			HashMap[temp->val] = temp;
		}	
		else
			return;
		for (auto i = node->neighbors.begin(); i != node->neighbors.end(); i++)
		{
			CreateHashMap(*i);
		}
	}
	void CloneNode(Node* node,Node** newNode)
	{
		if (visited[node] == false)
		{
			visited[node] = true;
			for (auto i = node->neighbors.begin(); i != node->neighbors.end(); i++)
			{
				(*newNode)->neighbors.push_back(HashMap[(*i)->val]);	
				CloneNode(*i, &HashMap[(*i)->val]);
			}
		}
	}
};
class Solution1 {
public:
	unordered_map<Node*, Node*> HashMap;    //保存旧节点与新生成的节点之间映射
	Node* cloneGraph(Node* node) {
		//优化版本：这道题充分说明建立好的数据结构对解决问题事半功倍
		//上面的想法是自己想出来的，建立的是val与node的HashMap，导致代码不够简洁，这是参考别人的想法
		if (node == NULL)
			return NULL;
		//已经生成的节点不再生成
		if (HashMap.find(node) != HashMap.end())
			return HashMap[node];
		Node* newNode = new Node(node->val);
		HashMap[node] = newNode;
		//生成与node相连接的节点
		for (auto i = node->neighbors.begin(); i != node->neighbors.end(); i++)
		{
			newNode->neighbors.push_back(cloneGraph(*i));
		}
		return newNode;
	}
};
int main()
{
	Solution1 solute;
	vector<int> vec = { 1,2,3,4 };
	Node* node = new Node(1);
	InitGraph(node, vec);
	node = solute.cloneGraph(node);
	cout << node->val << endl;
	for (auto n = node->neighbors.begin(); n != node->neighbors.end(); n++)
	{
		cout << (*n)->val << endl;
		cout << (*n)->neighbors.front()->val << endl;
		cout << (*n)->neighbors.back()->val << endl;
	}
		
	return 0;
}