#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vec;
		int i=0,j=nums.size()-1,sum;
		while(i<j)
		{
			sum = nums[i] + nums[j];
			if(sum>target)
				j--;
			else if(sum<target)
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