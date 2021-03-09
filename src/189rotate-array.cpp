#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
    }
};
class Solution1 {
public:
	void rotate(vector<int>& nums, int k) {
		//����˼�룺ʹ�÷�ת���Ƚ�nums����Ԫ�ط�ת���ٽ�ǰk��Ԫ�غͺ�n-k��Ԫ�طֱ�ת��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(1)
		if (nums.size() == 0 || k == 0)
			return;
		k = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
		return;
	}
};
class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		//����˼�룺��������ʱ���ƶ�k�Σ�ÿ�ν�������������Ԫ�������ƶ�1��λ��
		if (nums.size() == 0)
			return;
		int i, cur, pre, pos, cnt;
		while (k)
		{
			cnt = nums.size();
			i = 0;
			pre = nums[0];
			while (cnt)
			{
				pos = (i + 1) % nums.size();
				cur = nums[pos];
				nums[pos] = pre;
				pre = cur;
				i = pos;
				cnt--;
			}
			k--;
		}
		return;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,2,3,4 };
	int k = 2;
	solute.rotate(nums, k);
	for_each(nums.begin(), nums.end(), [](const auto v) {cout << v << " "; });
	cout << endl;
	return 0;
}