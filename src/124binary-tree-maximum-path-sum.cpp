#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<algorithm>
#include<map>
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
	int res = INT_MIN;
	int maxPathSum(TreeNode* root) {
		//基本思想：递归后序遍历
		//一开始想法是求每个节点的局部最优解，然后再求全局最优解，这样做效率很低，直接求局部最优解的时候求全局最优解
		if (root == NULL)
			return INT_MIN;
		Recursion(root);
		return res;
	}
	int Recursion(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		vector<int> cur;
		//计算每个节点以该节点为终点的左子树路径得到的最大值、右子树路径得到的最大值
		cur.push_back(root->val);
		cur.push_back(root->val + Recursion(root->left));
		cur.push_back(root->val + Recursion(root->right));
		//求全局最优解，最大路径和就是左子树最大路径和、右子树最大路径和、左右子树相连三条路径中最大的一个
		res=max(res, max(cur[0],max(cur[1] + cur[2] - cur[0], max(cur[1] , cur[2]))));
		//返回每个节点左子树最大路径、右子树最大路径、自身节点值三者中的最大值就是该节点为终点路径的最大值，也就是局部最优解
		return *max_element(cur.begin(),cur.end());
	}
};
class Solution1 {
public:
	int maxPathSum(TreeNode* root) {
		//基本思想：迭代，自底向上求二叉树中每个节点以该节点为终点的路径中的最大路径，也就是局部最优解
		//然后求全局最优解，最大路径和就是节点左子树最大路径和、右子树最大路径和、左右子树相连三条路径中最大的一个
		if (root == NULL)
			return INT_MIN;
		stack<TreeNode*> st;
		list<TreeNode*> queue;
		//hashmap用于保存每个节点以该节点为终点的路径中的最大路径，为了方便查找左右孩子
		map<TreeNode*, vector<int>> hashMap;
		TreeNode* p;
		int res = INT_MIN;
		queue.push_front(root);
		//队列queue用于求二叉树自底向上顺序节点排序保存至栈st中，其实也就是层次遍历
		while (!queue.empty())
		{
			//将保存在queue中的当前层节点从队尾弹出保存至vec，弹出的同时将下一层的节点从队首入队列
			int len = queue.size();
			for (int i = 0; i < len; i++)
			{
				p = queue.back();
				queue.pop_back();
				st.push(p);
				if (p->left != NULL)
					queue.push_front(p->left);
				if (p->right != NULL)
					queue.push_front(p->right);
			}
		}
		//自底向上求二叉树中每个节点以该节点为终点的路径中的最大路径，也就是局部最优解
		while (!st.empty())
		{
			p = st.top();
			st.pop();
			//cur保存该节点为终点的三条路径中的最大路径：自己单独、左子树最大路径、右子树最大路径
			vector<int> cur;
			cur.push_back(p->val);
			if (p->left == NULL)
				cur.push_back(p->val + 0);
			else
				cur.push_back(*max_element(hashMap[p->left].begin(), hashMap[p->left].end())+ p->val);
			if (p->right == NULL)
				cur.push_back(p->val + 0);
			else
				cur.push_back(*max_element(hashMap[p->right].begin(), hashMap[p->right].end())+ p->val);
			//求全局最优解，最大路径和就是节点左子树最大路径和、右子树最大路径和、左右子树相连三条路径中最大的一个
			res = max(res, max(cur[0], max(cur[1] + cur[2] - cur[0], max(cur[1], cur[2]))));
			hashMap[p] = cur;
		}
		return res;
	}
};
class Solution2 {
public:
	vector<vector<int>> res;
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return INT_MIN;
		int maxPath = Recursion(root);
		//遍历每个节点，求全局最优解
		for (auto i = 0; i < res.size(); i++)
		{
			//最大路径和就是左子树最大路径和、右子树最大路径和、左右子树相连三条路径中最大的一个
			int L = res[i][1];
			int R = res[i][2];
			maxPath = max(maxPath, max(L + R - res[i][0], max(L, R)));
		}
		return maxPath;
	}
	int Recursion(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		vector<int> cur;
		//计算每个节点左子树路径得到的最大值、右子树路径得到的最大值
		cur.push_back(root->val);
		cur.push_back(root->val + Recursion(root->left));
		cur.push_back(root->val + Recursion(root->right));
		res.push_back(cur);
		//返回每个节点左子树最大路径、右子树最大路径、自身节点值三者中的最大值就是该节点为终点路径的最大值，局部最优解
		return *max_element(cur.begin(), cur.end());
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,-1,inf,inf,-2,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.maxPathSum(root) << endl;
	return 0;
}