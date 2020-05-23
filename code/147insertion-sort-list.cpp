#include<iostream>
#include<algorithm>
#include<vector>
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
	p->next = NULL;
}
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		//基本思想：单链表操作
		if (head == NULL)
			return NULL;
		ListNode* start = new ListNode(0);
		start->next = head;
		//p指向当前需要插入的节点，end为当前已排好序的最后一个节点
		ListNode* p = head->next, * end = head;
		while (p != NULL)
		{
			end->next = p->next;
			//找到p需要插入的位置节点q之后
			ListNode* q = start;
			while (q->next != NULL && p->val > q->next->val && q != end->next)
				q = q->next;
			p->next = q->next;
			q->next = p;
			//如果q=end，p插入的是end之后，则p是排好序节点中最大的节点，更新end
			if (q == end)
				end = end->next;
			p = end->next;
		}
		return start->next;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 6,5,3,1,8,7,2,4 };
	//vector<int> vec = { 6,5,3,1,8,7 };
	//初始化链表
	Init_ListNode(head, vec);
	ListNode* p = solute.insertionSortList(head);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}