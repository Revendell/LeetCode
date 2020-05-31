#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
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
}
class Solution {
public:
	void reorderList(ListNode* head) {
		//����˼�룺ջ������ջ�洢��Ҫ�����Ľڵ�
		int len = 0;
		ListNode* p , * q, * pre;
		stack<ListNode*> st;
		//���������ȣ�����ʹ�ÿ���˫ָ���ҵ������е�
		for (p = head; p != NULL; p = p->next)
			len++;
		if (len <= 2)
			return;
		//�ҵ���Ҫ��������ʼ�ڵ�p
		q = head;
		for (int i = 0; i < len / 2; i++)
			q = q->next;
		p = q->next;
		q->next = NULL;
		//����Ҫ�����Ľڵ���ջ��Ҳ����p֮��Ľڵ�
		while (p != NULL)
		{
			st.push(p);
			p = p->next;
		}
		p = head;
		//���в�����Ҫ�����Ľڵ�
		while (p != NULL)
		{
			if (!st.empty())
			{
				q = st.top();
				st.pop();
			}
			else
				break;
			q->next = p->next;
			p->next = q;
			p = p->next->next;
		}
	}
};
class Solution1 {
public:
	void reorderList(ListNode* head) {
		//����˼�룺��һ����������ƽ���ֳ����룻�ڶ��������ڶ����������򣻵�����������������������
		int len = 0;
		ListNode* p, * q, * cur;
		//���������ȣ�����ʹ�ÿ���˫ָ���ҵ������е�
		for (p = head; p != NULL; p = p->next)
			len++;
		if (len <= 2)
			return;
		//�ҵ���Ҫ��������ʼ�ڵ�p��������ƽ���ֳ�����
		q = head;
		for (int i = 0; i < len / 2; i++)
			q = q->next;
		p = q->next;
		q->next = NULL;
		//���ڶ�����������
		q = p;
		while (q->next != NULL)
			q = q->next;
		while (p != q)
		{
			cur = p;
			p = p->next;
			cur->next = q->next;
			q->next = cur;
		}
		//����������������
		p = head;
		while (q != NULL)
		{
			cur = q;
			q = q->next;
			cur->next = p->next;
			p->next = cur;
			p = p->next->next;
		}
	}
};
int main()
{
	Solution1 solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5,6,7,8 };
	//��ʼ������
	Init_ListNode(head, vec);
	solute.reorderList(head);
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}