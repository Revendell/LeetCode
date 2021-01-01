#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<map>
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
class Solution {
public:
    map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        //基本思想：递归+备忘录，递归遍历所有可能的情况，备忘录防止超时
        //当前节点T被偷，那么T的left和right节点不能被偷
        //当前节点T不被偷，那么T的left和right节点能被偷
        return dfs(root);
    }
    int dfs(TreeNode* T)
    {
        if (T == NULL)
            return 0;
        if(dp.find(T)!=dp.end())
            return dp[T];
        //num1记录当前节点T被偷，那么T的left和right节点不能被偷
        //num2记录当前节点T不被偷，那么T的left和right节点能被偷
        int num1=0,num2=0;
        num1=T->val;
        if(T->left!=NULL)
            num1+=dfs(T->left->left)+dfs(T->left->right);
        if(T->right!=NULL)
            num1+=dfs(T->right->left)+dfs(T->right->right);
        num2=dfs(T->left)+dfs(T->right);
        dp[T]=max(num1,num2);
        return max(num1,num2);
    }
};
int main()
{
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	Solution solute;
	cout<<solute.rob(root)<<endl;
	return 0;
}
