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
	unordered_map<Node*, bool> visited;    //��Ǿ�ͼ�нڵ��Ƿ���ʹ�
	unordered_map<int, Node*> HashMap;    //�������ɵ��½ڵ㣬val��nodeӳ��
	Node* cloneGraph(Node* node) {
		//����˼�룺�ݹ�+HashMap���ȵݹ������½ڵ㱣����HashMap�У�Ȼ��ݹ齫���ɵ��½ڵ�������������ͼ
		if (node == NULL)
			return NULL;
		//�ݹ������½ڵ㱣����HashMap��
		CreateHashMap(node);
		Node* newNode = HashMap[node->val];
		//�ݹ齫���ɵ��½ڵ�������������ͼ
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
	unordered_map<Node*, Node*> HashMap;    //����ɽڵ��������ɵĽڵ�֮��ӳ��
	Node* cloneGraph(Node* node) {
		//�Ż��汾���������˵�������õ����ݽṹ�Խ�������°빦��
		//������뷨���Լ�������ģ���������val��node��HashMap�����´��벻����࣬���ǲο����˵��뷨
		if (node == NULL)
			return NULL;
		//�Ѿ����ɵĽڵ㲻������
		if (HashMap.find(node) != HashMap.end())
			return HashMap[node];
		Node* newNode = new Node(node->val);
		HashMap[node] = newNode;
		//������node�����ӵĽڵ�
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