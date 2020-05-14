#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		//����˼�룺HashMap��ʱ�临�Ӷ�O(n+n)����������ʱ�临�Ӷ��ϸ�Ҫ��ģ���һʱ���뵽�ռ任ʱ��
		int length, res = 0;
		//HashMap��key��nums�е�ֵvalue��bool���Ƿ���ʹ�
		unordered_map<int, bool> dict;
		for (auto& v : nums)
			dict.insert({ v,false });
		auto i = dict.begin();
		while (i != dict.end())
		{
			if (i->second == true)
			{
				i++;
				continue;
			}
			int v = i->first;
			length = 0;
			while (dict.find(v) != dict.end())
			{
				dict[v] = true;
				v++;
				length++;
				res = max(res, length);
			}
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = {  };
	cout << solute.longestConsecutive(nums) << endl;
	return 0;
}