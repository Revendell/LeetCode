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
}
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//基本思想：单链表基本操作，记得删除等于val节点内存空间
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* p = start, * toDelete = nullptr;
		while (p != NULL && p->next != NULL)
		{
			if (p->next->val == val)
			{
				toDelete = p->next;
				p->next = p->next->next;
				delete toDelete;
			}	
			else
			    p = p->next;
		}
		return start->next;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 6,6,6,1,2,3,6,4,5,6 };
	Init_ListNode(head, vec);
	ListNode* p;
	int val = 6;
	p = solute.removeElements(head, val);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}