#include<algorithm>
#include<vector>
#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
	vector<int> dp;
	int minCut(string s) {
		//����˼�룺��̬�滮+������չ������dp[i]��ʾ��s[0:i]�ָ�ɻ����Ӵ�����С�ָ����
		//ע��dp[i]�ǽ�ֹs[i]���������aba��dp����010������000
		//����s��ÿ���ַ����Ը��ַ�Ϊ������������չ����չ�����в��ϸ���dp[right] = min(dp[right], dp[left - 1] + 1);
		if (s.size() == 0)
			return 0;
		//��ʼ��dp
		for (int i = 0; i < s.size(); i++)
			dp.push_back(i);
		//����s��ÿ���ַ����Ը��ַ�Ϊ������������չ����չ�����в��ϸ���dp
		for (int i = 0; i < s.size(); i++)
		{
			Recursion(s, i, i);    //���Ĵ��������
			Recursion(s, i, i + 1);    //���Ĵ�ż�����
		}
		return dp[s.size() - 1];
	}
	void Recursion(string& s, int left, int right)
	{
		if (right == s.size() || left == -1)
			return;
		//���s[left]=s[right]����s[left:right]֮����ַ����һ�����Ĵ�����ôdp[right]=min(dp[right],dp[left-1]+1)
		if (s[left] == s[right])
		{
			if (left == 0)
				dp[right] = min(dp[right], 0);
			else
				dp[right] = min(dp[right], dp[left - 1] + 1);
			Recursion(s, left - 1, right + 1);
		}
	}
};
int main()
{
	Solution solute;
	string s = "didbhbd";
	cout << solute.minCut(s) << endl;
	return 0;
}