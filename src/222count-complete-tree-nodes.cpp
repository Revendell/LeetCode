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
class Solution {
public:
	int countNodes(TreeNode* root) {
		//基本思想：层次遍历，将每一层的节点数加到res
		deque<TreeNode*> queue;
		int res = 0;;
		if (root != nullptr)
		    queue.push_front(root);
		while (!queue.empty())
		{
			int len = queue.size();
			res += len;
			while (len--)
			{
				TreeNode* temp = queue.back();
				queue.pop_back();
				if (temp->left != nullptr)
					queue.push_front(temp->left);
				if (temp->right != nullptr)
					queue.push_front(temp->right);
			}
		}
		return res;
	}
};
class Solution1 {
public:
	int countNodes(TreeNode* root) {
		//基本思想：递归，利用完全二叉树的性质，满二叉树的节点总数是2^k-1
		//分别求左右子树的最大深度
		//如果左右子树深度是一样的话，那么左子树一定是满二叉树，左子树节点数2^leftdepth-1加上根节点就是2^leftdepth
		//如果左子树深度大于右子树深度，那么右子树一定是满二叉树，右子树节点数2^rightdepth-1加上根节点就是2^rightdepth
		if (root == nullptr)
			return 0;
		int leftdepth = depth(root->left);
		int rightdepth = depth(root->right);
		if (leftdepth == rightdepth)
			return pow(2, leftdepth) + countNodes(root->right);
		else
			return pow(2, rightdepth) + countNodes(root->left);
	}
	int depth(TreeNode* root)
	{
		int dep = 0;
		while (root)
		{
			dep++;
			root = root->left;
		}
		return dep;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,4,inf,inf,5,inf,inf,3,6,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.countNodes(root) << endl;
	return 0;
}
