#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		//����˼�룺�ַ����������������ȥ��ĩβ�ո��ټ������ֿո�ǰ�ķǿո��ַ��������������һ�����ʳ���
		int res = 0, i = s.length() - 1;
		while (i >= 0 && s[i] == ' ')
			i--;
		while (i >= 0 && s[i--] != ' ')
			res++;
		return res;
	}
};
int main()
{
	Solution solute;
	string s = "  hello world   ";
	cout << solute.lengthOfLastWord(s) << endl;
	return 0;
}