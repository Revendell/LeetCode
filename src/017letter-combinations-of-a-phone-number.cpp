#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> res;  //����ֵ�����������s���
	//��������ĸ��ӳ������ּ�2����Ӧ
	vector<vector<char>> letter = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'} ,{'m','n','o'} ,{'p','q','r','s'} ,{'t','u','v'} ,{'w','x','y','z'} };
	vector<string> letterCombinations(string digits) {
		int i = 0;  //iָ���ַ���digits���±�
		string s;  //sΪ��ϵ�һ�����
		if (digits == "")  //�����������������⿼�ǣ��򷵻ص�res=[""]������ȷ���Ӧ����resΪ��res=[]
			return res;
		Recursion(digits, i, s);  //�ݹ���ã�ֱ��i���ϼ�1��0�ӵ�len������digits���ݹ����
		return res;
	}
	void Recursion(string digits, int i, string s)
	{
		//��i==len��������digits�������εݹ�Ľ������res��
		if (i == digits.size())
		{
			res.push_back(s);
		}
		else
		{
			int digit = digits[i] - '0' - 2;
			//�����ַ���digits�е��ַ�digits[i]�ж��������ÿ�����letter[digit][j]�ӵ�s���棬�����ݹ���ã�ֱ��i==len������digits�������εݹ��һ�ֽ������res��
			for (int j = 0; j < letter[digit].size(); j++)
			{
				Recursion(digits, i + 1, s + letter[digit][j]);
			}
		}
	}
};
int main()
{
	Solution solute;
	string digits = "2";
	vector<string> res;
	res = solute.letterCombinations(digits);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}