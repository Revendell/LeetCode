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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* p;
		p = head;
		//考虑链表为空的情况
		if (p == NULL)
			return head;
		int cnt = 1;
		//获取单链表长度cnt，此时p指向最后一个结点
		while (p->next != NULL)
		{
			cnt++;
			p = p->next;
		}
		//k对链表长取余数，避免多次循环
		k = k % cnt;
		if (k == 0)
			return head;
		//start为旋转后的头结点，也就是当前第cnt-k个节点，end为旋转后的尾结点，也就是当前第cnt-k-1个节点
		ListNode* start, * end;
		end = head;
		//找到start和end位于当前链表的位置
		for (int i = 0; i < cnt - k - 1; i++)
			end = end->next;
		start = end->next;
		//旋转操作：end->next指向空，当前链表最后一个结点p->next指向head
		end->next = NULL;
		p->next = head;
		return start;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	//初始化链表
	Init_ListNode(head, vec);
	int k = 4;
	ListNode* p;
	p = solute.rotateRight(head, k);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}