#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        //基本思想：二分查找，防止越界mid=low+(high-low)/2
        int res;
        int low=1,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isBadVersion(mid)==true)
            {
                res=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};
int main()
{
    Solution solute;
    int n=50;
    cout<<solute.firstBadVersion(n)<<endl;
    return 0;
}
