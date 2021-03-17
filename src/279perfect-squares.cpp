
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        //简化版：四平方和定理，牛顿18岁时的定理，组成一个正整数的完全平方数的个数小于等于4
        int i=sqrt(n);
        if(i*i==n)
            return 1;
        for(i=1;i*i<n;i++)
        {
            int j=pow(n-i*i,0.5);
            if(i*i+j*j==n)
                return 2;
        }
        for(i=1;i*i<n;i++)
        {
            for(int j=1;j*j+i*i<n;j++)
            {
                int k=pow(n-i*i-j*j,0.5);
                if(i*i+j*j+k*k==n)
                    return 3;
            }
        }
        return 4;
    }
};
class Solution1 {
public:
    int res=9999;
    int numSquares(int n) {
        //基本思想：递归，通过递归找出所有的可能，最优解赋值给res
        int cnt=0;
        Recursion(n,cnt);
        return res;
    }
    void Recursion(int n,int cnt)
    {
        if(cnt>res)
            return;
        if(n==0)
        {
            if(cnt<res)
                res=cnt;
            return;
        }
        int cur=sqrt(n);
        for(int i=cur;i>=cur/2;i--)
        {
            Recursion(n-i*i,cnt+1);
        }
        return;
    }
};
class Solution2 {
public:
    int numSquares(int n) {
        //基本思想：数学，四平方和定理
        //时间复杂度O(sqrt(n))空间复杂度O(1)
        /*
        1、任何正整数都可以拆分成不超过4个数的平方和 ---> 答案只可能是1,2,3,4
        2、如果一个数最少可以拆成4个数的平方和，则这个数还满足 n = (4^a)*(8b+7) ---> 因此可以先看这个数是否满足上述公式，如果不满足，答案就是1,2,3了
        3、如果这个数本来就是某个数的平方，那么答案就是1，否则答案就只剩2,3了
        4、如果答案是2，即n=a^2+b^2，那么我们可以枚举a，来验证，如果验证通过则答案是2
        5、只能是3
        */
        while (0 == n % 4)
            n /= 4;
        if (7 == n % 8)
            return 4;
        for (int i = 0; i * i < n; ++i) {
            int j = pow(n - i * i, 0.5);
            if (n == i * i + j * j)
                return !!i + !!j;
        }
        return 3;
    }
};
class Solution3 {
public:
    int numSquares(int n) {
        //基本思想：动态规划，dp[n]表示数字n需要最少的完全平方数组成，则dp[n]=1+min(dp[n-1*1],dp[n-2*2],dp[n-3*3]...dp[n-k*k])
        //时间复杂度O(n*sqrt(n))空间复杂度O(n)
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int minval=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                minval=min(minval,dp[i-j*j]);
            }
            dp[i]=1+minval;
        }
        return dp[n];
    }
};
int main()
{
    Solution solute;
    int n=64352;
    cout<<solute.numSquares(n)<<endl;
    return 0;
}
