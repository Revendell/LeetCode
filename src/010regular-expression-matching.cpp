#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//�򻯰棺��̬�滮����ʼ��dp[i][j]=false��
		//���s[i-1]==p[j-1]||p[j-1]=='.'����dp[i][j]=dp[i-1][j-1]
		//���p[j-1]=='*'������ѡ��ƥ��0����dp[i][j]=dp[i][j-2]������ѡ��ƥ��һ����ʱ�����s��ǰ�ַ���pǰһ���ַ�ƥ�䣬ƥ������Ϊ*���Լ���ƥ���ַ��������൱�ں�����s�еĵ�ǰ�ַ�(Ҳ���������s��������һ���ַ�����ʱp��*ƥ��������ַ�����Ҫ��dp[i-1][j]��������ַ�֮ǰ�Ƿ�ƥ��)�����Ի���������dp[i-1][j]
		vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
		dp[0][0]=true;
		for(int i=2;i<=p.size();i++)
		{
			if(p[i-1]=='*')
				dp[0][i]=dp[0][i-2];
		}
		for(int i=1;i<=s.size();i++)
		{
			for(int j=1;j<=p.size();j++)
			{
				if(s[i-1]==p[j-1]||p[j-1]=='.')
					dp[i][j]=dp[i-1][j-1];
				else if(p[j-1]=='*')
					dp[i][j]=dp[i][j-2]||(s[i-1]==p[j-2]||p[j-2]=='.')&&dp[i-1][j];
			}
		}
		return dp[s.size()][p.size()];	
	}
};
//�ݹ���ݷ���������⣬�ռ�ʱ�临�Ӷȸ�
class Solution1 {
public:
	bool isMatch(string s, string p) {
		//���ôӺ���ǰƥ�䣬��Ϊ������Ǵ�ǰ����ƥ�䣬ÿ���ַ����Ƕ����ж��Ƿ�������'*'������ĸ�����ǴӺ���ǰû������⣬һ��j����'*'��j-1��Ȼ�и��ַ�
		return recursionMatch(s, s.size() - 1, p, p.size() - 1);
	}
	bool recursionMatch(string s, int i, string p, int j)
	{
		//���j�Ѿ�<0��˵��p�Ѿ�ƥ�����ˣ���ʱ�����sҲƥ������˵����ȷ�����sûƥ����˵������
		//���i�Ѿ�<0��˵��s�Ѿ�ƥ���꣬��ʱ��p����ûƥ���ֻ꣬Ҫ������'*'���ڣ�����ִ�д��룬��������������õ����ó�������
		if (j == -1)
			if (i == -1)
				return true;
			else
				return false;
		//�ܹ�����ƥ�䷽ʽp[j]=='.'||s[i]==p[j]����p[j]=='*'ʱ����ƥ�䣬����������if��������
		if (p[j] == '*')  //��p[j]='*'ʱ�����ִ����������һ����p[j-1]=='.'||s[i]==p[j-1]���ƥ��1��Ԫ��i-1���ڶ�����p[j-1]=='.'||s[i]==p[j-1]������ǲ�ƥ��ֱ������j-2�������������p[j-1]��='.'&&s[i]��=p[j-1]��ƥ������j-2
		{
			if (i >= 0 && (p[j - 1] == '.' || s[i] == p[j - 1]))  //����һ�������ƥ��ֱ��ƥ���ַ���s�е�һ��Ԫ��i-1��j����'*'���Լ���ƥ��ʹ��
				if(recursionMatch(s, i - 1, p, j))  //��if������ֱ��return����Ϊ������������ܲ�����ȫƥ�䣬�������������в��������������Ҳ����
				    return true;
			return recursionMatch(s, i, p, j - 2);  //���ڶ����������������j-2�����ǿ���ƥ�������������ǲ�����ƥ�䱻������������j-2һ����
		}
		if (i >= 0 && (p[j] == '.' || s[i] == p[j]))  //��p[j]!='*' ��p[j]=='.'||s[i]==p[j]���ʱ��ֱ��ƥ�䣬i-1��j-1
		{
			return recursionMatch(s, i - 1, p, j - 1);
		}
		//���������������ƥ�䣬����false
		return false;
	}
};
//��̬�滮��������⣬ʱ��ռ临�Ӷȵ�
class Solution2 {
public:
	bool isMatch(string s, string p) {
		int s_len = s.size(), p_len = p.size();
		bool dp[100][100];  //dp[i][j]��ʾs[0,i-1]ǰi���ַ���p[0,j-1]ǰj���ַ��Ƿ�ƥ�䣬trueƥ�䣬false��ƥ��
		int i, j;  //i��ʾ�ַ���s���±꣬j��ʾ�ַ���p���±�
		bool temp = false;
		dp[0][0] = true;  //��s��pͬʱΪ��ʱ��ƥ��ɹ�
		//��ʼ��dp��dp[i][0]=false����j=0��pΪ��ʱ��sֻ��i=0Ϊ��ʱ��ƥ�䣬����������޷�ƥ��
		for (i = 1; i <= s_len; i++)
			dp[i][0] = false;
		//��ʼ��dp��ֻ��a*��ƥ��մ������p��*(p[j-1]='*')����ôdp[0][j]һ����dp[0][j-2]����ͬ
		for (j = 2; j <= p_len; j++)  //��Ϊ'*'���ַ���p�г��ֵ�λ����ǰ���±�1����j-1>=1����dp��j-2>=0������j��2��ʼ
		{
			if (p[j - 1] == '*')  //dp��j�±����ַ���p���±���j-1
				dp[0][j] = dp[0][j - 2];
			else
				dp[0][j] = false;
		}
		for (i = 1; i <= s_len; i++)
		{
			for (j = 1; j <= p_len; j++)
			{
				//�ܹ�����ƥ�䷽ʽp[j]=='.'||s[i]==p[j]����p[j]=='*'ʱ����ƥ��
				//��p[j]='*'ʱ�����ִ����������һ����p[j-1]=='.'||s[i]==p[j-1]���ƥ��1��Ԫ��i-1���ڶ�����p[j-1]=='.'||s[i]==p[j-1]������ǲ�ƥ��ֱ������j-2�������������p[j-1]��='.'&&s[i]��=p[j-1]��ƥ������j-2
				if (p[j - 1] == '*')
				{
					//���ڶ����������������*����ƥ��0�Σ����߶���һ���j�������Զ����*���ţ�dp[i]���ϵ���dp[i-1]�൱�ڶ������*ƥ��
					dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);	
				}
				else
				{    //dp[i][j]��ʾs[0,i-1]��p[0,j-1]�Ƿ�ƥ��ȡ����p[j-1]=='.'||s[i-1]==p[j-1]�ַ�ƥ����dp[i-1][j-1]=true
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
				}
			}
		}
		//����dp[s_len][p_len]��s[0,s_len-1]ǰs_len���ַ���p[0,p_len-1]ǰp_len���ַ��Ƿ�ƥ��
		return dp[s_len][p_len];
	}
};
int main()
{
	Solution1 solute1;
	Solution2 solute2;
	//�����������һ��������a*����ֱ��������Ҳ��������ƥ��s[1]=a�����Բ��õݹ���ݵķ��������ƥ�䲻�ɹ�����
	string s = "aaaa";
	string p = "aa*aa";
	cout << solute1.isMatch(s, p) << endl;
	cout << solute2.isMatch(s, p) << endl;
	return 0;
}
