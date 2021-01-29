#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        //基本思想：哈希表HashMap
        vector<int> Map(26,0);
        for(auto c:s)
            Map[c-'a']++;
        for(int i=0;i<s.size();i++)
        {
            if(Map[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};
int main()
{
    string s="loveleetcod";
    Solution solute;
    cout<<solute.firstUniqChar(s)<<endl;
    return 0;
}
