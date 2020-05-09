#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isPalindrome(string s) {
		//����˼�룺�ݹ飬�����±���ָ�ַ���תΪСд�ַ��Ƚ��Ƿ���ȣ��������ȷ���false������left++right--�����Ƚ���һ���ַ�
		return Recursion(s, 0, s.size() - 1);
	}
	bool Recursion(string& s, int left, int right)
	{
		//�ݹ���ֹ����
		if (left == right || left > right)
			return true;
		if (!isalnum(s[left]))
			return Recursion(s, left + 1, right);
		if (!isalnum(s[right]))
			return Recursion(s, left, right - 1);
		if (tolower(s[left]) != tolower(s[right]))
			return false;
		else
			return Recursion(s, left + 1, right - 1);
	}
};
class Solution1 {
public:
	bool isPalindrome(string s) {
		//����˼�룺�����������±���ָ�ַ���תΪСд�ַ��Ƚ��Ƿ���ȣ��������ȷ���false������left++right--�����Ƚ���һ���ַ�
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			if (!isalnum(s[left]))
			{
				left++;
				continue;
			}
			if (!isalnum(s[right]))
			{
				right--;
				continue;
			}
			if (tolower(s[left]) != tolower(s[right]))
				return false;
			left++;
			right--;
		}
		return true;
	}
};
int main()
{
	Solution solute;
	string s = "A man, a plan, a canal: Panama";
	cout << solute.isPalindrome(s) << endl;
	return 0;
}