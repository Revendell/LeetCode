#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	string minWindow(string s, string t) {
		//����˼�룺HashMap+�������ڣ�HashMapͳ��t�г��ֵ��ַ�������ƥ��s�еĻ�������[left,right]����t�е��ַ�
		//�ڻ��������д���t�г��ֵ��ַ�--HashMap[s[i]]��ֻҪĳ���ַ�������HashMap�е���0��cnt++��ֱ��HashMap���ַ�������С�ڵ���0
		//��cnt=HashMap.size��˵��t���ַ��������ڻ������ڳ��֣���¼�˴���λ�����С
		//����������߽�left����++��ֱ��HashMap����t�г��ֵ��ַ���������0��cnt--������ѭ�����������������ұ߽�right����++
		int pos = 0, len, i, left, right, cnt = 0, flag = 0;
		len = s.size();
		if (len == 0 || s.size() < t.size())
			return "";
		map<char, int> HashMap;
		//HashMapͳ��t�г��ֵ��ַ�����
		for (auto c : t)
			++HashMap[c];
		left = 0;
		//��s�л�������[left,right]�����������ұ߽�right++
		for (i = 0; i < s.size(); i++)
		{
			if (HashMap.find(s[i]) != HashMap.end())
			{
				//ƥ��s�еĻ�������[left,right]����t�е��ַ����ڻ��������д���t�г��ֵ��ַ�--HashMap[s[i]]
				--HashMap[s[i]];
				//ֻҪĳ���ַ�������HashMap�е���0��cnt++��ֱ��HashMap���ַ�������С�ڵ���0
				if (HashMap[s[i]] == 0)
					++cnt;
				right = i;
				//HashMap���ַ�������С�ڵ���0����cnt=HashMap.size��˵��t���ַ��������ڻ������ڳ��֣���¼�˴���λ�����С
				while (cnt == HashMap.size())
				{
					if (right - left + 1 <= len)
					{
						len = right - left + 1;
						pos = left;
						flag=1;
					}
					//����������߽�left����++��ֱ��HashMap����t�г��ֵ��ַ���������0��cnt--������ѭ��
					if (HashMap.find(s[left]) != HashMap.end())
					{
						++HashMap[s[left]];
						if (HashMap[s[left]] > 0)	
							--cnt;
					}
					left++;
				}
			}
		}
		//flag���ڱ��s���Ƿ����t�����е��ַ�����Ϊ��������ڣ�Ĭ��pos=0��len=s.size����󷵻ص���s
		if (flag == 0)
			return "";
		return s.substr(pos, len);
	}
};
int main()
{
	Solution solute;
	string s ="cabwefgewcwaefgcf";
	string t = "cae";
	cout << solute.minWindow(s, t) << endl;
	return 0;
}