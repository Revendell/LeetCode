#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};
#define inf 9999
void Init_TreeNode(Node** T, vector<int>& vec, int& pos)
{
	if (vec[pos] == inf || vec.size() == 0)
		*T = NULL;
	else
	{
		(*T) = new Node(0);
		(*T)->val = vec[pos];
		(*T)->next = NULL;
		Init_TreeNode(&(*T)->left, vec, ++pos);
		Init_TreeNode(&(*T)->right, vec, ++pos);
	}
}
void PreOrderTraverse(Node* T)
{
	if (T == NULL)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);
}
class Solution {
public:
	Node* connect(Node* root) {
		//����˼�룺�ݹ�
		Recursion(root);
		return root;
	}
	void Recursion(Node* root)
	{
		if (root == NULL)
			return;
		//root��������root���Һ�������
		if (root->left != NULL)
			root->left->next = root->right;
		//root���Һ�����root�ֵܵ���������
		if (root->next != NULL && root->right != NULL)
			root->right->next = root->next->left;
		Recursion(root->left);
		Recursion(root->right);
	}
};
class Solution1 {
public:
	Node* connect(Node* root) {
		//����˼�룺����������nextָ�����ÿһ������нڵ�
		//����ÿһ������нڵ㣬ʹ�øò�ÿ���ڵ���������Һ��������Լ��ýڵ���Һ��������ֵܵ���������
		Node* p = root;
		while (p != NULL)
		{
			//������һ��ĵ�һ���ڵ�
			Node* q = p->left;
			//������ǰ������нڵ�
			while (p != NULL)
			{
				//p��������p���Һ�������
				if (p->left != NULL)
					p->left->next = p->right;
				//p���Һ�����p�ֵܵ���������
				if (p->next != NULL && p->right != NULL)
					p->right->next = p->next->left;
				//���ʵ�ǰ����һ���ڵ�
				p = p->next;
			}
			//pָ����һ��ĵ�һ���ڵ�
			p = q;
		}
		return root;
	}
};
int main()
{
	Solution1 solute;
	Node* root = NULL;
	vector<int> vec = { 1,2,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	root = solute.connect(root);
	PreOrderTraverse(root);
	return 0;
}