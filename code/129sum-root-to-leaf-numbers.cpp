#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
	int sumNumbers(TreeNode* root) {
		//基本思想：递归
		Recursion(root, 0);
		return res;
	}
	void Recursion(TreeNode* root, int cur)
	{
		if (root == NULL)
			return;
		cur = cur * 10 + root->val;
		if (root->left == NULL && root->right == NULL)
		{
			res += cur;
			return;
		}
		Recursion(root->left, cur);
		Recursion(root->right, cur);
		return;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,1,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.sumNumbers(root) << endl;
	return 0;
}