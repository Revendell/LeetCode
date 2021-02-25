#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //基本思想：排序+双指针，将问题转化为56合并区间
        //通过map获取每个字符的区间范围，然后将这些区间合并即可
        vector<int> res;
        map<char,pair<int,int>> Mapinterval;
        for(int i=0;i<S.size();i++)
        {
            if(Mapinterval.find(S[i])==Mapinterval.end())
                Mapinterval[S[i]]={i,i};
            else
                Mapinterval[S[i]].second=i;
        }
        vector<pair<int,int>> intervals;
        for(auto iter=Mapinterval.begin();iter!=Mapinterval.end();iter++)
            intervals.push_back((*iter).second);
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();)
        {
            int j=i+1;
            int left=intervals[i].first,right=intervals[i].second;
            while(j<intervals.size()&&intervals[j].first<right)
            {
                left=min(left,intervals[j].first);
                right=max(right,intervals[j].second);
                j++;
            }
            res.push_back(right-left+1);
            i=j;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    string S = "ababcbacadefegdehijhklij";
    vector<int> res=solute.partitionLabels(S);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
