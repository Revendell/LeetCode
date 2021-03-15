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
		//�򻯰�
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
		//����˼�룺��ϣ��
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
		//����˼�룺����˫ָ�룬����ʼ�㵽�뻷�����M�����о���N
		//��һ�׶ε�slow�����뻷���Ѿ�����M����fast����2*M��������M+M%N�ڵ�
		//��ʱfast��slowǰM%N���룬Ҳ����slow��fastǰN-M%N���룬��Ϊslow��1��fast��2��
		//�ڶ��׶�slow����N-M%N����������������������뻷��N-(N-M%N)Ҳ����M%N
		//�����׶������ʱһ��ָ�����ʼ����M��һ��һ����slowҲ��M������ô�������뻷������
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
	//��ʼ������
	Init_ListNode(head, vec);
	ListNode* p = solute.detectCycle(head);
	cout << p->val << endl;
	return 0;
}