#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<stdlib.h>
using namespace std;
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //基本思想：数组存储值（实现O(1)插入、随机读），哈希表存储值对应的索引（实现O(1)查找） 
        //删除时将要删除的数与数组最后一个数交换位置（避免移动，实现O(1)删除）
        //随机函数nums[rand()%nums.size()]获取随机元素

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(Map.find(val)==Map.end())
        {
            nums.push_back(val);
            Map[val]=nums.size()-1;
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(Map.find(val)!=Map.end())
        {
            Map[nums.back()]=Map[val];
            nums[Map[val]]=nums.back();
            Map.erase(val);
            nums.pop_back();
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
private:
    unordered_map<int,int> Map;
    vector<int> nums;
};
int main()
{
    RandomizedSet* obj = new RandomizedSet();
    cout<<obj->insert(1)<<endl;
    cout<<obj->insert(2)<<endl;
    cout<<obj->remove(1)<<endl;
    cout<<obj->getRandom()<<endl;
    return 0;
}