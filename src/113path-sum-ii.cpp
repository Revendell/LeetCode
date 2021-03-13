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
		//�򻯰棺�ݹ����
		vector<int> cur;
		Recursion(root, sum, cur);
		return res;
	}
	void Recursion(TreeNode* root, int sum, vector<int> cur)
	{
		if(root == NULL)
			return;
		cur.push_back(root->val);
		//��ֹ������rootΪҶ�ӽڵ�
		if (root->right == NULL && root->left == NULL)
		{
			//���֮ǰ�ڵ�ֵ��+��ǰ�ڵ�ֵ=sum�������·�����нڵ�cur��res
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
		//����˼�룺�ݹ���ݣ��ݹ�������ж�����·���Ƿ���һ��·���͵���sum�������·�������нڵ�ֵ��cur
		//С���ɣ�һ��ʼ�ݹ麯������һ������vector<int> cur����Ч�ʺܵͣ�Ȼ������curΪȫ�ֱ�����Ч�������ܴ�
		if (root == NULL)
			return res;
		Recursion(root, sum, 0);
		return res;
	}
	void Recursion(TreeNode* root, int sum, int pre_sum)
	{
		cur.push_back(root->val);
		//��ֹ������rootΪҶ�ӽڵ�
		if (root->right == NULL && root->left == NULL)
		{
			//���֮ǰ�ڵ�ֵ��+��ǰ�ڵ�ֵ=sum�������·�����нڵ�cur��res
			if (sum == pre_sum + root->val)
				res.push_back(cur);
			return;
		}
		//�ݹ�������
		if (root->left != NULL)
		{
			Recursion(root->left, sum, pre_sum + root->val);
			cur.pop_back();
		}
		//�ݹ�������
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