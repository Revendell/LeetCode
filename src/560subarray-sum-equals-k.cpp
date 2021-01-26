#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //����˼�룺������ʱ��˫��ѭ���������п��ܵ����������У�����ⲻ���û������ڣ���ΪԪ�ش��ڸ���
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==k)  res++;
            }
        }
        return res;
    }
};
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        //����˼�룺ǰ׺��+��ϣ��HashMap��HashMap[i]��ʾǰ׺��Ϊi�������г��ֵĴ���,pre[i]-pre[j-1]==k,pre[j-1]==pre[i]-k
        //��������nums������ӵ�0��Ԫ�ص���ǰԪ�صĺ�sum���ù�ϣ��Map������ֹ����ۻ���sum�Ĵ���;
        //���sum-k�ڹ�ϣ���г��ֹ��������ӵ�ǰ�±�i��ǰ��������������ĺ�Ϊsum.
        int res=0;
        unordered_map<int,int> Map;
        Map[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(Map.find(sum-k)!=Map.end())
            {
                res+=Map[sum-k];
            }
            Map[sum]++;
        }
        return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={1,1,1};
    int k=2;
    cout<<solute.subarraySum(nums,k)<<endl;
    return 0;
}
