#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//����˼�룺�������У�һ��ʼ���뷨������155����Сջʹ�õĸ���ջ˼��
		//ά��һ�����У����е�ͷΪ��ǰ�������ڵ����ֵ��Ҳ���ǻ��������ұ߽����һ��ֵnums[right]
		//�ͽ�nums[right]����е�β����ֵ�Ƚϣ���nums[right]С�Ķ���Ϊnums[right]��������ʹ�ö���ͷ��Զ�ǻ������ڵ����ֵ
		//�����ַ����������ţ���Ϊ���ܲ��ϳ��ֱȶ��е�β���ֵ������Ҫ�����޸ģ�ʱ�临�Ӷȱ��
		//��ѵķ�����nums[right]����е�β����ֵ�Ƚϱ�nums[right]С��ȫ����������
		//������ʹ�ö����е�ֵ������ȷ���ˣ���һ����k��ֵ�����Զ��б������nums�±꣬�������ܱ�֤��������k��ֵ
		vector<int> res;
		deque<int> queue;
		int right = 0;
		while (right < nums.size())
		{
			if (queue.size() == k)
				queue.pop_front();
			if (!queue.empty() && nums[right] > queue.back())
			{
				for (auto iter = queue.rbegin(); iter != queue.rend() && nums[right] > * iter; iter++)
					*iter = nums[right];
			}
			queue.push_back(nums[right]);
			if (queue.size() == k)
				res.push_back(queue.front());
			right++;
		}
		return res;
	}
};
class Solution1 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		//����˼�룺�������У�һ��ʼ���뷨������155����Сջʹ�õĸ���ջ˼��
		//ά��һ�����У����е�ͷΪ��ǰ�������ڵ����ֵ��Ҳ���ǻ��������ұ߽����һ��ֵnums[i]
		//�ͽ�nums[i]����е�β����ֵ�Ƚϣ���nums[i]С�Ķ���Ϊnums[i]��������ʹ�ö���ͷ��Զ�ǻ������ڵ����ֵ
		//�����ַ����������ţ���Ϊ���ܲ��ϳ��ֱȶ��е�β���ֵ������Ҫ�����޸ģ�ʱ�临�Ӷȱ��
		//��ѵķ�����nums[i]����е�β����ֵ�Ƚϱ�nums[i]С��ȫ����������
		//������ʹ�ö����е�ֵ������ȷ���ˣ���һ����k��ֵ�����Զ��б������nums�±꣬�������ܱ�֤��������k��ֵ
		vector<int> res;
        deque<int> queue;
        for(int i=0;i<nums.size();i++)
        {
            if(!queue.empty()&&i-queue.front()>=k)
                queue.pop_front();
            while(!queue.empty()&&nums[i]>nums[queue.back()])
                queue.pop_back();
            queue.push_back(i);
            if(i>=k-1)
                res.push_back(nums[queue.front()]);
        }
        return res;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = solute.maxSlidingWindow(nums, k);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}