#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
class WordDictionary {
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		//����˼�룺ǰ׺��+�����������
		//��ÿһ���ַ�����һ��Trie�ṹ����ǰ�ַ��ĺ���ַ�����������26����ĸ������26������
		//�����ֹ��ǰ�ַ����ɲ�����ַ������õ�ǰ�ַ��ڵ��isWordΪtrue��
		//����'.'�Ĵ���ʹ���������������������ǰ�ڵ����зǿպ����Ƿ������ƥ���ϣ������ƥ�䲻�Ϸ���false
		//Trie ����һ���и�������������������ֶΣ�
		//���R��ָ���ӽ������ӣ�����ÿ�����Ӷ�Ӧ��ĸ�����ݼ��е�һ����ĸ������RΪ26
		//�����ֶΣ���ָ���ڵ��Ƕ�Ӧ���Ľ�β����ֻ�Ǽ�ǰ׺��
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