#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<set>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        //基本思想：暴力超时
        if(s.size()<k)  return 0;
        int len=0;
        for(int i=0;i<=s.size()-k;i++)
        {
            for(int j=i+k-1;j<s.size()&&j-i+1>len;j++)
            {
                vector<int> cnt(26,0);
                for(int t=i;t<=j;t++)
                {
                    cnt[s[t]-'a']++;
                }
                bool flag=true;
                for(auto c:cnt)
                {
                    if(c>0&&c<k)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                    len=max(len,j-i+1);
            }
        }
        return len;
    }
};
class Solution1 {
public:
    int res=0;
    int longestSubstring(string s, int k) {
        //基本思想：分治法，对于一个字符串来说，如果要求子串最少出现k次，那么如果某些字母出现的次数小于k,
        //这些字母一定不会出现在最长的子串中，并且这些字母将整个字符子串分割成小段，这些小段有可能是最长的
        //但是由于被分割了，还是要检查这一小段，如果某些字母出现的次数小于k，会将小段继续分割下去
        //直到该小段所有字符出现次数都不小于k，即seg.empty()，就不可再分res=max(res,int(s.size()))
        Recursion(s,k);
        return res;
    }
    void Recursion(string s,int k)
    {
        if(s.size()<k)  return;
        vector<int> cnt(26,0);
        set<char> seg;
        for(auto c:s)
            cnt[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>0&&cnt[i]<k)
                seg.insert(i+'a');
        }
        if(seg.empty())
        {
            res=max(res,int(s.size()));
            return;
        }
        int start=0;
        for(int i=0;i<=s.size();i++)
        {
            if(i==s.size()||seg.find(s[i])!=seg.end())
            {
                Recursion(s.substr(start,i-start),k);
                start=i+1;
            }
        }
    }
};
int main()
{
    Solution1 solute;
    string s="ababbc";
    int k=2;
    cout<<solute.longestSubstring(s,k)<<endl;
    return 0;
}