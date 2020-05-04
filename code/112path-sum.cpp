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
	bool hasPathSum(TreeNode* root, int sum) {
		//����˼�룺�ݹ飬�ݹ�������ж�����·���Ƿ���һ��·���͵���sum
		if (root == NULL)
			return false;
		return Recursion(root, sum, 0);
	}
	bool Recursion(TreeNode* root, int sum, int pre_sum)
	{
		//��ֹ������rootΪҶ�ӽڵ�
		if (root->right==NULL && root->left==NULL)
		{
			//���֮ǰ�ڵ�ֵ��+��ǰ�ڵ�ֵ=sum������true
			if (sum == pre_sum + root->val)
				return true;
			else
				return false;
		}
		//�ݹ�������
		if (root->right != NULL && Recursion(root->right, sum, pre_sum + root->val))
			return true;
		//�ݹ�������
		if (root->left != NULL && Recursion(root->left, sum, pre_sum + root->val))
			return true;
		//�ݹ�������������������һ��·���͵���sum������false
		return false;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 3,2,inf,inf,4,2,inf,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	int sum = 7;
	cout << solute.hasPathSum(root, sum) << endl;
	return 0;
}