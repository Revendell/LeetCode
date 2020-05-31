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
		//����˼�룺BFS
		unordered_map<string, int> mindepth;    //mindepth���ڼ�¼��ǰ����cur���ȳ��ֵĲ���
		unordered_set<string> dict(wordList.begin(), wordList.end()); //�ռ任ʱ�䣬���ڲ���cur���ڵĵ���
		list<string> queue;    //queue���ڲ�α���
		int flag = 0;    //����Ƿ��Ѿ�����endWord
		queue.push_front(beginWord);
		int depth = 0;    //��α��������
		while (!queue.empty())
		{
			depth++;
			int len = queue.size();
			//�ȰѸò�����е��ʼ�¼��ȣ���ʱmindepth��¼�Ĳ��ǵ������ȳ��ֵĲ���
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//������ǰ�����е��ʣ���¼ÿ���������ڵ���֮ǰ��û�г��ֹ����е��������queue
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				if (cur == endWord)
					flag = 1;
				string temp = cur;
				//���ҵ�ǰ����cur����һ��ת���ĵ��ʣ���curֻ���һ����ĸ
				for (int j = 0; j < cur.size(); j++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[j] == c)
							continue;
						char oldc = cur[j];
						cur[j] = c;
						//�ڿ��ǵ� k ���ĳһ�����ʣ������������ڵ� 1 �� k-1 ���Ѿ����ֹ���������ʵ�Ͳ��ü�������̽����
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
		//����˼�룺˫��BFS����������queue1��queue2�ֱ��beginWord��endWord�����������ڵĵ���(��Щ������֮ǰ��û�г��ֹ�)��ֱ������������������ͬ�ĵ���
		//����ÿ�δ��ĸ�������չ�����ǿ���ÿ��ѡ����Ҫ��չ�Ľڵ����ٵķ��������չ
		unordered_map<string, int> mindepth1;    //mindepth���ڼ�¼beginWord�������ڵ������ȳ��ֵĲ���
		unordered_map<string, int> mindepth2;    //mindepth���ڼ�¼endWord�������ڵ������ȳ��ֵĲ���
		unordered_set<string> dict(wordList.begin(), wordList.end()); //�ռ任ʱ�䣬���ڲ���cur���ڵĵ���
		if (dict.find(endWord) == dict.end())
			return 0;
		list<string> queue1;    //queue1����beginWord���²�α���
		list<string> queue2;    //queue2����endWord���ϲ�α���
		int flag = 0;    //������������Ƿ�������ͬ�ĵ���
		queue1.push_front(beginWord);
		queue2.push_front(endWord);
		int depth1 = 0;    //beginWord���²�α��������
		int depth2 = 0;    //endWord���ϲ�α��������
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
			//�ȰѸò�����е��ʼ�¼��ȣ���ʱmindepth��¼�Ĳ��ǵ������ȳ��ֵĲ���
			for (auto i = queue.begin(); i != queue.end(); i++)
			{
				if (mindepth.find(*i) == mindepth.end())
					mindepth[*i] = depth;
			}
			//������ǰ�����е��ʣ���¼ÿ���������ڵ���֮ǰ��û�г��ֹ����е��������queue
			for (int i = 0; i < len; i++)
			{
				string cur = queue.back();
				queue.pop_back();
				string temp = cur;
				//���ҵ�ǰ����cur����һ��ת���ĵ��ʣ���curֻ���һ����ĸ
				for (int j = 0; j < cur.size(); j++)
				{
					for (char c = 'a'; c <= 'z'; c++)
					{
						if (cur[j] == c)
							continue;
						char oldc = cur[j];
						cur[j] = c;
						//�ڿ��ǵ� k ���ĳһ�����ʣ������������ڵ� 1 �� k-1 ���Ѿ����ֹ���������ʵ�Ͳ��ü�������̽����
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
			//ֱ������������������ͬ�ĵ���flag=1����ѭ��
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