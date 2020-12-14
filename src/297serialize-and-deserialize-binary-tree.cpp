
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<sstream>
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
void PreOrderTraverse(TreeNode* T)
{
	if (T == NULL)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);

}
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		//基本思想：将二叉树root转化为前序遍历的序列，为NULL的叶子填充为inf，将得到的序列重新转化为二叉树，为inf的节点就是NULL
		if (root == NULL)
			return to_string(infnum) + " ";
		string res = to_string(root->val) + " ";
		res+= serialize(root->left);
		res+= serialize(root->right);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<int> vec;
		istringstream is(data);
		int cur;
		while (is >> cur)
			vec.push_back(cur);
		int pos = 0;
		TreeNode* root = NULL;
		BuildTreeNode(&root, vec, pos);
		return root;
	}
	void BuildTreeNode(TreeNode** T, vector<int>& vec, int& pos)
	{
		if (vec[pos] == infnum || vec.size() == 0)
		{
			*T = NULL;
			return;
		}
		else
		{
			(*T) = new TreeNode(0);
			(*T)->val = vec[pos];
			BuildTreeNode(&(*T)->left, vec, ++pos);
			BuildTreeNode(&(*T)->right, vec, ++pos);
		}
	}
private:
	int infnum = 9999999;
};
int main()
{
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	Codec ser, deser;
	TreeNode* ans = deser.deserialize(ser.serialize1(root));
	PreOrderTraverse(ans);
	return 0;
}
