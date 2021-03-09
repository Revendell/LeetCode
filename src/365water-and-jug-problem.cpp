#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    set<int> res;
    bool canMeasureWater(int x, int y, int z) {
        //基本思想：递归dfs深度优先搜索，超时
        //将x与y相减得到的数cur保存至res，然后cur与res中所有数相减得到新的数加入res
        //这个过程中如果cur=z，则返回true
        if(z==x||z==y||x+y==z||z==0)  return true;
        res.insert(x);
        res.insert(y);
        int cur=x>y?x-y:y-x;
        return dfs(cur,z);
    }
    bool dfs(int cur,int z)
    {
        if(res.find(cur)!=res.end())
            return false;
        if(cur==z)
            return true;
        for(auto iter=res.begin();iter!=res.end();iter++)
        {
            if(cur+*iter==z)
                return true;
        }
        res.insert(cur);
        for(auto iter=res.begin();iter!=res.end();iter++)
        {
            if(*iter==cur)
                continue;
            else if(*iter>cur&&dfs(*iter-cur,z))
                return true;
            else if(cur>*iter&&dfs(cur-*iter,z))
                return true;
        }
        return false;
    }
};
class Solution1 {
public:
    bool canMeasureWater(int x, int y, int z) {
        //基本思想：数学，贝祖定理，找到x,y的最大公约数能否z被整除
        if (x + y < z)
            return false;
        if (z == 0 || x + y == z)
            return true;
        if(x>y) swap(x,y);
        if(x==0)  return y==z;
        while(y%x!=0)
        {
            int temp=x;
            x=y%x;
            y=temp;
        }
        return z % x == 0;
    }

};
int main()
{
    Solution1 solute;
    int x=2,y=6,z=5;
    cout<<solute.canMeasureWater(x,y,z)<<endl;
    return 0;
}
