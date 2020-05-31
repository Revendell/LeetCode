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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* p;
		p = head;
		//��������Ϊ�յ����
		if (p == NULL)
			return head;
		int cnt = 1;
		//��ȡ��������cnt����ʱpָ�����һ�����
		while (p->next != NULL)
		{
			cnt++;
			p = p->next;
		}
		//k������ȡ������������ѭ��
		k = k % cnt;
		if (k == 0)
			return head;
		//startΪ��ת���ͷ��㣬Ҳ���ǵ�ǰ��cnt-k���ڵ㣬endΪ��ת���β��㣬Ҳ���ǵ�ǰ��cnt-k-1���ڵ�
		ListNode* start, * end;
		end = head;
		//�ҵ�start��endλ�ڵ�ǰ�����λ��
		for (int i = 0; i < cnt - k - 1; i++)
			end = end->next;
		start = end->next;
		//��ת������end->nextָ��գ���ǰ�������һ�����p->nextָ��head
		end->next = NULL;
		p->next = head;
		return start;
	}
};
int main()
{
	Solution solute;
	ListNode* head = new ListNode(0);
	vector<int> vec = { 1,2,3,4,5 };
	//��ʼ������
	Init_ListNode(head, vec);
	int k = 4;
	ListNode* p;
	p = solute.rotateRight(head, k);
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}