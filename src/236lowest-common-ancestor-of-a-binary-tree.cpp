#include<iostream>
#include<vector>
#include<unordered_map>
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
	unordered_map<int, TreeNode*> father;
	vector<TreeNode*> vecp;
	vector<TreeNode*> vecq;
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//����˼�룺HashMap�洢���ڵ㣬һ��ʼ�뽨��TreeNode*��TreeNode*��ӳ�䣬
		//�����ֲ���ֻ�ܽ���int��TreeNode*��ӳ�䣬��ΪTreeNode* p������root����Ľڵ㣬ֻ�ǽڵ�ֵ��ͬ
		//��p��root��·���洢��vecp��q��root��·���洢��vecq��Ȼ�������vecp��vecq�ҵ���Զ�Ĺ����ڵ�
		father[root->val] = nullptr;
		dfs(root);
		TreeNode* res = nullptr;
		while (p != nullptr)
		{
			vecp.push_back(p);
			p = father[p->val];	
		}
		while (q != nullptr)
		{
			vecq.push_back(q);
			q = father[q->val];
		}
		for (auto i = vecp.rbegin(), j = vecq.rbegin(); i != vecp.rend() && j != vecq.rend(); i++, j++)
		{
			if (*i == *j)
				res = *i;
			else
				break;
		}
		return res;
	}
	void dfs(TreeNode* root)
	{
		if (root->left != nullptr)
		{
			father[root->left->val] = root;
			dfs(root->left);
		}
		if (root->right != nullptr)
		{
			father[root->right->val] = root;
			dfs(root->right);
		}
		return;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 5,3,2,1,inf,inf,inf,4,inf,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	TreeNode* p = new TreeNode(6);
	TreeNode* q = new TreeNode(1);
	TreeNode* res = solute.lowestCommonAncestor(root, p, q);
	cout << res->val << endl;
	return 0;
}
