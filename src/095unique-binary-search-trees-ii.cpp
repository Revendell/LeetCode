#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void PreOrderTraverse(TreeNode* T)
{
	if (T == NULL)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);
}
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		//基本思想：递归法，二叉搜索树的左子树节点小于根节点，右子树节点大于根节点
		//i将[1,n]分割成左右子树两部分，i为根节点
		//左子树递归寻找[1,i-1]所有可能的树形，返回每一种树形的根节点
		//右子树递归寻找[i+1,n]所有可能的树形，返回每一种树形的根节点
		//遍历左右子树形成的树形的所有根节点，拼接在i的左右节点上，并将每一种树形结果的根节点i保存到head返回
		if (n == 0)
			return {};
		else
		    return Recursion(1, n);
	}
	vector<TreeNode*> Recursion(int start, int end)
	{
		if (start > end)
			return { NULL };
		vector<TreeNode*> head;
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> L = Recursion(start, i - 1);
			vector<TreeNode*> R = Recursion(i + 1, end);
			for (auto& l : L)
			{
				for (auto& r : R)
				{
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					head.push_back(root);
				}
			}
		}
		return head;
	}
};
int main()
{
	Solution solute;
	int n = 3;
	vector<TreeNode*> res = solute.generateTrees(n);
	for (int i = 0; i < res.size(); i++)
	{
		PreOrderTraverse(res[i]);
		cout << endl;
	}
	return 0;
}