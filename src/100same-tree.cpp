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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//基本思想：递归
		return PreOrderTraverse(p, q);
	}
	bool PreOrderTraverse(TreeNode* p, TreeNode* q)
	{
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		if (p->val != q->val)
			return false;
		if (PreOrderTraverse(p->left, q->left) == false)
			return false;
		if (PreOrderTraverse(p->right, q->right) == false)
			return false;
		return true;
	}
};
class Solution1 {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//基本思想：迭代
		if (p == NULL && q == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		stack<TreeNode*> st1, st2;
		while (p != NULL || !st1.empty()||q != NULL || !st2.empty())
		{
			if (p != NULL && q != NULL)
			{
				st1.push(p);
				st2.push(q);
				p = p->left;
				q = q->left;
			}
			else if (p == NULL && q == NULL)
			{
				p = st1.top();
				st1.pop();
				q = st2.top();
				st2.pop();
				if (p->val != q->val)
					return false;
				p = p->right;
				q = q->right;
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
	TreeNode* p = NULL, * q = NULL;
	vector<int> vec1 = { 1,2,inf,inf,inf };
	vector<int> vec2 = { 1,inf,2,inf,inf };
	int pos1 = 0, pos2 = 0;
	Init_TreeNode(&p, vec1, pos1);
	Init_TreeNode(&p, vec2, pos2);
	cout << solute.isSameTree(p, q);
	return 0;
}