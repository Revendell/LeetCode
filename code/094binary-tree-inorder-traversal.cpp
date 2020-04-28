#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<stack>
using namespace std;
#define inf 99999
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//空指针传参，代码把函数的第一个参数的值压入栈中存储，而空指针指向为空，不存在值*p，因此给*p一个临时变量和主函数并不是同一个*p
void Init_TreeNode(TreeNode** T, vector<int> &vec,int &pos)
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
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		//基本思想：递归法中序遍历二叉树
		Recursion(root);
		return res;
	}
	void Recursion(TreeNode* root)
	{
		if (root == NULL)
			return;
		else
		{
			Recursion(root->left);
			res.push_back(root->val);
			Recursion(root->right);
		}
	}
};
class Solution1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		//基本思想：迭代法基于栈中序遍历二叉树
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
		return res;
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,inf,2,3,inf,inf,inf };
	int pos = 0;
	//传入指向指针的指针
	Init_TreeNode(&root, vec, pos);
	vec = solute.inorderTraversal(root);
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
