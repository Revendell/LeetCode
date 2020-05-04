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
	int minDepth(TreeNode* root) {
		//基本思想：递归找到最小深度，注意只有左右孩子都为空的节点才是路径的终点，否则不是
		return Recursion(root);
	}
	int Recursion(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		//对于root只有一个孩子的情况考虑，只有左右孩子都为空的节点才是路径的终点
		if (root->left != NULL&& root->right==NULL)
		{
			return Recursion(root->left) + 1;
		}
		if (root->right != NULL && root->left == NULL)
		{
			return Recursion(root->right) + 1;
		}
		return min(Recursion(root->left), Recursion(root->right)) + 1;	
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,2,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.minDepth(root) << endl;
	return 0;
}