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
		//简化版：快慢指针
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
//双指针法
class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = 0, i = 0;
		ListNode* s, * p, *temp;
		s = head;
		if (n < 1 || head == NULL)
			return NULL;
		//采用双指针法:指针p指向头节点，指针s在指针p后的第n个位置，两个指针同步向表尾移动，直到s移动到表尾即s->next=NULL，那么此时p->next就是要删除的节点
		while (n > 0)
		{
			n--;
			s = s->next;
		}
		//如果n等于表长，表示删除的节点就是第一个节点直接返回head->next
		if (s == NULL)
			return head->next;
		p = head;
		//两个指针p,s同步向表尾移动，直到s移动到表尾即s->next=NULL
		while (s->next != NULL)
		{
			s = s->next;
			p = p->next;
		}
		//删除p->next节点
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
		//第一次遍历得到链表的长度len
		while (s != NULL)
		{
			len++;
			s = s->next;
		}
		if (n > len|| n < 1 || head == NULL)
			return NULL;
		//如果n等于表长，表示删除的节点就是第一个节点直接返回head->next
		if (n == len)
			return head->next;
		s = head;
		//思路很简单，两次遍历，第一次遍历得到链表的长度len，第二次遍历找到要删除节点的位置len-n+1
		while (s != NULL)
		{
			i++;
			//找到要删除的节点p=s->next，并删除节点p
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
//头插法建立n个元素带表头节点的单链表L
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