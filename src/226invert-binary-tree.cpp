#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
	TreeNode* invertTree(TreeNode* root) {
		//基本思想：递归
		Recursion(root);
		return root;
	}
	void Recursion(TreeNode* root)
	{
		if (root == nullptr)
			return;
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		Recursion(root->left);
		Recursion(root->right);
	}
};
class Solution1 {
public:
	TreeNode* invertTree(TreeNode* root) {
		//基本思想：迭代
		if (root == nullptr)
			return nullptr;
		deque<TreeNode*> queue;
		queue.push_front(root);
		while (!queue.empty())
		{
			TreeNode* cur = queue.back();
			queue.pop_back();
			TreeNode* temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;
			if (cur->left != nullptr)
				queue.push_front(cur->left);
			if (cur->right != nullptr)
				queue.push_front(cur->right);
		}
		return root;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,4,inf,inf,5,inf,inf,3,6,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	root = solute.invertTree(root);
	PreOrderTraverse(root);
	return 0;
}