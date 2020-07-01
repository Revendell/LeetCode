#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
		//����˼�룺ʹ������ջ�����O(n)������O(1)
		//��ջpush�½���һ��Ԫ��val����ջ��ԭ��������Ԫ�����γ�ջ��val��ջ������������ջ��������ʹ����Ԫ��valλ��ջ���˶���ԭ��Ԫ��˳�򲻱�
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> st_temp;
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            st_temp.push(temp);
        }
        st.push(x);
        while (!st_temp.empty())
        {
			int temp = st_temp.top();
			st_temp.pop();
			st.push(temp);
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = st.top();
        st.pop();
        return temp;
    }
    /** Get the front element. */
    int peek() {
        return st.top();
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
private:
    stack<int> st;
};
class MyQueue1 {
public:
	/** Initialize your data structure here. */
	MyQueue1() {
		//����˼�룺ʹ������ջ���൱��ģ����е���ͷһ��ջģ�����һͷ��һ��ջģ�����һͷ
	}
	/** Push element x to the back of queue. */
	void push(int x) {
        st1.push(x);
	}
	/** Removes the element from in front of queue and returns that element. */
	int pop() {
        if (!st2.empty())
        {
            int temp = st2.top();
            st2.pop();
            return temp;
        }
		while (!st1.empty())
		{
			int temp = st1.top();
			st1.pop();
			st2.push(temp);
		}
		int temp = st2.top();
		st2.pop();
		return temp;
	}
	/** Get the front element. */
	int peek() {
        if (!st2.empty())
            return st2.top();
        while (!st1.empty())
        {
            int temp = st1.top();
            st1.pop();
            st2.push(temp);
        }
		return st2.top();
	}
	/** Returns whether the queue is empty. */
	bool empty() {
        return st1.empty() && st2.empty();
	}
private:
	stack<int> st1;
	stack<int> st2;
};
int main()
{
	MyQueue1 queue;
	queue.push(1);
	queue.push(2);
    cout << queue.peek() << endl;  // ���� 1
    cout << queue.pop() << endl;   // ���� 1
    cout << queue.peek() << endl;  // ���� 2
    cout << queue.empty() << endl; // ���� false
    return 0;
}