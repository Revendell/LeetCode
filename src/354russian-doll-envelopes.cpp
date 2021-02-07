#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(vector<int> a,vector<int> b)
{
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //����˼�룺��̬�滮+���ֲ��ң�ʱ�临�Ӷ�O(NlogN)
        //�ȶ�envelopes���򣬰��ճ��ȴ�С�����������������ȣ����տ�ȴӴ�С��������ת������300���������������
        //������Ŀ���Ǳ���ͬ��ʱ���С��Ҳ��������������У���Ϊͬ����ֻ��ѡ��һ��
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> nums;
        for(int i=0;i<envelopes.size();i++)
        {
            if(nums.empty()||envelopes[i][1]>nums.back())
                nums.push_back(envelopes[i][1]);
            else
            {
                auto iter=lower_bound(nums.begin(),nums.end(),envelopes[i][1]);
                *iter=envelopes[i][1];
            }
        }
        return nums.size();
    }
};
int main()
{
    Solution solute;
    vector<vector<int>> envelopes={{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    cout<<solute.maxEnvelopes(envelopes)<<endl;
    return 0;
}
