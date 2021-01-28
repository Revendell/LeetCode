#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //基本思想：哈希表HashMap
        vector<int> r(26,0),m(26,0);
        for(auto c:ransomNote)
            r[c-'a']++;
        for(auto c:magazine)
            m[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(m[i]<r[i])
                return false;
        }
        return true;
    }
};
int main()
{
    Solution solute;
    string ransomNote="aa",magazine="aab";
    cout<<solute.canConstruct(ransomNote,magazine)<<endl;
    return 0;
}
