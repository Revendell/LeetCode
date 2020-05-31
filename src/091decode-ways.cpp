#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		//����˼�룺��̬�滮����dp[i]��ʾǰi���ַ��Ľ��뷽ʽ���ܸ���
		//�����ǰ�ַ�������0����ǰ�ַ����Խ���ɵ����ַ�������dp[i]+=dp[i-1]
		//�����ǰ�ַ���ǰһ���ַ���10-26֮�䣬�������ַ�Ҳ���ԳɶԽ��룬����dp[i]+=dp[i-2]
		if (s.size() == 0)
			return 0;
		int res = 0, i;
		vector<int> dp(s.size() + 1, 0);
		dp[0] = 1;
		if (s[0] != '0')
			dp[1] = 1;
		for (i = 2; i <= s.size(); i++)
		{
			if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
				dp[i] += dp[i - 2];
			if (s[i - 1] != '0')
				dp[i] += dp[i - 1];
		}
		return dp[s.size()];
	}
};
class Solution1 {
public:
	int res = 0;
	int numDecodings(string s) {
		//����˼�룺�ݹ���ݷ�����ʱ
		if (s.size() == 0)
			return 0;
		Recursion(s, 0);
		return res;
	}
	void Recursion(string &s, int pos)
	{
		if (pos == s.size())
		{
			res++;
			return;
		}
		if (s[pos] > '0')
		{
			Recursion(s, pos + 1);
		}
		if (pos + 1 <= s.size() - 1 && (s[pos] == '1' || s[pos] == '2' && s[pos + 1] <= '6'))
		{
			Recursion(s, pos + 2);
		}
		return;
	}
};
int main()
{
	Solution solute;
	string s = "01";
	cout << solute.numDecodings(s) << endl;
	return 0;
}