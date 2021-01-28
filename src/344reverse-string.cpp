#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        //基本思想：双指针，和algo里面的reverse算法一致
        if(s.size()==0)  return;
        int left=0,right=s.size()-1;
        while(left<right)
            swap(s[left++],s[right--]);
        return;
    }
};
int main()
{
    Solution solute;
    vector<char> s{'a','b','c','d'};
    solute.reverseString(s);
    for_each(s.begin(),s.end(),[](char c){cout<<c<<endl;});
    return 0;
}
