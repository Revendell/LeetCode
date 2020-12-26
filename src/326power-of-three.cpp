#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        //基本思想：数学，n不断除以3，如果不能取余3返回false，直到n==1返回true，时间复杂度O(logn)
        if(n<1) return false;
        while(n!=1)
        {
            if(n%3!=0)
                return false;
            n/=3;
        }
        return true;
    }
};
int main()
{
    Solution solute;
    int n=34627766;
    cout<<solute.isPowerOfThree(n)<<endl;
    return 0;
}
