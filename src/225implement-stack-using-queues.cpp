#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	    //基本思想：队列，用队列实现栈
		//当队列push新进来一个元素val，则将队列里原来的所有元素依次出队列重新依次入队列，这样就使得新元素val位于队头了而且原来元素顺序不变
		//入栈时间复杂度O(N)出栈时间复杂度O(1)
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