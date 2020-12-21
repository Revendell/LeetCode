#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //基本思想：单调栈，有条件限制的单调栈，遇到一个新字符如果比栈顶小并且在新字符后面还有和栈顶一样的就把栈顶的字符抛弃了
        stack<char> st;  //维护的栈
        set<char> letters;  //记录栈中保存的字母，方便判断当前字母是否已经存在栈中，主要是C++stack不能遍历
        vector<int> counts(26,0);  //记录s中每个字母的个数
        //统计s中每个字母出现的次数
        for(int i=0;i<s.size();i++)
            counts[s[i]-'a']++;
        //遍历s中每个字母
        for(int i=0;i<s.size();i++)
        {
            counts[s[i]-'a']--;
            if(letters.find(s[i])!=letters.end())  //栈中已存在该字母continue
                continue;
            //如果当前字母比栈顶的字母小并且在当前字母后面还有和栈顶字母一样的字母，就把栈顶的字母抛弃了
            while(!st.empty()&&s[i]<st.top()&&counts[st.top()-'a']>0)
            {
                letters.erase(st.top());
                st.pop();
            }
            letters.insert(s[i]);
            st.push(s[i]);
        }
        string res;
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};
int main()
{
    Solution solute;
    string s="cbacdcbc";
    cout<<solute.removeDuplicateLetters(s)<<endl;
    return 0;
}

