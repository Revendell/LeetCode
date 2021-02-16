#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
bool compare(vector<int>& a,vector<int>& b)
{
    return a[0]+a[1]<b[0]+b[1];
}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //����˼�룺�󶥶ѣ�����ת��Ϊ215�����е�ǰK����СԪ�أ�ʱ�临�Ӷ�O(m*n*logk)
        //����󶥶ѣ���ǰK����СԪ�ر������󶥶��У�ֻҪ�бȶѶ�Ԫ��С�ľ����
        vector<vector<int>> res;
        k=nums1.size()*nums2.size()<k?nums1.size()*nums2.size():k;
        vector<vector<int>> max_heap;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(max_heap.size()<k||max_heap[0][0]+max_heap[0][1]>nums1[i]+nums2[j])
                {
                    max_heap.push_back({nums1[i],nums2[j]});
                    push_heap(max_heap.begin(), max_heap.end(),compare);
                }
                if(max_heap.size()>k)
                {
                    pop_heap(max_heap.begin(), max_heap.end(),compare);
                    max_heap.pop_back();
                }
            }
        }
        while(!max_heap.empty())
        {
            pop_heap(max_heap.begin(), max_heap.end(),compare);
            res.push_back(max_heap.back());
            max_heap.pop_back();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution1 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //����˼�룺С���ѣ�����ת��Ϊ23�ϲ�K���������飬ʱ�临�Ӷ�O(k*logn)
        //����С���ѣ���ǰK����СԪ�ر�����С�����У�pair<int,int>��first��nums1�е�Ԫ�أ�second��nums2�е��±�
        //��ÿ������ĵ�һ��Ԫ�ؼ���С���ѣ�����С���ѵĶѶ�Ԫ��
        //������Ԫ�������ĸ����飬�Ͱ��Ǹ��������һ��Ԫ�ؼ���С����
        //ֱ���������鶼û����һ��Ԫ�أ�����ֻ��Ҫ����K�Σ����ɻ�ȡǰKС��Ԫ��
        vector<vector<int>> res;
        if(nums1.size()==0||nums2.size()==0)  return res;
        k=nums1.size()*nums2.size()<k?nums1.size()*nums2.size():k;
        vector<pair<int,int>> min_heap;
        for(int i=0;i<nums1.size();i++)
        {
            min_heap.push_back(pair<int,int>{nums1[i],0});
            push_heap(min_heap.begin(), min_heap.end(),[nums2](pair<int,int>& a,pair<int,int>& b){return a.first+nums2[a.second]>b.first+nums2[b.second];});
        }
        while(k--)
        {
            res.push_back(vector<int>{min_heap[0].first,nums2[min_heap[0].second]});
            min_heap[0].second++;
            pair<int,int> temp=min_heap[0];
            pop_heap(min_heap.begin(), min_heap.end(),[nums2](pair<int,int>& a,pair<int,int>& b){return a.first+nums2[a.second]>b.first+nums2[b.second];});
            min_heap.pop_back();
            if(temp.second!=nums2.size())
            {
                min_heap.push_back(temp);
                push_heap(min_heap.begin(), min_heap.end(),[nums2](pair<int,int>& a,pair<int,int>& b){return a.first+nums2[a.second]>b.first+nums2[b.second];});
            }
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums1{1,7,8};
    vector<int> nums2{2,4,6};
    int k=4;
    vector<vector<int>> res=solute.kSmallestPairs(nums1,nums2,k);
    for_each(res.begin(),res.end(),[](vector<int> v){cout<<v[0]<<" "<<v[1]<<endl;});
    return 0;
}
