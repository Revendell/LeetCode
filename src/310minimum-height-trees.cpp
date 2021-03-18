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
        //�򻯰棺��������ʹ��multimap�洢ͼ�ṹ�������map<int,set<int>>�洢ͼ�ṹ����
        //����Ϊ1�Ľڵ㲻�ϴ�����ͼ���Ƴ���ֱ��ʣ��ڵ���С�ڵ���2����ôʣ��Ľڵ���Ϊ���ڵ��γɵ����ĸ߶���С
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
        //����˼�룺��������˼·������Ϊ1�Ľڵ㲻�ϴ�����ͼ���Ƴ���ֱ��ʣ��ڵ���С�ڵ���2����ôʣ��Ľڵ���Ϊ���ڵ��γɵ����ĸ߶���С
        //Ϊʲô���Ͻ���Ϊ1�Ľڵ������ͼ���Ƴ����ʣ�µĽڵ�������ս����
        //���е���̰���㷨��������һ����ͣ�����ÿ�ν���ͷ�����ȥ����������ˣ�����ʣ�µ����һ����λ���м����ڣ�
        //���м�����Ϊ��㽫����۶��γɵ����һ������̵ģ���������һ���ĵ���
        if(n==1)  return {0};
        vector<int> res;  //��󷵻صĽ��
        map<int,set<int>> Map;  //��¼���ڵ���������ӹ�ϵ��Map[0]={1,2,3}��ʾ0�ڵ�ָ��1,2,3�ڵ�
        for(int i=0;i<edges.size();i++)
        {
            Map[edges[i][0]].insert(edges[i][1]);
            Map[edges[i][1]].insert(edges[i][0]);
        }
        queue<map<int,set<int>>::iterator> delnode;  //��¼��Ϊ1�Ľڵ�ĵ�����
        //����Ϊ1�Ľڵ�ĵ�����������delnode
        for(auto iter=Map.begin();iter!=Map.end();iter++)
        {
            if(iter->second.size()==1)
                delnode.push(iter);
        }
        //����Ϊ1�Ľڵ㲻�ϴ�����ͼ���Ƴ���ֱ��ʣ��ڵ���С�ڵ���2����ѭ��
        while(Map.size()>2)
        {
            //����Ϊ1�Ľڵ�ɾ����ɾ��֮ǰҲҪ��ָ�����ı�ȥ��������ɾ���ڵ�2����Map[3]={1,2,4}��ôҪ��Map[3]�еĽڵ�2ȥ��
            int queuelen=delnode.size();
            for(int i=0;i<queuelen;i++)
            {
                map<int,set<int>>::iterator iter=delnode.front();
                delnode.pop();
                //��Ϊ1�Ľڵ�ɾ��֮ǰ��ָ�����ı�Ҳȥ��
                set<int> curset=Map[*(iter->second.begin())];
                set<int>::iterator pos = curset.find(iter->first);
                curset.erase(pos);
                Map[*(iter->second.begin())]=curset;
                //����Ϊ1�Ľڵ�ĵ�����������delnode
                if(curset.size()==1)
                {
                    map<int,set<int>>::iterator curiter=Map.find(*(iter->second.begin()));
                    delnode.push(curiter);
                }
                //����Ϊ1�Ľڵ�ɾ��
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
    map<int,vector<int>> Map;  //��¼���ڵ�������������
    int depth;  //��¼�Ե�ǰ�ڵ�Ϊ���ڵ���������߶�
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //����˼�룺��������˼άȻ����ʱ������0~n-1ÿ���ڵ㣬�Ըýڵ�Ϊ���ڵ㣬���ϵݹ�����Դ˽ڵ�Ϊ���ڵ���������߶�depth��
        //���depthС��mindepth��˵���Դ˽ڵ�Ϊ���ڵ�����ĸ߶���Ŀǰ���߶�����С�ģ�����mindepth������˽ڵ㵽res
        vector<int> res;
        int mindepth=1e9;
        //����ת��Ϊ�ڵ������������������Map
        for(int i=0;i<edges.size();i++)
        {
            Map[edges[i][0]].push_back(edges[i][1]);
            Map[edges[i][1]].push_back(edges[i][0]);
        }
        //����0~n-1ÿ���ڵ㣬�Ըýڵ�Ϊ���ڵ㣬���ϵݹ�����Դ˽ڵ�Ϊ���ڵ���������߶�depth
        for(int i=0;i<n;i++)
        {
            vector<int> path{i};
            depth=0;
            int h=1;
            Recursion(i,path,h);
            //���depthС��mindepth��˵���Դ˽ڵ�Ϊ���ڵ�����ĸ߶���Ŀǰ���߶�����С�ģ�����mindepth������˽ڵ㵽res
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
