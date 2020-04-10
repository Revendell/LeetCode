#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> res;
	int cnt = 0;
	string getPermutation(int n, int k) {
		//����˼�룺�ݹ����n���е�ǰk�����У�Ȼ�󷵻�res[k-1]����ʱ�������ԣ�����ֻҪ���k�����������ǰk-1��û��Ҫ���˷�ʱ��
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
		//����˼�룺������λ��vec������1-n��ͨ��kÿ�ζ�λi=k/(n-1)!��vec[i]���浽s��ȥ��vec[i]������k-=k/fac(n-1)*fac(n-1)��ʹ��kΪ����������(n-1)!���ж�λ
		//���磺n=4��k=9��Ҳ��n=4���±��0��ʼ�ĵ�8������i=8/3!=1����λ��vec[1]����˼���ܹ�4!=24�������ֳ�4�ݷֱ�1234��ͷÿ��3!����8/3!=1��λ����1�ݾ���2��ͷvec[1]���浽s
		//Ȼ��k���£�ȥ��ǰ��ķݵ�����k-k/(n-1)!*(n-1)!=2��ʹ��k��ɴӵ�ǰ��3!�������ֳ�134��ͷÿ��2!���м�����λ��2������i=2/2!=1����λ��vec[1]���浽s
		int i;
		string s;
		vector<char> vec;
		for (i = 1; i <= n; i++)
			vec.push_back(char(i+'0'));
		//�±��0��ʼ
		--k;
		while (n > 0)
		{
			//��λ��ǰ��ͷ����vec[i]
			i = k / fac(n - 1);
			s.push_back(vec[i]);
			vec.erase(vec.begin() + i);
			//���µ�ǰk
			k = k - k / fac(n - 1) * fac(n - 1);
			n--;
		}
		return s;
	}
	//��n�Ľ׳�n!
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