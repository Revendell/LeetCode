#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<algorithm>
#include<map>
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
	int res = INT_MIN;
	int maxPathSum(TreeNode* root) {
		//����˼�룺�ݹ�������
		//һ��ʼ�뷨����ÿ���ڵ�ľֲ����Ž⣬Ȼ������ȫ�����Ž⣬������Ч�ʺܵͣ�ֱ����ֲ����Ž��ʱ����ȫ�����Ž�
		if (root == NULL)
			return INT_MIN;
		Recursion(root);
		return res;
	}
	int Recursion(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		vector<int> cur;
		//����ÿ���ڵ��Ըýڵ�Ϊ�յ��������·���õ������ֵ��������·���õ������ֵ
		cur.push_back(root->val);
		cur.push_back(root->val + Recursion(root->left));
		cur.push_back(root->val + Recursion(root->right));
		//��ȫ�����Ž⣬���·���;������������·���͡����������·���͡�����������������·��������һ��
		res=max(res, max(cur[0],max(cur[1] + cur[2] - cur[0], max(cur[1] , cur[2]))));
		//����ÿ���ڵ����������·�������������·��������ڵ�ֵ�����е����ֵ���Ǹýڵ�Ϊ�յ�·�������ֵ��Ҳ���Ǿֲ����Ž�
		return *max_element(cur.begin(),cur.end());
	}
};
class Solution1 {
public:
	int maxPathSum(TreeNode* root) {
		//����˼�룺�������Ե��������������ÿ���ڵ��Ըýڵ�Ϊ�յ��·���е����·����Ҳ���Ǿֲ����Ž�
		//Ȼ����ȫ�����Ž⣬���·���;��ǽڵ����������·���͡����������·���͡�����������������·��������һ��
		if (root == NULL)
			return INT_MIN;
		stack<TreeNode*> st;
		list<TreeNode*> queue;
		//hashmap���ڱ���ÿ���ڵ��Ըýڵ�Ϊ�յ��·���е����·����Ϊ�˷���������Һ���
		map<TreeNode*, vector<int>> hashMap;
		TreeNode* p;
		int res = INT_MIN;
		queue.push_front(root);
		//����queue������������Ե�����˳��ڵ����򱣴���ջst�У���ʵҲ���ǲ�α���
		while (!queue.empty())
		{
			//��������queue�еĵ�ǰ��ڵ�Ӷ�β����������vec��������ͬʱ����һ��Ľڵ�Ӷ��������
			int len = queue.size();
			for (int i = 0; i < len; i++)
			{
				p = queue.back();
				queue.pop_back();
				st.push(p);
				if (p->left != NULL)
					queue.push_front(p->left);
				if (p->right != NULL)
					queue.push_front(p->right);
			}
		}
		//�Ե��������������ÿ���ڵ��Ըýڵ�Ϊ�յ��·���е����·����Ҳ���Ǿֲ����Ž�
		while (!st.empty())
		{
			p = st.top();
			st.pop();
			//cur����ýڵ�Ϊ�յ������·���е����·�����Լ����������������·�������������·��
			vector<int> cur;
			cur.push_back(p->val);
			if (p->left == NULL)
				cur.push_back(p->val + 0);
			else
				cur.push_back(*max_element(hashMap[p->left].begin(), hashMap[p->left].end())+ p->val);
			if (p->right == NULL)
				cur.push_back(p->val + 0);
			else
				cur.push_back(*max_element(hashMap[p->right].begin(), hashMap[p->right].end())+ p->val);
			//��ȫ�����Ž⣬���·���;��ǽڵ����������·���͡����������·���͡�����������������·��������һ��
			res = max(res, max(cur[0], max(cur[1] + cur[2] - cur[0], max(cur[1], cur[2]))));
			hashMap[p] = cur;
		}
		return res;
	}
};
class Solution2 {
public:
	vector<vector<int>> res;
	int maxPathSum(TreeNode* root) {
		if (root == NULL)
			return INT_MIN;
		int maxPath = Recursion(root);
		//����ÿ���ڵ㣬��ȫ�����Ž�
		for (auto i = 0; i < res.size(); i++)
		{
			//���·���;������������·���͡����������·���͡�����������������·��������һ��
			int L = res[i][1];
			int R = res[i][2];
			maxPath = max(maxPath, max(L + R - res[i][0], max(L, R)));
		}
		return maxPath;
	}
	int Recursion(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		vector<int> cur;
		//����ÿ���ڵ�������·���õ������ֵ��������·���õ������ֵ
		cur.push_back(root->val);
		cur.push_back(root->val + Recursion(root->left));
		cur.push_back(root->val + Recursion(root->right));
		res.push_back(cur);
		//����ÿ���ڵ����������·�������������·��������ڵ�ֵ�����е����ֵ���Ǹýڵ�Ϊ�յ�·�������ֵ���ֲ����Ž�
		return *max_element(cur.begin(), cur.end());
	}
};
int main()
{
	Solution1 solute;
	TreeNode* root = NULL;
	vector<int> vec = { 2,-1,inf,inf,-2,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	cout << solute.maxPathSum(root) << endl;
	return 0;
}