
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        //�򻯰棺��ƽ���Ͷ���ţ��18��ʱ�Ķ������һ������������ȫƽ�����ĸ���С�ڵ���4
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
        //����˼�룺�ݹ飬ͨ���ݹ��ҳ����еĿ��ܣ����Ž⸳ֵ��res
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
        //����˼�룺��ѧ����ƽ���Ͷ���
        //ʱ�临�Ӷ�O(sqrt(n))�ռ临�Ӷ�O(1)
        /*
        1���κ������������Բ�ֳɲ�����4������ƽ���� ---> ��ֻ������1,2,3,4
        2�����һ�������ٿ��Բ��4������ƽ���ͣ�������������� n = (4^a)*(8b+7) ---> ��˿����ȿ�������Ƿ�����������ʽ����������㣬�𰸾���1,2,3��
        3������������������ĳ������ƽ������ô�𰸾���1������𰸾�ֻʣ2,3��
        4���������2����n=a^2+b^2����ô���ǿ���ö��a������֤�������֤ͨ�������2
        5��ֻ����3
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
        //����˼�룺��̬�滮��dp[n]��ʾ����n��Ҫ���ٵ���ȫƽ������ɣ���dp[n]=1+min(dp[n-1*1],dp[n-2*2],dp[n-3*3]...dp[n-k*k])
        //ʱ�临�Ӷ�O(n*sqrt(n))�ռ临�Ӷ�O(n)
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
