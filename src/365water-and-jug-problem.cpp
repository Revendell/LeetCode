#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    set<int> res;
    bool canMeasureWater(int x, int y, int z) {
        //����˼�룺�ݹ�dfs���������������ʱ
        //��x��y����õ�����cur������res��Ȼ��cur��res������������õ��µ�������res
        //������������cur=z���򷵻�true
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
        //����˼�룺��ѧ�����涨���ҵ�x,y�����Լ���ܷ�z������
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
