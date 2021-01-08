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
        //����˼�룺�ݹ飬��Map��¼int��Ӧ�ڵ��ӳ�䣬�������ڵ��Զ���С���������ˣ�Ȼ������ڵ㲻��sum+=iter->first����sumֵ������ǰ�ڵ�
        //�˷�������κζ����������ԣ������Ƕ���������
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
        //����˼�룺�ݹ飬���ö��������������ʣ��ȱ������ִ�Ľڵ㣬����sum+=root->val����sumֵ������ǰ�ڵ�
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
