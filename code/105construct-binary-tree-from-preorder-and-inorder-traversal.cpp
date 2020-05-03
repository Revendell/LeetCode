#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		//����˼�룺�ݹ飬�����Ը��ڵ��ֳ���������ǰ���������������ǰ�����򣬼����ݹ飬ֱ������������
		//��������ǰ������Ϊpreorder_left��inorder_left
		//��������ǰ������Ϊpreorder_right��inorder_right
		if (preorder.size() == 0)
			return NULL;
		TreeNode* root = NULL;
		Recursion(preorder, inorder, &root);
		return root;

	}
	void Recursion(vector<int> preorder, vector<int> inorder, TreeNode** root)
	{
		int i, j;
		(*root) = new TreeNode(preorder[0]);
		//�ҵ���������ķָ��㣬Ҳ����ǰ������ĵ�һ���ڵ㣬������ֳ���������
		for (i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == preorder[0])
				break;
		}
		vector<int> preorder_left, preorder_right;
		vector<int> inorder_left, inorder_right;
		//�õ���������ǰ������Ϊpreorder_left��inorder_left
		for (j = 1; j <= i; j++)
		{
			preorder_left.push_back(preorder[j]);
			inorder_left.push_back(inorder[j - 1]);
		}
		//�õ���������ǰ������Ϊpreorder_right��inorder_right
		for (j = i + 1; j < preorder.size(); j++)
		{
			preorder_right.push_back(preorder[j]);
			inorder_right.push_back(inorder[j]);
		}
		//�����ݹ�����������ֱ������������
		if (preorder_left.size() > 0)
			Recursion(preorder_left, inorder_left, &(*root)->left);
		if (preorder_right.size() > 0)
			Recursion(preorder_right, inorder_right, &(*root)->right);
	}
};
int main()
{
	Solution solute;
	vector<int> preorder = { 3,9,20,15,7 };
	vector<int> inorder = { 9,3,15,20,7 };
	TreeNode* root = solute.buildTree(preorder,inorder);
	PreOrderTraverse(root);
	return 0;
}