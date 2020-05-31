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
		//基本思想：递归
		Recursion(root);
		return root;
	}
	void Recursion(Node* root)
	{
		if (root == NULL)
			return;
		//root的左孩子与root的右孩子相连
		if (root->left != NULL)
			root->left->next = root->right;
		//root的右孩子与root兄弟的左孩子相连
		if (root->next != NULL && root->right != NULL)
			root->right->next = root->next->left;
		Recursion(root->left);
		Recursion(root->right);
	}
};
class Solution1 {
public:
	Node* connect(Node* root) {
		//基本思想：迭代，利用next指针遍历每一层的所有节点
		//遍历每一层的所有节点，使得该层每个节点的左孩子与右孩子相连以及该节点的右孩子与它兄弟的左孩子相连
		Node* p = root;
		while (p != NULL)
		{
			//保存下一层的第一个节点
			Node* q = p->left;
			//遍历当前层的所有节点
			while (p != NULL)
			{
				//p的左孩子与p的右孩子相连
				if (p->left != NULL)
					p->left->next = p->right;
				//p的右孩子与p兄弟的左孩子相连
				if (p->next != NULL && p->right != NULL)
					p->right->next = p->next->left;
				//访问当前层下一个节点
				p = p->next;
			}
			//p指向下一层的第一个节点
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