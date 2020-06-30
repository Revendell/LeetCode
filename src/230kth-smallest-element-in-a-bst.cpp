#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int kthSmallest(TreeNode* root, int k) {
		//基本思想：中序遍历
		stack<TreeNode*> st;
		while (root != nullptr || !st.empty())
		{
			while (root != nullptr)
			{
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			k--;
			if (k == 0)
				return root->val;
			root = root->right;
		}
		return 0;
    }
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 5,3,2,1,inf,inf,inf,4,inf,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	int k = 6;
	cout << solute.kthSmallest(root, k) << endl;
	return 0;
}