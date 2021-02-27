#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        //基本思想：数字与字符串的相互转换，分别是std::to_string和std::stoi/stol/stoll
        vector<string> s{"Fizz","Buzz","FizzBuzz"};
        vector<string> res;
        for(int i=1;i<=n;i++)
        {
            if(i%15==0)
                res.push_back(s[2]);
            else if(i%5==0)
                res.push_back(s[1]);
            else if(i%3==0)
                res.push_back(s[0]);
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
int main()
{
    Solution solute;
    int n=15;
    vector<string> res=solute.fizzBuzz(n);
    for_each(res.begin(),res.end(),[](string v){cout<<v<<endl;});
    return 0;
}