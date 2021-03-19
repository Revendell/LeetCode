#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        //迭代：位运算，a^b是无进位的相加;a&b<<1得到每一位的进位
        int carry,sum;
        sum=a^b;
        carry=static_cast<unsigned int>(a&b)<<1;
        while(carry!=0)
        {
            a=sum,b=carry;
            sum=a^b;
            carry=static_cast<unsigned int>(a&b)<<1;
        }
        return sum;
    }
};
class Solution1 {
public:
    int getSum(int a, int b) {
        //基本思想：位运算，a^b是无进位的相加;a&b<<1得到每一位的进位;
        //让无进位相加的结果与进位不断的异或，直到进位为0
        int carry,sum;
        sum=a^b;
        carry=static_cast<unsigned int>(a&b)<<1;
        if(carry!=0)
            return getSum(sum,carry);
        return sum;
    }
};
int main()
{
    Solution solute;
    int a=1,b=3;
    cout<<solute.getSum(a,b)<<endl;
    return 0;
}
