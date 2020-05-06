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
		//����˼�룺����������nextָ�����ÿһ������нڵ�
		//����ÿһ������нڵ㣬ʹ�øò�ÿ���ڵ���������Һ�������(���������Һ���)�Լ��ýڵ�ĺ��������ֵܵĺ�������
		Node* p = root;
		while (p != NULL)
		{
			Node* pre = NULL, * q = NULL;
			//����next�ҵ���һ��ĵ�һ���ڵ�q
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
			//�ҵ���һ��pre�ڵ㣬preָ��ǰһ���ֵܵĺ��ӣ�������ӽ�Ҫ�뵱ǰ�ڵ�p�ĺ�������
			//���p�����Һ��ӣ�preָ��p���Һ���
			//���pֻ��һ�����ӣ�preָ��ú���
			if (p->left != NULL && p->right != NULL)
			{
				p->left->next = p->right;
				pre = p->right;
			}
			else
				pre = q;
			p = p->next;
			//������ǰ������нڵ�
			while (p != NULL)
			{
				//���pͬʱ�������Һ��ӣ����Һ�������
				//pre��p��ǰһ�ֵܵĺ��ӣ�preָ��p������
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
			//pָ����һ��ĵ�һ���ڵ�
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