#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		//基本思想：HashMap+滑动窗口，HashMap统计t中出现的字符次数，匹配s中的滑动窗口[left,right]中在t中的字符
		//在滑动窗口中存在t中出现的字符--HashMap[s[i]]，只要某个字符次数在HashMap中等于0，cnt++，直至HashMap中字符次数都小于等于0
		//则cnt=HashMap.size，说明t中字符次数都在滑动窗口出现，记录此窗口位置与大小
		//滑动窗口左边界left不断++，直至HashMap中在t中出现的字符次数大于0，cnt--，跳出循环，继续滑动窗口右边界right不断++
		int pos = 0, len, i, left, right, cnt = 0, flag = 0;
		len = s.size();
		if (len == 0 || s.size() < t.size())
			return "";
		map<char, int> HashMap;
		//HashMap统计t中出现的字符次数
		for (auto c : t)
			++HashMap[c];
		left = 0;
		//在s中滑动窗口[left,right]，滑动窗口右边界right++
		for (i = 0; i < s.size(); i++)
		{
			if (HashMap.find(s[i]) != HashMap.end())
			{
				//匹配s中的滑动窗口[left,right]中在t中的字符，在滑动窗口中存在t中出现的字符--HashMap[s[i]]
				--HashMap[s[i]];
				//只要某个字符次数在HashMap中等于0，cnt++，直至HashMap中字符次数都小于等于0
				if (HashMap[s[i]] == 0)
					++cnt;
				right = i;
				//HashMap中字符次数都小于等于0，则cnt=HashMap.size，说明t中字符次数都在滑动窗口出现，记录此窗口位置与大小
				while (cnt == HashMap.size())
				{
					if (right - left + 1 <= len)
					{
						len = right - left + 1;
						pos = left;
						flag=1;
					}
					//滑动窗口左边界left不断++，直至HashMap中在t中出现的字符次数大于0，cnt--，跳出循环
					if (HashMap.find(s[left]) != HashMap.end())
					{
						++HashMap[s[left]];
						if (HashMap[s[left]] > 0)	
							--cnt;
					}
					left++;
				}
			}
		}
		//flag用于标记s中是否存在t中所有的字符，因为如果不存在，默认pos=0，len=s.size，最后返回的是s
		if (flag == 0)
			return "";
		return s.substr(pos, len);
	}
};
int main()
{
	Solution solute;
	string s ="cabwefgewcwaefgcf";
	string t = "cae";
	cout << solute.minWindow(s, t) << endl;
	return 0;
}