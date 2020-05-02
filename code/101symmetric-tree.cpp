#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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
	bool isSymmetric(TreeNode* root) {
		//基本思想：递归
		if (root == NULL)
			return true;
		return Recursion(root->left, root->right);
	}
	bool Recursion(TreeNode* L, TreeNode* R)
	{
		if (L == NULL && R == NULL)
			return true;
		if (L == NULL || R == NULL)
			return false;
		if (L->val != R->val)
			return false;
		if (Recursion(L->left, R->right) == false)
			return false;
		if (Recursion(L->right, R->left) == false)
			return false;
		return true;
	}
};
class Solution1 {
public:
	bool isSymmetric(TreeNode* root) {
		//基本思想：迭代，遍历左子树与右子树每一对应节点，判断是否相等
		if (root == NULL)
			return true;
		stack<TreeNode*> st1, st2;
		TreeNode* p, * q;
		p = root->left;
		q = root->right;
		while (p != NULL || q != NULL || !st1.empty() || !st2.empty())
		{
			if (p != NULL && q != NULL)
			{
				if (p->val != q->val)
					return false;
				st1.push(p);
				st2.push(q);
				p = p->left;
				q = q->right;
			}
			else if (p == NULL && q == NULL)
			{
				p = st1.top();
				st1.pop();
				q = st2.top();
				st2.pop();
				p = p->right;
				q = q->left;
			}
			else
				return false;
		}
		return true;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,inf,inf,2,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.isSymmetric(root) << endl;
	return 0;
}