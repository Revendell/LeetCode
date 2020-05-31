#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void Init_ListNode(ListNode* head, vector<int> vec)
{
	if (vec.size() == 0)
	{
		head = NULL;
		return;
	}
	ListNode* p;
	p = head;
	p->val = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		ListNode* q = new ListNode(vec[i]);
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
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
	TreeNode* sortedListToBST(ListNode* head) {
		//基本思想：递归，找到链表中间节点p，以p->next节点为根节点，分成左右子树，不断递归此过程
		if (head == NULL)
			return NULL;
		TreeNode* root = NULL;
		//多加一个start无效头节点，方便处理
		ListNode *start = new ListNode(0);
		start->next = head;
		Recursion(start, &root);
		return root;
	}
	void Recursion(ListNode* head, TreeNode** root)
	{
		//递归终止条件为链表长度为0
		if (head->next == NULL)
			return;
		int len = 0;
		//计算有效链表长度len
		ListNode* p = head->next;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		//找到链表中间节点p，以p->next节点为根节点，分成左右子树
		p = head;
		for (int i = 0; i < len/2; i++)
			p = p->next;
		//p->next节点为根节点
		(*root) = new TreeNode(p->next->val);
		//递归终止条件为链表长度为1
		if (len == 1)
			return;
		//中间节点右部分递归调用，构建成二叉搜索树的右子树
		Recursion(p->next, &(*root)->right);
		//中间节点左部分递归调用，构建成二叉搜索树的左子树
		p->next = NULL;
		Recursion(head, &(*root)->left);	
	}
};

int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//初始化链表
	Init_ListNode(head, vec);
	TreeNode* root = solute.sortedListToBST(head);
	PreOrderTraverse(root);
	return 0;
}