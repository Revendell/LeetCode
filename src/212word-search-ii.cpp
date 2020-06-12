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
		//����˼�룺ǰ׺��+������������ݹ����
		//1��ǰ׺���Ľṹ��R��ָ���ӽ������ӣ�����ÿ�����Ӷ�Ӧ��ĸ�����ݼ��е�һ����ĸ��
		//��һ���ַ����ֶε���ֹ�ýڵ㹹��һ�����ʾͽ��ýڵ���ַ����ֶ���Ϊ�õ��ʣ�
		//���������ֹ�ýڵ��ַ����ֶβ�Ϊ��˵��������ֹ�ýڵ㹹��һ�����ʿ���ֱ�Ӽ���res��֮ǰ�������Ǹ�dfs����һ��string�βα��浱ǰdfs���������ַ����������������ٶ�
		//2����������ǰ�ڵ㹹��һ�����ʼ���res���øýڵ��ַ����ֶ�Ϊ�գ�������ֹres�����ظ����ʡ�֮ǰ������������resΪset��������������ã�����������Ա������board���ظ����ʡ�
		//3������board��һ��dfs�ѷ��ʹ����ַ������ٴη��ʽ�����������ѷ��ʹ���board���ַ�Ϊ'*'��dfs�������ٻָ���֮ǰ����������visited��ά���飬����������dfs�βθ���ռ�ø����ڴ档
		//4��ע���ֹ��ǰ�ڵ��Ѿ�����һ�����ʺ󣬿��Լ���dfs�����������ʣ���Ϊ���ܳ���һ����������һ�����ʵ�ǰ׺�����������ǰ����dfs��
		Trie* t = new Trie();
		//����ǰ׺������words�����е��ʼ���ǰ׺��
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