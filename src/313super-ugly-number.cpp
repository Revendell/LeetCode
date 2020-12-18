#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //基本思想：动态规划多指针，参考题号264
        //为每个质因数建立一个指针，然后再这几个质因数运算的结果中，找出个最小的，然后匹配这个数是由哪个质因数算出来的，把它的指针值+1。
        vector<int> index(primes.size(),0);
        vector<int> num = { 1 };
        for(int i=1;i<n;i++)
        {
            int cur=INT_MAX;
            for(int j=0;j<index.size();j++)
            {
                if(num[index[j]]*primes[j]<cur)
                    cur=num[index[j]]*primes[j];
            }
            num.push_back(cur);
            for(int j=0;j<index.size();j++)
            {
                if(num[index[j]]*primes[j]==cur)
                    index[j]++;
            }
        }
        return num.back();
    }
};
int main()
{
    int n=12;
    vector<int> primes={2,7,13,19};
    Solution solute;
    cout<<solute.nthSuperUglyNumber(n,primes)<<endl;
    return 0;
}
