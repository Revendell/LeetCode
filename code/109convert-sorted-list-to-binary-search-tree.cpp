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
		//����˼�룺�ݹ飬�ҵ������м�ڵ�p����p->next�ڵ�Ϊ���ڵ㣬�ֳ��������������ϵݹ�˹���
		if (head == NULL)
			return NULL;
		TreeNode* root = NULL;
		//���һ��start��Чͷ�ڵ㣬���㴦��
		ListNode *start = new ListNode(0);
		start->next = head;
		Recursion(start, &root);
		return root;
	}
	void Recursion(ListNode* head, TreeNode** root)
	{
		//�ݹ���ֹ����Ϊ������Ϊ0
		if (head->next == NULL)
			return;
		int len = 0;
		//������Ч������len
		ListNode* p = head->next;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		//�ҵ������м�ڵ�p����p->next�ڵ�Ϊ���ڵ㣬�ֳ���������
		p = head;
		for (int i = 0; i < len/2; i++)
			p = p->next;
		//p->next�ڵ�Ϊ���ڵ�
		(*root) = new TreeNode(p->next->val);
		//�ݹ���ֹ����Ϊ������Ϊ1
		if (len == 1)
			return;
		//�м�ڵ��Ҳ��ֵݹ���ã������ɶ�����������������
		Recursion(p->next, &(*root)->right);
		//�м�ڵ��󲿷ֵݹ���ã������ɶ�����������������
		p->next = NULL;
		Recursion(head, &(*root)->left);	
	}
};

int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//��ʼ������
	Init_ListNode(head, vec);
	TreeNode* root = solute.sortedListToBST(head);
	PreOrderTraverse(root);
	return 0;
}