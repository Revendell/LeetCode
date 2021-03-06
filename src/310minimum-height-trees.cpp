#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
#include<set>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //简化版：拓扑排序，使用multimap存储图结构，相比于map<int,set<int>>存储图结构更简单
        //将度为1的节点不断从无向图中移除，直至剩余节点数小于等于2，那么剩余的节点作为根节点形成的树的高度最小
        if(n==1)  return {0};
        vector<int> res;
        multimap<int,int> Map;
        deque<int> queue;
        for(auto v:edges)
        {
            Map.insert({v[0],v[1]});
            Map.insert({v[1],v[0]});
        }
        for(int i=0;i<n;i++)
        {
            if(Map.count(i)==1)
                queue.push_front(i);   
        }
        while(Map.size()>2)
        {
            int len=queue.size();
            while(len--)
            {
                int num1=queue.back();
                int num2=Map.find(num1)->second;
                queue.pop_back();
                int cnt=Map.count(num2);
                auto iter=Map.find(num2);
                while(cnt--)
                {
                    if(iter->second==num1)
                    {
                        Map.erase(iter);
                        break;
                    }
                    iter++;
                }
                if(Map.count(num2)==1)
                    queue.push_front(num2);
                Map.erase(num1);
            }
        }
        while(!queue.empty())
        {
            res.push_back(queue.back());
            queue.pop_back();
        }
        return res;
    }
};
class Solution1 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //基本思想：拓扑排序思路，将度为1的节点不断从无向图中移除，直至剩余节点数小于等于2，那么剩余的节点作为根节点形成的树的高度最小
        //为什么不断将度为1的节点从无向图中移除最后剩下的节点就是最终结果？
        //这有点像贪心算法，假设有一根竹竿，我们每次将两头的竹节去掉，反复如此，最终剩下的竹节一定是位于中间的竹节，
        //以中间的竹节为起点将竹竿折断形成的竹竿一定是最短的，这和这道题一样的道理。
        if(n==1)  return {0};
        vector<int> res;  //最后返回的结果
        map<int,set<int>> Map;  //记录树节点的有向连接关系：Map[0]={1,2,3}表示0节点指向1,2,3节点
        for(int i=0;i<edges.size();i++)
        {
            Map[edges[i][0]].insert(edges[i][1]);
            Map[edges[i][1]].insert(edges[i][0]);
        }
        queue<map<int,set<int>>::iterator> delnode;  //记录度为1的节点的迭代器
        //将度为1的节点的迭代器保存至delnode
        for(auto iter=Map.begin();iter!=Map.end();iter++)
        {
            if(iter->second.size()==1)
                delnode.push(iter);
        }
        //将度为1的节点不断从无向图中移除，直至剩余节点数小于等于2结束循环
        while(Map.size()>2)
        {
            //将度为1的节点删除，删除之前也要将指向它的边去除，比如删除节点2，而Map[3]={1,2,4}那么要将Map[3]中的节点2去除
            int queuelen=delnode.size();
            for(int i=0;i<queuelen;i++)
            {
                map<int,set<int>>::iterator iter=delnode.front();
                delnode.pop();
                //度为1的节点删除之前将指向它的边也去除
                set<int> curset=Map[*(iter->second.begin())];
                set<int>::iterator pos = curset.find(iter->first);
                curset.erase(pos);
                Map[*(iter->second.begin())]=curset;
                //将度为1的节点的迭代器保存至delnode
                if(curset.size()==1)
                {
                    map<int,set<int>>::iterator curiter=Map.find(*(iter->second.begin()));
                    delnode.push(curiter);
                }
                //将度为1的节点删除
                Map.erase(iter);
            }
        }
        for(auto iter=Map.begin();iter!=Map.end();iter++)
            res.push_back(iter->first);
        return res;
    }
};
class Solution2 {
public:
    map<int,vector<int>> Map;  //记录树节点的有向连接情况
    int depth;  //记录以当前节点为根节点的树的最大高度
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //基本思想：最正常的思维然而超时，遍历0~n-1每个节点，以该节点为根节点，不断递归计算以此节点为根节点的树的最大高度depth，
        //如果depth小于mindepth，说明以此节点为根节点的树的高度是目前树高度中最小的，更新mindepth，保存此节点到res
        vector<int> res;
        int mindepth=1e9;
        //将边转化为节点有向连接情况保存至Map
        for(int i=0;i<edges.size();i++)
        {
            Map[edges[i][0]].push_back(edges[i][1]);
            Map[edges[i][1]].push_back(edges[i][0]);
        }
        //遍历0~n-1每个节点，以该节点为根节点，不断递归计算以此节点为根节点的树的最大高度depth
        for(int i=0;i<n;i++)
        {
            vector<int> path{i};
            depth=0;
            int h=1;
            Recursion(i,path,h);
            //如果depth小于mindepth，说明以此节点为根节点的树的高度是目前树高度中最小的，更新mindepth，保存此节点到res
            if(depth<mindepth)
            {
                res.clear();
                res.push_back(i);
                mindepth=depth;
            }
            else if(depth==mindepth)
                res.push_back(i);
        }
        return res;
    }
    void Recursion(int n,vector<int> path,int h)
    {
        if(h>depth)
            depth=h;
        vector<int> nextnode=Map[n];
        for(int i=0;i<nextnode.size();i++)
        {
            vector<int>::iterator iter=find(path.begin(),path.end(),nextnode[i]);
            if(iter==path.end())
            {
                path.push_back(nextnode[i]);
                Recursion(nextnode[i],path,h+1);
            }
        }
    }
};
int main()
{
    Solution1 solute;
    int n=6;
    vector<vector<int>> edges={{0,1},{0,2},{0,3},{3,4},{4,5}};
    vector<int> res=solute.findMinHeightTrees(n,edges);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<" ";});
    cout<<endl;
}
