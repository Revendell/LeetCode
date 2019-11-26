#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
		int imin, imax, half_len;  //imin和imax用于折半查找数组a中的i
		int max_of_left, min_of_right;  //max_of_left中位数左边最大值，min_of_right右边最小值
		int m = a.size(), n = b.size();
		int i, j;  //i标记数组a下标，j标记数组b下标，i+j把数组a、b分成了两半，即a[0]到a[i-1]和b[0]到b[j-1]个数之和i+j等于m+n+1的一半
		
		//交换a和b，使得length(a)<=length(b)，即m<=n，防止j=(m+n+1)/2-i<0情况发生
		if (m > n) {
			swap(a, b);
			swap(m, n);
		}
		imin = 0;
		imax = m;
		half_len = (m + n + 1) / 2; //下取整
		while (imin <= imax) {
			i = (imin + imax) / 2;  //折半查找，找到满足要求的i使得a[i-1]<=b[j]和b[j-1]<=a[i]，且i+j=(m+n+1)/2
			j = half_len - i;  //因为中位数是最中间的数，所以i+j=(m+n+1)/2始终保存以i为界限的左边和以j为界限的右边个数之和等于m+n+1的一半，也就是a[0]到a[i-1]和b[0]到b[j-1]个数之和等于m+n+1的一半
			//保证i+j把数组a、b分成了两半情况下，即a[0]到a[i-1]和b[0]到b[j-1]个数之和i+j等于m+n+1的一半
			//必须使得a[i-1]<=b[j]和b[j-1]<=a[i]，才满足中位数的性质，即中位数的左边小于中位数的右边

			//如果b[j-1] > a[i]说明i小了，imin=i+1
			if (i < m && b[j-1] > a[i]) {
				imin = i + 1;
			}
			//如果a[i-1] > b[j]说明i大了，iman=i-1
			else if (i > 0 && a[i-1] > b[j]) {
				imax = i - 1;
			}
			//找到i满足a[i-1]<=b[j]和b[j-1]<=a[i]，且i+j=(m+n+1)/2
			else {
				//找到左边的最大值max(a[i-1], b[j-1])，可能i=0，数组a无左边值；j=0，数组b无左边值
				if (i == 0) {
					max_of_left = b[j - 1];
				}
				else if (j == 0) {
					max_of_left = a[i - 1];
				}
				else {
					max_of_left = max(a[i - 1], b[j - 1]);
				}
				//找到右边的最小值min(a[i], b[j])，可能i-1=m-1，数组a无右边值；j-1=n-1数组b无右边值
				if (i == m) {
					min_of_right = b[j];
				}
				else if (j == n) {
					min_of_right = a[i];
				}
				else {
					min_of_right = min(a[i], b[j]);
				}

				//当m+n等于奇数，中位数就是第i+j=(m + n + 1) / 2个，因为a的左边是a[0]到a[i-1]共i个元素，b的左边是b[0]到b[j-1]共j个元素，所以第i+j大元素就是max(a[i-1],a[j-1])=max_of_left
				if ((m + n) % 2==1) {
					return max_of_left;
				}
				//当m+n等于偶数，中位数就是第i+j=(m + n + 1) / 2和i+j+1大值的平均
				//因为a的左边是a[0]到a[i-1]共i个元素，b的左边是b[0]到b[j-1]共j个元素，所以第i+j大元素就是max(a[i-1],a[j-1])=max_of_left，i的右边最小的是a[i],j的右边最小的是b[j]，所以第i+j+1大元素就是min(a[i],b[j])=min_of_right
				else {
					return ((max_of_left + min_of_right) / 2.0);
				}	
			}
		}
		return -1;
	}
};
int main()
{
	Solution solute;
	vector<int> a = { 1, 3 };
	vector<int> b = { 2 };
	cout << solute.findMedianSortedArrays(a, b);
	return 0;
}