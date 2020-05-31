#include<iostream>
#include<vector>
#include<algorithm>
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
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		//基本思想：自顶向下递归，不断比较以root为根的左右子树的高度差是否大于1
		return Recursion(root);
	}
	bool Recursion(TreeNode* root)
	{
		if (root == NULL)
			return true;
		//计算左右子树的高度差是否大于1
		if (abs(depth(root->left) - depth(root->right)) > 1)
			return false;
		return Recursion(root->left) && Recursion(root->right);
	}
	//递归计算root为根的二叉树的高度
	int depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,2,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.isBalanced(root)<< endl;
	return 0;
}