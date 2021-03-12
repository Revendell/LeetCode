#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
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
    ListNode* partition(ListNode* head, int x) {
		//�򻯰棺���������������start1��Ԫ�ض�С��x������start2��Ԫ�ض����ڵ���x�����ϲ���������
		ListNode* start1=new ListNode(0),*start2=new ListNode(0);
		ListNode* p=start1,*q=start2;
		while(head)
		{
			if(head->val<x)
			{
				p->next=head;
				p=p->next;
			}
			else
			{
				q->next=head;
				q=q->next;
			}
			head=head->next;
		}
		p->next=start2->next;
		q->next=nullptr;
		return start1->next;
    }
};
class Solution1 {
public:
	ListNode* partition(ListNode* head, int x) {
		//����˼�룺�����������pָ��С��x���ұ߽�ڵ㣬qָ����ڵ���x���ұ߽�ڵ㣬curָ��ǰ�ڵ�
		//�����ǰ�ڵ�curС��x����cur�ڵ�嵽p��λ��
		//�����ǰ�ڵ�cur���ڵ���x����cur�ڵ�嵽q��λ��
		if (head == NULL)
			return NULL;
		ListNode* p, * q, * cur, * start;
		p = new ListNode(0);
		start = p;
	    //�ҵ�p�ڵ��λ�ã�pָ��С��x���ұ߽�ڵ�
		p->next = head;
		while (p->next!=NULL && p->next->val < x)
			p = p->next;
		//����������нڵ�С��x�����õ����ڵ㣬����
		if (p->next == NULL)
			return start->next;
		//�ҵ�p�ڵ��λ�ã�qָ����ڵ���x���ұ߽�ڵ�
		q = p->next;
		while (q->next != NULL && q->next->val >= x)
			q = q->next;
		//�������p֮�����нڵ���ڵ���x�����õ����ڵ㣬����
		if (q->next == NULL)
			return start->next;
		//����q֮�����нڵ�
		cur = q->next;
		while (cur != NULL)
		{
			//�����ǰ�ڵ�cur���ڵ���x����cur�ڵ�嵽q��λ��
			if (cur->val >= x)
			{
				q = cur;
				cur = q->next;
			}
			//�����ǰ�ڵ�curС��x����cur�ڵ�嵽p��λ��
			else
			{
				q->next = cur->next;
				cur->next = p->next;
				p->next = cur;
				p = cur;
				cur = q->next;
			}
		}
		return start->next;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 5,1,1,1,1,1 };
	//��ʼ������
	Init_ListNode(head, vec);
	ListNode* p;
	int x = 3;
	p = solute.partition(head, x);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}