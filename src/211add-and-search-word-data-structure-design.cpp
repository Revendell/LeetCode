#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		//基本思想：前缀树+深度优先搜索
		//给每一个字符建立一个Trie结构，当前字符的后继字符可能是任意26个字母所以有26个孩子
		//如果截止当前字符构成插入的字符串，置当前字符节点的isWord为true。
		//对于'.'的处理，使用深度优先搜索，遍历当前节点所有非空孩子是否最后能匹配上，如果都匹配不上返回false
		//Trie 树是一个有根的树，其结点具有以下字段：
		//最多R个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母。本题R为26
		//布尔字段，以指定节点是对应键的结尾还是只是键前缀。
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
		isWord = false;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		WordDictionary* t = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (t->child[word[i]-'a'] == nullptr)
				t->child[word[i] - 'a'] = new WordDictionary();
			t = t->child[word[i] - 'a'];
		}
		t->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		WordDictionary* t = this;
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == '.')
			{
				for (int j = 0; j < 26; j++)
				{
					if (t->child[j] != nullptr)
					{
						if (t->child[j]->search(word.substr(i + 1, word.size() - i - 1)) == true)
							return true;
					}
				}
				return false;
			}
			else
			{
				if (t->child[word[i] - 'a'] == nullptr)
					return false;
				t = t->child[word[i] - 'a'];
			}
		}
		return t->isWord;
	}
private:
	WordDictionary* child[26];
	bool isWord;
};
int main()
{
	WordDictionary* obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("dad");
	obj->addWord("mad");
	cout << obj->search("a.") << endl;// -> false
	cout << obj->search("pad") << endl;// -> false
	cout << obj->search("bad") << endl;// -> true
	cout << obj->search(".ad") << endl;// -> true
	cout << obj->search("b..") << endl;// -> true
	return 0;
}