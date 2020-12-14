#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //����˼�룺����ʱ�临�Ӷ�O(nlogn)�ռ临�Ӷ�O(1)
        int res = 0;
        sort(citations.begin(),citations.end(),[](const int v1,const int v2){return v1>v2;});
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=i+1 && res < i+1)
                res=i+1;
        }
        return res;
    }
};
class Solution1 {
public:
    int hIndex(vector<int>& citations) {
        //����˼�룺������ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(n)
        //���һƪ���µ����ô����������ĵ�����n����ô���������ô�������Ϊn Ҳ����ı�h ָ����ֵ
        int n=citations.size();
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(citations[i]>n)
                cnt[n]++;
            else
                cnt[citations[i]]++;
        }
        for(int i=n;i>=1;i--)
        {
            if(cnt[i]>=i)
                return i;
            cnt[i-1]+=cnt[i];
        }
        return 0;
    }
};
int main()
{
    Solution1 solute;
    vector<int> num={0};
    cout<<solute.hIndex(num)<<endl;
    return 0;
}
