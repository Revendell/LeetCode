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
		//����˼�룺������������������Խ�����ĺ�벿�ַ�ת���޸�����ṹ����Ȼ��ǰ�벿�ֺͺ�벿�ֽ��бȽϡ�
		//�Ƚ���ɺ�����Ӧ�ý�����ָ�ԭ������Ϊʹ�øú������˲�ϣ������ṹ�����ġ�
		//��һ�����ҵ������м�ڵ㣬���ÿ���ָ��
		//�ڶ�������ת��벿������
		//���������ж��Ƿ�Ϊ��������
		//���Ĳ����ָ��������п��ޣ�
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