#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
//解法一：逐一比较
//比较k个节点（每个链表的首节点），获得最小值的节点，将选中的节点接在最终有序链表res的后面。时间复杂度O(k*N)
class Solution1 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		ListNode* res, * head = new ListNode(0);
		res = head;
		if (k == 0)
			return res->next;
		int i, j = 0, flag = 0, minVal;  //j标记一次比较k个链表的首节点最小的节点的下标，minVal标记最小节点值val
		//flag标记已经有几个链表到表尾NULL扫描完了，达到k循环结束，表示k个链表都扫描完了
		while (flag < k)
		{
			minVal = 6553500;
			//一次比较k个链表的首节点找到最小的节点的下标j和最小值minVal
			for (i = 0; i < k; i++)
			{
				if (lists[i] != NULL && lists[i]->val < minVal)
				{
					minVal = lists[i]->val;
					j = i;
				}
			}
			//对于所有k个链表都为NULL的情况，如果有lists[j]为空，表示lists[0]为空且其它链表也为空，不断flag++达到k大小返回NULL
			if (lists[j] == NULL)
			{
				flag++;
				continue;
			}
			//找到最小的节点lists[j]放入最终有序链表res后面，且该节点指针指向下一个节点lists[j]=lists[j]->next
			head->next = lists[j];
			head = lists[j];
			lists[j] = lists[j]->next;
			//如果下一个节点为空，说明该链表扫描完为空了flag++
			if (lists[j] == NULL)
				flag++;
		}
		return res->next;
	}
};
//解法二：分治思想
//使用双指针，i=0指向lists头，j=k-1指向lists尾，不断i++，j--比较两个链表合并成一个有序链表，最终合并成一个有序链表res返回。时间复杂度O(N*logk)
class Solution2 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		if (k == 0)
			return NULL;
		int i = 0, j = k - 1; 
		while (j > 0)
		{
			//不断合并两个链表，并将合并的有序链表存放在i节点，相当于k长度链表合并成k/2个链表保存在lists前k/2位置，然后i=0再重新合并i=0到j=k/2之间的链表存放入0到k/4lists位置
			while (i < j)
			{
				lists[i] = mergeTwoLists(lists[i], lists[j]);
				i++;
				j--;
			}
			i = 0;
		}
		
		return lists[0];
	}
	//合并两个链表成一个有序链表
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l3, * head;
		l3 = new ListNode(0);
		head = l3;
		//当两个链表都非空时：如果节点l1<=节点，将节点l1加到l3后l1到下一节点l1=l1->next，否则将节点l2加到l3后l2到下一节点l2=l2->next
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				l3->next = l1;
				l1 = l1->next;
			}
			else
			{
				l3->next = l2;
				l2 = l2->next;
			}
			l3 = l3->next;
		}
		//当一个链表为空了，另一个非空链表，直接加到l3后面
		if (l1 == NULL)
			l3->next = l2;
		else
			l3->next = l1;
		return head->next;
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
	Solution2 solute;
	int n = 3;
	vector<ListNode*> lists;
	ListNode* head = new ListNode(0), * res;
	CreateList(head, n);
	lists.push_back(head->next);
	head = new ListNode(0);
	CreateList(head, n);
	lists.push_back(head->next);
	res = solute.mergeKLists(lists);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}