#include<iostream>
#include<vector>
#include<algorithm>
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
		//基本思想：迭代，利用next指针遍历每一层的所有节点
		//遍历每一层的所有节点，使得该层每个节点的左孩子与右孩子相连(若存在左右孩子)以及该节点的孩子与它兄弟的孩子相连
		Node* p = root;
		while (p != NULL)
		{
			Node* pre = NULL, * q = NULL;
			//利用next找到下一层的第一个节点q
			while (p != NULL)
			{
				if (p->left != NULL || p->right != NULL)
				{
					q = p->left != NULL ? p->left : p->right;
					break;
				}	
				p = p->next;
			}
			if (p == NULL)
				break;
			//找到第一个pre节点，pre指向前一个兄弟的孩子，这个孩子将要与当前节点p的孩子相连
			//如果p有左右孩子，pre指向p的右孩子
			//如果p只有一个孩子，pre指向该孩子
			if (p->left != NULL && p->right != NULL)
			{
				p->left->next = p->right;
				pre = p->right;
			}
			else
				pre = q;
			p = p->next;
			//遍历当前层的所有节点
			while (p != NULL)
			{
				//如果p同时存在左右孩子，左右孩子相连
				//pre是p的前一兄弟的孩子，pre指向p的左孩子
				if (p->left != NULL && p->right != NULL)
				{
					pre->next = p->left;
					p->left->next = p->right;
					pre = p->right;
				}
				else if (p->left != NULL || p->right != NULL)
				{
					pre->next = p->left != NULL ? p->left : p->right;
					pre = pre->next;
				}
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
	Solution solute;
	Node* root = NULL;
	vector<int> vec = { 1,2,4,inf,inf,inf,3,inf,5,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	root = solute.connect(root);
	PreOrderTraverse(root);
	return 0;
}