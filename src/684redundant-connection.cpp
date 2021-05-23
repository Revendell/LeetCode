#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> fa;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //基本思想：并查集
        fa.resize(edges.size()+1);
        for(int i=0;i<=edges.size();i++)
            fa[i]=i;
        for(int i=0;i<edges.size();i++)
        {
            if(find(edges[i][0])==find(edges[i][1]))
                return edges[i];
            merge(edges[i][0],edges[i][1]);
        }
        return {0,0};
    }
    int find(int x)
    {
        if(fa[x] == x)
            return x;
        else
            return find(fa[x]);
    }
    void merge(int i, int j)
    {
        fa[find(i)] = find(j);
    }
};
int main()
{
    Solution solute;
    vector<vector<int>> edges={{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    vector<int> res=solute.findRedundantConnection(edges);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
