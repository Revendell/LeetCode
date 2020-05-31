#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
	//����˼�룺HashMap��ʱ�临�Ӷ�O(N)
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
	//����˼�룺HashMap+list��ʱ�临�Ӷ�O(1)���õ����ݽṹ�ǳɹ���һ��
	//list����key->value�ԣ���ͷ��β�������ʹ��(ͷ)������ʹ��(β)˳������
	//HashMap����key->iterator�ԣ�iteratorָ��list�б�����Ӧkey�Ķԣ�ͨ��HashMap[key]���Կ����ҵ�key��list��λ��
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
	list<pair<int, int>> listNode;    //����Ĳ���ɾ������������ʧЧ
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