#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        //����˼�룺��ѧ��������n������������3�ȷ�ʱ���˻����
        int res=1;
        vector<int> num{0,1,1,2};
        if(n<4)  return num[n];
        while(n>4)
        {
            res*=3;
            n-=3;
        }
        return res*n;
    }
};
int main()
{
    Solution solute;
    int n=2;
    cout<<solute.integerBreak(n)<<endl;
    return 0;
}
