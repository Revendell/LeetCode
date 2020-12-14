
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //基本思想：双指针，慢指针指向0，快指针指向非0，然后两个交换
        int left=0,right=0;
        while(right<nums.size())
        {
            if(nums[left]!=0)
            {
                left++;
                right=left+1;
            }
            else
            {
                if(nums[right]==0)
                    right++;
                else
                {
                    nums[left]=nums[right];
                    nums[right]=0;
                    left++;
                    right++;
                }
            }
        }
    }
};
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        //基本思想：双指针，使用快慢指针，快指针遇到非0值就将该值赋值给慢指针，慢指针前进，
        //最后当快指针到达终点，则慢指针之后的值全都是0，这种思想来自于STL中的remove_copy
        int left=0,right=0;
        for(;right<nums.size();right++)
        {
            if(nums[right]!=0)
            {
                nums[left]=nums[right];
                ++left;
            }
        }
        while(left<nums.size())
            nums[left++]=0;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={0,1,0,3,12};
    solute.moveZeroes(nums);
    for_each(nums.begin(),nums.end(),[](const int v){cout<<v<<endl;});
    return 0;
}
