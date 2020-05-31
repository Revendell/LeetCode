#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		//����˼�룺��̬�滮����dp[i][j]��ʾword1ǰi���ַ�ת����word2ǰj���ַ���Ҫ�����ٲ���
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		int i, j;
		if (word1.size() == 0 || word2.size() == 0)
			return max(word1.size(), word2.size());
		for (i = 1; i <= word1.size(); i++)
			dp[i][0] = i;
		for (j = 1; j <= word2.size(); j++)
			dp[0][j] = j;
		for (i = 1; i <= word1.size(); i++)
		{
			for (j = 1; j <= word2.size(); j++)
			{
				//��ǰword1[i]��word2[j]�ַ���ȣ���dp[i][j]=dp[i-1][j-1]
				if (word1[i-1] == word2[j-1])
					dp[i][j] = dp[i - 1][j - 1];
				//��ǰword1[i]��word2[j]�ַ���ȣ�Ϊ��ʹword1ת��Ϊword2�����ַ��������ٲ���
				//һ����ɾ��word1[i]�ַ���dp[i][j]=dp[i-1][j]+1
				//�����԰�word1[i]�滻��word2[j]��dp[i][j]=dp[i-1][j-1]+1
				//�����Բ���word2[j]�ַ���dp[i][j]=dp[i][j-1]+1
				else
					dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
			}
		}
		return dp[word1.size()][word2.size()];
	}
};
class Solution1 {
public:
	int res;
	int minDistance(string word1, string word2) {
		//����˼�룺�ݹ���ݷ�����ʱ
		res = max(word1.size(), word2.size());
		Recursion(word1, word2, 0, 0, -1, -1, 0);
		return res;
	}
	void Recursion(string word1, string word2, int i, int j, int prei, int prej, int cnt)
	{
		if (i == word1.size() || j == word2.size())
		{
			cnt += max(word1.size() - prei - 1, word2.size() - prej - 1);
			if (cnt < res)
				res = cnt;
			return;
		}
		if (word1[i] == word2[j])
		{
			cnt += max(i - prei - 1, j - prej - 1);
			//��֦
			if (cnt > res)
				return;
			prei = i;
			prej = j;
			Recursion(word1, word2, i + 1, j + 1, prei, prej, cnt);
		}
		else
		{
			Recursion(word1, word2, i, j + 1, prei, prej, cnt);
			Recursion(word1, word2, i + 1, j, prei, prej, cnt);
		}
		return;
	}
};
int main()
{
	Solution solute;
	string word1 = "horse";
	string word2 = "ros";
	cout << solute.minDistance(word1, word2) << endl;
	return 0;
}