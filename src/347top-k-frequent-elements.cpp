#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //基本思想：小顶堆，构造前k个最大频率元素的小顶堆
        vector<int> res;
        map<int,int> cnt;  //元素计数，key是元素，value是计数
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(int i=0;i<nums.size();i++)
            cnt[nums[i]]++;
        for(auto iter=cnt.begin();iter!=cnt.end();iter++)
        {
            min_heap.push(pair<int,int>(iter->second,iter->first));
            if(min_heap.size()>k)
                min_heap.pop();
        }
        while(!min_heap.empty())
        {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //基本思想：哈希表，先对元素对应计数映射得到map cnt，然后反向计数对应元素映射得到map Map
        //因为可能同一个计数对应多个元素所以value是vector<int>，因为map是红黑树，所以已经排序好了，只要从尾到头取k个元素即可
        vector<int> res;
        map<int,int> cnt;
        map<int,vector<int>> Map;
        for(int i=0;i<nums.size();i++)
            cnt[nums[i]]++;
        for(auto iter=cnt.begin();iter!=cnt.end();iter++)
            Map[iter->second].push_back(iter->first);
        int n=0;
        for(auto iter=Map.rbegin();iter!=Map.rend()&&n<k;iter++)
        {
            res.insert(res.end(),(iter->second).begin(),(iter->second).end());
            n+=(iter->second).size();
        }
        return res;
    }
};
class Solution2{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //基本思想：桶排序
        //为每个值设立一个桶，桶内记录这个值出现的次数，然后对桶进行排序。
        //我们先通过桶排序得到三个桶 [1,2,3,4]，它们的值分别 为 [4,2,1,1]，表示每个数字出现的次数。
        //紧接着，我们对桶的频次进行排序，前 k 大个桶即是前 k 个频繁的数。
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int & num : nums)
            max_count = max(max_count, ++counts[num]);
        vector<vector<int>> buckets(max_count + 1);
        for (const auto & p : counts)
            buckets[p.second].push_back(p.first);
        vector<int> ans;
        for (int i = max_count; i >= 0 && ans.size() < k; --i) {
            for (const int & num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
int main()
{
    Solution solute;
    vector<int> nums={5,2,5,3,5,3,1,1,3};
    int k=2;
    vector<int> res=solute.topKFrequent(nums,k);
    for_each(res.begin(),res.end(),[](auto v){cout<<v<<endl;});
    return 0;
}
