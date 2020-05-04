#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#define inf 9999
void Init_TreeNode(TreeNode** T, vector<int>& vec, int& pos)
{
	if (vec[pos] == inf || vec.size() == 0)
		*T = NULL;
	else
	{
		(*T) = new TreeNode(0);
		(*T)->val = vec[pos];
		Init_TreeNode(&(*T)->left, vec, ++pos);
		Init_TreeNode(&(*T)->right, vec, ++pos);
	}
}
void PreOrderTraverse(TreeNode* T)
{
	if (T == NULL)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);
}
class Solution {
public:
	void flatten(TreeNode* root) {
		//基本思想：类似单链表基本操作，p表示当前处理的节点，q指向p的左子树的最右边节点
		//将p的左子树插入到p的右子树的地方
		//将p原来的右子树接到p的左子树的最右边节点
		//考虑新的右子树的根节点p = p->right，一直重复上边的过程，直到新的右子树为 null
		TreeNode* p, * q;
		p = root;
		while (p != NULL)
		{
			if (p->left == NULL)
				p = p->right;
			else
			{
				//找到q的位置，q指向p的左子树的最右边节点
				q = p->left;
				while (q->right != NULL)
					q = q->right;
				//q的右孩子指向p的右子树
				q->right = p->right;
				//p的右孩子指向p的左子树
				p->right = p->left;
				//p的左孩子指向NULL
				p->left = NULL;
				//考虑新的右子树的根节点
				p = p->right;
			}			
		}
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,3,4,inf,inf,inf,inf,5,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	solute.flatten(root);
	PreOrderTraverse(root);
	return 0;
}