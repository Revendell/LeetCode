#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;
class Solution {
public:
	int candy(vector<int>& ratings) {
	    //����˼�룺̰���㷨
	    //�����к��ӵ��ǹ�����ʼ��Ϊ 1��
        //�ȴ������ұ���һ�飬����ұߺ��ӵ����ֱ���ߵĸߣ����ұߺ��ӵ��ǹ�������Ϊ��ߺ��ӵ��ǹ����� 1��
        //�ٴ����������һ�飬�����ߺ��ӵ����ֱ��ұߵĸߣ�����ߺ��ӵ�ǰ���ǹ����������ұߺ��ӵ��ǹ���������ߺ��ӵ��ǹ�������Ϊ�ұߺ��ӵ��ǹ����� 1
        if (ratings.size() < 2) return ratings.size();
        vector<int> nums(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1])
                nums[i] = nums[i-1] + 1;
        }
        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i] < ratings[i-1])
                nums[i-1] = max(nums[i-1], nums[i] + 1);
        }
		int sum = 0;
		//��󷵻�numsԪ��֮��
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
};
class Solution1 {
public:
	int candy(vector<int>& ratings) {
		//����˼�룺�����ݼ�ջ����Ϊ��ǰ���Ӹ����ǹ���ȡ�������ڵĺ������֣��������ֵݼ����������ʱ��ȷ������ǰ���Ӽ����ǹ�
		//���õ����ݼ�ջ�������ǰ�������ִ�����һ��������ջ��ֱ����ǰ��������С����һ�����ӳ�ջ
		if (ratings.size() <= 1)
			return ratings.size();
		//nums�����Ӧ�±꺢�ӵ��ǹ�������󷵻�numsԪ��֮��
		vector<int> nums(ratings.size(), 0);
		stack<int> st;    //�����ݼ�ջ
		int i = 0;
		while (i < ratings.size() || !st.empty())
		{
			//��ǰ�������ִ�����һ�����ӣ��������ֿ�ʼ���µݼ�ȫ����ջ
			if (i + 1<= ratings.size() - 1 && ratings[i] > ratings[i + 1])
			{
				st.push(i);
			}
			//��ǰ��������С����һ�����ӣ��������ֿ�ʼ���µ���
			else
			{
				//��ǰ�������ִ�����һ������ֱ���ǹ���+1�������������µ���
				if (i < ratings.size() && i - 1 >= 0 && ratings[i] > ratings[i - 1])
					nums[i] = nums[i - 1] + 1;
				//��ǰ������������������������֣�λ���½����
				else
				    nums[i] = 1;
				while (!st.empty())
				{
					int pos = st.top();
					st.pop();
					//�����ǰ������������������������֣�λ���¶�
					if (pos - 1 >= 0 && ratings[pos] > ratings[pos - 1])
						nums[pos] = max(nums[pos + 1], nums[pos - 1]) + 1;
					else
						nums[pos] = nums[pos + 1] + 1;
				}
			}
			i++;
		}
		int sum = 0;
		//��󷵻�numsԪ��֮��
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
};
class Solution2 {
public:
	vector<int> nums;
	int candy(vector<int>& ratings) {
		//����˼�룺�ݹ飬��ʱ
		if (ratings.size() <= 1)
			return ratings.size();
		for (int i = 0; i < ratings.size(); i++)
			nums.push_back(0);
		for (int i = 0; i < ratings.size(); i++)
		{
			if (nums[i] == 0)
				dfs(ratings, i);
		}
		int sum = 0;
		for_each(nums.begin(), nums.end(), [&sum](const int& v) {sum += v; });
		return sum;
	}
	int dfs(vector<int>& ratings, int pos)
	{
		//�ұ߽�
		if (pos == ratings.size() - 1)
		{
			nums[pos] = ratings[pos] <= ratings[pos - 1] ? 1 : dfs(ratings, pos - 1) + 1;
			return nums[pos];
		}
		//��߽�
		if (pos == 0)
		{
			nums[pos] = ratings[pos] <= ratings[pos + 1] ? 1 : dfs(ratings, pos + 1) + 1;
			return nums[pos];
		}
		//ͬʱС������ֵ
		if (ratings[pos] <= ratings[pos + 1] && ratings[pos] <= ratings[pos - 1])
		{
			nums[pos] = 1;
			return  nums[pos];
		}
		//ͬʱ��������ֵ
		if (ratings[pos] > ratings[pos + 1] && ratings[pos] > ratings[pos - 1])
		{
			nums[pos] = max(dfs(ratings, pos + 1), dfs(ratings, pos - 1)) + 1;
			return nums[pos];
		}
		//С��һ��ֵ����һ��ֵ
		nums[pos] = ratings[pos] > ratings[pos + 1] ? dfs(ratings, pos + 1) + 1 : dfs(ratings, pos - 1) + 1;
		return nums[pos];
	}
};
int main()
{
	Solution solute;
	vector<int> ratings = { 1,2,2 };
	cout << solute.candy(ratings) << endl;
	return 0;
}
