#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		int len = s.size();
		//����map������������������ӳ���
		map<char, int> mapRoman;
		mapRoman['M'] = 1000;
		mapRoman['D'] = 500;
		mapRoman['C'] = 100;
		mapRoman['L'] = 50;
		mapRoman['X'] = 10;
		mapRoman['V'] = 5;
		mapRoman['I'] = 1;
		int sum = 0;
		//������������MCMXCIV=1994,M=1000,CM=900,XC=90,IV=4��Ҳ���Կ���M-C+M-X+C-I+V=1994
		for (int i = 0; i < len - 1; i++)
		{
			//����4:IV=-I+V��9:IX=-I+X�������mapRoman[s[i]]<mapRoman[s[i+1]],sum -= mapRoman[s[i]]
			if (mapRoman[s[i]] < mapRoman[s[i + 1]])
				sum -= mapRoman[s[i]];
			else
				sum += mapRoman[s[i]];
		}
		sum += mapRoman[s[len - 1]];
		return sum;
	}
};
int main()
{
	Solution solute;
	string s = "MCMXCIV";
	cout << solute.romanToInt(s) << endl;
	return 0;
}
