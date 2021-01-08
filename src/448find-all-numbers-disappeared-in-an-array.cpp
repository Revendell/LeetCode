#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //����˼�룺��ϣ��HashMap������nums������±���Ϊ��ϣ���ӳ�䣬����������ڣ����Ӧ�±��Ԫ��Ϊ���������Ͳ����������ռ��Ǹ������ڲ��Ҳ��ı��±�Ԫ��ֵ
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                continue;
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                res.push_back(i+1);
        return res;
    }
};
int main()
{
    vector<int> nums={1,2,2,3,3,4,4};
    Solution solute;
    vector<int> res=solute.findDisappearedNumbers(nums);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
