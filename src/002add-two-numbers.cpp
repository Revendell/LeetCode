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
		//�����ڵ�����ı�ͷ��ŵ�λ��β��Ÿ�λ�����Դӱ�ͷ����β������ӣ���λ�洢��carry�������λû�����ֲ�0����
		while (l1 != NULL || l2 != NULL)
		{
			int l1_val = (l1 != NULL) ? l1->val : 0;
			int l2_val = (l2 != NULL) ? l2->val : 0;
			sum_val = l1_val + l2_val + carry;
			carry = sum_val / 10;  //��λ
			sum_val = sum_val % 10;  //��λ
			s->next = new ListNode(sum_val);
			s = s->next;
			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
		}
		//���һλ��ӽ�λ1����Ҫ����һ���ڵ�
		if (carry == 1)
			s->next = new ListNode(1);
		return head->next;
	}
};
//ͷ�巨����n��Ԫ�ش���ͷ�ڵ�ĵ�����L
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
	//����������l1��l2�洢����
	CreateListHead(l1, 3);
	CreateListHead(l2, 3);
	//l1+l2���浽������s�У���ͷ��ŵ�λ��β��Ÿ�λ
	s=solute.addTwoNumbers(l1->next, l2->next);
	while (s != NULL)
	{
		cout << s->val;
		s = s->next;
	}
	return 0;
}