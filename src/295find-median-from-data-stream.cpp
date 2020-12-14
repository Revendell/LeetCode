#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<deque>
using namespace std;
class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
		//基本思想：维护两个堆，一个大顶堆，一个小顶堆，
        //其中大顶堆中最大的数值小于等于小顶堆中的最小数，两个堆中元素相差为0或1, 不能>1
		//这样我们就会发现，如果数据总数是偶数，那么大顶堆和小顶堆，各占一半元素，此时中位数为两堆顶平均值
		//如果数据个数为奇数，则中位数出现在元素个数多的堆的堆顶中
	}

	void addNum(int num) {
		int temp;
		if (max_heap.size() == 0)
		{
			max_heap.push_back(num);
			push_heap(max_heap.begin(), max_heap.end());
			return;
		}
		if (num > max_heap[0])
		{
			min_heap.push_back(num);
			push_heap(min_heap.begin(), min_heap.end(), greater<int>());
			if (min_heap.size() > max_heap.size() + 1)
			{
				temp = min_heap[0];
				pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
				min_heap.pop_back();

				max_heap.push_back(temp);
				push_heap(max_heap.begin(), max_heap.end());
			}
		}
		else
		{
			max_heap.push_back(num);
			push_heap(max_heap.begin(), max_heap.end());
			if (max_heap.size() > min_heap.size() + 1)
			{
				temp = max_heap[0];
				pop_heap(max_heap.begin(), max_heap.end());
				max_heap.pop_back();

				min_heap.push_back(temp);
				push_heap(min_heap.begin(), min_heap.end(), greater<int>());
			}
		}
	}
	double findMedian() {
		double res = 0;
		if (max_heap.size() != min_heap.size())
			res = max_heap.size() > min_heap.size() ? max_heap[0] : min_heap[0];
		else
			res = double(max_heap.top() + min_heap.top()) / 2;
		return res;
	}
private:
	vector<int> max_heap;
	vector<int> min_heap;
};
class MedianFinder1 {
public:
	/** initialize your data structure here. */
	MedianFinder1() {
		//利用优先队列priority_queue，封装地更好，实际上和上面一模一样
	}

	void addNum(int num) {
		int temp;
		if (max_heap.size() == 0)
		{
			max_heap.push(num);
			return;
		}
		if (num > max_heap.top())
		{
			min_heap.push(num);
			if (min_heap.size() > max_heap.size() + 1)
			{
				temp = min_heap.top();
				min_heap.pop();
				max_heap.push(temp);
			}
		}
		else
		{
			max_heap.push(num);
			if (max_heap.size() > min_heap.size() + 1)
			{
				temp = max_heap.top();
				max_heap.pop();
				min_heap.push(temp);
			}
		}
	}
	double findMedian() {
		double res = 0;
		if (max_heap.size() != min_heap.size())
			res = max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
		else
			res = double(max_heap.top() + min_heap.top()) / 2;
		return res;
	}
private:
	priority_queue<int,vector<int>,less<int>> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;
};
int main()
{
	MedianFinder* obj = new MedianFinder();
	obj->addNum(40);
	obj->addNum(16);
	obj->addNum(12);
	obj->addNum(11);
	obj->addNum(10);
    cout << obj->findMedian() << endl;
    return 0;
}
