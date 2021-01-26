#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //����˼�룺̰���㷨��ͳ��tasks����ĸ���ִ�����Ȼ��Ӵ�С����
        //��ĳ����ĸ����Ƶ�����ΪMap[0]�����ڸ���ĸ����ִ�е�ʱ��ΪMap[0]+(Map[0]-1)*n
        //��������һ�����������һ��������������������һ��res++
        //cpu���Ȳ��ԣ�Ŀ���Ǿ�����ѹեcpu����Ҫ������У���cpu�����ʴﵽ���
        int res;
        vector<int> Map(26,0);
        for(auto task:tasks)
            Map[task-'A']++;
        sort(Map.begin(),Map.end(),greater<int>());
        res=Map[0]+(Map[0]-1)*n;
        for(int i=1;i<Map.size();i++)
        {
            if(Map[i]==Map[0])
                res++;
        }
        return max(res,int(tasks.size()));
    }
};
int main()
{
    Solution solute;
    vector<char> tasks={'A','A','A','B','B','B'};
    int n=2;
    cout<<solute.leastInterval(tasks,n)<<endl;
    return 0;
}
