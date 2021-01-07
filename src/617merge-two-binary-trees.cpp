
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //基本思想：递归，没有返回值，如果t1缺节点，生成一个节点，值为t2的节点值；否则将t1节点值加到t2上。
        dfs(&t1,t2);
        return t1;
    }
    void dfs(TreeNode** root1, TreeNode* root2)
    {
        if(root2==NULL)
            return;
        else if(*root1==NULL)
            (*root1)=new TreeNode(root2->val);
        else if(*root1!=NULL)
            (*root1)->val+=root2->val;
        dfs(&(*root1)->left,root2->left);
        dfs(&(*root1)->right,root2->right);
    }
};
class Solution1 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //基本思想：递归，有返回值，修改了输入树的结构
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        //基本思想：递归，有返回值，不修改输入树的结构
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    }
};
int main()
{
	TreeNode* root1 = NULL;
	TreeNode* root2 = NULL;
	vector<int> vec1 = { 1,1,1,inf,inf,1,1,inf,inf,inf,1,inf,inf };
	vector<int> vec2 = { 2,2,2,inf,inf,2,2,inf,inf,inf,2,inf,inf };
	int pos1 = 0;
	int pos2 = 0;
	Init_TreeNode(&root1, vec1, pos1);
	Init_TreeNode(&root2, vec2, pos2);
	Solution1 solute;
	TreeNode* ans = solute.mergeTrees(root1,root2);
	PreOrderTraverse(ans);
	return 0;
}
