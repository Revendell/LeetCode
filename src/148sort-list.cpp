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
		//����˼�룺�鲢���򣬲��Ϸָ�����ֱ��ÿ���ڵ㶼�Ͽ���Ȼ�󲻶������ϲ�����������
		if (head == NULL)
			return NULL;
		return MergeSort(head);
	}
	ListNode* Merge(ListNode* l1, ListNode* l2)
	{
		//�������ڽ���start�ڵ㣬��������start->next����������ͷ�ڵ�
		ListNode* start = new ListNode(0), * cur;
		cur = start;
		//�ϲ�����l1��l2
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
			//����ָ���ҵ�������м�ڵ㣬preָ���м�ڵ��ǰһ���ڵ������Ͽ�����
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
		//����˼�룺����������һ���ڵ���Ϊ���ᣬ��С������Ľڵ�ŵ���ߴ�������Ľڵ�ŵ��ұߣ�Ȼ������ݹ�����������ߵĽڵ�
		if (head == NULL)
			return NULL;
		//�������ڽ���start�ڵ㣬��������start->next����������ͷ�ڵ�
		ListNode* tail = head, * start = new ListNode(0);
		start->next = head;
		while (tail->next != NULL)
			tail = tail->next;
		return QuickSort(start, tail);
	}
	//��������head->next��tail�Ľڵ㣬����head�ڵ���Ϊ�˷��������С�Ľڵ�ǰ��ͬʱ���Ա��������������ߴ�������״̬��������Ч�ڵ㲻��Ҫ����
	ListNode* QuickSort(ListNode* head, ListNode* tail)
	{
		if (head->next == tail || head == tail)
			return tail;
		else
		{
			//preָ�������������һ���ڵ㣬pivotΪ����ȡ��һ���ڵ㣬endָ��������ұ����һ���ڵ�
			ListNode* pre = head, * pivot = head->next, * end = head->next;
			//���������ұ����еĽڵ�
			while (end->next != tail->next)
			{
				//������С��ȫ���ŵ������ǰ��
				if (end->next->val < pivot->val)
				{
					ListNode* cur = end->next;
					end->next = cur->next;
					pre->next = cur;
					pre = pre->next;
				}
				//����������Ȼ��������ĺ��棬����������һ���ڵ�
				else
					end = end->next;
			}
			pre->next = pivot;    //����������������
			QuickSort(head, pre);  //�����ݹ�������ߵĽڵ�
			QuickSort(pivot, end);  //�����ݹ������ұߵĽڵ�
			return head->next;  //head����Ч�ڵ㣬��󷵻�head->next
		}
	}
};
int main()
{
	Solution1 solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { -1,5,3,4,0 };
	//��ʼ������
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