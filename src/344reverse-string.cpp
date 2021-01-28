#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        //����˼�룺˫ָ�룬��algo�����reverse�㷨һ��
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
