#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};
class Solution {
public:
    int fib(int n) {
        if(n==0||n==1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};
class Solution1 {
public:
    int fib(int n) {
        if(n==0||n==1)
            return n;
        int first=0,second=1;
        for(int i=2;i<=n;i++)
        {
            int tmp=first+second;
            first=second;
            second=tmp;
        }
        return second;
    }
};
int main()
{
    Solution solute;
    int n=10;
    cout<<solute.fib(n)<<endl;
    return 0;
}