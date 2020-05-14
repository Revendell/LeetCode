#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std;
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//基本思想：BFS
		unordered_map<string, int> mindepth;    //mindepth用于记录当前单词cur最先出现的层数
		unordered_set<string> dict(wordList.begin(), wordList.end()); //空间换时间，用于查找cur相邻的单词
		list<string> queue;    //queue用于层次遍历
		int flag = 0;    //标记是否已经遇到endWord
		queue.push_front(beginWord);
		int depth = 0;    //层次遍历的深度
		while (!queue.empty())
		{
			depth++;
			int len = queue.size();
			//先把该层的所有单词记录深度，这时mindepth记录的才是单词最先出现的层数
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//遍历当前层所有单词，记录每个单词相邻的在之前层没有出现过所有单词入队列queue
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				if (cur == endWord)
					flag = 1;
				string temp = cur;
				//查找当前单词cur的下一个转换的单词：和cur只相差一个字母
				for (int j = 0; j < cur.size(); j++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[j] == c)
							continue;
						char oldc = cur[j];
						cur[j] = c;
						//在考虑第 k 层的某一个单词，如果这个单词在第 1 到 k-1 层已经出现过，我们其实就不用继续向下探索了
						if (dict.find(cur) != dict.end() && mindepth.find(cur) == mindepth.end())
						{
							queue.push_front(cur);
						}
						cur[j] = oldc;
					}
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			return depth;
		else
			return 0;
	}
};
class Solution1 {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//基本思想：双向BFS，两个队列queue1、queue2分别从beginWord和endWord出发查找相邻的单词(这些单词在之前层没有出现过)，直到两个队列中遇到相同的单词
		//至于每次从哪个方向扩展，我们可以每次选择需要扩展的节点数少的方向进行扩展
		unordered_map<string, int> mindepth1;    //mindepth用于记录beginWord往下相邻单词最先出现的层数
		unordered_map<string, int> mindepth2;    //mindepth用于记录endWord往上相邻单词最先出现的层数
		unordered_set<string> dict(wordList.begin(), wordList.end()); //空间换时间，用于查找cur相邻的单词
		if (dict.find(endWord) == dict.end())
			return 0;
		list<string> queue1;    //queue1用于beginWord往下层次遍历
		list<string> queue2;    //queue2用于endWord往上层次遍历
		int flag = 0;    //标记两个队列是否遇到相同的单词
		queue1.push_front(beginWord);
		queue2.push_front(endWord);
		int depth1 = 0;    //beginWord往下层次遍历的深度
		int depth2 = 0;    //endWord往上层次遍历的深度
		while (!queue1.empty() && !queue2.empty())
		{
			int len1 = queue1.size();
			int len2 = queue2.size();
			int len;
			list<string> queue;
			int depth;
			unordered_map<string, int> mindepth;
			if (len1 <= len2)
			{
				depth1++;
				queue = queue1;
				mindepth = mindepth1;
				len = len1;
				depth = depth1;
			}
			else
			{
				depth2++;
				queue = queue2;
				mindepth = mindepth2;
				len = len2;
				depth = depth2;
			}
			//先把该层的所有单词记录深度，这时mindepth记录的才是单词最先出现的层数
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//遍历当前层所有单词，记录每个单词相邻的在之前层没有出现过所有单词入队列queue
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				string temp = cur;
				//查找当前单词cur的下一个转换的单词：和cur只相差一个字母
				for (int j = 0; j < cur.size(); j++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[j] == c)
							continue;
						char oldc = cur[j];
						cur[j] = c;
						//在考虑第 k 层的某一个单词，如果这个单词在第 1 到 k-1 层已经出现过，我们其实就不用继续向下探索了
						if (dict.find(cur) != dict.end() && mindepth.find(cur) == mindepth.end())
						{
							queue.push_front(cur);
						}
						cur[j] = oldc;
					}
				}
			}
			if (len1 <= len2)
			{
				queue1 = queue;
				mindepth1 = mindepth;
			}
			else
			{
				queue2 = queue;
				mindepth2 = mindepth;
			}
			//直到两个队列中遇到相同的单词flag=1跳出循环
			for (auto i = queue1.begin(); i != queue1.end() && flag==0; i++)
			{
				for (auto j = queue2.begin(); j != queue2.end() && flag==0; j++)
				{
					if (*i == *j)
						flag = 1;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			return depth1 + depth2 + 1;
		else
			return 0;
	}
};
int main()
{
	Solution1 solute;
	string beginWord = "hog";
	string endWord = "cog";
	vector<string> wordList = { "cog" };
	cout << solute.ladderLength(beginWord, endWord, wordList) << endl;
	return 0;
}