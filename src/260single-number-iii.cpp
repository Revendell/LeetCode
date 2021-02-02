#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //����˼�룺λ���㣬��nums������Ԫ�����õ��ľ�������Ԫ��a��b����λ����ӽ��x
        //��ôx�ĵ�һ����0λn����a��b�ڵ�nλ�ϻ�Ϊ0��1�����Կ��Խ�nums������Ԫ���ڵ�nλ����0��1�ֳ����࣬������Ԫ�طֱ����͵õ���a��bֵ
        int a=0,b=0;
        int x=0,n;
        for(auto num:nums)
            x^=num;
        for(n=0;n<32;n++)
        {
            if(x&1)
                break;
            x>>=1;
        }
        for(auto num:nums)
        {
            if(num>>n&1)
                a^=num;
            else
                b^=num;
        }
        return {a,b};
    }
};
int main()
{
    Solution solute;
    vector<int> nums{1,2,1,3,2,5};
    vector<int> res=solute.singleNumber(nums);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}
