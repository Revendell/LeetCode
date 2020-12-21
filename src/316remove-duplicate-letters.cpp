#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //����˼�룺����ջ�����������Ƶĵ���ջ������һ�����ַ������ջ��С���������ַ����滹�к�ջ��һ���ľͰ�ջ�����ַ�������
        stack<char> st;  //ά����ջ
        set<char> letters;  //��¼ջ�б������ĸ�������жϵ�ǰ��ĸ�Ƿ��Ѿ�����ջ�У���Ҫ��C++stack���ܱ���
        vector<int> counts(26,0);  //��¼s��ÿ����ĸ�ĸ���
        //ͳ��s��ÿ����ĸ���ֵĴ���
        for(int i=0;i<s.size();i++)
            counts[s[i]-'a']++;
        //����s��ÿ����ĸ
        for(int i=0;i<s.size();i++)
        {
            counts[s[i]-'a']--;
            if(letters.find(s[i])!=letters.end())  //ջ���Ѵ��ڸ���ĸcontinue
                continue;
            //�����ǰ��ĸ��ջ������ĸС�����ڵ�ǰ��ĸ���滹�к�ջ����ĸһ������ĸ���Ͱ�ջ������ĸ������
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

