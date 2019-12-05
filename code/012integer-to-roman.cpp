#include<iostream>
#include<vector>
using namespace std;
//暴力法
class Solution1 {
public:
	string intToRoman(int num) {
		string s;  //整数转罗马数字返回的字符串
		int t, counter=0;  //counter标记余数t是位于个位还是十位百位千位
		vector<string> roman = { "I","X","C","M","V","L","D"};  //1,10,100,1000,5,50,500
		//不断循环t=num % 10取出num的低位，用一个counter标记余数t是位于个位还是十位百位千位，然后根据不同位counter以及罗马数字的命名规律从头部插入余数t到转换的s中去
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
//贪心法
class Solution2 {
public:
	string intToRoman(int num)
	{
		string result;
		vector<int> integer = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		//贪心法:循环遍历比数组integer中大的数，然后将其罗马数形式加入字符串中，num -= integer[i]
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