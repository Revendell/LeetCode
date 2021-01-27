#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{
        return isInt;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{
        return val;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{
        return nestedList;
    }
    int val;
    bool isInt;
    vector<NestedInteger> nestedList;
};
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        //基本思想：递归dfs深度优先搜索
        pos=0;
        dfs(nestedList);
    }
    void dfs(vector<NestedInteger> nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
                val.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    int next() {
        return val[pos++];
    }
    bool hasNext() {
        return pos<val.size()?true:false;
    }
private:
    vector<int> val;
    int pos;
};
int main()
{
    NestedInteger i1,i2,i3;
    i1.isInt=true;
    i1.val=1;
    i2.isInt=true;
    i2.val=2;
    i3.isInt=false;
    i3.nestedList={i1,i2};
    vector<NestedInteger> nestedList{i1,i2,i3};
    NestedIterator i(nestedList);
    while (i.hasNext())
        cout << i.next()<<endl;
    return 0;
}
