#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //基本思想：双指针，与algo里面的set_intersection算法一致
        vector<int> res;
        multiset<int> s1,s2;
        for(auto num:nums1)
            s1.insert(num);
        for(auto num:nums2)
            s2.insert(num);
        multiset<int>::iterator iter1=s1.begin(),iter2=s2.begin();
        while(iter1!=s1.end()&&iter2!=s2.end())
        {
            if(*iter1==*iter2)
            {
                res.push_back(*iter1);
                iter1++;
                iter2++;
            }
            else if(*iter1>*iter2)
                iter2++;
            else
                iter1++;
        }
        return res;
    }
};
class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //基本思想：哈希表HashMap，与algo里面的set_intersection算法一致
        vector<int> res;
        map<int,int> s1,s2;
        for(auto num:nums1)
            s1[num]++;
        for(auto num:nums2)
            s2[num]++;
        map<int,int>::iterator iter1=s1.begin(),iter2=s2.begin();
        while(iter1!=s1.end()&&iter2!=s2.end())
        {
            if(iter1->first==iter2->first)
            {
                int cnt=min(iter1->second,iter2->second);
                while(cnt--)
                    res.push_back(iter1->first);
                iter1++;
                iter2++;
            }
            else if(iter1->first>iter2->first)
                iter2++;
            else
                iter1++;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    vector<int> nums=solute.intersect(nums1,nums2);
    for_each(nums.begin(),nums.end(),[](int n){cout<<n<<endl;});
    return 0;
}

