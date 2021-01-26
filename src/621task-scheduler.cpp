#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //基本思想：贪心算法，统计tasks中字母出现次数，然后从大到小排序
        //则某个字母出现频次最大为Map[0]，对于该字母最少执行的时间为Map[0]+(Map[0]-1)*n
        //再排序下一个任务，如果下一个任务个数和最大任务数一致res++
        //cpu调度策略：目的是尽可能压榨cpu，不要让其空闲，让cpu利用率达到最大化
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
