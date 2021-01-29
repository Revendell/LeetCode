#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        //����˼�룺��ϣ��HashMap
        char res;
        vector<int> Maps(26,0),Mapt(26,0);
        for(auto c:s)
            Maps[c-'a']++;
        for(auto c:t)
            Mapt[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(Mapt[i]!=Maps[i])
            {
                res=static_cast<char>(i+'a');
                break;
            }
        }
        return res;
    }
};
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        //����˼�룺λ���㣬���������������Ϊ0
        int res=0;
        for(auto c:s)
            res^=c;
        for(auto c:t)
            res^=c;
        return res;
    }
};
class Solution2 {
public:
    char findTheDifference(string s, string t) {
        //����˼�룺��ѧ
        int res=0;
        for(auto c:t)
            res+=c;
        for(auto c:s)
            res-=c;
        return res;
    }
};
int main()
{
    Solution1 solute;
    string s = "abcd", t = "abcde";
    cout<<solute.findTheDifference(s,t)<<endl;
    return 0;
}
