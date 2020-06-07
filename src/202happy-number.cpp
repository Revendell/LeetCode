#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	unordered_set<int> nums;
	bool isHappy(int n) {
		//基本思想：哈希表，时间复杂度O(logn)空间复杂度O(logn)
		if (n == 1)
			return true;
		else if (nums.find(n) != nums.end())
			return false;
		nums.insert(n);
		int res = 0;
		while (n)
		{
			int r = n % 10;
			res += r * r;
			n /= 10;
		}
		return isHappy(res);
	}
};
class Solution1 {
public:
	bool isHappy(int n) {
		//基本思想：快慢指针，上面的方法通过哈希表找循环的点，也可以通过快慢指针找
		//时间复杂度O(logn)空间复杂度O(1)，面试的时候应该想到这种方法
		int slow = n, fast = n;
		while (fast != 1)
		{
			slow = get_next(slow);
			fast = get_next(get_next(fast));
			//如果快慢指针相遇，说明快乐数成环返回false
			if (fast != 1 && slow == fast)
				return false;
		}
		return true;
	}
	int get_next(int n)
	{
		int res = 0;
		while (n)
		{
			int r = n % 10;
			res += r * r;
			n /= 10;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	int n = 10;
	cout << solute.isHappy(n) << endl;
	return 0;
}