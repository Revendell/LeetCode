#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<unordered_set>
using namespace std;
class Solution {
public:
	unordered_map<string, vector<string>> HashMap;    //HashMap用于保存与当前单词cur相邻的所有单词的映射表
	vector<vector<string>> res;    //res保存所有转换单词序列情况
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//基本思想：DFS+剪枝(剪枝方法：BFS、map、set)
		vector<string> ans;    //ans保存某一种转换单词序列情况
		ans.push_back(beginWord);
		bfs(beginWord, endWord, wordList);    //bfs构建HashMap
		dfs(endWord, ans, wordList);    //dfs查找所有转换单词序列情况
		return res;
	}
	void bfs(string beginWord, string endWord, vector<string>& wordList)
	{
		int depth = 0, flag = 0;
		list<string> queue;    //queue用于层次遍历
		unordered_map<string, int> mindepth;    //mindepth用于记录当前单词cur最先出现的层数
		unordered_set<string> dict(wordList.begin(), wordList.end());    //空间换时间，用于查找cur相邻的单词
		queue.push_front(beginWord);
		//层次遍历，构建HashMap用于保存与当前单词cur相邻的所有单词的映射表
		while (!queue.empty())
		{
			int len = queue.size();
			depth++;
			//先把该层的所有单词记录深度，这时mindepth记录的才是单词最先出现的层数
			for (auto i=queue.begin();i!=queue.end();i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//遍历当前层所有单词，记录每个单词相邻的在之前层没有出现过所有单词
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				if (HashMap.find(cur) == HashMap.end())
				{
					//查找当前单词cur的下一个转换的单词：和cur只相差一个字母
					for (int j = 0; j < cur.size(); j++)
					{
						for (char c = 'a'; c <= 'z'; c++)
						{
							string temp = cur;
							if(cur[j]==c)
								continue;
							char oldc = cur[j];
							cur[j] = c;
							if (dict.find(cur) != dict.end())
							{
								//考虑第k层的某一个单词，如果这个单词在第1到k-1层已经出现过，就不用继续向下探索
								if (mindepth.find(cur) == mindepth.end())
								{
									HashMap[temp].push_back(cur);
									queue.push_front(cur);
								}
							}
							cur[j] = oldc;
						}
					}
				}
			}
		}
	}
	void dfs(string endWord, vector<string> ans, vector<string>& wordList)
	{
		string cur = ans[ans.size() - 1];
		//递归终止条件：当前单词cur就是目标单词
		if (cur == endWord)
		{
			res.push_back(ans);
			return;
		}
		//当前单词为cur，利用HashMap映射表查找下一个转换的单词
		for (auto v : HashMap[cur])
		{
			ans.push_back(v);
			dfs(endWord, ans, wordList);
			ans.pop_back();
		}
		return;
	}
};
class Solution1 {
public:
	unordered_map<string, vector<string>> HashMap;    //HashMap用于保存与当前单词cur相邻的所有单词的映射表
	vector<vector<string>> res;    //res保存所有转换单词序列情况
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//基本思想：BFS
		bfs(beginWord, endWord, wordList);
		return res;
	}
	void bfs(string beginWord, string endWord, vector<string>& wordList)
	{
		int depth = 0, flag = 0;
		list<vector<string>> queue;    //queue用于层次遍历
		vector<string> ans;    //ans保存某一种转换单词序列情况
		ans.push_back(beginWord);
		unordered_map<string, int> mindepth;    //mindepth用于记录当前单词cur最先出现的层数
		unordered_set<string> dict(wordList.begin(), wordList.end());    //空间换时间，用于查找cur相邻的单词
		queue.push_front(ans);
		//层次遍历，构建HashMap用于保存与当前单词cur相邻的所有单词的映射表
		while (!queue.empty())
		{
			int len = queue.size();
			depth++;
			//先把该层的所有单词记录深度，这时mindepth记录的才是单词最先出现的层数
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find((*i).back()) == mindepth.end())
					mindepth[(*i).back()] = depth;
			}
			//遍历当前层所有单词，记录每个单词相邻的在之前层没有出现过所有单词
			for (int i = 0; i < len; i++)
			{
				vector<string> ans = queue.back();
				string cur = ans.back();
				queue.pop_back();
				if (cur == endWord)
				{
					res.push_back(ans);
					flag = 1;
				}
				//查找当前单词cur的下一个转换的单词：和cur只相差一个字母
				for (int j = 0; j < cur.size(); j++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						string temp = cur;
						if (cur[j] == c)
							continue;
						char oldc = cur[j];
						cur[j] = c;
						if (dict.find(cur) != dict.end())
						{
							//考虑第k层的某一个单词，如果这个单词在第1到k-1层已经出现过，就不用继续向下探索
							if (mindepth.find(cur) == mindepth.end())
							{
								HashMap[temp].push_back(cur);
								ans.push_back(cur);
								queue.push_front(ans);
								ans.pop_back();
							}
						}
						cur[j] = oldc;
					}
			    }
			}
			if (flag == 1)
				break;
		}
	}
};
class Solution2 {
public:
	//保存所有转换单词序列情况
	vector<vector<string>> res;
	//最短的转换单词序列的长度
	int minlength=INT_MAX;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//基本思想：单纯递归DFS，超时
		vector<string> ans;    //ans保存某一种转换单词序列情况
		ans.push_back(beginWord);
		Recursion(endWord, ans, wordList);
		return res;
	}
	void Recursion(string endWord, vector<string> ans, vector<string>& wordList)
	{
		//剪枝效果不佳，因为如果终点单词在比较深的层，那么dfs的规模仍然很庞大
		if (ans.size() > minlength)
			return;
		string cur = ans[ans.size() - 1];
		//递归终止条件：当前单词cur就是目标单词
		if (cur == endWord)
		{
			//只保留最短的转换单词序列
			if (res.empty())
			{
				res.push_back(ans);
				minlength = ans.size();
			}
			else
			{
				if (ans.size() < minlength)
				{
					res.clear();
					res.push_back(ans);
					minlength = ans.size();
				}
				else if (ans.size() == minlength)
				{
					res.push_back(ans);
				}
			}
			return;
		}
		//当前单词为cur，查找下一个转换的单词
		for (int i = 0; i < wordList.size(); i++)
		{
			int cnt = 0, flag = 0;
			//下一个转换的单词的要求：1、和当前单词cur只相差一个字母 2、还没在转换单词序列保存器ans中出现过
			//判断下一个转换的单词是否与当前单词cur只相差一个字母
			for (int j = 0; j < cur.size(); j++)
			{
				if (cur[j] == wordList[i][j])
					cnt++;
			}
			if (cnt == cur.size() - 1)
			{
				//判断下一个转换的单词是否已经在ans中出现
				for (auto& s : ans)
				{
					if (s == wordList[i])
					{
						flag = 1;
						break;
					}	
				}
				if(flag==1)
					continue;
				else
				{
					ans.push_back(wordList[i]);
					Recursion(endWord, ans, wordList);
					ans.pop_back();
				}
			}	
		}
		return;
	}
};
int main()
{
	Solution1 solute;
	string beginWord = "red";
	string endWord = "tax";
	vector<string> wordList = { "ted","tex","red","tax","tad","den","rex","pee" };
	vector<vector<string>> res = solute.findLadders(beginWord, endWord, wordList);
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for_each(res[i].begin(), res[i].end(), [](const string& s) {cout << s << " "; });
		cout << endl;
	}
	return 0;
}