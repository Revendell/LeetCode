#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //����˼�룺����ջ��ά������Ϊ3�ĵ���ջ�������ǰԪ�ر�ջ������ջ������ǰԪ���滻��ջ�иպñ������Ԫ�أ�
        //�����滻�ĺô��ǲ���Ӱ����������еĳ���
        //Ϊʲô���ڵ�ǰ����nums��Ԫ����Ҫ�������ǵ�ջ�б������ڻ���ڵ�Ԫ���е�һ��Ԫ�أ�
		//��������[2,4,5,3,7]��������3ʱ��ջ������Ԫ����[2,4,5]����Ҫ��3���ǵ�4���������������ǵ��������г���Ϊ2�����������У����һ��Ԫ����С������3�滻��֮ǰ��С������4�����
        if(nums.size()<3)  return false;
        vector<int> res{nums[0]};
        for(int i=1;i<nums.size()&&res.size()<3;i++)
        {
            if(nums[i]>res.back())
                res.push_back(nums[i]);
            else if(nums[i]<res.back())
            {
                auto iter=lower_bound(res.begin(),res.end(),nums[i]);
                *iter=nums[i];
            }
        }
        return res.size()==3;
    }
};
int main()
{
    Solution solute;
    vector<int> nums{2,1,5,0,3};
    cout<<solute.increasingTriplet(nums)<<endl;
    return 0;
}
