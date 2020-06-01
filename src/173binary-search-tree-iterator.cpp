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
		//基本思想：栈，next()和hasNext()操作的时间复杂度是O(1)，并使用O(h)内存，其中h是树的高度
		//一开始的想法就是建立一个O(n)的空间按中序遍历从小到大保存，然后依次输出next，但是空间复杂度O(n)
		//然后不断思考怎么实现O(h)的内存，突然想到中序遍历的过程中可以返回next，不用将所有节点保存多此一举
		TreeNode* p = root;
		while (p != NULL)
		{
			st.push(p);
			p = p->left;
		}
	}
	/** @return the next smallest number */
	int next() {
		//摊还分析,所有节点均只会入栈一次,摊还下来,每次next只有一次入栈操作所以时间复杂度O(1)
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
	cout << iterator.next() << endl;    // 返回 3
	cout << iterator.next() << endl;    // 返回 7
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 9
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 15
	cout << iterator.hasNext() << endl; // 返回 true
	cout << iterator.next() << endl;    // 返回 20
	cout << iterator.hasNext() << endl; // 返回 false
	return 0;
}