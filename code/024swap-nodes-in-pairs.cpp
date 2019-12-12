#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//tempָ��ת�������ڵ��ǰһ���ڵ㣬first=temp->nextָ��ת�ĵ�һ���ڵ㣬second=temp->next->nextָ��ת�ĵڶ����ڵ�
		ListNode* temp = new ListNode(0), * first, * second, * pre;  //pre�洢����ͷ�ڵ�
		if (head == NULL || head->next == NULL)  //ת��������ֻ��һ���ڵ����Ϊ�գ�ֱ�ӷ���head
			return head;
		temp->next = head;  //��ʼһ��temp��temp��һ���ڵ�ָ������ͷhead
		pre = temp;  //pre->next�洢����ͷ�ڵ�
		//�����ת�������ڵ㶼��Ϊ�գ����з�ת
		while (temp->next != NULL && temp->next->next != NULL)
		{

			first = temp->next;  //firstָ��ת�ĵ�һ���ڵ�
			second = temp->next->next;  //secondָ��ת�ĵڶ����ڵ�
			first->next = second->next;  //��ת�ĵ�һ��������һ���ڵ�ָ��ڶ����ڵ���һ���ڵ�
			temp->next = second;  //��ת�ĵڶ���������תǰһ���ڵ�ָ��ڶ����ڵ�
			second->next = first;  //��ת�ĵ����������ڶ����ڵ�ָ���һ���ڵ�
			temp = temp->next->next;  //tempָ����һ����ת�������ڵ��ǰһ���ڵ�
		}
		return pre->next;
	}
};
void CreateList(ListNode* head, int n)
{
	ListNode* p;
	for (int i = 1; i <= n; i++)
	{
		p = new ListNode(i);
		head->next = p;
		head = p;
	}
}
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0), * res;
	int n = 5;
	CreateList(head, n);
	res = solute.swapPairs(head->next);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
