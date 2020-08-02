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
	void deleteNode(ListNode* node) {
		//����˼�룺�������������
		ListNode* post = node->next;
		node->val = post->val;
		node->next = post->next;
		delete(post);    //�����new��������Ҫdelete������Ŀ�Ľڵ㲻֪����ջ�ռ仹�Ƕѿռ�
		return;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	Init_ListNode(head, vec);
	solute.deleteNode(head->next->next);
	while (head)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}