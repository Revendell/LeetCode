#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<deque>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		//基本思想：队列，将每一层的节点按照先进先出顺序保存到queue队列
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		deque<TreeNode*> queue;
		TreeNode* cur;
		vector<int> vec;
		queue.push_back(root);
		int cnt = 0;
		while (!queue.empty())
		{
			//将保存在queue中的当前层节点从队尾弹出保存至vec，弹出的同时将下一层的节点从队首入队列
			int len = queue.size();
			for (int i = 0; i < len; i++)
			{
				cur = queue.back();
				queue.pop_back();
				vec.push_back(cur->val);
				if (cur->left != NULL)
					queue.push_front(cur->left);
				if (cur->right != NULL)
					queue.push_front(cur->right);
			}
			if (cnt % 2 == 1)
				reverse(vec.begin(), vec.end());
			res.push_back(vec);
			vec.clear();
			cnt++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,inf,inf,2,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<vector<int>> res = solute.zigzagLevelOrder(root);
	for (int i = 0; i < res.size(); i++)
	{
		copy(res[i].begin(), res[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}