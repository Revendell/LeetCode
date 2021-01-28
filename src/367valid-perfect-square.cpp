#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        //基本思想：牛顿迭代法，f(x)=x^2-N，求f(x)=0时，x的值。
        //初始x=N，不断求x位置的切线与x轴的交点作为新的x，如此反复，直至x^2与N差值小于1，便得到sqrt(N)的整数部分
        //初始(x0,x0^2-N)，y`=2*x0，得到切线方程y-(x0^2-N)=2*x0(x-x0)，当y=0时得x=(x0-N/x0)/2
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
