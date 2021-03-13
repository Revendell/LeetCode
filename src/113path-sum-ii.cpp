#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
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
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		//简化版：递归回溯
		vector<int> cur;
		Recursion(root, sum, cur);
		return res;
	}
	void Recursion(TreeNode* root, int sum, vector<int> cur)
	{
		if(root == NULL)
			return;
		cur.push_back(root->val);
		//终止条件：root为叶子节点
		if (root->right == NULL && root->left == NULL)
		{
			//如果之前节点值和+当前节点值=sum，保存该路径所有节点cur到res
			if (sum == root->val)
				res.push_back(cur);
			return;
		}
		Recursion(root->left, sum - root->val,cur);
		Recursion(root->right, sum - root->val,cur);
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<int> cur;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		//基本思想：递归回溯，递归遍历所有二叉树路径是否有一条路径和等于sum，保存该路径下所有节点值到cur
		//小技巧：一开始递归函数中有一个参数vector<int> cur导致效率很低，然后设置cur为全局变量后，效率提升很大
		if (root == NULL)
			return res;
		Recursion(root, sum, 0);
		return res;
	}
	void Recursion(TreeNode* root, int sum, int pre_sum)
	{
		cur.push_back(root->val);
		//终止条件：root为叶子节点
		if (root->right == NULL && root->left == NULL)
		{
			//如果之前节点值和+当前节点值=sum，保存该路径所有节点cur到res
			if (sum == pre_sum + root->val)
				res.push_back(cur);
			return;
		}
		//递归左子树
		if (root->left != NULL)
		{
			Recursion(root->left, sum, pre_sum + root->val);
			cur.pop_back();
		}
		//递归右子树
		if (root->right != NULL)
		{
			Recursion(root->right, sum, pre_sum + root->val);
			cur.pop_back();
		}
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,2,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	int sum = 9;
	vector<vector<int>> res = solute.pathSum(root, sum);
	for (int i = 0; i < res.size(); i++)
	{
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}