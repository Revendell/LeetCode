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
		ListNode* temp = new ListNode(0), * pre,* p;  //temp指向翻转的k个节点的头节点，pre->next存储返回的头节点，p为翻转的k个节点的头节点
		vector<ListNode*> reverseNode;  //存储翻转节点的栈
		temp->next = head;  //初始化temp，temp指向翻转的k个节点的头节点
		pre = temp;  //pre->next存储返回的头节点
		int i;
		//从链表头开始扫描
		while (temp->next != NULL)
		{
			reverseNode.clear();
			//p为翻转的k个节点的头节点
			p = temp->next;
			i = 0;
			//将翻转的k个节点入栈
			while (i < k)
			{
				reverseNode.push_back(p);
				p = p->next;
				//如果节点总数不是k的整数倍，将最后剩余的节点保持原有顺序，不用翻转直接返回结果
				if (p == NULL && i != k - 1)
					return pre->next;
				i++;
			}
			//将翻转的k个节点出栈，实现了k个节点翻转
			while (i > 0)
			{
				temp->next = reverseNode[i-1];
				temp = reverseNode[i-1];
				i--;
			}
			//temp指向下一个翻转的k个节点的头节点
			temp->next = p;
		}
		return pre->next;
	}
};
//尾插法创建链表
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
