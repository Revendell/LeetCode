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
        //����˼�룺�ݹ����dfs�������������ʹ��map<string,map<string,int>>���ݽṹ����ͼ����Ϊmap�Ƕ���ƽ�����������������
        //��Ϊ����ͼ��JFK��������ÿ���ڵ��·���Ǵ��ڵģ����ҷ����ֵ�����С��·�������Դ�JFK�������ֵ������JFKָ���ÿ���ڵ�
        //������·���߹��ı���Ϊedges����һ·���������շ��صĽ�������򷵻�false˵����·����������ͨ���ڵ�pop
        //һ��ʼʹ��map<string,multiset<string>>����ͼ������ĳ�����߹�����Ҫerase������������������vexNode������Ч�ʼ������
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
