#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    vector<double> res;  //��󷵻صĽ��
    map<string,int> vex;  //����stringת��Ϊintӳ�䣬���������Ӿ���洢�����Ȩͼ
    vector<vector<double>> arc;  //���Ӿ����ʾ�����Ȩͼ
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //����˼�룺�ݹ�dfs�����������������������Ȩͼ��ʹ��������ȱ�����Ѱ·����·���ϵ�ֵ��˼�Ϊ���
        int cnt=0;
        //������stringת��Ϊintӳ�䣬���������Ӿ����ʾ�����Ȩͼ
        for(int i=0;i<equations.size();i++)
        {
            if(vex.find(equations[i][0])==vex.end())
                vex[equations[i][0]]=cnt++;
            if(vex.find(equations[i][1])==vex.end())
                vex[equations[i][1]]=cnt++;
        }
        vector<double> temp(cnt,0.0);
        arc.resize(cnt,temp);
        //��ʼ�����Ӿ���
        for(int i=0;i<equations.size();i++)
        {
            arc[vex[equations[i][0]]][vex[equations[i][1]]]=values[i];
            arc[vex[equations[i][1]]][vex[equations[i][0]]]=1.0/values[i];
            arc[vex[equations[i][0]]][vex[equations[i][0]]]=1.0;
            arc[vex[equations[i][1]]][vex[equations[i][1]]]=1.0;
        }
        //����ÿһ����Ҫ��ѯ�Ķ���from��to��·��Ȩ��
        for(int i=0;i<queries.size();i++)
        {
            //û�д洢���Ķ��㣬����-1
            if(vex.find(queries[i][0])==vex.end()||vex.find(queries[i][1])==vex.end())
            {
                res.push_back(-1.0);
                continue;
            }
            //visited��¼��ǰ�����Ƿ���ʹ�
            vector<bool> visited(cnt,false);
            visited[vex[queries[i][0]]]=true;
            //�����������from��to��·��Ȩ��
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
