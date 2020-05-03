#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//基本思想：递归，不断以根节点拆分出左子树的前序中序和右子树的前序中序，继续递归，直至生成整棵树
		//左子树的前序中序为preorder_left、inorder_left
		//右子树的前序中序为preorder_right、inorder_right
		if (preorder.size() == 0)
			return NULL;
		TreeNode* root = NULL;
		Recursion(preorder, inorder, &root);
		return root;

	}
	void Recursion(vector<int> preorder, vector<int> inorder, TreeNode** root)
	{
		int i, j;
		(*root) = new TreeNode(preorder[0]);
		//找到中序遍历的分隔点，也就是前序遍历的第一个节点，将树拆分成左右子树
		for (i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == preorder[0])
				break;
		}
		vector<int> preorder_left, preorder_right;
		vector<int> inorder_left, inorder_right;
		//得到左子树的前序中序为preorder_left、inorder_left
		for (j = 1; j <= i; j++)
		{
			preorder_left.push_back(preorder[j]);
			inorder_left.push_back(inorder[j - 1]);
		}
		//得到右子树的前序中序为preorder_right、inorder_right
		for (j = i + 1; j < preorder.size(); j++)
		{
			preorder_right.push_back(preorder[j]);
			inorder_right.push_back(inorder[j]);
		}
		//继续递归左右子树，直至生成整棵树
		if (preorder_left.size() > 0)
			Recursion(preorder_left, inorder_left, &(*root)->left);
		if (preorder_right.size() > 0)
			Recursion(preorder_right, inorder_right, &(*root)->right);
	}
};
int main()
{
	Solution solute;
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode* root = solute.buildTree(preorder,inorder);
	PreOrderTraverse(root);
	return 0;
}