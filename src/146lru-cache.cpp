#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
	//基本思想：HashMap，时间复杂度O(N)
	LRUCache(int capacity) : capacity(capacity) {}
	int get(int key) {
		if (key_value.find(key) != key_value.end())
		{
			key_clock[key] = ++clock;
			return key_value[key];
		}
		else
			return -1;
	}
	void put(int key, int value) {
		if (key_value.find(key) != key_value.end())
		{
			key_value[key] = value;
			key_clock[key] = ++clock;
			return;
		}
		if (key_value.size() < capacity)
		{
			key_value[key] = value;
			key_clock[key] = ++clock;
		}
		else
		{
			int res_key, min_clock = clock;
			for (auto it = key_clock.begin(); it != key_clock.end(); it++)
			{
				if (it->second <= min_clock)
				{
					min_clock = it->second;
					res_key = it->first;
				}
			}
			key_value.erase(res_key);
			key_clock.erase(res_key);
			key_value[key] = value;
			key_clock[key] = ++clock;
		}
	}
private:
	int capacity;
	unordered_map<int, int> key_value;
	unordered_map<int, int> key_clock;
	int clock = 0;
};
class LRUCache1 {
public:
	//基本思想：HashMap+list，时间复杂度O(1)，好的数据结构是成功的一半
	//list保存key->value对，从头到尾按照最近使用(头)到最少使用(尾)顺序排列
	//HashMap保存key->iterator对，iterator指向list中保存相应key的对，通过HashMap[key]可以快速找到key在list中位置
	LRUCache1(int capacity) : capacity(capacity) {}
	int get(int key) {
		if (key_value.find(key) != key_value.end())
		{
			int res = key_value[key]->second;
			listNode.erase(key_value[key]);
			listNode.push_front(make_pair(key, res));
			key_value[key] = listNode.begin();
			return res;
		}
		else
			return -1;
	}
	void put(int key, int value) {
		if (key_value.find(key) != key_value.end())
		{
			listNode.erase(key_value[key]);
			listNode.push_front(make_pair(key, value));
			key_value[key] = listNode.begin();
			return;
		}
		if (key_value.size() < capacity)
		{
			listNode.push_front(make_pair(key, value));
			key_value[key] = listNode.begin();
		}
		else
		{	
			key_value.erase(listNode.back().first);
			listNode.pop_back();
			listNode.push_front(make_pair(key, value));
			key_value[key] = listNode.begin();
		}
	}
private:
	int capacity;
	unordered_map<int, list<pair<int, int>>::iterator> key_value;
	list<pair<int, int>> listNode;    //链表的插入删除迭代器不会失效
};
int main()
{
	LRUCache1 cache(2);
	cout << cache.get(2) << endl;
	cache.put(2, 6);
	cout << cache.get(1) << endl;
	cache.put(1, 5);
	cache.put(1, 2);
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	return 0;
}