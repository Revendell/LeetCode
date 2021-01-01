#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,multiset<string>> vexNode;
        for(int i=0;i<tickets.size();i++)
            vexNode[tickets[i].front()].insert(tickets[i].back());
        int edges=tickets.size();
        dfs("JFK",edges,vexNode);
        return res;
    }
    bool dfs(string cur,int edges,map<string,multiset<string>> vexNode)
    {
        res.push_back(cur);
        if(edges==0)
            return true;
        for(auto iter=vexNode[cur].begin();iter!=vexNode[cur].end();iter++)
        {
            map<string,multiset<string>> temp(vexNode);
            auto iterera=temp[cur].find(*iter);
            temp[cur].erase(iterera);
            if(dfs(*iter,edges-1,temp))
                return true;
            res.pop_back();
        }
        return false;
    }
};
class Solution1 {
public:
    vector<string> res;
    map<string,map<string,int>> vexNode;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //基本思想：递归回溯dfs深度优先搜索，使用map<string,map<string,int>>数据结构保存图，因为map是二叉平衡树，所以是有序的
        //因为有向图从JFK出发遍历每个节点的路径是存在的，并且返回字典序最小的路径，所以从JFK出发按字典序遍历JFK指向的每个节点
        //如果最后路径走过的边数为edges，这一路径就是最终返回的结果，否则返回false说明此路径并不能走通，节点pop
        //一开始使用map<string,multiset<string>>保存图，但是某条边走过就需要erase，这样函数参数多了vexNode，导致效率及其低下
        for(int i=0;i<tickets.size();i++)
            vexNode[tickets[i].front()][tickets[i].back()]++;
        int edges=tickets.size();
        dfs("JFK",edges);
        return res;
    }
    bool dfs(string cur,int edges)
    {
        res.push_back(cur);
        if(edges==0)
            return true;
        for(auto iter=vexNode[cur].begin();iter!=vexNode[cur].end();iter++)
        {
            if(iter->second>0)
            {
                iter->second--;
                if(dfs(iter->first,edges-1))
                    return true;
                iter->second++;
                res.pop_back();
            }
        }
        return false;
    }
};
int main()
{
    Solution1 solute;
    vector<vector<string>> tickets={{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res=solute.findItinerary(tickets);
    for_each(res.begin(),res.end(),[](const string &v){cout<<v<<endl;});
    return 0;
}
