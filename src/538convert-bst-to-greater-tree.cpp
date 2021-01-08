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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    map<int,TreeNode*> Map;
    TreeNode* convertBST(TreeNode* root) {
        //基本思想：递归，用Map记录int对应节点的映射，这样将节点自动从小到大排序了，然后遍历节点不断sum+=iter->first并将sum值赋给当前节点
        //此方法针对任何二叉树都可以，不必是二叉搜索树
        dfs(root);
        int sum=0;
        for(auto iter=Map.rbegin();iter!=Map.rend();iter++)
        {
            sum+=iter->first;
            iter->second->val=sum;
        }
        return root;
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        Map[root->val]=root;
        dfs(root->left);
        dfs(root->right);
    }
};
class Solution1 {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        //基本思想：递归，利用二叉搜索树的性质，先遍历数字大的节点，不断sum+=root->val并将sum值赋给当前节点
        dfs(root);
        return root;
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs(root->right);
        sum+=root->val;
        root->val=sum;
        dfs(root->left);
    }
};
int main()
{
    TreeNode* root = NULL;
	vector<int> vec = { 1,2,3,4,inf,inf,inf,inf,inf};
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	Solution solute;
	TreeNode* res=solute.convertBST(root);
	PreOrderTraverse(res);
	return 0;
}
