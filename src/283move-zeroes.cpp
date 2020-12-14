
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //����˼�룺˫ָ�룬��ָ��ָ��0����ָ��ָ���0��Ȼ����������
        int left=0,right=0;
        while(right<nums.size())
        {
            if(nums[left]!=0)
            {
                left++;
                right=left+1;
            }
            else
            {
                if(nums[right]==0)
                    right++;
                else
                {
                    nums[left]=nums[right];
                    nums[right]=0;
                    left++;
                    right++;
                }
            }
        }
    }
};
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        //����˼�룺˫ָ�룬ʹ�ÿ���ָ�룬��ָ��������0ֵ�ͽ���ֵ��ֵ����ָ�룬��ָ��ǰ����
        //��󵱿�ָ�뵽���յ㣬����ָ��֮���ֵȫ����0������˼��������STL�е�remove_copy
        int left=0,right=0;
        for(;right<nums.size();right++)
        {
            if(nums[right]!=0)
            {
                nums[left]=nums[right];
                ++left;
            }
        }
        while(left<nums.size())
            nums[left++]=0;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={0,1,0,3,12};
    solute.moveZeroes(nums);
    for_each(nums.begin(),nums.end(),[](const int v){cout<<v<<endl;});
    return 0;
}
