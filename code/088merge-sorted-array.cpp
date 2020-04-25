#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//����˼�룺˫ָ�룬�Ӻ���ǰ��������Ϊnums1����������λ�ã������Ͳ���Ҫ�������ռ�
		//i�Ӻ���ǰָ��nums1��ЧԪ�أ�j�Ӻ���ǰָ��nums2��ЧԪ�أ�cur��m+n-1��0ָ��ϲ���Ԫ��
		int i = m - 1, j = n - 1, cur = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] < nums2[j])
				nums1[cur--] = nums2[j--];
			else
				nums1[cur--] = nums1[i--];
		}
		while (i >= 0)
			nums1[cur--] = nums1[i--];
		while (j >= 0)
			nums1[cur--] = nums2[j--];
	}
};
int main()
{
	Solution solute;
	vector<int> nums1 = { 2,0 };
	vector<int> nums2 = { 1 };
	int m = 1, n = 1;
	solute.merge(nums1, m, nums2, n);
	copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
	return 0;
}