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
    struct Node{
        ListNode* ptr;
        Node(){}
        Node(ListNode* ptr):ptr(ptr){}
        bool operator>(const Node& a)const{return this->ptr->val>a.ptr->val;}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode();
        ListNode* p=head;
        priority_queue<Node,vector<Node>,greater<Node>> min_heap;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                min_heap.push(Node(lists[i]));
        }
        while(!min_heap.empty())
        {
            Node cur=min_heap.top();
            min_heap.pop();
            p->next=cur.ptr;
            p=p->next;
            if(cur.ptr->next)
            {
                cur.ptr=cur.ptr->next;
                min_heap.push(cur);
            }
        }
        return head->next;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		//����˼�룺�鲢+�ѣ�ά��һ���ѣ�����Ϊÿ��list�ĵ�ǰ��С�Ľڵ㣬�Ѵ�Сlists.size��
		//���ϴӶ���ȡ����С�Ľڵ㣬ȡ����С�Ľڵ�󣬼���ýڵ�����list����һ���ڵ����
        ListNode* head=new ListNode();
        ListNode* p=head;
        vector<ListNode*> min_heap;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                min_heap.push_back(lists[i]);
                push_heap(min_heap.begin(),min_heap.end(),[](ListNode* &a,ListNode* &b){return a->val>b->val;});
            } 
        }
        while(!min_heap.empty())
        {
            ListNode* cur=min_heap[0];
            pop_heap(min_heap.begin(),min_heap.end(),[](ListNode* &a,ListNode* &b){return a->val>b->val;});
            min_heap.pop_back();
            p->next=cur;
            p=p->next;
            cur=cur->next;
            if(cur)
            {
                min_heap.push_back(cur);
                push_heap(min_heap.begin(),min_heap.end(),[](ListNode* &a,ListNode* &b){return a->val>b->val;});
            }
        }
        return head->next;

    }
};
//�ⷨһ����һ�Ƚ�
//�Ƚ�k���ڵ㣨ÿ��������׽ڵ㣩�������Сֵ�Ľڵ㣬��ѡ�еĽڵ����������������res�ĺ��档ʱ�临�Ӷ�O(k*N)
class Solution1 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		ListNode* res, * head = new ListNode(0);
		res = head;
		if (k == 0)
			return res->next;
		int i, j = 0, flag = 0, minVal;  //j���һ�αȽ�k��������׽ڵ���С�Ľڵ���±꣬minVal�����С�ڵ�ֵval
		//flag����Ѿ��м���������βNULLɨ�����ˣ��ﵽkѭ����������ʾk������ɨ������
		while (flag < k)
		{
			minVal = 6553500;
			//һ�αȽ�k��������׽ڵ��ҵ���С�Ľڵ���±�j����СֵminVal
			for (i = 0; i < k; i++)
			{
				if (lists[i] != NULL && lists[i]->val < minVal)
				{
					minVal = lists[i]->val;
					j = i;
				}
			}
			//��������k������ΪNULL������������lists[j]Ϊ�գ���ʾlists[0]Ϊ������������ҲΪ�գ�����flag++�ﵽk��С����NULL
			if (lists[j] == NULL)
			{
				flag++;
				continue;
			}
			//�ҵ���С�Ľڵ�lists[j]����������������res���棬�Ҹýڵ�ָ��ָ����һ���ڵ�lists[j]=lists[j]->next
			head->next = lists[j];
			head = lists[j];
			lists[j] = lists[j]->next;
			//�����һ���ڵ�Ϊ�գ�˵��������ɨ����Ϊ����flag++
			if (lists[j] == NULL)
				flag++;
		}
		return res->next;
	}
};
//�ⷨ��������˼��
//ʹ��˫ָ�룬i=0ָ��listsͷ��j=k-1ָ��listsβ������i++��j--�Ƚ���������ϲ���һ�������������պϲ���һ����������res���ء�ʱ�临�Ӷ�O(N*logk)
class Solution2 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int k = lists.size();
		if (k == 0)
			return NULL;
		int i = 0, j = k - 1; 
		while (j > 0)
		{
			//���Ϻϲ��������������ϲ���������������i�ڵ㣬�൱��k��������ϲ���k/2����������listsǰk/2λ�ã�Ȼ��i=0�����ºϲ�i=0��j=k/2֮�����������0��k/4listsλ��
			while (i < j)
			{
				lists[i] = mergeTwoLists(lists[i], lists[j]);
				i++;
				j--;
			}
			i = 0;
		}
		
		return lists[0];
	}
	//�ϲ����������һ����������
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l3, * head;
		l3 = new ListNode(0);
		head = l3;
		//�����������ǿ�ʱ������ڵ�l1<=�ڵ㣬���ڵ�l1�ӵ�l3��l1����һ�ڵ�l1=l1->next�����򽫽ڵ�l2�ӵ�l3��l2����һ�ڵ�l2=l2->next
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				l3->next = l1;
				l1 = l1->next;
			}
			else
			{
				l3->next = l2;
				l2 = l2->next;
			}
			l3 = l3->next;
		}
		//��һ������Ϊ���ˣ���һ���ǿ�����ֱ�Ӽӵ�l3����
		if (l1 == NULL)
			l3->next = l2;
		else
			l3->next = l1;
		return head->next;
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
	Solution2 solute;
	int n = 3;
	vector<ListNode*> lists;
	ListNode* head = new ListNode(0), * res;
	CreateList(head, n);
	lists.push_back(head->next);
	head = new ListNode(0);
	CreateList(head, n);
	lists.push_back(head->next);
	res = solute.mergeKLists(lists);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	return 0;
}