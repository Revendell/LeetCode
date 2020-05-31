#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l3, * head;
		l3 = new ListNode(0);
		head = l3;
		//�����������ǿ�ʱ������ڵ�l1<=�ڵ㣬���ڵ�l1�ӵ�l3��l1����һ�ڵ�l1=l1->next�����򽫽ڵ�l2�ӵ�l3��l2����һ�ڵ�l2=l2->next
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				l3->next = l1;
				l1 = l1->next;
			}
			else
			{
				l3->next = l2;
				l2 = l2->next;
			}
			l3 = l3->next;
		}
		//��һ������Ϊ���ˣ���һ���ǿ�����ֱ�Ӽӵ�l3����
		if (l1 == NULL)
			l3->next = l2;
		else
			l3->next = l1;
		return head->next;
	}
};
//β�巨��������
void CreateList(ListNode* head,int n)
{
	int i;
	ListNode* p;
	for (i = 1; i <= n; i++)
	{
		p = new ListNode(i);
		head->next = p;
		head = p;
	}
}
int main()
{
	Solution solute;
	ListNode* l1 = new ListNode(0), * l2 = new ListNode(0), * l3;
	int n = 5;
	//������������l1 l2
	CreateList(l1, n);
	CreateList(l2, n);
	l3 = solute.mergeTwoLists(l1->next, l2->next);
	while (l3 != NULL)
	{
		cout << l3->val << endl;
		l3 = l3->next;
	}
	return 0;
}