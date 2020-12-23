#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //����˼�룺����ջ+�鲢˼��
        //�������Ǵ�nums1��ȡ��k1������num2��ȡ��k2��������k1+k2=k��
        //��k1��k2�����������������ǻ����ġ��������������������໥�����ģ�
        //�������ֻ��Ҫ�ֱ���⣬Ȼ�󽫽���ϲ����ɡ�
        //��δ�num��ȡn��������������أ�
        //ʹ�õ���ջ�������ǰ���ֱ�ջ���󣬲��ҵ�ǰ����֮�����㹻���������Ϊnλ����
        //��ջ�����ֳ�ջ����ǰ������ջ���滻����ջ������
        vector<int> res;
        if(k==0) return {};
        for(int i=0;i<=k&&i<=nums1.size();i++)
        {
            if(k-i>nums2.size())
                continue;
            vector<int> temp1=maxPick(nums1,i);
            vector<int> temp2=maxPick(nums2,k-i);
            vector<int> cur=mergeNums(temp1,temp2);
            res=max(res,cur);
        }
        return res;
    }
    //����ջ����num��ȡn�������������
    vector<int> maxPick(vector<int> num,int n)
    {
        vector<int> st;
        if(n==0) return st;
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty()&&st.back()<num[i]&&n-int(st.size())<=int(num.size())-1-i)
                st.pop_back();
            if(st.size()<n)
                st.push_back(num[i]);
        }
        return st;
    }
    //��nums1��nums2��ȡ�������ϲ��������
    vector<int> mergeNums(vector<int> nums1,vector<int> nums2)
    {
        vector<int> nums;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            //����ע�⵱nums1[i]==nums2[j]��ʱ����Ҫ�Ƚ�i��j��������ִ�С����ȷ������push_back
            //����nums1={6,7} nums2={6,0,4}����Ϊ6==6�����ԱȽ�{7}��{0,4}�Ĵ�С������Ǹ��Ż�push_back
            if(nums1[i]>nums2[j])
                nums.push_back(nums1[i++]);
            else if(nums1[i]<nums2[j])
                nums.push_back(nums2[j++]);
            else
            {
                vector<int> nums1copy(nums1.begin()+i+1,nums1.end());
                vector<int> nums2copy(nums2.begin()+j+1,nums2.end());
                if(nums1copy>nums2copy)
                    nums.push_back(nums1[i++]);
                else
                    nums.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size())
            nums.push_back(nums1[i++]);
        while(j<nums2.size())
            nums.push_back(nums2[j++]);
        return nums;
    }
};
int main()
{
    Solution solute;
    vector<int> nums1={3, 4, 6, 5};
    vector<int> nums2={9, 1, 2, 5, 8, 3};
    int k=5;
    vector<int> res=solute.maxNumber(nums1,nums2,k);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
