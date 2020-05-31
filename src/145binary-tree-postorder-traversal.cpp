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
	vector<int> postorderTraversal(TreeNode* root) {
		//基本思想：迭代，后序遍历是左右根，后序遍历的逆序是根右左，而前序遍历是根左右
		//所以只要稍微修改下前序遍历得到根右左的遍历顺序，最后返回根右左的逆序就是后序遍历
		TreeNode* p = root;
		stack<TreeNode*> st;
		vector<int> res;
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				res.push_back(p->val);
				p = p->right;
			}
			p = st.top();
			st.pop();
			p = p->left;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
class Solution1 {
public:
	vector<int> res;
	vector<int> postorderTraversal(TreeNode* root) {
		//基本思想：递归
		Recursion(root);
		return res;
	}
	void Recursion(TreeNode* root)
	{
		if (root == NULL)
			return;
		Recursion(root->left);
		Recursion(root->right);
		res.push_back(root->val);	
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<int> res = solute.postorderTraversal(root);
	for_each(res.begin(), res.end(), [](const int& v) {cout << v << endl; });
	return 0;
}