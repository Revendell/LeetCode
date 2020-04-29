#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
	vector<TreeNode*> generateTrees(int n) {
		//����˼�룺�ݹ鷨���������������������ڵ�С�ڸ��ڵ㣬�������ڵ���ڸ��ڵ�
		//i��[1,n]�ָ���������������֣�iΪ���ڵ�
		//�������ݹ�Ѱ��[1,i-1]���п��ܵ����Σ�����ÿһ�����εĸ��ڵ�
		//�������ݹ�Ѱ��[i+1,n]���п��ܵ����Σ�����ÿһ�����εĸ��ڵ�
		//�������������γɵ����ε����и��ڵ㣬ƴ����i�����ҽڵ��ϣ�����ÿһ�����ν���ĸ��ڵ�i���浽head����
		if (n == 0)
			return {};
		else
		    return Recursion(1, n);
	}
	vector<TreeNode*> Recursion(int start, int end)
	{
		if (start > end)
			return { NULL };
		vector<TreeNode*> head;
		for (int i = start; i <= end; i++)
		{
			vector<TreeNode*> L = Recursion(start, i - 1);
			vector<TreeNode*> R = Recursion(i + 1, end);
			for (auto& l : L)
			{
				for (auto& r : R)
				{
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					head.push_back(root);
				}
			}
		}
		return head;
	}
};
int main()
{
	Solution solute;
	int n = 3;
	vector<TreeNode*> res = solute.generateTrees(n);
	for (int i = 0; i < res.size(); i++)
	{
		PreOrderTraverse(res[i]);
		cout << endl;
	}
	return 0;
}