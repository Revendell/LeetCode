#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
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
		*T = NULL;
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
	vector<int> rightSideView(TreeNode* root) {
		//����˼�룺�������������������ʹ��ջ�ֱ��¼�ڵ��Լ���Ӧ�ڵ����
		//ֻ�б����Ľڵ���ȵ��ڵ�ǰ�ѱ����������Ȳż���res
		stack<TreeNode*> nodeStack;
		stack<int> depthStack;
		vector<int> res;
		int curdepth = 0, preNodedepth = -1;
		while (root != NULL || !nodeStack.empty())
		{
			while (root != NULL)
			{
				nodeStack.push(root);
				depthStack.push(preNodedepth + 1);
				if (curdepth == depthStack.top())
				{
					res.push_back(root->val);
					curdepth++;
				}
				preNodedepth++;
				root = root->right;
			}
			root = nodeStack.top();
			nodeStack.pop();
			preNodedepth = depthStack.top();
			depthStack.pop();
			root = root->left;
		}
		return res;
	}
};
class Solution1 {
public:
	vector<int> res;
	int curdepth = 0;
	vector<int> rightSideView(TreeNode* root) {
		//����˼�룺������������ݹ鷨������������ʼ���ϱ����ڵ㲢�Ҽ�¼�ڵ����
		//ֻ�б����Ľڵ���ȵ��ڵ�ǰ�ѱ����������Ȳż���res
		Recursion(root, 0);
		return res;
	}
	void Recursion(TreeNode* root, int depth)
	{
		if (root == NULL)
			return;
		if (curdepth == depth)
		{
			res.push_back(root->val);
			curdepth++;
		}
		Recursion(root->right, depth + 1);
		Recursion(root->left, depth + 1);
	}
};
class Solution2 {
public:
	vector<int> rightSideView(TreeNode* root) {
		//����˼�룺���������������������ÿһ��Ľڵ㰴���Ƚ��ȳ�˳�򱣴浽���У���ÿһ�����һ���ڵ�ֵ����res
		vector<int> res;
		if (root == NULL)
			return res;
		deque<TreeNode*> queue;
		TreeNode* cur;
		vector<int> vec;
		queue.push_back(root);
		while (!queue.empty())
		{
			//��������queue�еĵ�ǰ��ڵ�Ӷ�β����������vec��������ͬʱ����һ��Ľڵ�Ӷ��������
			int len = queue.size();
			for (int i = 0; i < len; i++)
			{
				cur = queue.back();
				queue.pop_back();
				vec.push_back(cur->val);
				if (cur->left != NULL)
					queue.push_front(cur->left);
				if (cur->right != NULL)
					queue.push_front(cur->right);
			}
			res.push_back(vec.back());
			vec.clear();
		}
		return res;
	}
};
int main()
{
	Solution solute;
	TreeNode* root = NULL;
	vector<int> vec = { 0,2,1,5,inf,inf,7,inf,inf,inf,4,3,inf,6,inf,inf,-1,inf,8,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	vector<int> res = solute.rightSideView(root);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}