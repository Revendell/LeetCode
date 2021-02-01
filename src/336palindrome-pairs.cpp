#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //基本思想：暴力，超时，时间复杂度O(n^2*m)
        vector<vector<int>> res;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(checkPalindrome(words[i]+words[j]))
                    res.push_back({i,j});
                if(checkPalindrome(words[j]+words[i]))
                    res.push_back({j,i});
            }
        }
        return res;
    }
    bool checkPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
struct Trie
{
	Trie* child[26];
	int index=-1;
	Trie() {
		for (int i = 0; i < 26; i++)
			child[i] = nullptr;
	}
};
class Solution1 {
public:
    Trie* t = new Trie();
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //基本思想：前缀树，x+y组成回文串，要么x和y中有一部分是回文例如lls+sssll，要么x和y中完全没有回文各占回文一半abcd+dcba
        //将words中所有单词存储在前缀树结构中，然后遍历words中每一个单词
        //如果它的前半部分回文并且后半部分逆序后在前缀树中找到，则(前缀树中找到的单词+该单词)组成回文串lls+sssll
        //如果它的后半部分回文并且前半部分逆序后在前缀树中找到，则(该单词+前缀树中找到的单词)组成回文串llsss+sll
        vector<vector<int>> res;
		for(int i=0;i<words.size();i++)
			insertTrie(words[i],i);
        for(int i=0;i<words.size();i++)
        {
            int len=words[i].size();
            for(int j=0;j<=len;j++)
            {
                //这里注意j!=0，因为j=0和j=len这两种情况重复了
                if(j!=0&&checkPalindrome(words[i],0,j-1))
                {
                    int index=findTrie(words[i],j,len-1);
                    if(index!=-1&&index!=i)
                        res.push_back({index,i});
                }
                if(checkPalindrome(words[i],j,len-1))
                {
                    int index=findTrie(words[i],0,j-1);
                    if(index!=-1&&index!=i)
                        res.push_back({i,index});
                }
            }
        }
        return res;
    }
    void insertTrie(string word,int i)
    {
        //对word单词插入前缀树
        Trie* cur=t;
		for (auto c:word)
		{
			if (cur->child[c-'a'] == nullptr)
				cur->child[c-'a'] = new Trie();
			cur = cur->child[c-'a'];
		}
		cur->index=i;
	}
	int findTrie(string word,int left,int right)
	{
	    //对word中[left,right]的逆序在前缀树中是否查找到
        Trie* cur=t;
        for(int i=right;i>=left;i--)
        {
            if(cur->child[word[i]-'a']==nullptr)
                return -1;
            cur=cur->child[word[i]-'a'];
        }
        return cur->index;
	}
	bool checkPalindrome(string s,int left,int right)
    {
        //检查字符串s的[left,right]范围是否构成回文
        int i=left,j=right;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    Solution1 solute;
    vector<string> words{"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> res=solute.palindromePairs(words);
    for_each(res.begin(),res.end(),[](vector<int> v){cout<<v[0]<<" "<<v[1]<<endl;});
    return 0;
}
