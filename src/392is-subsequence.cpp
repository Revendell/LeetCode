#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //基本思想：双指针，p1指向s的下标，p2指向t的下标
        int p1=0,p2=0;
        while(p1<s.size()&&p2<t.size())
        {
            if(s[p1]==t[p2])
            {
                p1++;
                p2++;
            }
            else
                p2++;
        }
        return p1==s.size();
    }
};
int main()
{
    string s="ace",t="qabcdeq";
    Solution solute;
    cout<<solute.isSubsequence(s,t)<<endl;
    return 0;
}
