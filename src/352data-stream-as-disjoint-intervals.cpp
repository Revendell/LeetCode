#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        //基本思想：把每个插入值放在一个set里，返回的列表就每次遍历set

    }

    void addNum(int val) {
        nums.insert(val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        auto iter=nums.begin();
        while(iter!=nums.end())
        {
            auto left=iter,right=iter;
            right++;
            while(right!=nums.end()&&*left+1==*right)
            {
                left++;
                right++;
            }
            res.push_back({*iter,*left});
            iter=right;
        }
        return res;
    }
private:
    set<int> nums;
};
int main()
{
    SummaryRanges* obj = new SummaryRanges();
    vector<int> nums{1,3,7,2,6};
    for(auto num:nums)
        obj->addNum(num);
    vector<vector<int>> res = obj->getIntervals();
    for_each(res.begin(),res.end(),[](vector<int> v){cout<<v[0]<<" "<<v[1]<<endl;});
    return 0;
}
