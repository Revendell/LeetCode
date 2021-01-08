#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //基本思想：哈希表HashMap，利用nums数组的下标作为哈希表的映射，如果该数存在，则对应下标的元素为负。这样就不用申请额外空间标记该数存在并且不改变下标元素值
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                continue;
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                res.push_back(i+1);
        return res;
    }
};
int main()
{
    vector<int> nums={1,2,2,3,3,4,4};
    Solution solute;
    vector<int> res=solute.findDisappearedNumbers(nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
