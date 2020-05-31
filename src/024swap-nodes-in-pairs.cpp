#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//temp指向翻转的两个节点的前一个节点，first=temp->next指向翻转的第一个节点，second=temp->next->next指向翻转的第二个节点
		ListNode* temp = new ListNode(0), * first, * second, * pre;  //pre存储返回头节点
		if (head == NULL || head->next == NULL)  //转换的链表只有一个节点或者为空，直接返回head
			return head;
		temp->next = head;  //初始一个temp，temp下一个节点指向链表头head
		pre = temp;  //pre->next存储返回头节点
		//如果翻转的两个节点都不为空，进行翻转
		while (temp->next != NULL && temp->next->next != NULL)
		{

			first = temp->next;  //first指向翻转的第一个节点
			second = temp->next->next;  //second指向翻转的第二个节点
			first->next = second->next;  //翻转的第一个操作第一个节点指向第二个节点下一个节点
			temp->next = second;  //翻转的第二个操作翻转前一个节点指向第二个节点
			second->next = first;  //翻转的第三个操作第二个节点指向第一个节点
			temp = temp->next->next;  //temp指向下一个翻转的两个节点的前一个节点
		}
		return pre->next;
	}
};
void CreateList(ListNode* head, int n)
{
	ListNode* p;
	for (int i = 1; i <= n; i++)
	{
		p = new ListNode(i);
		head->next = p;
		head = p;
	}
}
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0), * res;
	int n = 5;
	CreateList(head, n);
	res = solute.swapPairs(head->next);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
