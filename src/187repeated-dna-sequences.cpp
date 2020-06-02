#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//����˼�룺������Ƭ+HashSet����s���д��ڻ�����Ƭ��ÿ����Ƭ��СΪ10���ַ������浽set
		//����´���Ƭ��set���Ѿ����ֹ���˵������1�Σ�����res��resҲ��set��ֹ�ظ����ֵ���Ƭ��
		//ʱ�临�Ӷ�O((N-L)L)�ռ临�Ӷ�O((N-L)L)��ΪL=10����������O(N)
		unordered_set<string> dict;
		unordered_set<string> res;
		if (s.size() < 10)
			return {};
		for (int i = 0; i <= s.size() - 10; i++)
		{
			string cur = s.substr(i, 10);    //ʱ�临�Ӷ�O(L)
			if (dict.find(cur) != dict.end())
				res.insert(cur);
			else
				dict.insert(cur);
		}
		return vector<string>(res.begin(),res.end());
	}
};
class Solution1 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//����˼�룺λ���㣬�������淽�����Ż������淽������s.substr(i, 10)̫��ʱ��10���ַ���Ӧset�˷ѿռ�
		//��A��C��G��T����00��01��10��11������10���ַ����Ƕ�Ӧ20��bit
		//����s����һ���ַ�����ôcurֻ��Ҫ����2λ�������ַ���Ӧbit����cur���2λ����
		unordered_map<char, int> HashMap = { {'A',0},{'C',1},{'G',2},{'T',3} };
		unordered_set<bitset<20>> dict;
		unordered_set<string> res;
		bitset<20> cur;
		for (int i = 0; i < s.size(); i++)
		{
			cur <<= 2;
			cur |= HashMap[s[i]];
			if (i >= 9)
			{
				if (dict.find(cur) != dict.end())
					res.insert(s.substr(i - 9, 10));
				else
					dict.insert(cur);
			}
		}
		return vector<string>(res.begin(), res.end());
	}
};
int main()
{
	Solution1 solute;
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string> res = solute.findRepeatedDnaSequences(s);
	for_each(res.begin(), res.end(), [](const auto v) {cout << v << endl; });
	return 0;
}