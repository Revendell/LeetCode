#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
#define inf 9999
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void Init_TreeNode(TreeNode** T, vector<int>& vec, int& pos)
{
	if (vec[pos] == inf || vec.size() == 0)
	{
		*T = NULL;
		return;
	}
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
	bool isValidBST(TreeNode* root) {
		//基本思想：建立二叉排序树的中序遍历res，如果res不是从小到大排序，那么返回false
		if (root == NULL)
			return true;
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (!st.empty() || p != NULL)
		{
			while (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			p = st.top();
			st.pop();
			res.push_back(p->val);
			p = p->right;
		}
		for (int i = 0; i < res.size() - 1; i++)
		{
			if (res[i] >= res[i + 1])
				return false;
		}
		return true;
	}
};
class Solution1 {
public:
	bool isValidBST(TreeNode*a root) {
		//基本思想：递归
		return Recursion(root,inf,inf);
	}
	bool Recursion(TreeNode* root, int lower, int upper)
	{
		if (root == NULL)
			return true;
		if (upper != inf && upper <= root->val || lower != inf &&  root->val <= lower)
			return false;
		if (Recursion(root->left, lower, root->val)==false)
			return false;
		if (Recursion(root->right, root->val, upper) == false)
			return false;
		return true;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.isValidBST(root) << endl;
	return 0;
}