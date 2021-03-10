#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		//�򻯰棺����ָ��
		ListNode* tmp=new ListNode(0,head);
        ListNode* fast = tmp, *slow=tmp;
		while(n--)
			fast=fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return tmp->next;
    }
};
//˫ָ�뷨
class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = 0, i = 0;
		ListNode* s, * p, *temp;
		s = head;
		if (n < 1 || head == NULL)
			return NULL;
		//����˫ָ�뷨:ָ��pָ��ͷ�ڵ㣬ָ��s��ָ��p��ĵ�n��λ�ã�����ָ��ͬ�����β�ƶ���ֱ��s�ƶ�����β��s->next=NULL����ô��ʱp->next����Ҫɾ���Ľڵ�
		while (n > 0)
		{
			n--;
			s = s->next;
		}
		//���n���ڱ�����ʾɾ���Ľڵ���ǵ�һ���ڵ�ֱ�ӷ���head->next
		if (s == NULL)
			return head->next;
		p = head;
		//����ָ��p,sͬ�����β�ƶ���ֱ��s�ƶ�����β��s->next=NULL
		while (s->next != NULL)
		{
			s = s->next;
			p = p->next;
		}
		//ɾ��p->next�ڵ�
		temp = p->next;
		p->next = temp->next;
		delete temp;
		return head;
	}
};
class Solution2 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len=0,i=0;
		ListNode* s, *p;
		s = head;
		//��һ�α����õ�����ĳ���len
		while (s != NULL)
		{
			len++;
			s = s->next;
		}
		if (n > len|| n < 1 || head == NULL)
			return NULL;
		//���n���ڱ�����ʾɾ���Ľڵ���ǵ�һ���ڵ�ֱ�ӷ���head->next
		if (n == len)
			return head->next;
		s = head;
		//˼·�ܼ򵥣����α�������һ�α����õ�����ĳ���len���ڶ��α����ҵ�Ҫɾ���ڵ��λ��len-n+1
		while (s != NULL)
		{
			i++;
			//�ҵ�Ҫɾ���Ľڵ�p=s->next����ɾ���ڵ�p
			if (i == len - n)
			{
				p = s->next;
				s->next = p->next;
				delete p;
				break;
			}
			s = s->next;
		}
		return head;
	}
};
//ͷ�巨����n��Ԫ�ش���ͷ�ڵ�ĵ�����L
void CreateListHead(ListNode* L, int n)
{
	ListNode* p;
	int i;
	for (i = 0; i < n; i++)
	{
		p = new ListNode(i + 1);
		p->next = L->next;
		L->next = p;
	}
}
int main()
{
	int n = 1;
	Solution1 solute;
	ListNode* head = new ListNode(0), *s;
	CreateListHead(head, 5);
	s = solute.removeNthFromEnd(head->next, n);
	while (s != NULL)
	{
		cout << s->val << endl;
		s = s->next;
	}
	return 0;

}