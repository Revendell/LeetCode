#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
void Init_Node(Node* head, vector<int> vec, unordered_map<int, Node*> &HashMap)
{
	if (vec.size() == 0)
	{
		head = NULL;
		return;
	}
	Node* p = head;
	p->val = vec[0];
	HashMap[p->val] = p;
	for (int i = 1; i < vec.size(); i++)
	{
		Node* q = new Node(vec[i]);
		p->next = q;
		p = p->next;
		HashMap[p->val] = p;
	}
	p->next = NULL;
}
class Solution {
public:
	unordered_map<Node*, Node*> HashMap;  //����ɽڵ��������ɵĽڵ�֮��ӳ��
	Node* copyRandomList(Node* head) {
		//����˼�룺�ݹ�+HashMap
		if (head == NULL)
			return NULL;
		//�Ѿ����ɵĽڵ㲻������
		if (HashMap.find(head) != HashMap.end())
			return HashMap[head];
		Node* cur = new Node(head->val);
		HashMap[head] = cur;
		//������ɽڵ������ӵĽڵ�ݹ�����
		if (head->next != NULL)
			cur->next = copyRandomList(head->next);
		if (head->random != NULL)
			cur->random = copyRandomList(head->random);
		return cur;
	}
};
int main()
{
	Solution solute;
	Node* head = new Node(0);
	unordered_map<int, Node*> HashMap;
	vector<int> vec = { 7,13,11,10,1 };
	//��ʼ������
	Init_Node(head, vec, HashMap);
	HashMap[13]->random = NULL;
	HashMap[13]->random = HashMap[7];
	HashMap[11]->random = HashMap[1];
	HashMap[10]->random = HashMap[11];
	HashMap[1]->random = HashMap[7];
	Node *p = solute.copyRandomList(head);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}