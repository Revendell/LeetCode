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
	bool hasCycle(ListNode* head) {
		//����˼�룺��ϣ��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(n)
		unordered_set<ListNode*> dictNode;
		while (head != NULL)
		{
			if (dictNode.find(head) == dictNode.end())
				dictNode.insert(head);
			else
				return true;
			head = head->next;
		}
		return false;
	}
};
class Solution1 {
public:
	bool hasCycle(ListNode* head) {
		//����˼�룺����˫ָ�룬ͨ��ʹ�þ��в�ͬ�ٶȵĿ졢������ָ��������������ָ���������л�
		//ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)
		ListNode* slow, * fast;
		if (head == NULL || head->next == NULL)
			return false;
		slow = head;
		fast = head->next;
		while (fast != slow)
		{
			if (fast == NULL || fast->next == NULL)
				return false;
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	//��ʼ������
	Init_ListNode(head, vec);
	cout << solute.hasCycle(head) << endl;
	return 0;
}