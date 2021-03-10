#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		//简化版：找规律，循环周期n=2*numRows-2，第一行和第numRows行，按照n间隔摆放
		//其他行，每次摆放两个字符，分别按照n-2*(i-1)和2*(i-1)间隔摆放
		if(numRows==1)  return s;
		string res;
		int n=2*numRows-2;
		for(int i=1;i<=numRows;i++)
		{
			int index=i-1;
			if(i==1||i==numRows)
			{
				while(index<s.size())
				{
					res.push_back(s[index]);
					index+=n;
				}
			}
			else
			{
				while(index<s.size())
				{
					res.push_back(s[index]);
					index+=n-2*(i-1);
					if(index<s.size())
						res.push_back(s[index]);
					index+=2*(i-1);
				}
			}
		}
		return res;
	}
};
class Solution1 {
public:
	string convert(string s, int numRows) {
		int len = s.size();  //字符串s的长度
		int m = numRows;  //输入的行号
		int n = 2 * m - 2;  //Z字循环的最小单元长度
		if (m == 1)  //输入的行号为1，直接返回s
			return s;
		int i, j, stride = 0;  //stride为字符串s的下标按Z字行依次摆放的字符位置
		string ret;
		//按Z字摆放，依次读取m行
		for (i = 1; i <= m; i++)
		{
			stride = i - 1;
			//对于每一行，依次读取摆放的字符（字符位于s的位置是s[stride]）添加到字符串ret的后面，stride下标小于字符串s的长度len
			while (stride < len)
			{
				//第一行和第m行字符摆放的规律是字符所在s的位置下标每隔n取一次摆放
				if (i == 1 || i == m)
				{
					ret.push_back(s[stride]);
					stride += n;
				}
				//其他行字符摆放的规律是字符所在s的位置下标每隔n-2*(i-1)和2*(i-1)取两次摆放，n是循环的最小单元长度，i是行号
				else
				{
					ret.push_back(s[stride]);
					stride += n - 2 * (i - 1);
					if (stride < len)
						ret.push_back(s[stride]);
					stride += 2 * (i - 1);
				}
			}
		}
		return ret;
	}
};
int main()
{
	Solution solute;
	string s = "LEETCODEISHIRING";
	int numRows = 4;
	cout << solute.convert(s, numRows) << endl;
	return 0;
}