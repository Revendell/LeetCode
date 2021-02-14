#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        //基本思想：快速幂算法+取模运算性质
        //a^b%p=((a%p)^b)%p
        int res=1;
        a=a%1337;
        for(int i=int(b.size())-1;i>=0;i--)
        {
            res=res*myPow(a,b[i])%1337;
            a=myPow(a,10)%1337;
        }
        return res;
    }
    int myPow(int a,int n)
    {
        int res=1;
        while(n>0)
        {
            if(n%2==1)
                res=res*a%1337;
            n>>=1;
            a=a*a%1337;
        }
        return res;
    }
};
int main()
{
    int a=2147483647;
    vector<int> b={2,0,0};
    Solution solute;
    cout<<solute.superPow(a,b)<<endl;
    return 0;
}
