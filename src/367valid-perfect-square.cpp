#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        //����˼�룺ţ�ٵ�������f(x)=x^2-N����f(x)=0ʱ��x��ֵ��
        //��ʼx=N��������xλ�õ�������x��Ľ�����Ϊ�µ�x����˷�����ֱ��x^2��N��ֵС��1����õ�sqrt(N)����������
        //��ʼ(x0,x0^2-N)��y`=2*x0���õ����߷���y-(x0^2-N)=2*x0(x-x0)����y=0ʱ��x=(x0-N/x0)/2
        long long root=num;
        while(root*root-num>=1)
        {
            root=(root+num/root)/2;
        }
        return root*root==num;
    }
};
int main()
{
    Solution solute;
    int num=16;
    cout<<solute.isPerfectSquare(num)<<endl;
    return 0;
}
