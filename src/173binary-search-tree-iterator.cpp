#include<iostream>
#include<algorithm>
#include<vector>
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
		(*T) = new TreeNode(vec[pos]);
		Init_TreeNode(&(*T)->left, vec, ++pos);
		Init_TreeNode(&(*T)->right, vec, ++pos);
	}
}
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		//����˼�룺ջ��next()��hasNext()������ʱ�临�Ӷ���O(1)����ʹ��O(h)�ڴ棬����h�����ĸ߶�
		//һ��ʼ���뷨���ǽ���һ��O(n)�Ŀռ䰴���������С���󱣴棬Ȼ���������next�����ǿռ临�Ӷ�O(n)
		//Ȼ�󲻶�˼����ôʵ��O(h)���ڴ棬ͻȻ�뵽��������Ĺ����п��Է���next�����ý����нڵ㱣����һ��
		TreeNode* p = root;
		while (p != NULL)
		{
			st.push(p);
			p = p->left;
		}
	}
	/** @return the next smallest number */
	int next() {
		//̯������,���нڵ��ֻ����ջһ��,̯������,ÿ��nextֻ��һ����ջ��������ʱ�临�Ӷ�O(1)
		int res = st.top()->val;
		TreeNode* p = st.top();
		st.pop();
		p = p->right;
		while (p != NULL)
		{
			st.push(p);
			p = p->left;
		}
		return res;
	}
	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (!st.empty())
			return true;
		else
			return false;
	}
private:
	stack<TreeNode*> st;
};
class BSTIterator1 {
public:
	BSTIterator1(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* p = root;
		while (p != NULL || !st.empty())
		{
			while (p != NULL)
			{
				st.push(p);
				p = p->left;
			}
			p = st.top();
			st.pop();
			vec.push_back(p);
			p = p->right;
		}
		cur = 0;
	}
	/** @return the next smallest number */
	int next() {
		return vec[cur++]->val;
	}
	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (cur < vec.size())
			return true;
		else
			return false;
	}
private:
	vector<TreeNode*> vec;
	int cur;
};
int main()
{
	TreeNode* root = NULL;
	vector<int> vec = { 7,3,inf,inf,15,9,inf,inf,20,inf,inf };
	int pos = 0;
	Init_TreeNode(&root, vec, pos);
	BSTIterator iterator(root);
	cout << iterator.next() << endl;    // ���� 3
	cout << iterator.next() << endl;    // ���� 7
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 9
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 15
	cout << iterator.hasNext() << endl; // ���� true
	cout << iterator.next() << endl;    // ���� 20
	cout << iterator.hasNext() << endl; // ���� false
	return 0;
}