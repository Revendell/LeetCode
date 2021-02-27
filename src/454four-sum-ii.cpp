#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //基本思想：哈希表，典型的空间换时间，将四重循环转化为两重循环
        //用哈表表存储AB中元素之和出现的次数，如果CD中元素和的相反数在哈希表中出现，说明ABCD组合为0
        int res=0;
        unordered_map<int,int> Map;
        for(auto a:A)
        {
            for(auto b:B)
                Map[a+b]++;
        }
        for(auto c:C)
        {
            for(auto d:D)
                res+=Map[-(c+d)];
        }
        return res;
    }
};
int main()
{
    Solution solute;
    vector<int> A={1, 2},B = {-2,-1},C = {-1, 2},D = { 0, 2};
    cout<<solute.fourSumCount(A,B,C,D)<<endl;
    return 0;
}