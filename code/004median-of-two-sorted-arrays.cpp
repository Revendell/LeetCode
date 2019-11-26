#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
		int imin, imax, half_len;  //imin��imax�����۰��������a�е�i
		int max_of_left, min_of_right;  //max_of_left��λ��������ֵ��min_of_right�ұ���Сֵ
		int m = a.size(), n = b.size();
		int i, j;  //i�������a�±꣬j�������b�±꣬i+j������a��b�ֳ������룬��a[0]��a[i-1]��b[0]��b[j-1]����֮��i+j����m+n+1��һ��
		
		//����a��b��ʹ��length(a)<=length(b)����m<=n����ֹj=(m+n+1)/2-i<0�������
		if (m > n) {
			swap(a, b);
			swap(m, n);
		}
		imin = 0;
		imax = m;
		half_len = (m + n + 1) / 2; //��ȡ��
		while (imin <= imax) {
			i = (imin + imax) / 2;  //�۰���ң��ҵ�����Ҫ���iʹ��a[i-1]<=b[j]��b[j-1]<=a[i]����i+j=(m+n+1)/2
			j = half_len - i;  //��Ϊ��λ�������м����������i+j=(m+n+1)/2ʼ�ձ�����iΪ���޵���ߺ���jΪ���޵��ұ߸���֮�͵���m+n+1��һ�룬Ҳ����a[0]��a[i-1]��b[0]��b[j-1]����֮�͵���m+n+1��һ��
			//��֤i+j������a��b�ֳ�����������£���a[0]��a[i-1]��b[0]��b[j-1]����֮��i+j����m+n+1��һ��
			//����ʹ��a[i-1]<=b[j]��b[j-1]<=a[i]����������λ�������ʣ�����λ�������С����λ�����ұ�

			//���b[j-1] > a[i]˵��iС�ˣ�imin=i+1
			if (i < m && b[j-1] > a[i]) {
				imin = i + 1;
			}
			//���a[i-1] > b[j]˵��i���ˣ�iman=i-1
			else if (i > 0 && a[i-1] > b[j]) {
				imax = i - 1;
			}
			//�ҵ�i����a[i-1]<=b[j]��b[j-1]<=a[i]����i+j=(m+n+1)/2
			else {
				//�ҵ���ߵ����ֵmax(a[i-1], b[j-1])������i=0������a�����ֵ��j=0������b�����ֵ
				if (i == 0) {
					max_of_left = b[j - 1];
				}
				else if (j == 0) {
					max_of_left = a[i - 1];
				}
				else {
					max_of_left = max(a[i - 1], b[j - 1]);
				}
				//�ҵ��ұߵ���Сֵmin(a[i], b[j])������i-1=m-1������a���ұ�ֵ��j-1=n-1����b���ұ�ֵ
				if (i == m) {
					min_of_right = b[j];
				}
				else if (j == n) {
					min_of_right = a[i];
				}
				else {
					min_of_right = min(a[i], b[j]);
				}

				//��m+n������������λ�����ǵ�i+j=(m + n + 1) / 2������Ϊa�������a[0]��a[i-1]��i��Ԫ�أ�b�������b[0]��b[j-1]��j��Ԫ�أ����Ե�i+j��Ԫ�ؾ���max(a[i-1],a[j-1])=max_of_left
				if ((m + n) % 2==1) {
					return max_of_left;
				}
				//��m+n����ż������λ�����ǵ�i+j=(m + n + 1) / 2��i+j+1��ֵ��ƽ��
				//��Ϊa�������a[0]��a[i-1]��i��Ԫ�أ�b�������b[0]��b[j-1]��j��Ԫ�أ����Ե�i+j��Ԫ�ؾ���max(a[i-1],a[j-1])=max_of_left��i���ұ���С����a[i],j���ұ���С����b[j]�����Ե�i+j+1��Ԫ�ؾ���min(a[i],b[j])=min_of_right
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