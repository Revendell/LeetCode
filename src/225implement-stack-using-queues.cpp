#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	    //����˼�룺���У��ö���ʵ��ջ
		//������push�½���һ��Ԫ��val���򽫶�����ԭ��������Ԫ�����γ�����������������У�������ʹ����Ԫ��valλ�ڶ�ͷ�˶���ԭ��Ԫ��˳�򲻱�
		//��ջʱ�临�Ӷ�O(N)��ջʱ�临�Ӷ�O(1)
	}

	/** Push element x onto stack. */
	void push(int x) {
		int len = queue.size();
		queue.push_back(x);
		while (len--)
		{
			int val = queue.front();
			queue.pop_front();
			queue.push_back(val);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int val = queue.front();
		queue.pop_front();
		return val;
	}

	/** Get the top element. */
	int top() {
		return queue.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return queue.empty();
	}
private:
	deque<int> queue;
};
int main()
{
	MyStack obj;
	obj.push(1);
	obj.push(2);
	cout << obj.pop() << endl;
	cout << obj.top() << endl;
	cout << obj.empty() << endl;
	return 0;
}