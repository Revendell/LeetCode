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
		//基本思想：栈，利用栈存储需要交换的节点
		int len = 0;
		ListNode* p , * q, * pre;
		stack<ListNode*> st;
		//计算链表长度，或者使用快慢双指针找到链表中点
		for (p = head; p != NULL; p = p->next)
			len++;
		if (len <= 2)
			return;
		//找到需要交换的起始节点p
		q = head;
		for (int i = 0; i < len / 2; i++)
			q = q->next;
		p = q->next;
		q->next = NULL;
		//将需要交换的节点入栈，也就是p之后的节点
		while (p != NULL)
		{
			st.push(p);
			p = p->next;
		}
		p = head;
		//进行插入需要交换的节点
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
		//基本思想：第一步，将链表平均分成两半；第二步，将第二个链表逆序；第三步，依次连接两个链表；
		int len = 0;
		ListNode* p, * q, * cur;
		//计算链表长度，或者使用快慢双指针找到链表中点
		for (p = head; p != NULL; p = p->next)
			len++;
		if (len <= 2)
			return;
		//找到需要交换的起始节点p，将链表平均分成两半
		q = head;
		for (int i = 0; i < len / 2; i++)
			q = q->next;
		p = q->next;
		q->next = NULL;
		//将第二个链表逆序
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
		//依次连接两个链表
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
	//初始化链表
	Init_ListNode(head, vec);
	solute.reorderList(head);
	while (head != NULL)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}