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
		//����˼�룺ά�������ѣ�һ���󶥶ѣ�һ��С���ѣ�
        //���д󶥶���������ֵС�ڵ���С�����е���С������������Ԫ�����Ϊ0��1, ����>1
		//�������Ǿͻᷢ�֣��������������ż������ô�󶥶Ѻ�С���ѣ���ռһ��Ԫ�أ���ʱ��λ��Ϊ���Ѷ�ƽ��ֵ
		//������ݸ���Ϊ����������λ��������Ԫ�ظ�����ĶѵĶѶ���
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
		//�������ȶ���priority_queue����װ�ظ��ã�ʵ���Ϻ�����һģһ��
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
