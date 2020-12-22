
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //����˼�룺������counts��ά�����wordsÿ���ַ����е��ַ�������Ȼ��ͨ��˫��ѭ������words�ж�ÿ���ַ���������ַ����Ƿ���ڹ�ͬ��ĸ
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
        //�Ż�����һ��32λint��ʾһ��word�г��ֵ���ĸ����int32λ��������vector<int>(26,0)�������ռ临�Ӷȴ�O(n*26)��С��O(n)��
        //�����ж������ַ����Ƿ��й�ͬ��ĸ����ͨ��(counts[i]&counts[j])==0
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
        //��һ��˼·����set_intersection�󽻼������ǳ�ʱ
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
