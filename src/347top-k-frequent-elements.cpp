#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //����˼�룺С���ѣ�����ǰk�����Ƶ��Ԫ�ص�С����
        vector<int> res;
        map<int,int> cnt;  //Ԫ�ؼ�����key��Ԫ�أ�value�Ǽ���
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
        //����˼�룺��ϣ���ȶ�Ԫ�ض�Ӧ����ӳ��õ�map cnt��Ȼ���������ӦԪ��ӳ��õ�map Map
        //��Ϊ����ͬһ��������Ӧ���Ԫ������value��vector<int>����Ϊmap�Ǻ�����������Ѿ�������ˣ�ֻҪ��β��ͷȡk��Ԫ�ؼ���
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
        //����˼�룺Ͱ����
        //Ϊÿ��ֵ����һ��Ͱ��Ͱ�ڼ�¼���ֵ���ֵĴ�����Ȼ���Ͱ��������
        //������ͨ��Ͱ����õ�����Ͱ [1,2,3,4]�����ǵ�ֵ�ֱ� Ϊ [4,2,1,1]����ʾÿ�����ֳ��ֵĴ�����
        //�����ţ����Ƕ�Ͱ��Ƶ�ν�������ǰ k ���Ͱ����ǰ k ��Ƶ��������
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
