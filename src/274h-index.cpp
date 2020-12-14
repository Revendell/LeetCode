#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //基本思想：排序，时间复杂度O(nlogn)空间复杂度O(1)
        int res = 0;
        sort(citations.begin(),citations.end(),[](const int v1,const int v2){return v1>v2;});
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=i+1 && res < i+1)
                res=i+1;
        }
        return res;
    }
};
class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        //基本思想：计数，时间复杂度O(n)空间复杂度O(n)
        //如果一篇文章的引用次数超过论文的总数n，那么将它的引用次数降低为n 也不会改变h 指数的值
        int n=citations.size();
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(citations[i]>n)
                cnt[n]++;
            else
                cnt[citations[i]]++;
        }
        for(int i=n;i>=1;i--)
        {
            if(cnt[i]>=i)
                return i;
            cnt[i-1]+=cnt[i];
        }
        return 0;
    }
};
int main()
{
    Solution1 solute;
    vector<int> num={0};
    cout<<solute.hIndex(num)<<endl;
    return 0;
}
