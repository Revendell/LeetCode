#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		//建立两个HashMap，words一个HashMap1，对字符串s窗口大小为word_len*words_len的字串一个HashMap2，如果两个HashMap相等则匹配成功记录起始下标
		map<string, int> HashMap1, HashMap2;
		//特殊情况考虑
		if (words.size() == 0 || s == "")
			return res;
		//words_len为words中单词个数，word_len为每个单词字母个数
		int words_len, word_len, i, j, k, flag;
		words_len = words.size();
		word_len = words[0].length();
		//计算得到words的HashMap1，建立单词string与出现次数int的HashMap
		for (i = 0; i < words_len; i++)
		{
			if (HashMap1.find(words[i]) != HashMap1.end())
				HashMap1[words[i]]++;
			else
				HashMap1[words[i]] = 1;
		}
		i = 0;
		//以窗口大小为words_len*word_len从0到s.length()-words_len*word_len在字符串s中滑动窗口
		while (i + word_len * words_len <= s.length())
		{
			HashMap2 = HashMap1;
			j = 0;
			//对每个窗口进行单词匹配，如果匹配成功HashMap2[words[k]]--，如果最后HashMap2中的单词对应次数都为0，则匹配成功记录起始下标i
			while (j < words_len * word_len)
			{
				flag = 0;
				//对words中每个单词匹配一次，匹配成功HashMap2[words[k]]--，字符串s的下标j向前移动word_len，如果没有匹配成功flag=0，break循环，此窗口不匹配进入下一个窗口
				for (k = 0; k < words_len; k++)
				{
					if (s.substr(i + j, word_len) == words[k])
					{
						HashMap2[words[k]]--;
						j = j + word_len;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					break;
			}
			flag = 1;
			//如果最后HashMap2中的每个单词对应次数都为0，则匹配成功记录起始下标i
			for (k = 0; k < words_len; k++)
			{
				if (HashMap2[words[k]] != 0)
					flag = 0;
			}
			if (flag == 1)
				res.push_back(i);
			//此窗口结束，向前移动1进入下一个窗口
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	string s = "w";
	vector<string> words = { "w", "w" };
	vector<int> res;
	res = solute.findSubstring(s, words);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}