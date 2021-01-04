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
        //����˼�룺ջ��stnum�������ֵ�ջ��ststr����[֮ǰ���ַ�����cur��ʾ��ǰ[]������ַ���
        //������[���ͽ���ǰ�ַ���cur��ջ��������]��˵��[]�е��ַ��Ѿ���ȡ�����˱�����cur����ststr.top��cur���ӣ�����µ�cur
        //��󷵻�cur
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
            //������[���ͽ���ǰ�ַ���cur��ջ
            if(s[i]=='[')
            {
                ststr.push(cur);
                cur="";
            }
            //������]��˵��[]�е��ַ��Ѿ���ȡ�����˱�����cur����ststr.top��cur���ӣ�����µ�cur
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
