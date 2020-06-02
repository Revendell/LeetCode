#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		//����˼�룺���򣬽��Ƚ�nums������תΪ�ַ������浽ans��Ȼ���ans����
		//�����㷨�ǽ������ַ�������ƴ�Ӻ�Ƚϴ�С������������Ŀ��Ҫ��ķ������ƴ�ӵ��ַ���
		string res;
		vector<string> ans;
		for (auto num : nums)
			ans.push_back(to_string(num));
		sort(ans.begin(), ans.end(), [](const string& a, const string& b) {return a + b > b + a; });
		for (int i = 0; i < ans.size(); i++)
			res.append(ans[i]);
		if (res[0] == '0')
			return "0";
		return res;
	}
};
class Solution1 {
public:
	string largestNumber(vector<int>& nums) {
		//����˼�룺�������ö�ά����vec����nums��ÿ�����ֵ�ÿһλ
		//Ȼ������������3,31,34��˳����34,3,31���Ƚ�ÿһλ�������vec[i][k]<vec[j][k]ֱ�ӽ���
		//���vec[i][k]==vec[j][k]�����ʱ�����vec[i]�����һλ�����ˣ��ǾͱȽ�vec[j]��ǰλ���ֺ�vec[i]��һλ���ֵĴ�С���С�ڽ���
		//���vec[i][0]==vec[j][k+1]��k+1��vec[j]���һλ���֣�����830,8308��898,89��������vec[i][temp]>vec[i][temp + 1]����
		string res;
		vector<vector<int>> vec;
		for (auto num : nums)
		{
			vector<int> cur;
			while (num / 10 != 0)
			{
				cur.push_back(num % 10);
				num = num / 10;
			}
			cur.push_back(num);
			reverse(cur.begin(), cur.end());
			vec.push_back(cur);
		}
		for (int i = 0; i < vec.size() - 1; i++)
		{
			for (int j = i + 1; j < vec.size(); j++)
			{
				int k = 0;
				while (k < vec[i].size() && k < vec[j].size())
				{
					if (vec[i][k] < vec[j][k])
					{
						swap(vec[i], vec[j]);
						break;
					}
					else if (vec[i][k] > vec[j][k])
					{
						break;
					}
					else
					{
						if (k == vec[i].size() - 1 && k < vec[j].size() - 1)
						{
							while (k < vec[j].size() - 1)
							{
								if (vec[i][0] < vec[j][k + 1])
								{
									swap(vec[i], vec[j]);
									break;
								}
								else if (vec[i][0] == vec[j][k + 1])
								{
									if (k + 1 == vec[j].size() - 1)
									{
										int temp = 0;
										while (temp < vec[i].size() - 1)
										{
											if (vec[i][temp] > vec[i][temp + 1])
											{
												swap(vec[i], vec[j]);
												break;
											}
											else if (vec[i][temp] < vec[i][temp + 1])
												break;
											else
												temp++;
										}
									}
									k++;
								}	
								else
									break;
							}
							break;
						}
						else if (k == vec[j].size() - 1 && k < vec[i].size() - 1)
						{
							while (k < vec[i].size() - 1)
							{
								if (vec[j][0] > vec[i][k + 1])
								{
									swap(vec[i], vec[j]);
									break;
								}
								else if (vec[j][0] == vec[i][k + 1])
								{
									if (k + 1 == vec[i].size()-1)
									{
										int temp = 0;
										while (temp < vec[j].size() - 1)
										{
											if (vec[j][temp] < vec[j][temp + 1])
											{
												swap(vec[i], vec[j]);
												break;
											}
											else if (vec[j][temp] > vec[j][temp + 1])
												break;
											else
												temp++;
										}
									}	
									k++;
								}	
								else
									break;
							}
							break;
						}
					}
					k++;
				}
			}
		}
		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
				res.push_back('0' + vec[i][j]);
		}
		if (res[0] == '0')
			return "0";
		else
		    return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 824,8248 };
	cout << solute.largestNumber(nums) << endl;
	return 0;
}