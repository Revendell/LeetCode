#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //基本思想：滑动窗口+哈希表HashMap
        //用哈希表表示窗口大小为p.size的s字符串，如果Map1==Map2说明该窗口满足条件，res.push_back(i)
        if(s.size()==0||s.size()<p.size()) return {};
        vector<int> Map1(26,0);
        vector<int> Map2(26,0);
        vector<int> res;
        //初始化Map1映射p中字符对应个数
        for(auto ch:p)
            Map1[ch-'a']++;
        //初始化Map2映射窗口为p.size的s中字符对应个数
        for(int i=0;i<p.size();i++)
            Map2[s[i]-'a']++;
        //滑动窗口起始位置从0到s.size()-p.size()，如果Map1==Map2说明该窗口满足条件，res.push_back(i)
        for(int i=0;i<=s.size()-p.size();i++)
        {
            if(Map1==Map2)
                res.push_back(i);
            if(i+p.size()==s.size()) break;
            //更新窗口内字符映射，即下一个窗口的字符对应个数
            Map2[s[i]-'a']--;
            Map2[s[i+p.size()]-'a']++;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    string s="aaaaaaaaaa";
    string p="aaaaaaaaaaaaa";
    vector<int> res=solute.findAnagrams(s,p);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
