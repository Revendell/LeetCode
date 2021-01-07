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
        //����˼�룺������չ����һ����Ĵ����ⶼ����ͨ��������չ�����߶�̬�滮�����
        int len=s.size();
        int res=0;
        for(int center=0;center<len;center++)
        {
            //���Ĵ�����Ϊ����
            int i=center,j=center;
            while (i >= 0 && j <= (len - 1) && s[i] == s[j])
			{
			    res++;
				i--;
				j++;
			}
			//���Ĵ�����Ϊż��
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
