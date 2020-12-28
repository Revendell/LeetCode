#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* oddEvenList(ListNode* head) {
        //基本思想：单链表的基本操作，head是偶链表的头p是偶链表的尾，head2是奇链表的头q是奇链表的尾
        //cur指向当前节点，nextnode指向下一个节点，如果cur当前节点是偶节点则加入偶链表的尾端，否则加入奇链表的尾端
        if(head==NULL) return head;
        ListNode* p=head,*q=head->next,*cur,*nextnode,*head2=head->next;
        if(q==NULL) return head;
        cur=q->next;
        p->next=NULL;
        q->next=NULL;
        int i=0;
        while(cur)
        {
            nextnode=cur->next;
            if(i%2==0)
            {
                p->next=cur;
                cur->next=NULL;
                p=cur;
            }
            else
            {
                q->next=cur;
                cur->next=NULL;
                q=cur;
            }
            i++;
            cur=nextnode;
        }
        p->next=head2;
        return head;
    }
};
int main()
{
    Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	Init_ListNode(head, vec);
	ListNode* res=solute.oddEvenList(head);
	while(res)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
