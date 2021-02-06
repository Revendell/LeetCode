#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //����˼�룺������ϣ����nλ������λ�����ֶ���ͬ����Ϸ�ʽ����n=4,cur=9*9*8*7
        int res=0;
        n=n>10?10:n;
        while(n>0)
        {
            if(n==1)
                res+=10;
            else
            {
                int cur=9,cnt=n-1;
                for(int i=9;cnt>0;cnt--,i--)
                    cur*=i;
                res+=cur;
            }
            n--;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    int n=3;
    cout<<solute.countNumbersWithUniqueDigits(n)<<endl;
    return 0;
}
