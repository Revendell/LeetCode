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
		//简化版：单链表操作，链表start1中元素都小于x，链表start2中元素都大于等于x，最后合并两个链表
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
		//基本思想：单链表操作，p指向小于x的右边界节点，q指向大于等于x的右边界节点，cur指向当前节点
		//如果当前节点cur小于x，将cur节点插到p的位置
		//如果当前节点cur大于等于x，将cur节点插到q的位置
		if (head == NULL)
			return NULL;
		ListNode* p, * q, * cur, * start;
		p = new ListNode(0);
		start = p;
	    //找到p节点的位置，p指向小于x的右边界节点
		p->next = head;
		while (p->next!=NULL && p->next->val < x)
			p = p->next;
		//如果链表所有节点小于x，不用调整节点，返回
		if (p->next == NULL)
			return start->next;
		//找到p节点的位置，q指向大于等于x的右边界节点
		q = p->next;
		while (q->next != NULL && q->next->val >= x)
			q = q->next;
		//如果链表p之后所有节点大于等于x，不用调整节点，返回
		if (q->next == NULL)
			return start->next;
		//遍历q之后所有节点
		cur = q->next;
		while (cur != NULL)
		{
			//如果当前节点cur大于等于x，将cur节点插到q的位置
			if (cur->val >= x)
			{
				q = cur;
				cur = q->next;
			}
			//如果当前节点cur小于x，将cur节点插到p的位置
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
	//初始化链表
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