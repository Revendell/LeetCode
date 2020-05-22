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
	vector<int> preorderTraversal(TreeNode* root) {
		//基本思想：迭代，迭代法前序遍历和中序遍历一模一样，区别在于节点值保存至res的位置不同
		TreeNode* p = root;
		stack<TreeNode*> st;
		vector<int> res;
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				res.push_back(p->val);
				p = p->left;
			}
			p = st.top();
			st.pop();
			/*如果在这里将节点值保存至res就是中序遍历*/
			p = p->right;
		}
		return res;
	}
};
class Solution1 {
public:
	vector<int> res;
	vector<int> preorderTraversal(TreeNode* root) {
		//基本思想：递归
		Recursion(root);
		return res;
	}
	void Recursion(TreeNode* root)
	{
		if (root == NULL)
			return;
		res.push_back(root->val);
		Recursion(root->left);
		Recursion(root->right);
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<int> res = solute.preorderTraversal(root);
	for_each(res.begin(), res.end(), [](const int& v) {cout << v << endl; });
	return 0;
}