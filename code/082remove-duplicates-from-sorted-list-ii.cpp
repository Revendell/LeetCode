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
	ListNode* deleteDuplicates(ListNode* head) {
		//����˼�룺�����������pָ��ǰ�ڵ㣬qָ��p֮��ڵ㣬preָ��p֮ǰ�ڵ�
		//���p��ֵ��q��ֵ��ȣ�ȥ���ظ��ڵ㣬pһֱ�����ƶ�����ֵ��Ȼ��pre->next=p
		ListNode* p, * q, * start;
		ListNode* pre = new ListNode(0);
		start = pre;
		pre->next = head;
		if (head == NULL)
			return head;
		p = pre->next;
		q = p->next;
		//ѭ����������ÿһ���ڵ�
		while (q != NULL)
		{
			//���p��ֵ��q��ֵ����ȣ�p�����ƶ�һ��
			if (p->val != q->val)
			{
				pre = p;
				p = q;
				q = q->next;
			}
			//���p��ֵ��q��ֵ��ȣ�ȥ���ظ��ڵ㣬pһֱ�����ƶ�����ֵ��Ȼ��pre->next=p
			else
			{
				while (p != NULL && p->val == q->val)
				{
					p = p->next;
				}
				pre->next = p;
				if (p != NULL)
					q = p->next;
				else
					q = p;
			}
		}
		return start->next;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,3,4,4,5 };
	//��ʼ������
	Init_ListNode(head, vec);
	ListNode* p;
	p = solute.deleteDuplicates(head);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}