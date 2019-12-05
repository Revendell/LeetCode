#include<iostream>
#include<vector>
using namespace std;
//������
class Solution1 {
public:
	string intToRoman(int num) {
		string s;  //����ת�������ַ��ص��ַ���
		int t, counter=0;  //counter�������t��λ�ڸ�λ����ʮλ��λǧλ
		vector<string> roman = { "I","X","C","M","V","L","D"};  //1,10,100,1000,5,50,500
		//����ѭ��t=num % 10ȡ��num�ĵ�λ����һ��counter�������t��λ�ڸ�λ����ʮλ��λǧλ��Ȼ����ݲ�ͬλcounter�Լ��������ֵ��������ɴ�ͷ����������t��ת����s��ȥ
		while (num != 0)
		{
			t = num % 10;
			//1,2,3->I,II,III
			while (t > 0 && t <= 3)
			{
				s.insert(0, roman[counter]);
				t--;
			}
			//4->IV
			if (t == 4)
			{
				s.insert(0, roman[counter + 4]);
				s.insert(0, roman[counter]);
			}
			//5,6,7,8->V,VI,VII,VIII
			while (t >= 5 && t <= 8)
			{
				if (t > 5)
					s.insert(0, roman[counter]);
				if (t == 5)
					s.insert(0, roman[counter + 4]);
				t--;
			}
			//9->IX
			if (t == 9)
			{
				s.insert(0, roman[counter + 1]);
				s.insert(0, roman[counter]);
			}
			num = num / 10;
			counter++;
		}
		return s;
	}
	
};
//̰�ķ�
class Solution2 {
public:
	string intToRoman(int num)
	{
		string result;
		vector<int> integer = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		//̰�ķ�:ѭ������������integer�д������Ȼ������������ʽ�����ַ����У�num -= integer[i]
		for (int i = 0; i < integer.size(); i++)
		{
			while (num >= integer[i])
			{
				result.append(roman[i]);
				num -= integer[i];
			}
		}
		return result;
	}
};
int main()
{
	Solution1 solute1;
	Solution2 solute2;
	int num = 2019;
	cout << solute1.intToRoman(num) << endl;
	cout << solute2.intToRoman(num) << endl;
	return 0;
}