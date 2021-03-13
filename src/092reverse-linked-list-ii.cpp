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
		//简化版：头插法，对[m,n]进行逆序，p指向m-1，q指向n+1，cur指向当前节点，nextv指向cur的下一个节点，finish指向逆序后的最后一个节点
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
		//基本思想：单链表操作，cur从p到q遍历所有需要反转的节点，具体做法是不断将cur放到q后面，最后pre指向q
		if (head == NULL)
			return NULL;
		//p指向第m个节点，q指向第n个节点，pre指向p的前一个节点，cur从p到q遍历需要反转的节点
		ListNode* p, * q, * cur, * pre;
		int flag = m;
		pre = new ListNode;
		pre->next = head;
		m--;
		n--;
		//找到第m个节点p以及指向p的前一个节点pre
		while (m != 0)
		{
			pre = pre->next;
			m--;
			n--;
		}
		p = pre->next;
		q = p;
		//找到第n个节点q
		while (n != 0)
		{
			q = q->next;
			n--;
		}
		//cur从p到q遍历所有需要反转的节点，具体做法是不断将cur放到q后面，最后pre指向q
		while (p != q)
		{
			cur = p;
			p = p->next;
			cur->next = q->next;
			q->next = cur;
		}
		pre->next = q;
		//如果m=1，则head节点也反转了不能返回head
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
	//初始化链表
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