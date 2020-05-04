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
	bool hasPathSum(TreeNode* root, int sum) {
		//基本思想：递归，递归遍历所有二叉树路径是否有一条路径和等于sum
		if (root == NULL)
			return false;
		return Recursion(root, sum, 0);
	}
	bool Recursion(TreeNode* root, int sum, int pre_sum)
	{
		//终止条件：root为叶子节点
		if (root->right==NULL && root->left==NULL)
		{
			//如果之前节点值和+当前节点值=sum，返回true
			if (sum == pre_sum + root->val)
				return true;
			else
				return false;
		}
		//递归右子树
		if (root->right != NULL && Recursion(root->right, sum, pre_sum + root->val))
			return true;
		//递归左子树
		if (root->left != NULL && Recursion(root->left, sum, pre_sum + root->val))
			return true;
		//递归遍历所有情况都不存在一条路径和等于sum，返回false
		return false;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,2,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	int sum = 7;
	cout << solute.hasPathSum(root, sum) << endl;
	return 0;
}