#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		//�򻯰棺��������+��ϣ��
		vector<int> res;
		if(words.size()==0)  return res;
		map<string,int> Map;
		for(auto word:words)
			Map[word]++;
		int wlen=words[0].size();
		for(int i=0;i+words.size()*wlen<=s.size();i++)
		{
			map<string,int> tmp=Map;
			int cnt=0;
			for(int j=0;j<words.size();j++)
			{
				string cur=s.substr(i+j*wlen,wlen);
				if(tmp[cur]>0)
				{
					tmp[cur]--;
					cnt++;
				}
				else
					break;
			}
			if(cnt==words.size())
				res.push_back(i);
		}
		return res;
    }
};
class Solution1 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		//��������HashMap��wordsһ��HashMap1�����ַ���s���ڴ�СΪword_len*words_len���ִ�һ��HashMap2���������HashMap�����ƥ��ɹ���¼��ʼ�±�
		map<string, int> HashMap1, HashMap2;
		//�����������
		if (words.size() == 0 || s == "")
			return res;
		//words_lenΪwords�е��ʸ�����word_lenΪÿ��������ĸ����
		int words_len, word_len, i, j, k, flag;
		words_len = words.size();
		word_len = words[0].length();
		//����õ�words��HashMap1����������string����ִ���int��HashMap
		for (i = 0; i < words_len; i++)
		{
			if (HashMap1.find(words[i]) != HashMap1.end())
				HashMap1[words[i]]++;
			else
				HashMap1[words[i]] = 1;
		}
		i = 0;
		//�Դ��ڴ�СΪwords_len*word_len��0��s.length()-words_len*word_len���ַ���s�л�������
		while (i + word_len * words_len <= s.length())
		{
			HashMap2 = HashMap1;
			j = 0;
			//��ÿ�����ڽ��е���ƥ�䣬���ƥ��ɹ�HashMap2[words[k]]--��������HashMap2�еĵ��ʶ�Ӧ������Ϊ0����ƥ��ɹ���¼��ʼ�±�i
			while (j < words_len * word_len)
			{
				flag = 0;
				//��words��ÿ������ƥ��һ�Σ�ƥ��ɹ�HashMap2[words[k]]--���ַ���s���±�j��ǰ�ƶ�word_len�����û��ƥ��ɹ�flag=0��breakѭ�����˴��ڲ�ƥ�������һ������
				for (k = 0; k < words_len; k++)
				{
					if (s.substr(i + j, word_len) == words[k])
					{
						HashMap2[words[k]]--;
						j = j + word_len;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					break;
			}
			flag = 1;
			//������HashMap2�е�ÿ�����ʶ�Ӧ������Ϊ0����ƥ��ɹ���¼��ʼ�±�i
			for (k = 0; k < words_len; k++)
			{
				if (HashMap2[words[k]] != 0)
					flag = 0;
			}
			if (flag == 1)
				res.push_back(i);
			//�˴��ڽ�������ǰ�ƶ�1������һ������
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	string s = "w";
	vector<string> words = { "w", "w" };
	vector<int> res;
	res = solute.findSubstring(s, words);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}