#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //基本思想：二分查找
        int res=0;
        int n=citations.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            cout<<mid<<endl;
            if(citations[mid]>=n-mid)
            {
                res=n-mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    vector<int> num={0,1,1,3,3,5,6};
    cout<<solute.hIndex(num)<<endl;
    return 0;
}
