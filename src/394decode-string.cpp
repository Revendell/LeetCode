#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        //基本思想：栈，stnum保存数字的栈，ststr保存[之前的字符串，cur表示当前[]里面的字符串
        //当遇到[，就将当前字符串cur入栈；当遇到]，说明[]中的字符已经提取出来了保存在cur，将ststr.top与cur连接，组成新的cur
        //最后返回cur
        stack<int> stnum;
        stack<string> ststr;
        int i=0;
        string cur;
        while(i<s.size())
        {
            int num=0;
            while(s[i]>='0'&&s[i]<='9')
            {
                num*=10;
                num+=s[i]-'0';
                i++;
            }
            if(num!=0)
                stnum.push(num);
            //当遇到[，就将当前字符串cur入栈
            if(s[i]=='[')
            {
                ststr.push(cur);
                cur="";
            }
            //当遇到]，说明[]中的字符已经提取出来了保存在cur，将ststr.top与cur连接，组成新的cur
            else if(s[i]==']')
            {
                string temp=ststr.top();
                ststr.pop();
                int cnt=stnum.top();
                stnum.pop();
                while(cnt--)
                    temp+=cur;
                cur=temp;
            }
            else
                cur.push_back(s[i]);
            i++;
        }
        return cur;
    }
};
int main()
{
    Solution solute;
    string s="abc3[cd]xyz";
    cout<<solute.decodeString(s)<<endl;
    return 0;
}
