#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        //������λ���㣬a^b���޽�λ�����;a&b<<1�õ�ÿһλ�Ľ�λ
        int carry,sum;
        sum=a^b;
        carry=static_cast<unsigned int>(a&b)<<1;
        while(carry!=0)
        {
            a=sum,b=carry;
            sum=a^b;
            carry=static_cast<unsigned int>(a&b)<<1;
        }
        return sum;
    }
};
class Solution1 {
public:
    int getSum(int a, int b) {
        //����˼�룺λ���㣬a^b���޽�λ�����;a&b<<1�õ�ÿһλ�Ľ�λ;
        //���޽�λ��ӵĽ�����λ���ϵ����ֱ����λΪ0
        int carry,sum;
        sum=a^b;
        carry=static_cast<unsigned int>(a&b)<<1;
        if(carry!=0)
            return getSum(sum,carry);
        return sum;
    }
};
int main()
{
    Solution solute;
    int a=1,b=3;
    cout<<solute.getSum(a,b)<<endl;
    return 0;
}
