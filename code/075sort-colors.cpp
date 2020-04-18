#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //基本思想：荷兰国旗问题，三指针，一次遍历，如果是0，则移动到表头，如果是2，则移动到表尾，不用考虑1
        //left指向0的右边界，right指向2的左边界，也就是通过left和right将三色隔离红色[0,left)白色[left,right]蓝色(righ,n-1]
        int left, right, cur;
        left = 0;
        right = nums.size() - 1;
        cur = 0;
        while (cur <= right)
        {
            //当前元素为0，需要跟0的右边界left交换，0的右边界left++，cur++
            if (nums[cur] == 0)
            {
                swap(nums[cur], nums[left]);
                left++;
                cur++;
            }
            //当前元素为1，cur一直位于left与right之间的1元素上，所以不需要交换，cur++
            else if (nums[cur] == 1)
            {
                cur++;
            }
            //当前元素为2，需要跟2的左边界right交换，2的左边界right--
            else
            {
                swap(nums[cur], nums[right]);
                right--;
            }
        }
        return;
    }
};
int main()
{
    Solution solute;
    vector<int> nums = { 2,0,2,1,1,0 };
    solute.sortColors(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    return 0;
}