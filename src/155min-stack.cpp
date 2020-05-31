#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class MinStack {
public:
	//基本思想：辅助栈
	MinStack() {
		minElem.push_back(INT_MAX);
	}
	void push(int x) {
		st.push_back(x);
		minElem.push_back(min(minElem[minElem.size() - 1], x));
	}
	void pop() {
		st.pop_back();
		minElem.pop_back();
	}
	int top() {
		return st[st.size() - 1];
	}
	int getMin() {
		return minElem[minElem.size() - 1];
	}
private:
	vector<int> st;
	vector<int> minElem;
};
class MinStack1 {
public:
	//基本思想：栈+HashMap
	MinStack1() {

	}
	void push(int x) {
		++minElem[x];
		st.push_back(x);
	}
	void pop() {
		--minElem[top()];
		if (minElem[top()] <= 0)
			minElem.erase(top());
		st.pop_back();
	}
	int top() {
		return st[st.size() - 1];
	}
	int getMin() {
		return (*minElem.begin()).first;
	}
private:
	map<int,int> minElem;
	vector<int> st;
};
int main()
{
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout << minStack->getMin() << endl;
	minStack->pop();
	cout << minStack->top() << endl;
	cout << minStack->getMin() << endl;
	return 0;
}