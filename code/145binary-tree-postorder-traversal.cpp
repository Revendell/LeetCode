#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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
	vector<int> postorderTraversal(TreeNode* root) {
		//����˼�룺������������������Ҹ�����������������Ǹ����󣬶�ǰ������Ǹ�����
		//����ֻҪ��΢�޸���ǰ������õ�������ı���˳����󷵻ظ������������Ǻ������
		TreeNode* p = root;
		stack<TreeNode*> st;
		vector<int> res;
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				res.push_back(p->val);
				p = p->right;
			}
			p = st.top();
			st.pop();
			p = p->left;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
class Solution1 {
public:
	vector<int> res;
	vector<int> postorderTraversal(TreeNode* root) {
		//����˼�룺�ݹ�
		Recursion(root);
		return res;
	}
	void Recursion(TreeNode* root)
	{
		if (root == NULL)
			return;
		Recursion(root->left);
		Recursion(root->right);
		res.push_back(root->val);	
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<int> res = solute.postorderTraversal(root);
	for_each(res.begin(), res.end(), [](const int& v) {cout << v << endl; });
	return 0;
}