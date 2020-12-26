#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {
        //����˼�룺��ѧ��n���ϳ���3���������ȡ��3����false��ֱ��n==1����true��ʱ�临�Ӷ�O(logn)
        if(n<1) return false;
        while(n!=1)
        {
            if(n%3!=0)
                return false;
            n/=3;
        }
        return true;
    }
};
int main()
{
    Solution solute;
    int n=34627766;
    cout<<solute.isPowerOfThree(n)<<endl;
    return 0;
}
