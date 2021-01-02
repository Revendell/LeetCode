#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        //基本思想：找规律发现，0是1的比特位数+1,2-3是0-1对应比特位数+1，4-7是0-3对应比特位数+1，8-15是0-7对应比特位数+1
        //所以当前数字j的比特位数res[j]=res[j-i]+1;其中i是比j小的最大2的次幂
        vector<int> res(num+1,0);
        int i=1;
        while(true)
        {
            for(int j=i;j<i<<1;j++)
            {
                if(j==num+1)
                    return res;
                res[j]=res[j-i]+1;
            }
            i=i<<1;
        }
    }
};
class Solution1 {
public:
    vector<int> countBits(int num) {
        //基本思想：位运算动态规划,i&(i-1)可以去掉i最右边的一个1（如果有），因此i&(i-1）是比i小的，
        //而且i&(i-1)的1的个数已经在前面算过了，所以i的1的个数就是i&(i-1)的1的个数加上1
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; ++ i) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    int num=3652;
    vector<int> res=solute.countBits(num);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<endl;});
    return 0;
}
