#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //����˼�룺��̬�滮��ָ�룬�ο����264
        //Ϊÿ������������һ��ָ�룬Ȼ�����⼸������������Ľ���У��ҳ�����С�ģ�Ȼ��ƥ������������ĸ�������������ģ�������ָ��ֵ+1��
        vector<int> index(primes.size(),0);
        vector<int> num = { 1 };
        for(int i=1;i<n;i++)
        {
            int cur=INT_MAX;
            for(int j=0;j<index.size();j++)
            {
                if(num[index[j]]*primes[j]<cur)
                    cur=num[index[j]]*primes[j];
            }
            num.push_back(cur);
            for(int j=0;j<index.size();j++)
            {
                if(num[index[j]]*primes[j]==cur)
                    index[j]++;
            }
        }
        return num.back();
    }
};
int main()
{
    int n=12;
    vector<int> primes={2,7,13,19};
    Solution solute;
    cout<<solute.nthSuperUglyNumber(n,primes)<<endl;
    return 0;
}
