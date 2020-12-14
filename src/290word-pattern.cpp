
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //����˼�룺����unordered_map����char��stringӳ���ϵ�Լ�string��charӳ���ϵ��ѭ������patternÿ����ĸ�ж��Ƿ���һһ��Ӧ
        vector<string> s;
        string cur;
        istringstream is(str);
        while(is>>cur)
            s.push_back(cur);
        if(pattern.size()!=s.size())
            return false;
        unordered_map<char,string> HashMap;
        unordered_map<string,char> HashMap1;
        for(int i=0;i<s.size();i++)
        {
            if(HashMap.find(pattern[i])==HashMap.end())
                HashMap[pattern[i]]=s[i];
            else
            {
                if(HashMap[pattern[i]]!=s[i])
                    return false;
            }

            if(HashMap1.find(s[i])==HashMap1.end())
                HashMap1[s[i]]=pattern[i];
            else
            {
                if(HashMap1[s[i]]!=pattern[i])
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution solute;
    string pattern="abba";
    string str="dog cat cat dog";
    cout<<solute.wordPattern(pattern,str)<<endl;
    return 0;
}
