#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum_val, carry = 0;
		ListNode* s, * head;
		head = new ListNode(0);
		s = head;
		//数字在单链表的表头存放低位表尾存放高位，所以从表头到表尾依次相加，进位存储到carry，如果高位没有数字补0即可
		while (l1 != NULL || l2 != NULL)
		{
			int l1_val = (l1 != NULL) ? l1->val : 0;
			int l2_val = (l2 != NULL) ? l2->val : 0;
			sum_val = l1_val + l2_val + carry;
			carry = sum_val / 10;  //进位
			sum_val = sum_val % 10;  //低位
			s->next = new ListNode(sum_val);
			s = s->next;
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
		}
		//最后一位相加进位1，需要增加一个节点
		if (carry == 1)
			s->next = new ListNode(1);
		return head->next;
	}
};
//头插法建立n个元素带表头节点的单链表L
void CreateListHead(ListNode* L, int n)
{
	ListNode *p;
	int i;
	for (i = 0; i < n; i++)
	{
		p = new ListNode(i+1);
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	Solution solute;
	ListNode* l1= new ListNode(0),*l2= new ListNode(0),*s;
	//创建单链表l1和l2存储数字
	CreateListHead(l1, 3);
	CreateListHead(l2, 3);
	//l1+l2保存到单链表s中，表头存放低位表尾存放高位
	s=solute.addTwoNumbers(l1->next, l2->next);
	while (s != NULL)
	{
		cout << s->val;
		s = s->next;
	}
	return 0;
}