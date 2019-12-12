#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* temp = new ListNode(0), * pre,* p;  //tempָ��ת��k���ڵ��ͷ�ڵ㣬pre->next�洢���ص�ͷ�ڵ㣬pΪ��ת��k���ڵ��ͷ�ڵ�
		vector<ListNode*> reverseNode;  //�洢��ת�ڵ��ջ
		temp->next = head;  //��ʼ��temp��tempָ��ת��k���ڵ��ͷ�ڵ�
		pre = temp;  //pre->next�洢���ص�ͷ�ڵ�
		int i;
		//������ͷ��ʼɨ��
		while (temp->next != NULL)
		{
			reverseNode.clear();
			//pΪ��ת��k���ڵ��ͷ�ڵ�
			p = temp->next;
			i = 0;
			//����ת��k���ڵ���ջ
			while (i < k)
			{
				reverseNode.push_back(p);
				p = p->next;
				//����ڵ���������k���������������ʣ��Ľڵ㱣��ԭ��˳�򣬲��÷�תֱ�ӷ��ؽ��
				if (p == NULL && i != k - 1)
					return pre->next;
				i++;
			}
			//����ת��k���ڵ��ջ��ʵ����k���ڵ㷭ת
			while (i > 0)
			{
				temp->next = reverseNode[i-1];
				temp = reverseNode[i-1];
				i--;
			}
			//tempָ����һ����ת��k���ڵ��ͷ�ڵ�
			temp->next = p;
		}
		return pre->next;
	}
};
//β�巨��������
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
	int n = 5, k = 3;
	ListNode* head = new ListNode(0), * res;
	CreateList(head, n);
	res = solute.reverseKGroup(head->next, k);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}
