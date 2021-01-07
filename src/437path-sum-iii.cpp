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
class Solution {
public:
    int res=0;
    int target;
    int pathSum(TreeNode* root, int sum) {
        //基本思想：双重递归，第一重递归dfs遍历root中的每一个节点，第二重递归path以该节点为起始点不断往下求和节点值，如果求和等于target，res+=1
        if(root==NULL) return res;
        target=sum;
        dfs(root);
        return res;
    }
    void path(TreeNode* root,int sum)
    {
        if(root==NULL)
            return;
        if(sum+root->val==target)
            res+=1;
        path(root->left,sum+root->val);
        path(root->right,sum+root->val);
    }
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        path(root,0);
        dfs(root->left);
        dfs(root->right);
    }
};
int main()
{
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,3,4,inf,inf,inf,inf,inf};
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	Solution solute;
	int sum=3;
	cout<<solute.pathSum(root,sum)<<endl;;
	return 0;
}
