#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<unordered_set>
using namespace std;
class Solution {
public:
	unordered_map<string, vector<string>> HashMap;    //HashMap���ڱ����뵱ǰ����cur���ڵ����е��ʵ�ӳ���
	vector<vector<string>> res;    //res��������ת�������������
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//����˼�룺DFS+��֦(��֦������BFS��map��set)
		vector<string> ans;    //ans����ĳһ��ת�������������
		ans.push_back(beginWord);
		bfs(beginWord, endWord, wordList);    //bfs����HashMap
		dfs(endWord, ans, wordList);    //dfs��������ת�������������
		return res;
	}
	void bfs(string beginWord, string endWord, vector<string>& wordList)
	{
		int depth = 0, flag = 0;
		list<string> queue;    //queue���ڲ�α���
		unordered_map<string, int> mindepth;    //mindepth���ڼ�¼��ǰ����cur���ȳ��ֵĲ���
		unordered_set<string> dict(wordList.begin(), wordList.end());    //�ռ任ʱ�䣬���ڲ���cur���ڵĵ���
		queue.push_front(beginWord);
		//��α���������HashMap���ڱ����뵱ǰ����cur���ڵ����е��ʵ�ӳ���
		while (!queue.empty())
		{
			int len = queue.size();
			depth++;
			//�ȰѸò�����е��ʼ�¼��ȣ���ʱmindepth��¼�Ĳ��ǵ������ȳ��ֵĲ���
			for (auto i=queue.begin();i!=queue.end();i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//������ǰ�����е��ʣ���¼ÿ���������ڵ���֮ǰ��û�г��ֹ����е���
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				if (HashMap.find(cur) == HashMap.end())
				{
					//���ҵ�ǰ����cur����һ��ת���ĵ��ʣ���curֻ���һ����ĸ
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
								//���ǵ�k���ĳһ�����ʣ������������ڵ�1��k-1���Ѿ����ֹ����Ͳ��ü�������̽��
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
		//�ݹ���ֹ��������ǰ����cur����Ŀ�굥��
		if (cur == endWord)
		{
			res.push_back(ans);
			return;
		}
		//��ǰ����Ϊcur������HashMapӳ��������һ��ת���ĵ���
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
	unordered_map<string, vector<string>> HashMap;    //HashMap���ڱ����뵱ǰ����cur���ڵ����е��ʵ�ӳ���
	vector<vector<string>> res;    //res��������ת�������������
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//����˼�룺BFS
		bfs(beginWord, endWord, wordList);
		return res;
	}
	void bfs(string beginWord, string endWord, vector<string>& wordList)
	{
		int depth = 0, flag = 0;
		list<vector<string>> queue;    //queue���ڲ�α���
		vector<string> ans;    //ans����ĳһ��ת�������������
		ans.push_back(beginWord);
		unordered_map<string, int> mindepth;    //mindepth���ڼ�¼��ǰ����cur���ȳ��ֵĲ���
		unordered_set<string> dict(wordList.begin(), wordList.end());    //�ռ任ʱ�䣬���ڲ���cur���ڵĵ���
		queue.push_front(ans);
		//��α���������HashMap���ڱ����뵱ǰ����cur���ڵ����е��ʵ�ӳ���
		while (!queue.empty())
		{
			int len = queue.size();
			depth++;
			//�ȰѸò�����е��ʼ�¼��ȣ���ʱmindepth��¼�Ĳ��ǵ������ȳ��ֵĲ���
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find((*i).back()) == mindepth.end())
					mindepth[(*i).back()] = depth;
			}
			//������ǰ�����е��ʣ���¼ÿ���������ڵ���֮ǰ��û�г��ֹ����е���
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
				//���ҵ�ǰ����cur����һ��ת���ĵ��ʣ���curֻ���һ����ĸ
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
							//���ǵ�k���ĳһ�����ʣ������������ڵ�1��k-1���Ѿ����ֹ����Ͳ��ü�������̽��
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
	//��������ת�������������
	vector<vector<string>> res;
	//��̵�ת���������еĳ���
	int minlength=INT_MAX;
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//����˼�룺�����ݹ�DFS����ʱ
		vector<string> ans;    //ans����ĳһ��ת�������������
		ans.push_back(beginWord);
		Recursion(endWord, ans, wordList);
		return res;
	}
	void Recursion(string endWord, vector<string> ans, vector<string>& wordList)
	{
		//��֦Ч�����ѣ���Ϊ����յ㵥���ڱȽ���Ĳ㣬��ôdfs�Ĺ�ģ��Ȼ���Ӵ�
		if (ans.size() > minlength)
			return;
		string cur = ans[ans.size() - 1];
		//�ݹ���ֹ��������ǰ����cur����Ŀ�굥��
		if (cur == endWord)
		{
			//ֻ������̵�ת����������
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
		//��ǰ����Ϊcur��������һ��ת���ĵ���
		for (int i = 0; i < wordList.size(); i++)
		{
			int cnt = 0, flag = 0;
			//��һ��ת���ĵ��ʵ�Ҫ��1���͵�ǰ����curֻ���һ����ĸ 2����û��ת���������б�����ans�г��ֹ�
			//�ж���һ��ת���ĵ����Ƿ��뵱ǰ����curֻ���һ����ĸ
			for (int j = 0; j < cur.size(); j++)
			{
				if (cur[j] == wordList[i][j])
					cnt++;
			}
			if (cnt == cur.size() - 1)
			{
				//�ж���һ��ת���ĵ����Ƿ��Ѿ���ans�г���
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