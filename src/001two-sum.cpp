#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//基本思想：哈希表
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec;  //vector容器用于存储之和等于target的两数下标
		int i=0,j=nums.size()-1,sum;  //两个数的下标i和j分别从容器头和尾检索
		sort(nums.begin(),nums.end());
		while(i<j)
		{
			sum = nums[i] + nums[j];
			if(sum>target)  //如果两数之和大于target，尾下标j--
				j--;
			else if(sum<target)  //如果两数之和小于target，头下标i++
				i++;
			else
			{
				vec.push_back(i);
				vec.push_back(j);
				return vec;
			}
		}
	}
};
int main()
{
	Solution solute;
	vector<int> vec{2, 7, 11, 15};
	int target=9;
	vec=solute.twoSum(vec,target);
	cout<<vec[0]<<vec[1];
	return 0;
}