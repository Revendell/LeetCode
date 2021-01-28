#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int pick=45;
int guess(int num)
{
    if(pick<num)
        return -1;
    else if(pick>num)
        return 1;
    else
        return 0;
}
class Solution {
public:
    int guessNumber(int n) {
        //基本思想：二分查找折半查找，求mid时不能用mid=(high+low)/2会超过2^31-1
        int mid,low=1,high=n;
        while(true)
        {
            mid=(high-low)/2+low;
            if(guess(mid)==-1)
                high=mid-1;
            else if(guess(mid)==1)
                low=mid+1;
            else
                break;
        }
        return mid;
    }
};
int main()
{
    Solution solute;
    int n=78;
    cout<<solute.guessNumber(n)<<endl;
    return 0;
}
