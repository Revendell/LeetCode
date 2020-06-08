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
	ListNode* reverseList(ListNode* head) {
		//基本思想：迭代
		ListNode* start = new ListNode(0), * p;
		while (head != NULL)
		{
			p = head;
			head = head->next;
			p->next = start->next;
			start->next = p;
		}
		return start->next;
	}
};
class Solution1 {
public:
	ListNode* reverseList(ListNode* head) {
		//基本思想：递归
		return Recursion(NULL, head);
	}
	ListNode* Recursion(ListNode* pre, ListNode* cur)
	{
		if (cur == NULL)
			return pre;
		ListNode* post = cur->next;
		cur->next = pre;
		return Recursion(cur, post);
	}
};
int main()
{
	Solution1 solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	Init_ListNode(head, vec);
	ListNode* p;
	p = solute.reverseList(head);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}