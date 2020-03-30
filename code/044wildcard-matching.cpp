#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		//����˼�룺�ݹ鷨���������Ż����ǳ�ʱ��������һ��˼���¼һ��
		string p1;
		int i = 0;
		//��֦�Ż���ȥ���ظ���*
		p1 = Remove_stars(p);
		//�ݹ����
		return Recursion(s, p1, 0, 0);
	}
	//��֦�Ż���ȥ���ظ���*
	string Remove_stars(string &p)
	{
		string p1;
		int i;
		if (p.size() == 0)
			return "";
		while (i < p.size() - 1)
		{
			if (p[i] == '*' && p[i + 1] == '*')
			{
				i++;
				continue;
			}
			else
				p1 += p[i];
			i++;
		}
		p1 += p[p.size() - 1];
		return p1;
	}
	bool Recursion(string s, string p, int m, int n)
	{
		//���s���±�m��p���±�n���Ѿ���ͷ��˵��ƥ��ɹ�
		if (m == s.size() && n == p.size())
			return true;
		//���s���±�m��ͷp���±�nû�е�ͷ����pʣ���ַ�����*��˵��ƥ�䲻�ɹ�
		if (m == s.size() && n < p.size() && p[n] != '*')
			return false;
		//���s���±�m��ͷp���±�nû�е�ͷ����p��һ�ַ���*�������ݹ���ÿ�ʣ���ַ��Ƿ���*
		if (m == s.size() && n < p.size() && p[n] == '*')
		{
			return Recursion(s, p, m, n + 1);
		}
		//���s���±�mû�е�ͷp���±�n��ͷ��˵��ƥ�䲻�ɹ�
		if (m < s.size() && n == p.size())
			return false;
		//�����ǰs��ָ�ַ���p��ָ�ַ���ͬ���ݹ����s��p�±궼+1
		if (s[m] == p[n])
		{
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//���p��ָ�ַ�Ϊ*�������������ƥ�������*ƥ����ַ�����*ƥ�����ַ���*ƥ���굱ǰ�ַ�����ƥ��
		else if (p[n] == '*')
		{
			if (Recursion(s, p, m, n + 1))
				return true;
			if (Recursion(s, p, m + 1, n))
				return true;
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//�����ǰp��ָ�ַ�Ϊ�����ݹ����s��p�±궼+1
		else if (p[n] == '?')
		{
			if (Recursion(s, p, m + 1, n + 1))
				return true;
		}
		//�����ǰs��ָ�ַ���p��ָ�ַ�����ȣ�˵��ƥ�䲻�ɹ�
		else if (s[m] != p[n])
		{
			return false;
		}
		//���һ��Ҫ����false����Ϊ�������if�����Recursion��������ɹ�����true��������ɹ������˳�ifִ����һ����䣬�����bool����û����������ˣ����ص��������
		return false;
	}
};
class Solution1 {
public:
	bool isMatch(string s, string p) {
		//����˼�룺��̬�滮���������ַ���ƥ�����ⶼ�����ö�̬�滮����������ƥ�����Ϣ����δƥ�����Ϣ��
		int m = s.size(), n = p.size(), i, j;
		//dp[i][j]��ʾs[0,i-1]ǰi���ַ���p[0,j-1]ǰj���ַ��Ƿ�ƥ��
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		//��s��p��Ϊ��ʱƥ��ɹ�
		dp[0][0] = true;
		//��s��Ϊ��pΪ��ʱ��ƥ��
		for (i = 1; i < m; i++)
			dp[i][0] = false;
		//��sΪ��j��ͷ��Ϊ*��*����ƥ��մ�����ͷ����ƥ��ɹ�
		for (j = 0; j < n; j++)
		{
			if (p[j] == '*')
				dp[0][j + 1] = true;
			else
				break;
		}
		//����ѭ������ά����dp��ֵ
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				//����ǰp[j]Ϊ*�����*�����մ���sǰi������pǰj�����Ƿ�ƥ��ȡ����sǰi����pǰj-1�����Ƿ�ƥ��
				//���*ƥ�䵱ǰs[i]�ַ���sǰi������pǰj�����Ƿ�ƥ��ȡ����sǰi-1����pǰj�����Ƿ�ƥ��
				if (p[j] == '*')
				{
					dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
				}
				//����ǰs[i]�ַ��뵱ǰp[j]�ַ���ȣ����ߵ�ǰp[j]Ϊ����sǰi������pǰj�����Ƿ�ƥ��ȡ����sǰi-1����pǰj-1�����Ƿ�ƥ��
				else if (s[i] == p[j] || p[j] == '?')
				{
					dp[i + 1][j + 1] = dp[i][j];
				}
				//��������������㣬sǰi������pǰj������ƥ��
				else
					dp[i + 1][j + 1] = false;
			}
		}
		return dp[m][n];

	}
};
class Solution2 {
public:
	bool isMatch(string s, string p) {
		//����˼�룺̰�Ļ��ݷ�
		int m = s.size(), n = p.size(), i, j, flag_i, flag_j;
		i = 0;
		j = 0;
		//��ʼ����ǵ�Ϊ-1�������ǵ���ڵ���0��˵���б�ǲ��ܻ���
		flag_j = -1;
		flag_i = -1;
		//һ��ѭ����sÿ���ַ�����ƥ��
		while (i < m)
		{
			//��ǰs[i]�ַ��뵱ǰp[j]�ַ���ȣ�s��p���±궼����һλ
			if (j < n && (s[i] == p[j] || p[j] == '?'))
			{
				i++;
				j++;
			}
			//��ǰp[j]Ϊ*����ǵ�ǰs���ַ���λ�ã����p��*����λ��Ϊflag_j��j����һλ��*����һ���ַ���˵��*ƥ��մ�
			else if (j < n && p[j] == '*')
			{

				flag_i = i;
				flag_j = j;
				j++;
			}
			//���*ƥ��մ���p��*�ĺ�һλ���Ǵ���s�ַ���ƥ�䣬˵��*����ƥ��մ���*ƥ��s��ǰ�ַ���i����һλ��j����ָ��*����һ���ַ�
			else if (flag_i >= 0)
			{
				flag_i++;
				i = flag_i;
				j = flag_j + 1;
			}
			//�����������ƥ�䣬����falseƥ�䲻�ɹ���������p��ͷ�˶�s�л����ַ��������ǵ�ǰs��ָ�ַ���p��ָ�ַ������
			else
				return false;
		}
		//s�Ѿ���ͷ�ˣ�ȥ��p������*��������j�ܵ�p��ͷ˵��ƥ��ɹ�������˵����ƥ��ɹ�����*�����������ַ�
		while (j < n && p[j] == '*')
			j++;
		return j==n;

	}
};
int main()
{
	Solution2 solute;
	string s = "aa";
	string p = "*";
	cout << solute.isMatch(s, p) << endl;
	return 0;
}