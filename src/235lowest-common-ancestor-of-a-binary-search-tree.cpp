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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//����˼�룺���ö������������ص㡣
		//���p��q��ֵ��С��root��˵��p��q�϶���root���������У�
		//���p��q������root��˵���϶���root���������У�
		//���һ������һ�����ң�˵����ʱ��root��Ϊ��Ӧ������������ȡ�
		while (root)
		{
			if (p->val < root->val && q->val < root->val)
				root = root->left;
			else if (p->val > root->val&& q->val > root->val)
				root = root->right;
			else
				return root;
		}
		return nullptr;
	}
};
class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* p1 = root, * q1 = root, * res = root;
		while (true)
		{
			if (p1 == q1)
				res = p1;
			else
				return res;
			if (p->val > p1->val)
				p1 = p1->right;
			else if (p->val < p1->val)
				p1 = p1->left;
			if (q->val > q1->val)
				q1 = q1->right;
			else if (q->val < q1->val)
				q1 = q1->left;
		}
		return nullptr;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 5,3,2,1,inf,inf,inf,4,inf,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	TreeNode* p = new TreeNode(2);
	TreeNode* q = new TreeNode(4);
	TreeNode* res = solute.lowestCommonAncestor(root, p, q);
	cout << res->val << endl;
	return 0;
}