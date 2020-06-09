#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		//基本思想：字典树（前缀树）的设计与实现，建议多看看高级数据结构源码实现
		//给每一个字符建立一个Trie结构，当前字符的后继字符可能是任意26个字母所以有26个孩子
		//如果截止当前字符构成插入的字符串，置当前字符节点的isWord为true
		//Trie 树是一个有根的树，其结点具有以下字段：
		//最多R个指向子结点的链接，其中每个链接对应字母表数据集中的一个字母。本题R为26
		//布尔字段，以指定节点是对应键的结尾还是只是键前缀。
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
		isWord = false;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* t = this;
		for (auto c : word)
		{
			if (t->child[c - 'a'] == nullptr)
				t->child[c - 'a'] = new Trie();
			t = t->child[c - 'a'];
		}
		t->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* t = this;
		for (auto c : word)
		{
			if (t->child[c - 'a'] == nullptr)
				return false;
			t = t->child[c - 'a'];
		}
		return t->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* t = this;
		for (auto c : prefix)
		{
			if (t->child[c - 'a'] == nullptr)
				return false;
			t = t->child[c - 'a'];
		}
		return true;
	}
private:
	Trie* child[26];
	bool isWord;
};
class Trie1 {
public:
	/** Initialize your data structure here. */
	Trie1() {
		//基本思想：HashMap+哈希表，用HashMap保存所有的前缀映射，比如apple：a->ap ap->app app->appl appl->apple
		//dict保存所有插入的字符串，使用HashMap和dict查找是否存在前缀prefix，插入一个字符串，建立相应的前缀映射
		//从后往前映射appl->apple到a->ap，这样对于相同前缀的appll字符插入时只需要插入appl->appll，效率提升
		//但是这种方法最终效率还是很低，因为随着哈希表大小增加，会出现大量的冲突
		//Trie 树优于哈希表的理由是，随着哈希表大小增加，会出现大量的冲突，时间复杂度可能增加到O(n)，其中n 是插入的键的数量。
		//与哈希表相比，Trie树在存储多个具有相同前缀的键时可以使用较少的空间。此时Trie树只需要O(m) 的时间复杂度，其中m为键长。
	}
	/** Inserts a word into the trie. */
	void insert(string word) {
		if (dict.find(word) != dict.end())
			return;
		dict.insert(word);
		string pre, cur = word;
		for (int i = word.size() - 1; i >= 1; i--)
		{
			pre = word.substr(0, i);
			if (HashMap.find(pre) == HashMap.end() || HashMap.find(cur) == HashMap.end())
				HashMap.insert({ pre,cur });
			else
				return;
			cur = pre;
		}
		pre = "*";
		HashMap.insert({ pre,cur });
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		if (dict.find(word) != dict.end())
			return true;
		else
			return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		if (dict.find(prefix) != dict.end())
			return true;
		if (HashMap.find(prefix) != HashMap.end())
			return true;
		return false;
	}
private:
	multimap<string, string> HashMap;
	unordered_set<string> dict;
};
int main()
{
	Trie trie;
	trie.insert("apple");
	cout << trie.search("apple") << endl;   // 返回 true
	cout << trie.search("app") << endl;     // 返回 false
	cout << trie.startsWith("app") << endl; // 返回 true
	trie.insert("app");
	cout << trie.search("app") << endl;     // 返回 true
	return 0;
}