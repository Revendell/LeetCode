#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
	void flatten(TreeNode* root) {
		//����˼�룺���Ƶ��������������p��ʾ��ǰ����Ľڵ㣬qָ��p�������������ұ߽ڵ�
		//��p�����������뵽p���������ĵط�
		//��pԭ�����������ӵ�p�������������ұ߽ڵ�
		//�����µ��������ĸ��ڵ�p = p->right��һֱ�ظ��ϱߵĹ��̣�ֱ���µ�������Ϊ null
		TreeNode* p, * q;
		p = root;
		while (p != NULL)
		{
			if (p->left == NULL)
				p = p->right;
			else
			{
				//�ҵ�q��λ�ã�qָ��p�������������ұ߽ڵ�
				q = p->left;
				while (q->right != NULL)
					q = q->right;
				//q���Һ���ָ��p��������
				q->right = p->right;
				//p���Һ���ָ��p��������
				p->right = p->left;
				//p������ָ��NULL
				p->left = NULL;
				//�����µ��������ĸ��ڵ�
				p = p->right;
			}			
		}
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 1,2,3,4,inf,inf,inf,inf,5,inf,6,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	solute.flatten(root);
	PreOrderTraverse(root);
	return 0;
}