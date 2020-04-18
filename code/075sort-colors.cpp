#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //����˼�룺�����������⣬��ָ�룬һ�α����������0�����ƶ�����ͷ�������2�����ƶ�����β�����ÿ���1
        //leftָ��0���ұ߽磬rightָ��2����߽磬Ҳ����ͨ��left��right����ɫ�����ɫ[0,left)��ɫ[left,right]��ɫ(righ,n-1]
        int left, right, cur;
        left = 0;
        right = nums.size() - 1;
        cur = 0;
        while (cur <= right)
        {
            //��ǰԪ��Ϊ0����Ҫ��0���ұ߽�left������0���ұ߽�left++��cur++
            if (nums[cur] == 0)
            {
                swap(nums[cur], nums[left]);
                left++;
                cur++;
            }
            //��ǰԪ��Ϊ1��curһֱλ��left��right֮���1Ԫ���ϣ����Բ���Ҫ������cur++
            else if (nums[cur] == 1)
            {
                cur++;
            }
            //��ǰԪ��Ϊ2����Ҫ��2����߽�right������2����߽�right--
            else
            {
                swap(nums[cur], nums[right]);
                right--;
            }
        }
        return;
    }
};
int main()
{
    Solution solute;
    vector<int> nums = { 2,0,2,1,1,0 };
    solute.sortColors(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    return 0;
}