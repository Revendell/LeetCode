#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        //基本思想：递归回溯，深度优先搜索
        dfs( k, n, 1);
        return res;
    }
    void dfs(int k, int n, int num)
    {
        if (k == 0)
        {
            if (n == 0)
                res.push_back(cur);
            return;
        }
        for (int i = num; i < 10 && n - i >= 0; i++)
        {
            cur.push_back(i);
            dfs(k - 1, n - i, i + 1);
            cur.pop_back();
        }
        return;
    }
};
int main()
{
    Solution solute;
    int k = 5, n = 27;
    vector<vector<int>> res = solute.combinationSum3(k, n);
    for (int i = 0; i < res.size(); i++)
    {
        for_each(res[i].begin(), res[i].end(), [](const auto v) {cout << v << " "; });
        cout << endl;
    }
    return 0;
}