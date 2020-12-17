#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
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
class Solution1 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //����˼�룺��������˼·������Ϊ1�Ľڵ㲻�ϴ�����ͼ���Ƴ���ֱ��ʣ��ڵ���С�ڵ���2����ôʣ��Ľڵ���Ϊ���ڵ��γɵ����ĸ߶���С
        //Ϊʲô���Ͻ���Ϊ1�Ľڵ������ͼ���Ƴ����ʣ�µĽڵ�������ս����
        //���е���̰���㷨��������һ����ͣ�����ÿ�ν���ͷ�����ȥ����������ˣ�����ʣ�µ����һ����λ���м����ڣ�
        //���м�����Ϊ��㽫����۶��γɵ����һ������̵ģ���������һ���ĵ���
        if(n==1)  return {0};
        vector<int> res;  //��󷵻صĽ��
        map<int,list<int>> Map;  //��¼���ڵ���������ӹ�ϵ��Map[0]={1,2,3}��ʾ0�ڵ�ָ��1,2,3�ڵ�
        for(int i=0;i<edges.size();i++)
        {
            Map[edges[i][0]].push_back(edges[i][1]);
            Map[edges[i][1]].push_back(edges[i][0]);
        }
        //����Ϊ1�Ľڵ㲻�ϴ�����ͼ���Ƴ���ֱ��ʣ��ڵ���С�ڵ���2����ѭ��
        while(Map.size()>2)
        {
            vector<map<int,list<int>>::iterator> delnode;  //��¼��Ϊ1�Ľڵ�ĵ�����
            //����Ϊ1�Ľڵ�ĵ�����������delnode
            for(auto iter=Map.begin();iter!=Map.end();iter++)
            {
                if(iter->second.size()==1)
                    delnode.push_back(iter);
            }
            //����Ϊ1�Ľڵ�ɾ����ɾ��֮ǰҲҪ��ָ�����ı�ȥ��������ɾ���ڵ�2����Map[3]={1,2,4}��ôҪ��Map[3]�еĽڵ�2ȥ��
            for(int i=0;i<delnode.size();i++)
            {
                map<int,list<int>>::iterator iter=delnode[i];
                //��Ϊ1�Ľڵ�ɾ��֮ǰ��ָ�����ı�Ҳȥ��
                list<int> curlist=Map[iter->second.back()];
                list<int>::iterator pos = find(curlist.begin(),curlist.end(),iter->first);
                curlist.erase(pos);
                Map[iter->second.back()]=curlist;
                //����Ϊ1�Ľڵ�ɾ��
                Map.erase(iter);
            }
        }
        for(auto iter=Map.begin();iter!=Map.end();iter++)
            res.push_back(iter->first);
        return res;
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
