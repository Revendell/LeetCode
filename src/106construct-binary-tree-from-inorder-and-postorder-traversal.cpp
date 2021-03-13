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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//简化版：递归，通过中序遍历序列找到根节点将中序遍历序列分割成左右子树，继续递归
		TreeNode* root = NULL;
		Recursion(inorder, postorder, root);
		return root;
	}
	void Recursion(vector<int> inorder, vector<int> postorder, TreeNode* &root)
	{
		if(inorder.size()==0)
			return;
		int i;
		for(i=0;i<inorder.size();i++)
		{
			if(inorder[i]==postorder[postorder.size()-1])
				break;
		}
		root=new TreeNode(postorder[postorder.size()-1]);
		Recursion(vector<int>(inorder.begin(),inorder.begin()+i),vector<int>(postorder.begin(),postorder.begin()+i),root->left);
		Recursion(vector<int>(inorder.begin()+i+1,inorder.end()),vector<int>(postorder.begin()+i,postorder.end()-1),root->right);
	}
};
class Solution1 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//基本思想：递归，不断以根节点拆分出左子树的后序中序和右子树的后序中序，继续递归，直至生成整棵树
		//左子树的后序中序为postorder_left、inorder_left
		//右子树的后序中序为postorder_right、inorder_right
		if (postorder.size() == 0)
			return NULL;
		TreeNode* root = NULL;
		Recursion(inorder, postorder, &root);
		return root;
	}
	void Recursion(vector<int> inorder, vector<int> postorder, TreeNode** root)
	{
		int i, j;
		(*root) = new TreeNode(postorder[postorder.size() - 1]);
		//找到中序遍历的分隔点，也就是后序遍历的最后一个节点，将树拆分成左右子树
		for (i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == postorder[postorder.size() - 1])
				break;
		}
		vector<int> postorder_left, postorder_right;
		vector<int> inorder_left, inorder_right;
		//得到左子树的后序中序为postorder_left、inorder_left
		for (j = 0; j < i; j++)
		{
			postorder_left.push_back(postorder[j]);
			inorder_left.push_back(inorder[j]);
		}
		//得到右子树的后序中序为postorder_right、inorder_right
		for (j = i + 1; j < postorder.size(); j++)
		{
			postorder_right.push_back(postorder[j - 1]);
			inorder_right.push_back(inorder[j]);
		}
		//继续递归左右子树，直至生成整棵树
		if (postorder_left.size() > 0)
			Recursion(inorder_left,postorder_left, &(*root)->left);
		if (postorder_right.size() > 0)
			Recursion(inorder_right,postorder_right, &(*root)->right);
	}
};
int main()
{
	Solution solute;
	vector<int> inorder = { 3,9 };
	vector<int> postorder = { 3,9 };
	TreeNode* root = solute.buildTree(inorder, postorder);
	PreOrderTraverse(root);
	return 0;
}