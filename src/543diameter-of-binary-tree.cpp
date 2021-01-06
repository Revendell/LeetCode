
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
    unordered_map<TreeNode*,int> path;
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        //����˼�룺�ݹ�dfs�����������+����¼���ݹ����ÿ���ڵ�ĸ߶Ȳ���¼��path=max(��ڵ�߶�,�ҽڵ�߶�)+1
        //�����������˳�����ýڵ�·��=��ڵ�߶�+�ҽڵ�߶�
        height(root);
        return res;
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        if(path.find(root)!=path.end())
            return path[root];
        int lh=height(root->left);
        int rh=height(root->right);
        res=max(res,lh+rh);
        path[root]=max(lh,rh)+1;
        return max(lh,rh)+1;
    }
};
int main()
{
	TreeNode* root = NULL;
	vector<int> vec = { 2,1,4,inf,inf,5,6,inf,inf,inf,3,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	Solution solute;
	cout<<solute.diameterOfBinaryTree(root)<<endl;
	return 0;
}
