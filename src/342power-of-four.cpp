#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1)
        {
            if(n%4!=0)
                return false;
            n/=4;
        }
        return n==1;
    }
};
class Solution1 {
    public boolean isPowerOfFour(int num) {
      //����˼�룺λ���㣬num&(num-1)==0�����ж�num�Ƿ���2����
      return (num > 0) && ((num & (num - 1)) == 0) && (num % 3 == 1);
    }
}
int main()
{
    Solution solute;
    int n=16;
    cout<<solute.isPowerOfFour(n)<<endl;
    return 0;
}
