#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<stdlib.h>
using namespace std;
class Solution {
public:
    Solution(vector<int>& nums) {
        //基本思想：洗牌算法
        //思路是在前n-1张牌洗好的情况下，第n张牌随机与前n-1张牌的其中一张牌交换，或者不换，即是随机洗牌
        this->nums=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp=this->nums;
        for(int i=1;i<temp.size();i++)
        {
            int j=rand()%(i+1);
            if(i!=j)
                swap(temp[j],temp[i]);
        }
        return temp;
    }
private:
    vector<int> nums;
};
int main()
{
    vector<int> nums{1,2,3,4};
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    for_each(param_1.begin(),param_1.end(),[](int v){cout<<v<<endl;});
    vector<int> param_2 = obj->shuffle();
    for_each(param_2.begin(),param_2.end(),[](int v){cout<<v<<endl;});
    return 0;
}