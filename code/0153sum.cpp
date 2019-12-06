#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i, j, k;
		int len = nums.size();
		vector<vector<int>> res;
		if (len < 3)  //�������Ԫ��С��3������""
			return res;
		sort(nums.begin(), nums.end());  //��nums����Ԫ������
		//����˫ָ�뷨�������������֮�ͣ��ȶ�nums��������Ȼ���nums��ÿ��Ԫ����������֮��ԭ��
		//��nums��ÿ��Ԫ��nums[k]���ۺ����Ƿ����������֮�͵���nums[k]���෴����������ָ��i��j��iָ��k���һ��Ԫ�أ�jָ��k�����һ��Ԫ�أ�Ȼ��ͨ��i++��j--���ϱƽ�֮�͵���nums[k]
		for (k = 0; k < len - 2; k++)
		{
			if (nums[k] > 0)  //���nums[k]>0����ônums[i]��nums[j]Ҳ����0�������ܺ�=0
				break;
			//��ֹ�����ظ��ĵ�һ������������nums[i]+nums[j]=-nums[k]��nums[k]����Ԫ�ؿ�����ͬ����
			if (k > 0 && nums[k] == nums[k - 1])
				continue;
			i = k + 1;  //i=k+1ָ��k���һ��Ԫ��
			j = len - 1;  //j=len-1ָ��k�����һ��Ԫ��
			while (i < j)
			{
				if (nums[i] + nums[j] > -nums[k])
					j--;
				else if (nums[i] + nums[j] < -nums[k])
					i++;
				else
				{
					res.push_back({ nums[k],nums[i],nums[j] });
					//��ֹ�����ظ��ĵڶ�������������nums[i]+nums[j]=-nums[k]��nums[i]��nums[j]������nums[i+1]��nums[j-1]����Ԫ�ؿ�����ͬ����
					while (i < j && nums[i] == nums[i + 1])
						i++;
					while (i < j && nums[j] == nums[j - 1])
						j--;
					i++;
					j--;
				}
			}
		}
		return res;
	}
};
//�ⷨ����Ҫ���õ�STL����erase��unique����ȥ�ظ��������һ�㣬��ʱ�������Լ��ڴ����ıȽϴ�
class Solution2 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i, j, k;
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0 || len < 3)
			return res;
		sort(nums.begin(), nums.end());
		if (nums[0] == 0 && nums[len - 1] == 0)  //��Ϊ����STL�⺯���ᵼ��ȫ0����Run time error
			return { {0,0,0} };
		for (k = 0; k < len - 2; k++)
		{
			if (nums[k] > 0)
				break;
			i = k + 1;
			j = len - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] > -nums[k])
					j--;
				else if (nums[i] + nums[j] < -nums[k])
					i++;
				else
				{
					res.push_back({ nums[k],nums[i],nums[j] });
					i++;
					j--;
				}
			}
		}
		//����res����п������ظ�����Ԫ�飬��STL����erase��unique����ȥ�ظ�
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};
int main()
{
	Solution1 solute1;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> res;
	res = solute1.threeSum(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 3; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
