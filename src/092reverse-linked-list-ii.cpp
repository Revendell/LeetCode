#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
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
		ListNode* q = new ListNode;
		q->val = vec[i];
		p->next = q;
		p = p->next;
	}
	p->next = NULL;
}
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//�򻯰棺ͷ�巨����[m,n]��������pָ��m-1��qָ��n+1��curָ��ǰ�ڵ㣬nextvָ��cur����һ���ڵ㣬finishָ�����������һ���ڵ�
		ListNode* start=new ListNode(0);
		start->next=head;
		ListNode* p=start, * q=head, * cur, * nextv,*finish;
		while(--m)
			p=p->next;
		while(n--)
			q=q->next;
		cur=p->next;
		finish=cur;
		nextv=cur->next;
		p->next=nullptr;
		while(cur!=q)
		{
			cur->next=p->next;
			p->next=cur;
			cur=nextv;
			if(cur!=nullptr)
				nextv=cur->next;
		}
		finish->next=q;
		return start->next;
	}
};
class Solution1 {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//����˼�룺�����������cur��p��q����������Ҫ��ת�Ľڵ㣬���������ǲ��Ͻ�cur�ŵ�q���棬���preָ��q
		if (head == NULL)
			return NULL;
		//pָ���m���ڵ㣬qָ���n���ڵ㣬preָ��p��ǰһ���ڵ㣬cur��p��q������Ҫ��ת�Ľڵ�
		ListNode* p, * q, * cur, * pre;
		int flag = m;
		pre = new ListNode;
		pre->next = head;
		m--;
		n--;
		//�ҵ���m���ڵ�p�Լ�ָ��p��ǰһ���ڵ�pre
		while (m != 0)
		{
			pre = pre->next;
			m--;
			n--;
		}
		p = pre->next;
		q = p;
		//�ҵ���n���ڵ�q
		while (n != 0)
		{
			q = q->next;
			n--;
		}
		//cur��p��q����������Ҫ��ת�Ľڵ㣬���������ǲ��Ͻ�cur�ŵ�q���棬���preָ��q
		while (p != q)
		{
			cur = p;
			p = p->next;
			cur->next = q->next;
			q->next = cur;
		}
		pre->next = q;
		//���m=1����head�ڵ�Ҳ��ת�˲��ܷ���head
		if (flag == 1)
			return pre->next;
		else
		    return head;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode;
	vector<int> vec = { 1,2,3,4,5 };
	//��ʼ������
	Init_ListNode(head, vec);
	ListNode* p;
	int m = 1, n = 1;
	p = solute.reverseBetween(head, m, n);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}