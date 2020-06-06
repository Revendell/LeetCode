#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>
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
	int res = 0;
	int maxDepth(TreeNode* root) {
		//基本思想：递归，深度优先搜索
		Recursion(root, 0);
		return res;
	}
	void Recursion(TreeNode* root,int depth)
	{
		if (root == NULL)
		{
			if (depth > res)
				res = depth;
		}
		else
		{
			Recursion(root->left, depth + 1);
			Recursion(root->right, depth + 1);
		}
	}
};
class Solution1 {
public:
	int maxDepth(TreeNode* root) {
		//基本思想：迭代，广度优先搜索
		if (root == NULL)
			return 0;
		deque<TreeNode*> queue;
		int depth = 0;
		TreeNode* cur;
		queue.push_back(root);
		while (!queue.empty())
		{
			depth++;
			int len = queue.size();
			for (int i = 0; i < len; i++)
			{
				cur = queue.back();
				queue.pop_back();
				if (cur->left != NULL)
					queue.push_front(cur->left);
				if (cur->right != NULL)
					queue.push_front(cur->right);
			}
		}
		return depth;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 0,2,1,5,inf,inf,7,inf,inf,inf,4,3,inf,6,inf,inf,-1,inf,8,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.maxDepth(root) << endl;
	return 0;
}