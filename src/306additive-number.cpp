
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        //����˼�룺�ݹ飬�������ҵ�һ����num1=[0,i]����len1���ڶ�����num2=[i+1,j]����len2��Ȼ���ҵ�������num3=[j+1,k]�����num1+num2=num3��ݹ������Ѱ�������������Ƿ�����
        //�ݹ麯����������������һ����string num�޳���һ����֮������֣�len1�ǵڶ��������ȣ�len2�ǵ�����������
        //���ɣ�
        //1����Ϊnum1+num2=num3�����Ե����������ȴ��ڵ��ڵ�һ��������Ҳ���ڵ��ڵڶ���������
        //2��ÿ�����ĳ���С��11λ����Ϊint���10λ
        //3������0������֧������0��ͷ�����֣�ע���ų������
        if (num.size() < 3)  return false;
        for (int i = 0; i < num.size() / 2 && i + 1 <= 11; i++)
        {
            if (num[0] == '0' && i != 0)  break;
            long long num1 = stoll(num.substr(0, i + 1));
            for (int j = i + 1; i + 1 <= num.size() - j && j - i <= num.size() - j && j - i <= 11; j++)
            {
                if (num[i + 1] == '0' && j != i + 1)  break;
                long long num2 = stoll(num.substr(i + 1, j - i));
                for (int k = j + 1; k < num.size() && k - j <= 11; k++)
                {
                    if (num[j + 1] == '0' && k != j + 1)  break;
                    long long num3 = stoll(num.substr(j + 1, k - j));
                    if (num1 + num2 == num3)
                    {
                        if (k == num.size() - 1)
                            return true;
                        int len1 = j - i, len2 = k - j;
                        if (Recursion(num.substr(i + 1, num.size() - i), len1, len2))
                            return true;
                    }
                }
            }
        }
        return false;
    }
    bool Recursion(string num, int len1, int len2)
    {
        long long num1 = stoll(num.substr(0, len1));
        long long num2 = stoll(num.substr(len1, len2));
        for (int k = len1 + len2; k < num.size() && k - len1 - len2 + 1 <= 11; k++)
        {
            if (num[len1 + len2] == '0' && k != len1 + len2)  break;
            long long num3 = stoll(num.substr(len1 + len2, k - len1 - len2 + 1));
            if (num1 + num2 == num3)
            {
                if (k == num.size() - 1)
                    return true;
                if (Recursion(num.substr(len1, num.size() - len1), len2, k - len1 - len2 + 1))
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution solute;
    string num = "192019223842";
    cout << solute.isAdditiveNumber(num) << endl;
    return 0;
}
