#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    vector<double> res;  //最后返回的结果
    map<string,int> vex;  //顶点string转化为int映射，方便用连接矩阵存储有向加权图
    vector<vector<double>> arc;  //连接矩阵表示有向加权图
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //基本思想：递归dfs深度优先搜索，抽象成有向加权图，使用深度优先遍历找寻路径，路径上的值相乘即为结果
        int cnt=0;
        //将顶点string转化为int映射，方便用连接矩阵表示有向加权图
        for(int i=0;i<equations.size();i++)
        {
            if(vex.find(equations[i][0])==vex.end())
                vex[equations[i][0]]=cnt++;
            if(vex.find(equations[i][1])==vex.end())
                vex[equations[i][1]]=cnt++;
        }
        vector<double> temp(cnt,0.0);
        arc.resize(cnt,temp);
        //初始化连接矩阵
        for(int i=0;i<equations.size();i++)
        {
            arc[vex[equations[i][0]]][vex[equations[i][1]]]=values[i];
            arc[vex[equations[i][1]]][vex[equations[i][0]]]=1.0/values[i];
            arc[vex[equations[i][0]]][vex[equations[i][0]]]=1.0;
            arc[vex[equations[i][1]]][vex[equations[i][1]]]=1.0;
        }
        //遍历每一个需要查询的顶点from到to的路径权重
        for(int i=0;i<queries.size();i++)
        {
            //没有存储过的顶点，保存-1
            if(vex.find(queries[i][0])==vex.end()||vex.find(queries[i][1])==vex.end())
            {
                res.push_back(-1.0);
                continue;
            }
            //visited记录当前顶点是否访问过
            vector<bool> visited(cnt,false);
            visited[vex[queries[i][0]]]=true;
            //深度优先搜索from到to的路径权重
            if(!dfs(vex[queries[i][0]],vex[queries[i][1]],1.0,visited))
                res.push_back(-1.0);
        }
        return res;
    }
    bool dfs(int from,int to,double cur,vector<bool> visited)
    {
        if(from==to)
        {
            res.push_back(cur);
            return true;
        }
        for(int i=0;i<arc[from].size();i++)
        {
            if(arc[from][i]!=0&&visited[i]==false)
            {
                visited[i]=true;
                if(dfs(i,to,cur*arc[from][i],visited))
                    return true;
                visited[i]=false;
            }
        }
        return false;
    }
};
int main()
{
    Solution solute;
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> res=solute.calcEquation(equations,values,queries);
    for_each(res.begin(),res.end(),[](double v){cout<<v<<endl;});
    return 0;
}
