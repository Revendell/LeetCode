#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct Bucket
{
	bool used = false;
	int maxVal = INT_MIN;
	int minVal = INT_MAX;
};
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		//����˼�룺Ͱ����ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(b)
		//����಻�������Ͱ�ڣ����nums�Ǿ��ȷֲ��ģ���ô��������Ͱ�Ĵ�С��
		//������Ǿ��ȷֲ��������һ������Ͱ�Ĵ�С����������಻�������Ͱ�ڡ�
		if (nums.size() < 2)
			return 0;
		int res = 0;
		//nums���������Сֵ
		int maxNum = *max_element(nums.begin(), nums.end());
		int minNum = *min_element(nums.begin(), nums.end());
		//Ͱ������С
		int bucketSize = (maxNum - minNum) / (nums.size() - 1);
		//����bucketSize=0�����Ͱ��СΪ0��ÿ��Ͱ��һ��Ԫ�ض��治��������Ϊnums�д��ڴ����ظ�Ԫ��
		if (bucketSize == 0)
			bucketSize = 1;
		//Ͱ����
		int bucketCount = (maxNum - minNum) / bucketSize + 1;
		//ÿ��Ͱ��ֻ����Ͱ�����Ԫ�غ���СԪ��
		vector<Bucket> buckets(bucketCount);
		for (auto& v : nums)
		{
			int pos = (v - minNum) / bucketSize;
			buckets[pos].used = true;
			buckets[pos].maxVal = max(buckets[pos].maxVal, v);
			buckets[pos].minVal = min(buckets[pos].minVal, v);
		}
		int pre = minNum;
		//����ÿ��Ͱ����������������Ͱ���Ԫ�ز�ֵ��
		for (int i = 0; i < buckets.size(); i++)
		{
			if (!buckets[i].used)
				continue;
			//��ǰͰ����Сֵ��ǰһ��Ͱ�����ֵ�Ĳ�ֵ������nums�������
			res = max(res, buckets[i].minVal - pre);
			//ǰһ��Ͱ�����ֵ
			pre = buckets[i].maxVal;
		}
		return res;
	}
};
class Solution1 {
public:
	int maximumGap(vector<int>& nums) {
		//����˼�룺set��ʱ�临�Ӷ�O(n)�ռ临�Ӷ�O(n)
		if (nums.size() < 2)
			return 0;
		set<int> dict(nums.begin(), nums.end());
		int res = 0;
		auto pre = dict.begin();
		auto i = pre;
		for (i++; i != dict.end(); i++)
		{
			res = max(res, *i - *pre);
			pre = i;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,9,2,1,6 };
	cout << solute.maximumGap(nums) << endl;
	return 0;
}