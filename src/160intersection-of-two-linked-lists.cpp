#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
void Init_ListNode(ListNode* headA, vector<int> vec1, int skipA, ListNode* headB, vector<int> vec2, int skipB)
{
	int i;
	ListNode* p1, * p2;
	p1 = headA;
	p1->val = vec1[0];
	p2 = headB;
	p2->val = vec2[0];
	for (i = 1; i < skipA; i++)
	{
		ListNode* q = new ListNode(vec1[i]);
		p1->next = q;
		p1 = p1->next;
	}
	for (i = 1; i < skipB; i++)
	{
		ListNode* q = new ListNode(vec2[i]);
		p2->next = q;
		p2 = p2->next;
	}
	for (; i < vec2.size(); i++)
	{
		ListNode* q = new ListNode(vec2[i]);
		p1->next = q;
		p1 = p1->next;
		p2->next = q;
		p2 = p2->next;
	}
	p1->next = NULL;
	p2->next = NULL;
}
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//����˼�룺˫ָ�뷨��һ��ʼ�뷨�ܻ��������������pA��headA��������Ȧ��pB��headB��������Ȧ
		//���headA��headB֮�����غϽڵ㣬pA��pB�������������ȵ���С��������ѭ������֮ǰO(m*n)λ�ڵ�һ���غϽڵ㴦����
		//�ٷ��𰸺����pA����headA���������ת��headB��pB����headB���������ת��headA������pA��pB��ѭ��O(m+n)֮ǰλ�ڵ�һ���غϽڵ㴦����
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* pA = headA, * pB = headB;
		while (pA != pB)
		{
			pA = pA == NULL ? headB : pA->next;
			pB = pB == NULL ? headA : pB->next;
		}
		return pA;
	}
};
class Solution1 {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//�Ż�����Ҫ�ԣ��Ż�����ԭʼ���뷨
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* pA = headA, * pB = headB;
		while (pA != pB)
		{
			pA = pA == NULL ? headA : pA->next;
			pB = pB == NULL ? headB : pB->next;
		}
		return pA;
	}
};
class Solution2 {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		//�Ż�����Ҫ�ԣ������ط������Ż�
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode* pA, * pB, * endA, * endB;
		int lenA = 1, lenB = 1, count = 0;
		pA = headA;
		pB = headB;
		while (pA->next != NULL)
		{
			lenA++;
			pA = pA->next;
		}
		endA = pA;
		while (pB->next != NULL)
		{
			lenB++;
			pB = pB->next;
		}
		endB = pB;
		if (endA != endB)
			return NULL;
		pA = headA;
		pB = headB;
		while (count <= lenA * lenB)
		{
			if (pA == pB)
				return pA;
			if (pA == endA)
				pA = headA;
			else
				pA = pA->next;
			if (pB == endB)
				pB = headB;
			else
				pB = pB->next;
			count++;
		}
		return NULL;
	}
};
int main()
{
	Solution solute;
	ListNode* headA = new ListNode(0);
	ListNode* headB = new ListNode(0);
	int skipA = 2, skipB = 3;
	vector<int> vec1 = { 4,1,8,4,5 };
	vector<int> vec2 = { 5,0,1,8,4,5 };
	//��ʼ������
	Init_ListNode(headA, vec1, skipA, headB, vec2, skipB);
	ListNode* p = solute.getIntersectionNode(headA, headB);
	if (p != NULL)
		cout << p->val << endl;
	else
		cout << "NULL" << endl;
	return 0;
}
