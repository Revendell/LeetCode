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
		//����˼�룺�ֵ�����ǰ׺�����������ʵ�֣�����࿴���߼����ݽṹԴ��ʵ��
		//��ÿһ���ַ�����һ��Trie�ṹ����ǰ�ַ��ĺ���ַ�����������26����ĸ������26������
		//�����ֹ��ǰ�ַ����ɲ�����ַ������õ�ǰ�ַ��ڵ��isWordΪtrue
		//Trie ����һ���и�������������������ֶΣ�
		//���R��ָ���ӽ������ӣ�����ÿ�����Ӷ�Ӧ��ĸ�����ݼ��е�һ����ĸ������RΪ26
		//�����ֶΣ���ָ���ڵ��Ƕ�Ӧ���Ľ�β����ֻ�Ǽ�ǰ׺��
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
		//����˼�룺HashMap+��ϣ����HashMap�������е�ǰ׺ӳ�䣬����apple��a->ap ap->app app->appl appl->apple
		//dict�������в�����ַ�����ʹ��HashMap��dict�����Ƿ����ǰ׺prefix������һ���ַ�����������Ӧ��ǰ׺ӳ��
		//�Ӻ���ǰӳ��appl->apple��a->ap������������ͬǰ׺��appll�ַ�����ʱֻ��Ҫ����appl->appll��Ч������
		//�������ַ�������Ч�ʻ��Ǻܵͣ���Ϊ���Ź�ϣ���С���ӣ�����ִ����ĳ�ͻ
		//Trie �����ڹ�ϣ��������ǣ����Ź�ϣ���С���ӣ�����ִ����ĳ�ͻ��ʱ�临�Ӷȿ������ӵ�O(n)������n �ǲ���ļ���������
		//���ϣ����ȣ�Trie���ڴ洢���������ͬǰ׺�ļ�ʱ����ʹ�ý��ٵĿռ䡣��ʱTrie��ֻ��ҪO(m) ��ʱ�临�Ӷȣ�����mΪ������
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
	cout << trie.search("apple") << endl;   // ���� true
	cout << trie.search("app") << endl;     // ���� false
	cout << trie.startsWith("app") << endl; // ���� true
	trie.insert("app");
	cout << trie.search("app") << endl;     // ���� true
	return 0;
}