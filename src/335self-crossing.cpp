#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    bool isSelfCrossing(vector<int>& x){
        //基本思想：数学，交叉只有三种可能
        for (int i = 3; i < x.size(); ++i){
            if(x[i]>=x[i-2]&&x[i-3]>=x[i-1]){
                return true;
            }
            if(i>=4&&x[i-1]==x[i-3]&&x[i]>=x[i-2]-x[i-4]){
                return true;
            }
            if(i>=5&&x[i-2]>=x[i-4]&&x[i-3]>=x[i-1]&&x[i-1]>=x[i-3]-x[i-5]&&x[i]>=x[i-2]-x[i-4]){
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution solute;
    vector<int> x{2,1,1,2};
    cout<<solute.isSelfCrossing(x)<<endl;
    return 0;
}
