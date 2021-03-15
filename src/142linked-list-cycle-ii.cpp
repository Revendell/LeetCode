#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
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
	p->next = head->next;
}
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		//简化版
        if(head==nullptr||head->next==nullptr)
            return nullptr;
        ListNode* slow=head,*fast=head->next;
        while(slow!=fast)
        {
            if(fast==nullptr||fast->next==nullptr)
                return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=slow->next;
        fast=head;
        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
class Solution1 {
public:
	ListNode* detectCycle(ListNode* head) {
		//基本思想：哈希表
		unordered_set<ListNode*> dictNode;
		while (head != NULL)
		{
			if (dictNode.find(head) == dictNode.end())
				dictNode.insert(head);
			else
				return head;
			head = head->next;
		}
		return NULL;
	}
};
class Solution2 {
public:
	ListNode* detectCycle(ListNode* head) {
		//基本思想：快慢双指针，设起始点到入环点距离M，环中距离N
		//第一阶段当slow到达入环点已经走了M步，fast走了2*M步，到达M+M%N节点
		//此时fast在slow前M%N距离，也就是slow在fast前N-M%N距离，因为slow走1步fast走2步
		//第二阶段slow再走N-M%N步两者相遇，相遇点距离入环点N-(N-M%N)也就是M%N
		//第三阶段如果此时一个指针从起始点走M步一次一步，slow也走M步，那么两者在入环点相遇
		ListNode* slow, * fast;
		slow = head;
		fast = head;
		while (true)
		{
			if (fast == NULL || fast->next == NULL)
				return NULL;
			slow = slow->next;
			fast = fast->next->next;
			if (slow==fast)
				break;
		}
		fast = head;
		while (fast != slow)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};
int main()
{
	Solution1 solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	//初始化链表
	Init_ListNode(head, vec);
	ListNode* p = solute.detectCycle(head);
	cout << p->val << endl;
	return 0;
}