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
		//����˼�룺ѭ��29�Σ�����ǰһ������ֵ���������õ���һ������ֵ��ֱ���õ�����30������ֵ�������±�ֵ��������ֵ
		for (i = 1; i < 30; i++)
		{
			//���㵱ǰ�±������ֵ
			string curent;
			//������ͬ�ַ�����
			counter = 1;
			//����ǰһ�����е������ַ��������ǰ�ַ�����һ���ַ���ͬcounter++����֮��counter���ַ���ӵ�curent
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
			//��������ַ��Ŀ��ǣ������ǰһ���ַ���ͬ����Ϊcounter�Ѿ�++������ֱ��д��curent�������ͬ��counter�Ѿ����1������Ҳֱ��д��curent
			curent += char(counter + '0');
			curent += res[i - 1][res[i - 1].size() - 1];
			//��ǰ�±������ֵ����õ���������res
			res.push_back(curent);
		}
		//��󷵻���Ҫ���±������ֵ
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