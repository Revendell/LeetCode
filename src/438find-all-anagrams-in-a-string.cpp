#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //����˼�룺��������+��ϣ��HashMap
        //�ù�ϣ���ʾ���ڴ�СΪp.size��s�ַ��������Map1==Map2˵���ô�������������res.push_back(i)
        if(s.size()==0||s.size()<p.size()) return {};
        vector<int> Map1(26,0);
        vector<int> Map2(26,0);
        vector<int> res;
        //��ʼ��Map1ӳ��p���ַ���Ӧ����
        for(auto ch:p)
            Map1[ch-'a']++;
        //��ʼ��Map2ӳ�䴰��Ϊp.size��s���ַ���Ӧ����
        for(int i=0;i<p.size();i++)
            Map2[s[i]-'a']++;
        //����������ʼλ�ô�0��s.size()-p.size()�����Map1==Map2˵���ô�������������res.push_back(i)
        for(int i=0;i<=s.size()-p.size();i++)
        {
            if(Map1==Map2)
                res.push_back(i);
            if(i+p.size()==s.size()) break;
            //���´������ַ�ӳ�䣬����һ�����ڵ��ַ���Ӧ����
            Map2[s[i]-'a']--;
            Map2[s[i+p.size()]-'a']++;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    string s="aaaaaaaaaa";
    string p="aaaaaaaaaaaaa";
    vector<int> res=solute.findAnagrams(s,p);
    for_each(res.begin(),res.end(),[](int v){cout<<v<<endl;});
    return 0;
}
