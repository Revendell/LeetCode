#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        //基本思想：双指针，和algo里面的reverse算法一致
        int left=0,right=s.size()-1;
        set<char> match={'a','o','e','i','u','A','O','E','I','U'};
        while(left<right)
        {
            while(left<s.size()&&match.find(s[left])==match.end())
                left++;
            while(right>=0&&match.find(s[right])==match.end())
                right--;
            if(left>=right)
                return s;
            swap(s[left++],s[right--]);
        }
        return s;
    }
};
int main()
{
    Solution solute;
    string s="leetcode";
    cout<<solute.reverseVowels(s)<<endl;
    return 0;
}
