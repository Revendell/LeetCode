#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int length = 0;  //��󴰿ڳ���
		int l = 0, r = -1;  //��Ϊs[r + 1]��Ϊ��ǰ�������ַ���r+1��Χ��0��s.size()-1�������ұ߽�r��ʼ��-1���Ϊs.size()-2����߽��ʼ��0
		int freq[256] = { 0 };    //�����ַ��������λ��֮���ӳ�䣬�ַ���a��z��Ӧ��ASCLL��97��122������һ�����1����֤�������ַ�ֻ���ֹ�һ�Σ�ӳ��ֵ��Ϊ0
		while (l < s.size())
		{
			//�����������һ���ַ�s[r + 1]�ڴ�����û�г��ֹ��������󴰿ڵ��ұ߽�r++����Ϊ��Ҫ�жϴ�������һ���ַ��Ƿ���ֹ�������r + 1 < s.size()������߽����
			if (r + 1 < s.size() && freq[s[r + 1]] == 0)
			{
				r++;
				freq[s[r]]++;
			}
			//�����������һ���ַ�s[r + 1]�ڴ����ڳ��ֹ�������С���ڵ��ұ߽�l++
			else {
				freq[s[l]]--;
				l++;

			}
			//�����ǰ���ڳ��ȴ�����󴰿ڳ��ȣ�������󴰿ڳ���
			if (r-l+1 > length)
				length = r-l+1;
		}
		return length;
	}
};
int main()
{
	Solution solute;
	string s = "abcabcbb";
	cout<<solute.lengthOfLongestSubstring(s);
	return 0;
}