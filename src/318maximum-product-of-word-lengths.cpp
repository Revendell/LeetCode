
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //基本思想：建立起counts二维数组对words每个字符串中的字符计数，然后通过双重循环遍历words判断每个字符串与后面字符串是否存在共同字母
        int res=0;
        if(words.size()==0) return res;
        vector<vector<int>> counts(words.size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
                counts[i][words[i][j]-'a']++;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                bool insectflag=false;
                for(int k=0;k<words[i].size();k++)
                {
                    if(counts[j][words[i][k]-'a']>0)
                    {
                        insectflag=true;
                        break;
                    }
                }
                if(insectflag==false)
                    res=max(res,static_cast<int>(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};
class Solution1 {
public:
    int maxProduct(vector<string>& words) {
        //优化：用一个32位int表示一个word中出现的字母，用int32位替代上面的vector<int>(26,0)，这样空间复杂度从O(n*26)减小到O(n)，
        //并且判断两个字符串是否有共同字母可以通过(counts[i]&counts[j])==0
        int res=0;
        if(words.size()==0) return res;
        vector<int> counts(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
                counts[i]|=1<<words[i][j]-'a';
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((counts[i]&counts[j])==0)
                    res=max(res,static_cast<int>(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};
class Solution2 {
public:
    int maxProduct(vector<string>& words) {
        //另一种思路，用set_intersection求交集，但是超时
        int res=0;
        if(words.size()==0) return res;
        vector<set<char>> counts(words.size(),set<char>{});
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
                counts[i].insert(words[i][j]);
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                set<char> temp;
                set_intersection(counts[i].begin(),counts[i].end(),counts[j].begin(),counts[j].end(),inserter(temp,temp.begin()));
                if(temp.size()==0)
                    res=max(res,static_cast<int>(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};
int main()
{
    Solution2 solute;
    vector<string> words={"abcw","baz","foo","bar","xtfn","abcdef"};
    int pos=1;
    cout<<solute.maxProduct(words)<<endl;
    return 0;
}
