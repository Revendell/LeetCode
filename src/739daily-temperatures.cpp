
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //基本思想：单调栈，递减栈，后入栈的元素总比栈顶元素小，栈记录的是 T 的下标
        //若当前元素<栈顶元素：入栈，若当前元素>栈顶元素：弹出栈顶元素，记录两者下标差值即为所求天数
        vector<int> res(T.size(),0);
        stack<int> st;
        for(int i=0;i<T.size();i++)
        {
            while(!st.empty()&&T[st.top()]<T[i])
            {
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
int main()
{
    vector<int> T={73, 74, 75, 71, 69, 72, 76, 73};
    Solution solute;
    vector<int> res=solute.dailyTemperatures(T);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
