#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry=0,i,j,cur;
        for(i=int(num1.size())-1,j=int(num2.size())-1;i>=0||j>=0;i--,j--)
        {
            if(i<0)
                cur=num2[j]-'0'+carry;
            else if(j<0)
                cur=num1[i]-'0'+carry;
            else
                cur=(num1[i]-'0')+(num2[j]-'0')+carry;
            carry=cur>9?1:0;
            cur=cur>9?cur-10:cur;
            res.push_back(cur+'0');
        }
        if(carry)
            res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    string num1="1243",num2="328748";
    Solution solute;
    cout<<solute.addStrings(num1,num2)<<endl;
    return 0;
}
