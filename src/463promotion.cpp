#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<int> promotion(int n,vector<vector<int>>& nums)
    {
        //基本思想：区间+前缀和
        vector<int> res(n,0);
        for(int i=0;i<nums.size();i++)
        {
            res[nums[i][0]-1]++;
            if(nums[i][1]!=n)
                res[nums[i][1]-1]--;

        }
        for(int i=1;i<n;i++)
            res[i]+=res[i-1];
        return res;
    }
};
int main()
{
    Solution solute;
    int n=3;
    vector<vector<int>> nums{{2,3},{1,3}};
    vector<int> res=solute.promotion(n,nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}