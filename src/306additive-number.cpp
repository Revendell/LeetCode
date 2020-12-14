
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        //基本思想：递归，主函数找第一个数num1=[0,i]长度len1，第二个数num2=[i+1,j]长度len2，然后找第三个数num3=[j+1,k]，如果num1+num2=num3则递归继续搜寻接下来的数字是否满足
        //递归函数有三个参数，第一个是string num剔除第一个数之后的数字，len1是第二个数长度，len2是第三个数长度
        //技巧：
        //1、因为num1+num2=num3，所以第三个数长度大于等于第一个数长度也大于等于第二个数长度
        //2、每个数的长度小于11位，因为int最大10位
        //3、除了0本身，不支持其他0开头的数字，注意排除此情况
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
