#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define inf 9999
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
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
	void recoverTree(TreeNode* root) {
		//基本思想：先基于栈的中序遍历二叉树，得到中序遍历序列middleOrder
		//然后基于双指针在middleOrder序列中找逆序对swap1和swap2
		//最后基于递归遍历二叉树找到swap1和swap2两个节点值并交换
		if (root == NULL)
			return;
		vector<int> middleOrder;
		stack<TreeNode*> st;
		TreeNode* p = root;
		int swap1 = -1, swap2 = -1;
		//基于栈的中序遍历二叉树，得到中序遍历序列middleOrder
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			p = st.top();
			st.pop();
			middleOrder.push_back(p->val);
			p = p->right;
		}
		//基于双指针在middleOrder序列中找逆序对swap1和swap2
		int i = 0, j = middleOrder.size() - 1;
		while (swap1 == -1 || swap2 == -1)
		{
			if (middleOrder[i] > middleOrder[i + 1])
				swap1 = i;
			else
				i++;
			if (middleOrder[j] < middleOrder[j - 1])
				swap2 = j;
			else
				j--;
		}
		//基于递归遍历二叉树找到swap1和swap2两个节点值并交换
		Traverse(root, middleOrder[swap1], middleOrder[swap2]);
	}
	void Traverse(TreeNode* T, int swap1, int swap2)
	{
		if (T == NULL)
			return;
		if (T->val == swap1 || T->val == swap2)
			T->val = T->val == swap1 ? swap2 : swap1;
		Traverse(T->left, swap1, swap2);
		Traverse(T->right, swap1, swap2);
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,1,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	solute.recoverTree(root);
	PreOrderTraverse(root);
	return 0;
}