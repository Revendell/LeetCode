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
		//当两个链表都非空时：如果节点l1<=节点，将节点l1加到l3后l1到下一节点l1=l1->next，否则将节点l2加到l3后l2到下一节点l2=l2->next
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
		//当一个链表为空了，另一个非空链表，直接加到l3后面
		if (l1 == NULL)
			l3->next = l2;
		else
			l3->next = l1;
		return head->next;
	}
};
//尾插法创建链表
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
	//创建两个链表l1 l2
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