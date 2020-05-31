#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0, right = numbers.size() - 1, sum;
		while (left < right)
		{
			sum = numbers[left] + numbers[right];
			if (sum == target)
				return { left + 1, right + 1 };
			else if (sum > target)
				right--;
			else
				left++;
		}
		return {-1, -1};
	}
};
int main()
{
	Solution solute;
	vector<int> numbers = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> res = solute.twoSum(numbers, target);
	for_each(res.begin(), res.end(), [](const int v) {cout << v << endl; });
	return 0;
}