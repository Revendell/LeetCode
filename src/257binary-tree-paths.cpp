#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
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
	vector<string> res;
	vector<string> binaryTreePaths(TreeNode* root) {
		//基本思想：递归
		if (root == nullptr)
			return res;
		string s;
		dfs(root, s);
		return res;
	}
	void dfs(TreeNode* root, string s)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			s.append(to_string(root->val));
			res.push_back(s);
			return;
		}
		s.append(to_string(root->val));
		s.append("->");
		if (root->left != nullptr)
		{
			dfs(root->left, s);
		}
		if (root->right != nullptr)
		{
			dfs(root->right, s);
		}
		return;
	}
};
class Solution1 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
		//非递归
        stack<TreeNode*> st;
        stack<string> path;
        vector<string> res;
        string cur;
        if(root)
        {
            st.push(root);
            path.push(to_string(root->val));
        }    
        while(!st.empty())
        {
            root=st.top();
            st.pop();
            cur=path.top();
            path.pop();
            if(root->left==nullptr&&root->right==nullptr)
                res.push_back(cur);
            if(root->left)
            {
                st.push(root->left);
                path.push(cur+"->"+to_string(root->left->val));
            }
            if(root->right)
            {
                st.push(root->right);
                path.push(cur+"->"+to_string(root->right->val));
            }
        }
        return res;
    }
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 5,-13,-2,-1,inf,inf,inf,4,inf,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<string> res = solute.binaryTreePaths(root);
	for_each(res.begin(), res.end(), [](const string v) {cout << v << endl; });
	return 0;
}