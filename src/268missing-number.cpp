
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //基本思想：索引作为哈希表，因为题目要求时间复杂度O(n)，空间复杂度常数级别额外空间，
        //所以只能使用已给数组nums作为HashMap。使用已给数组nums作为HashMap，
        //循环一次扫描nums中每个元素，然后对该元素为下标下的值取负号，则说明该元素存在，
        //这样既不改变该元素为下标下的值又能用下标标记该元素存在。
        int flagzero=1;
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])==nums.size())
                continue;
            else
            {
                if(nums[abs(nums[i])]==0)
                    flagzero=-1;
                else
                    nums[abs(nums[i])]=-nums[abs(nums[i])];
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0 || (nums[i]==0 && flagzero > 0))
                return i;
        }
        return nums.size();
    }
};
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        //基本思想：位运算异或，0,1,2,3,4^0,1,2,4=3
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            res = res ^ i ^ nums[i];            // a^b^b = a;
        return res ;
    }
};
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        //基本思想：数学求和
        int sum = 0, n = nums.size();
        for(int n : nums)
            sum += n;
        return (n * (n+1)) / 2 - sum;
    }
};
int main()
{
    Solution solute;
    vector<int> nums={1,2,3,4};
    cout<<solute.missingNumber(nums)<<endl;
    return 0;
}
