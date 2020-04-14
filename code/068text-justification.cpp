#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		//基本思想：贪心法，这是一道像公司的业务逻辑且麻烦又没有太大练习价值的题
		vector<string> res;
		//words_len记录当前行cur中所有单词长度，space_len记录maxWidth中除去单词长度后剩下的空格长度
		//q和r用来表示每两个单词间需要填充的空格数，cnt表示cur中所有单词的长度且每个单词至少空一格
		int i, words_len, space_len, cnt, k, q, r;
		i = 0;
		//cur表示在当前maxWidth长度里保存的最大单词数
		vector<string> cur;
		cnt = 0;
		//遍历words里面每个单词
		while (i < words.size())
		{
			//如果当前cur中所有单词长度加上当前words[i]长度cnt小于等于maxWidth，单词i加入cur中
			if (cnt + words[i].size() <= maxWidth)
			{
				cnt += words[i].size();
				//每个单词间至少空一个
				cnt++;
				cur.push_back(words[i]);
				//特殊情况：如果words[i]是words里最后一个单词，那么尽管cnt小于maxWidth，也要将cur中单词保存至res
				if (i == words.size() - 1)
				{
					string str;
					for (k = 0; k < cur.size() - 1; k++)
					{
						str += cur[k];
						str.append(" ");
					}
					str += cur[cur.size() - 1];
					//不满maxWidth的全部填空格
					str.append(maxWidth - str.size(), ' ');
					res.push_back(str);
				}
			}
			//如果当前cur中所有单词长度加上当前words[i]长度cnt大于maxWidth，cur中单词已满，要保存至res
			else
			{
				//计算cur中所有单词长度words_len
				words_len = 0;
				for (k = 0; k < cur.size(); k++)
				{
					words_len += cur[k].size();
				}
				//计算需要填充的空格数space_len
				space_len = maxWidth - words_len;
				string str;
				//特殊情况：cur中只有一个单词
				if (cur.size() == 1)
				{
					str += cur[0];
					//不满maxWidth的全部填空格
					str.append(maxWidth - str.size(), ' ');
					res.push_back(str);
					cur.clear();
					cnt = 0;
					continue;
				}
				//cur中有多个单词，计算每两个单词间填充的空格数q，以及前r个单词间多填充1个空格，使得space_len个空格均匀分配在单词间
				q = space_len / (cur.size() - 1);
				r = space_len % (cur.size() - 1);
				for (k = 0; k < cur.size() - 1; k++)
				{

					str += cur[k];
					str.append(q, ' ');
					if (r)
					{
						str.append(" ");
						r--;
					}
				}
				str.append(cur[cur.size() - 1]);
				res.push_back(str);
				cur.clear();
				cnt = 0;
				continue;
			}
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<string> words = {
		"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"
	};
	int maxWidth = 16;
	vector<string> res = solute.fullJustify(words, maxWidth);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}