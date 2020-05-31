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
	ListNode* sortList(ListNode* head) {
		//基本思想：归并排序，不断分割链表直至每个节点都断开，然后不断两两合并成有序链表
		if (head == NULL)
			return NULL;
		return MergeSort(head);
	}
	ListNode* Merge(ListNode* l1, ListNode* l2)
	{
		//技巧在于建立start节点，这样返回start->next就是排序后的头节点
		ListNode* start = new ListNode(0), * cur;
		cur = start;
		//合并链表l1和l2
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 == NULL ? l2 : l1;
		return start->next;
	}
	ListNode* MergeSort(ListNode* head)
	{
		if (head ->next == NULL)
			return head;
		else
		{
			//快慢指针找到链表的中间节点，pre指向中间节点的前一个节点用来断开链表
			ListNode* fast = head, * slow = head, * pre =head;
			while (true)
			{
				if (fast == NULL || fast->next == NULL)
					break;
				pre = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			pre->next = NULL;
			return Merge(MergeSort(head), MergeSort(slow));
		}
	}
};
class Solution1 {
public:
	ListNode* sortList(ListNode* head) {
		//基本思想：快速排序，以一个节点作为枢轴，将小于枢轴的节点放到左边大于枢轴的节点放到右边，然后继续递归除枢轴外两边的节点
		if (head == NULL)
			return NULL;
		//技巧在于建立start节点，这样返回start->next就是排序后的头节点
		ListNode* tail = head, * start = new ListNode(0);
		start->next = head;
		while (tail->next != NULL)
			tail = tail->next;
		return QuickSort(start, tail);
	}
	//快速排序head->next到tail的节点，其中head节点是为了方便比枢轴小的节点前移同时可以保持枢轴左右两边处于连接状态，属于无效节点不需要排序
	ListNode* QuickSort(ListNode* head, ListNode* tail)
	{
		if (head->next == tail || head == tail)
			return tail;
		else
		{
			//pre指向枢轴的左边最后一个节点，pivot为枢轴取第一个节点，end指向枢轴的右边最后一个节点
			ListNode* pre = head, * pivot = head->next, * end = head->next;
			//遍历枢轴右边所有的节点
			while (end->next != tail->next)
			{
				//比枢轴小的全部放到枢轴的前面
				if (end->next->val < pivot->val)
				{
					ListNode* cur = end->next;
					end->next = cur->next;
					pre->next = cur;
					pre = pre->next;
				}
				//比枢轴大的依然放在枢轴的后面，继续遍历下一个节点
				else
					end = end->next;
			}
			pre->next = pivot;    //保持左右两边连接
			QuickSort(head, pre);  //继续递归枢轴左边的节点
			QuickSort(pivot, end);  //继续递归枢轴右边的节点
			return head->next;  //head是无效节点，最后返回head->next
		}
	}
};
int main()
{
	Solution1 solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { -1,5,3,4,0 };
	//初始化链表
	Init_ListNode(head, vec);
	ListNode* p = solute.sortList(head);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}