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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //基本思想：反转链表+双指针
        l1=reverseList(nullptr,l1);
        l2=reverseList(nullptr,l2);
        ListNode* start=new ListNode(0),*l3;
        l3=start;
        int carry=0;
        while(l1||l2||carry)
        {
            int num1=l1==nullptr?0:l1->val;
            int num2=l2==nullptr?0:l2->val;
            int cur=num1+num2+carry;
            ListNode* tmp=new ListNode(cur%10);
            l3->next=tmp;
            carry=cur>9?1:0;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            l3=l3->next;
        } 
        return reverseList(nullptr,start->next);
    }
    ListNode* reverseList(ListNode* pre,ListNode* cur)
    {
        if(cur==nullptr)
            return pre;
        ListNode* post=cur->next;
        cur->next=pre;
        return reverseList(cur,post);
    }
};
int main()
{
    Solution solute;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	Init_ListNode(l1, vec);
	Init_ListNode(l2, vec);
	ListNode* p;
	p = solute.addTwoNumbers(l1,l2);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}