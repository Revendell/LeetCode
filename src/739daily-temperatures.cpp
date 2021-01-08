
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
        //����˼�룺����ջ���ݼ�ջ������ջ��Ԫ���ܱ�ջ��Ԫ��С��ջ��¼���� T ���±�
        //����ǰԪ��<ջ��Ԫ�أ���ջ������ǰԪ��>ջ��Ԫ�أ�����ջ��Ԫ�أ���¼�����±��ֵ��Ϊ��������
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
