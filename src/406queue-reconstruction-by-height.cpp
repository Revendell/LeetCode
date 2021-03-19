#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
bool Compare(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]>b[0];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //�򻯰棺���������Ƚ�people�Ӵ�С����Ȼ���ÿ��people��ǰ������������������
        vector<vector<int>> res(people);
        sort(res.begin(),res.end(),Compare);
        int i,j;
        for(i=1;i<res.size();i++)
        {
            vector<int> tmp=res[i];
            for(j=i-1;j>=0;j--)
            {
                if(tmp[1]<j+1)
                    res[j+1]=res[j];
                else
                    break;
            }
            res[j+1]=tmp;
        }
        return res;
    }
};
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people);
        sort(res.begin(),res.end());
        int n=res.size(),i,j;
        for(i=n-2;i>=0;i--)
        {
            int k=res[i][1];
            for(j=i-1;j>=0;j--)
            {
                if(res[j][0]>=res[i][0])
                    k--;
            }
            vector<int> temp(res[i]);
            for(j=i;j<n-1&&k>0;j++,k--)
                res[j]=res[j+1];
            res[j]=temp;
        }
        return res;
    }
};
bool cmpsort(const vector<int>& a,const vector<int>& b){
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
class Solution1 {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //����˼�룺�������򣬶�people�������򣬰�����ߴ�С�������������ȵ�ʱ�������ԴӴ�С����
        //Ȼ�����ÿһ��people������ǰpeople����������λ��������ȷλ��
        vector<vector<int>> res(people);
        sort(res.begin(),res.end(),cmpsort);
        int n=res.size(),i,j;
        for(i=n-2;i>=0;i--)
        {
            int k=res[i][1];
            vector<int> cur(res[i]);
            for(j=i;j<n-1&&k>0;j++,k--)
                res[j]=res[j+1];
            res[j]=cur;
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<vector<int>> people={{7,0},{4,4},{7,1},{5,0},{6,2},{5,2}};
    vector<vector<int>> res=solute.reconstructQueue(people);
    for(int i=0;i<res.size();i++)
        cout<<res[i][0]<<","<<res[i][1]<<endl;
    return 0;
}
