
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y,res=0;
        for(int i=0;i<32;i++)
        {
            if(z&1==1)
                res+=1;
            z=z>>1;
        }
        return res;
    }
};
int main()
{
    int x=1,y=4;
    Solution solute;
    cout<<solute.hammingDistance(x,y)<<endl;
    return 0;
}
