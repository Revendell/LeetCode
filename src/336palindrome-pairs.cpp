#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //����˼�룺��������ʱ��ʱ�临�Ӷ�O(n^2*m)
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
        //����˼�룺ǰ׺����x+y��ɻ��Ĵ���Ҫôx��y����һ�����ǻ�������lls+sssll��Ҫôx��y����ȫû�л��ĸ�ռ����һ��abcd+dcba
        //��words�����е��ʴ洢��ǰ׺���ṹ�У�Ȼ�����words��ÿһ������
        //�������ǰ�벿�ֻ��Ĳ��Һ�벿���������ǰ׺�����ҵ�����(ǰ׺�����ҵ��ĵ���+�õ���)��ɻ��Ĵ�lls+sssll
        //������ĺ�벿�ֻ��Ĳ���ǰ�벿���������ǰ׺�����ҵ�����(�õ���+ǰ׺�����ҵ��ĵ���)��ɻ��Ĵ�llsss+sll
        vector<vector<int>> res;
		for(int i=0;i<words.size();i++)
			insertTrie(words[i],i);
        for(int i=0;i<words.size();i++)
        {
            int len=words[i].size();
            for(int j=0;j<=len;j++)
            {
                //����ע��j!=0����Ϊj=0��j=len����������ظ���
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
        //��word���ʲ���ǰ׺��
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
	    //��word��[left,right]��������ǰ׺�����Ƿ���ҵ�
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
        //����ַ���s��[left,right]��Χ�Ƿ񹹳ɻ���
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
