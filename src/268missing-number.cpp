
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //����˼�룺������Ϊ��ϣ����Ϊ��ĿҪ��ʱ�临�Ӷ�O(n)���ռ临�Ӷȳ����������ռ䣬
        //����ֻ��ʹ���Ѹ�����nums��ΪHashMap��ʹ���Ѹ�����nums��ΪHashMap��
        //ѭ��һ��ɨ��nums��ÿ��Ԫ�أ�Ȼ��Ը�Ԫ��Ϊ�±��µ�ֵȡ���ţ���˵����Ԫ�ش��ڣ�
        //�����Ȳ��ı��Ԫ��Ϊ�±��µ�ֵ�������±��Ǹ�Ԫ�ش��ڡ�
        int flagzero=1;
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[i])==nums.size())
                continue;
            else
            {
                if(nums[abs(nums[i])]==0)
                    flagzero=-1;
                else
                    nums[abs(nums[i])]=-nums[abs(nums[i])];
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0 || (nums[i]==0 && flagzero > 0))
                return i;
        }
        return nums.size();
    }
};
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        //����˼�룺λ�������0,1,2,3,4^0,1,2,4=3
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            res = res ^ i ^ nums[i];            // a^b^b = a;
        return res ;
    }
};
class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        //����˼�룺��ѧ���
        int sum = 0, n = nums.size();
        for(int n : nums)
            sum += n;
        return (n * (n+1)) / 2 - sum;
    }
};
int main()
{
    Solution solute;
    vector<int> nums={1,2,3,4};
    cout<<solute.missingNumber(nums)<<endl;
    return 0;
}
