#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		//�򻯰棺��̬�滮+������չ����dp[i][j]��ʾs��[i,j]��Χ�ַ��Ƿ񹹳ɻ��Ĵ�
		int start, max_len = 0;
		vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));	
		for(int len=1;len<=s.size();len++)
		{
			for(int i=0;i<=s.size()-len;i++)
			{
				int j=i+len-1;
				if(s[i]==s[j]&&(i==j||i+1==j||dp[i+1][j-1]))
				{
					dp[i][j]=true;
					start=i;
					max_len=len;
				}		
			}
		}
		return max_len==0?s.substr(0,1):s.substr(start,max_len);
	}
};
//������չ��
class Solution1 {
public:
	string longestPalindrome(string s) {
		int start, max_len = 0;  //�������Ӵ���ʼ���±�start���������Ӵ�����max_len
		int i, j, center;  //center��Ϊ�����Ӵ������ģ�i��ǻ����Ӵ�����ߣ�j��ǻ����Ӵ����ұߣ�ͨ��s[i] == s[j]���ϴ�����center������չi--,j++
		int len = s.length();  //lenΪ�ַ���s�ĳ���
		if (len == 1 || len == 0)  //����ַ���Ϊ�ջ���ֻ��һ���ַ���ֱ�ӷ���s
			return s;
		//���������Ӵ�����Ϊ������i��jͬʱ��center��չ��
		for (center = 0; center < len; center++)
		{
			i = center;
			j = i;
			while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
				i--;
				j++;
			}
			if ((j - i + 1) - 2 > max_len)
			{
				max_len = j - i + 1 - 2;
				start = i + 1;
			}
		}
		//���������Ӵ�����Ϊż����i��center��չ����j��center+1��չ��
		for (center = 0; center < len; center++)
		{
			i = center;
			j = i + 1;
			while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
				i--;
				j++;
			}
			if ((j - i + 1) - 2 > max_len)
			{
				max_len = j - i + 1 - 2;
				start = i + 1;
			}
		}
		//max_len=0˵��û�л��Ĵ������Է��ص�һ���ַ��Ϳ�����
		if (max_len == 0)
			return s.substr(0, 1);
		else  //���ؽ�ȡs�Ļ��Ĵ���ʼ�±�start����Ϊmax_len
			return s.substr(start, max_len);
	}
};
//��̬�滮��
class Solution2 {
public:
	string longestPalindrome(string s) {
		int start, max_len = 0;
		int i, j;  //i����Ӵ�����ʼ�±꣬j����Ӵ�����ֹ�±꣬�Ӵ�����len=j-i+1
		int s_len = s.length();  //s_lenΪ�ַ���s�ĳ���
		int len;
		bool dp[1000][1000] = { false };  //pd[i][j]=true��ʾ���±�i���±�j���ַ��Ӵ�Ϊ���Ĵ�
		if (s_len == 1 || s_len == 0)  //����ַ���Ϊ�ջ���ֻ��һ���ַ���ֱ�ӷ���s
			return s;
		//��ʼ��pd
		for (i = 0; i < s_len - 1; i++)
		{
			dp[i][i] = true;  //�����ַ����ڻ��Ĵ����ǳ�����С�Ļ��Ĵ�
			j = i + 1;
			//�����������ַ���ͬ�����������ַ���ɻ��Ĵ�
			if (s[i] == s[j])
			{
				dp[i][j] = true;
				max_len = j - i + 1;
				start = i;
			}

		}
		//ѭ���ж��ַ���s���Ӵ�����len��3��s_len���Ƿ���ڻ��Ĵ����Ӵ��±��0��s_len - len�����dp[i+1][j-1]=true&&s[i] == s[j]�򳤶�len���Ӵ�(�±��i��j)Ϊ���Ĵ���dp[i][j]=true
		for (len = 3; len <= s_len; len++)
		{
			for (i = 0; i <= s_len - len; i++)
			{
				j = i + len - 1;
				//���dp[i+1][j-1]=true && s[i]=s[j]���򳤶�len���Ӵ�(�±��i��j)Ϊ���Ĵ�
				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					max_len = len;  //��Ϊ�Ӵ�����len��3��s_len���Ƿ���ڻ��Ĵ�������������ڻ��Ĵ������Ĵ��ĳ�����Խ��Խ��ģ���max_len�͵���len�������ж�len�Ƿ����max_len
					start = i;
				}
			}
		}
		//max_len=0˵��û�л��Ĵ������Է��ص�һ���ַ��Ϳ�����
		if (max_len == 0)
			return s.substr(0, 1);
		else  //���ؽ�ȡs�Ļ��Ĵ���ʼ�±�start����Ϊmax_len
			return s.substr(start, max_len);
	}
};
int main()
{
	Solution solute;
	string s;
	s = "abbbcd";
	cout << solute.longestPalindrome(s) << endl;
	return 0;
}