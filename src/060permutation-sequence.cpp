#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> res;
	int cnt = 0;
	string getPermutation(int n, int k) {
		//基本思想：递归求出n所有的前k个排列，然后返回res[k-1]，超时，很明显，我们只要求第k个，所以求的前k-1个没必要且浪费时间
		Recursion(n, k, "");
		return res[k-1];
	}
	void Recursion(int n, int k, string s)
	{
		if (cnt == k)
			return;
		if (s.size() == n)
		{
			res.push_back(s);
			cnt++;
			return;
		}
		for (int i = 1; i <= n; i++)
		{
			if (s.find(i + '0') == s.npos)
			{
				s.push_back(char(i + '0'));
				Recursion(n, k, s);
				s.pop_back();
			}
		}
		return;
	}
};
class Solution1 {
public:
	string getPermutation(int n, int k) {
		//基本思想：除法定位，vec保存数1-n，通过k每次定位i=k/(n-1)!，vec[i]保存到s，去除vec[i]，更新k-=k/fac(n-1)*fac(n-1)，使得k为接下来区间(n-1)!进行定位
		//例如：n=4，k=9，也是n=4，下标从0开始的第8个数，i=8/3!=1，定位到vec[1]，意思是总共4!=24个数，分成4份分别1234开头每份3!个，8/3!=1定位到第1份就是2开头vec[1]保存到s
		//然后k更新，去除前面的份的数量k-k/(n-1)!*(n-1)!=2，使得k变成从当前份3!个数，分成134开头每份2!个中继续定位第2个数，i=2/2!=1，定位到vec[1]保存到s
		int i;
		string s;
		vector<char> vec;
		for (i = 1; i <= n; i++)
			vec.push_back(char(i+'0'));
		//下标从0开始
		--k;
		while (n > 0)
		{
			//定位当前开头数字vec[i]
			i = k / fac(n - 1);
			s.push_back(vec[i]);
			vec.erase(vec.begin() + i);
			//更新当前k
			k = k - k / fac(n - 1) * fac(n - 1);
			n--;
		}
		return s;
	}
	//求n的阶乘n!
	int fac(int n)
	{
		int res = 1;
		while (n > 1)
		{
			res *= n;
			n--;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	int n = 9, k = 135401;
	cout << solute.getPermutation(n, k) << endl;
	return 0;
}