#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //基本思想：位运算，将nums中所有元素异或得到的就是所求元素a和b不进位的相加结果x
        //那么x的第一个非0位n就是a和b在第n位上互为0和1，所以可以将nums中所有元素在第n位上是0或1分成两类，这两类元素分别异或就得到了a和b值
        int a=0,b=0;
        int x=0,n;
        for(auto num:nums)
            x^=num;
        for(n=0;n<32;n++)
        {
            if(x&1)
                break;
            x>>=1;
        }
        for(auto num:nums)
        {
            if(num>>n&1)
                a^=num;
            else
                b^=num;
        }
        return {a,b};
    }
};
int main()
{
    Solution solute;
    vector<int> nums{1,2,1,3,2,5};
    vector<int> res=solute.singleNumber(nums);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
