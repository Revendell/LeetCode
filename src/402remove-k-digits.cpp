#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        //基本思想：单调栈，如果当前数字比栈顶大，并且当前数字之后还有足够的数字组成为n位数，则栈顶数字出栈，当前数字入栈，替换掉了栈顶数字。
        string res;
        int n=num.size()-k;
        for(int i=0;i<num.size();i++)
        {
            while(!res.empty()&&num[i]<res.back()&&int(num.size())-i-1>=n-int(res.size()))
                res.pop_back();
            if(res.size()<n)
                res.push_back(num[i]);
        }
        while(res[0]=='0')
            res.erase(res.begin());
        if(res.size()==0)
            return "0";
        return res;
    }
};
int main()
{
    Solution solute;
    string num="32646923";
    int k=3;
    cout<<solute.removeKdigits(num,k)<<endl;
    return 0;
}