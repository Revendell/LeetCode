#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
class LFUCache {
public:
    struct Node{
        int key,value;
        int cnt;
        int time;
        Node() {}
        Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
        bool operator< (const Node& rhs) const {
            return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
        }
    };
    
    LFUCache(int capacity) {
        this->capacity=capacity;
        this->time=0;
    }
    
    int get(int key) {
        if(keyMap.find(key)!=keyMap.end())
        {
            Node tmp=keyMap[key];
            listNode.erase(tmp);
            tmp.time=++time;
            tmp.cnt++;
            listNode.insert(tmp);
            keyMap[key]=tmp;
            return tmp.value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(keyMap.find(key)!=keyMap.end())
        {
            Node tmp=keyMap[key];
            listNode.erase(tmp);
            tmp.time=++time;
            tmp.cnt++;
            tmp.value=value;
            listNode.insert(tmp);
            keyMap[key]=tmp;
            return;
        }
        else
        {
            if(keyMap.size()==capacity)
            {
                keyMap.erase(listNode.begin()->key);
                listNode.erase(listNode.begin());
            }
            Node tmp=Node(1,++time,key,value);
            listNode.insert(tmp);
            keyMap.insert({key,tmp});
            return;
        }
    }
private:
    int capacity,time;
    set<Node> listNode;
    unordered_map<int,Node> keyMap;
};
int main()
{
    LFUCache* obj = new LFUCache(2);
    int param_1 = obj->get(0);
    cout<<param_1<<endl;
    return 0;
}
