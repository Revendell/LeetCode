#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string str = "";
		//�����ǰ׺�����ַ�������strs�������ַ�����ǰ׺��ͬ
		//˫ָ�뷨��ָ��iָ��ÿ���ַ�����ͬһ��λ�õ��ַ���ָ��j�������������ַ�����c=strs[0][i]��ʾ��һ���ַ������±�i���ַ�
		//i��0��������+1��ֱ�����������ַ������±�iλ���ַ�strs[j][i]���һ���ַ����±�iλ���ַ�����ͬ������str
		int i, j;
		char c;
		int len = strs.size();
		//���ַ�������strsΪ��ʱ������""
		if (len == 0)
			return str;
		//���ַ�������strs����һ�ַ���Ϊ�գ�����""
		for (int j = 0; j < len; j++)
		{
			if (strs[j] == "")
				return str;
		}
		int str_len = strs[0].size();
		//ָ��i����ÿ���ַ�����ͬһ��λ�õ��ַ�
		for (i = 0; i < str_len; i++)
		{
			c = strs[0][i];  //��ʾ��һ���ַ������±�i���ַ�
			//ָ��j�������������ַ����������������ַ�����iλ���ϵ��ַ��Ƿ����һ���ַ���iλ���ַ���ͬ
			for (j = 0; j < len; j++)
			{
				//�����ַ�������һ���ַ������һ���ַ���iλ���ַ�����ͬ������str
				if (c != strs[j][i])
					return str;
			}
			str += c;
		}
		return str;
	}
};
int main()
{
	Solution solute;
	vector<string> strs = { "flower","flow","flight" };
	cout << solute.longestCommonPrefix(strs) << endl;
	return 0;
}
