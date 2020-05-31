#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		vector<string> res;
		res.push_back("1");
		int i, j, counter;
		//基本思想：循环29次，根据前一个序列值，遍历，得到下一个序列值，直到得到所有30个序列值，返回下标值对于序列值
		for (i = 1; i < 30; i++)
		{
			//计算当前下标的序列值
			string curent;
			//计数相同字符个数
			counter = 1;
			//遍历前一个序列的所有字符，如果当前字符与下一个字符相同counter++，反之则将counter和字符添加到curent
			for (j = 0; j < res[i - 1].size() - 1; j++)
			{
				if (res[i - 1][j] == res[i - 1][j + 1])
					counter++;
				else
				{
					curent += char(counter + '0');
					curent += res[i - 1][j];
					counter = 1;
				}
			}
			//对于最后字符的考虑：如果和前一个字符相同，因为counter已经++，所以直接写入curent；如果不同，counter已经变成1，所以也直接写入curent
			curent += char(counter + '0');
			curent += res[i - 1][res[i - 1].size() - 1];
			//当前下标的序列值计算得到加入容器res
			res.push_back(curent);
		}
		//最后返回所要求下标的序列值
		return res[n - 1];
	}
};
int main()
{
	Solution solute;
	int n = 3;
	cout << solute.countAndSay(n) << endl;
	return 0;
}