#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(vector<int> a,vector<int> b)
{
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //基本思想：动态规划+二分查找，时间复杂度O(NlogN)
        //先对envelopes排序，按照长度从小到大排序，如果长度相等，按照宽度从大到小排序，这样转化成了300最长上升子序列问题
        //这样的目的是避免同长时宽度小的也被列入递增序列中，因为同长度只能选择一个
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> nums;
        for(int i=0;i<envelopes.size();i++)
        {
            if(nums.empty()||envelopes[i][1]>nums.back())
                nums.push_back(envelopes[i][1]);
            else
            {
                auto iter=lower_bound(nums.begin(),nums.end(),envelopes[i][1]);
                *iter=envelopes[i][1];
            }
        }
        return nums.size();
    }
};
int main()
{
    Solution solute;
    vector<vector<int>> envelopes={{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    cout<<solute.maxEnvelopes(envelopes)<<endl;
    return 0;
}
