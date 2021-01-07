#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        //基本思想：中心扩展法，一般回文串问题都可以通过中心扩展法或者动态规划法解决
        int len=s.size();
        int res=0;
        for(int center=0;center<len;center++)
        {
            //回文串长度为奇数
            int i=center,j=center;
            while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
			    res++;
				i--;
				j++;
			}
			//回文串长度为偶数
			i=center,j=center+1;
            while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
			    res++;
				i--;
				j++;
			}
        }
        return res;
    }
};
int main()
{
    string s="aaaaa";
    Solution solute;
    cout<<solute.countSubstrings(s)<<endl;
    return 0;
}
