#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
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
    bool isPalindrome(ListNode* head) {
		//基本思想：单链表基本操作，可以将链表的后半部分反转（修改链表结构），然后将前半部分和后半部分进行比较。
		//比较完成后我们应该将链表恢复原样，因为使用该函数的人不希望链表结构被更改。
		//第一步：找到链表中间节点，采用快慢指针
		//第二步：反转后半部分链表
		//第三步：判断是否为回文链表
		//第四步：恢复链表（可有可无）
		if (head == nullptr)
			return true;
		ListNode* fast = head->next, * slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* p = slow->next;
		slow->next = nullptr;
		ListNode* start = new ListNode(0);
		while (p != NULL)
		{
			ListNode* q = p->next;
			p->next = start->next;
			start->next = p;
			p = q;
		}
		p = start->next;
		while (p != nullptr && head != nullptr)
		{
			if (p->val != head->val)
				return false;
			p = p->next;
			head = head->next;
		}
		return true;
    }
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,2,1 };
	Init_ListNode(head, vec);
	cout << solute.isPalindrome(head) << endl;
	return 0;
}