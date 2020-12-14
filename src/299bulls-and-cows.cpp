
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        //����˼�룺��һ�α�����multiset��secretÿ�����ֹ������ֱ����������ڶ��α�����guess�������Ƿ������multiset����countB
        string res;
        int countA=0;
        int countB=0;
        multiset<char> Set;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                countA++;
            else
                Set.insert(secret[i]);
        }
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                continue;
            multiset<char>::iterator pos = Set.find(guess[i]);
            if(pos!=Set.end())
            {
                countB++;
                Set.erase(pos);
            }
        }
        res+=to_string(countA);
        res.push_back('A');
        res+=to_string(countB);
        res.push_back('B');
        return res;
    }
};
class Solution1 {
public:
    string getHint(string secret, string guess) {
        //����˼�룺Ͱ˼�룬bukets�洢secret��guess���������ֳ��ִ��������������secret�����ֳ��ִ���++�����������guess�����ֳ��ִ���--
        //��bukets[guess[i]-'0']>0˵����������secret�г��ֹ���guess[i]�ֳ��ֹ�������countB++
        //��bukets[secret[i]-'0']<0˵����������guess�г��ֹ���secret[i]�ֳ��ֹ�������countB++
        string res;
        int countA=0;
        int countB=0;
        int[10] bukets={0};
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                countA++;
            else
            {
                //bukets[guess[i]-'0']>0˵������guess[i]��secret�г��ֹ���guess[i]�ֳ��ֹ�������countB++
                if(bukets[guess[i]-'0']>0)  countB++;
                //bukets[secret[i]-'0']<0˵������secret[i]��guess�г��ֹ���secret[i]�ֳ��ֹ�������countB++
                if(bukets[secret[i]-'0']<0)  countB++;
                bukets[guess[i]-'0']--;
                bukets[secret[i]-'0']++;
            }
        }
        res+=to_string(countA);
        res.push_back('A');
        res+=to_string(countB);
        res.push_back('B');
        return res;
    }
};
int main()
{
    Solution solute;
    string secret="1807";
    string guess="7810";
    cout<<solute.getHint(secret,guess)<<endl;
    return 0;
}
