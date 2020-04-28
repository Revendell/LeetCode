#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		//����˼�룺�ݹ���ݷ���Ip��ַ�ܹ����Ĳ�����ɣ�cnt�����Ѿ��ӽ����������ˣ���pos��β��cnt=4��������ȷ�ָ�
		//Ip��ַÿһ���ֿ�����һλ��0-9����������λ��10-99��Ҳ��������λ��100-255
		if (s.size() > 12)
			return res;
		//curΪ��ǰ�ָ��һ�������pos��ǰs�±꣬cnt����
		string cur;
		Recursion(s, cur, 0, 0);
		return res;
	}
	void Recursion(string &s, string cur, int pos, int cnt)
	{
		if (pos == s.size())
		{
			//��pos��β��cnt=4��������ȷ�ָ���򷵻�
			if (cnt == 4)
			{
				cur.pop_back();
				res.push_back(cur);
			}	
			return;
		}
		//Ip��ַÿһ���ֿ�����һλ��0-9
		cur += s.substr(pos, 1) + '.';
		Recursion(s, cur, pos + 1, cnt + 1);
		cur.erase(cur.size() - 2, 2);
		//Ip��ַÿһ���ֿ�������λ��10-99
		if (pos + 1 < s.size() && s[pos] != '0')
		{
			cur += s.substr(pos, 2) + '.';
			Recursion(s, cur, pos + 2, cnt + 1);
			cur.erase(cur.size() - 3, 3);
		}
		//Ip��ַÿһ���ֿ�������λ��100-255
		if (pos + 2 < s.size() && (s[pos] == '1'|| (s[pos]=='2' && s.substr(pos,3)<="255")))
		{
			cur += s.substr(pos, 3) + '.';
			Recursion(s, cur, pos + 3, cnt + 1);
			cur.erase(cur.size() - 4, 4);
		}
		return;
	}
};
int main()
{
	Solution solute;
	string s = "172162541";
	vector<string> res = solute.restoreIpAddresses(s);
	copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}