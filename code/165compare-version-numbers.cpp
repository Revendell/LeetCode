#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int compareVersion(string version1, string version2) {
		//基本思想：用istrigstream做
		istringstream nums1(version1);
		istringstream nums2(version2);
		char c;
		int v1, v2;
		//while里面判断既不能用&&也不能用||，因为用&&，nums1>>v1成功后已经输出v1了
		while (bool(nums1 >> v1) + bool(nums2 >> v2))
		{
			if (v1 > v2)
				return 1;
			if (v1 < v2)
				return -1;
			v1 = 0;
			v2 = 0;
			nums1 >> c;
			nums2 >> c;
		}
		return 0;
	}
};
class Solution1 {
public:
	int compareVersion(string version1, string version2) {
		//基本思想：双指针，一次遍历，常数空间
		//version1上使用两个指针，以'.'分割跟踪每个数值的开始pos1和结束i，得到数值v1
		//version2上使用两个指针，以'.'分割跟踪每个数值的开始pos2和结束j，得到数值v2
		//分别比较对应v1和v2
		int pos1 = 0, pos2 = 0, i = 0, j = 0, v1, v2, flag1 = 0, flag2 = 0;
		while (i <= version1.size() && j <= version2.size())
		{
			if (i == version1.size() || version1[i] == '.')
				flag1 = 1;	
			else
				i++;
			if (j == version2.size() || version2[j] == '.')
				flag2 = 1;
			else
				j++;
			if (flag1 && flag2)
			{
				v1 = stoi(version1.substr(pos1, i - pos1));
				v2 = stoi(version2.substr(pos2, j - pos2));
				if (v1 > v2)
					return 1;
				if (v1 < v2)
					return -1;
				flag1 = 0;
				flag2 = 0;
				i++;
				j++;
				pos1 = i;
				pos2 = j;
			}
		}
		while (i <= version1.size())
		{
			if (version1[i] != '.' && version1[i] != '0')
				return 1;
			i++;
		}
		while (j <= version2.size())
		{
			if (version2[j] != '.' && version2[j] != '0')
				return -1;
			j++;
		}
		return 0;
	}
};
class Solution2 {
public:
	int compareVersion(string version1, string version2) {
		//基本思想：分割字符串，两次遍历，O(n)空间复杂度
		//将两个字符串分割出数字保存到两个数组，然后依次比较对应元素大小
		vector<int> v1, v2;
		int pos = 0, i;
		for (i = 0; i <= version1.size(); i++)
		{
			if (i == version1.size() || version1[i] == '.')
			{
				v1.push_back(stoi(version1.substr(pos, i - pos)));
				pos = i + 1;
			}
		}
		pos = 0;
		for (i = 0; i <= version2.size(); i++)
		{
			if (i == version2.size() || version2[i] == '.')
			{
				v2.push_back(stoi(version2.substr(pos, i - pos)));
				pos = i + 1;
			}
		}
		for (i = 0; i < v1.size() && i < v2.size(); i++)
		{
			if (v1[i] > v2[i])
				return 1;
			if (v1[i] < v2[i])
				return -1;
		}
		while (i < v1.size())
		{
			if (v1[i] != 0)
				return 1;
			i++;
		}
		while (i < v2.size())
		{
			if (v2[i] != 0)
				return -1;
			i++;
		}
		return 0;
	}
};

int main()
{
	Solution solute;
	string version1 = "7.5.2.4", version2 = "7.5";
	cout << solute.compareVersion(version1, version2) << endl;
	return 0;
}