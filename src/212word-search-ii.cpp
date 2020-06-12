#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
struct Trie
{
	Trie* child[26];
	string word = "";
	Trie() {
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
	}
};
class Solution {
public:
	vector<string> res;
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		//基本思想：前缀树+深度优先搜索递归回溯
		//1、前缀树的结构是R个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母，
		//和一个字符串字段当截止该节点构成一个单词就将该节点的字符串字段置为该单词，
		//这样如果截止该节点字符串字段不为空说明遍历截止该节点构成一个单词可以直接加入res。之前的做法是给dfs额外一个string形参保存当前dfs遍历过的字符，减慢函数调用速度
		//2、遍历到当前节点构成一个单词加入res后，置该节点字符串字段为空，这样防止res出现重复单词。之前的做法是设置res为set，不如这个方法好，这个方法可以避免遍历board中重复单词。
		//3、对于board中一次dfs已访问过的字符不能再次访问解决方法：置已访问过的board中字符为'*'，dfs结束后再恢复。之前做法是设置visited二维数组，这样增加了dfs形参个数占用更多内存。
		//4、注意截止当前节点已经构成一个单词后，可以继续dfs搜索其他单词，因为可能出现一个单词是另一个单词的前缀情况，不能提前结束dfs。
		Trie* t = new Trie();
		//创建前缀树，将words中所有单词加入前缀树
		for (int i = 0; i < words.size(); i++)
		{
			Trie* cur = t;
			for (int j = 0; j < words[i].size(); j++)
			{
				if (cur->child[words[i][j] - 'a'] == nullptr)
					cur->child[words[i][j] - 'a'] = new Trie();
				cur = cur->child[words[i][j] - 'a'];
			}
			cur->word = words[i];
		}
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[i].size(); j++)
			{
				dfs(board, t, i, j);	
			}
		}
		return res;
	}
	void dfs(vector<vector<char>>& board, Trie* t,int i ,int j)
	{
		if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
			return;
		char c = board[i][j];
		if (c == '*' || t->child[c-'a']==nullptr)
			return;
		t = t->child[c - 'a'];
		if (t->word != "")
		{
			res.push_back(t->word);
			t->word = "";
		}
		board[i][j] = '*';
		dfs(board, t, i + 1, j);
		dfs(board, t, i - 1, j);
		dfs(board, t, i, j + 1);
		dfs(board, t, i, j - 1);
		board[i][j] = c;
		return;	
	}
};
int main()
{
	Solution solute;
	vector<vector<char>> board = { {'a','b'},{'a','a'} };
	vector<string> words = { "aaab","aaa" };
	vector<string> res = solute.findWords(board, words);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}