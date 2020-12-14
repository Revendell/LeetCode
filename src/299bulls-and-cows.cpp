
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        //基本思想：第一次遍历用multiset将secret每个出现过的数字保存起来，第二次遍历看guess中数字是否存在于multiset计算countB
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
        //基本思想：桶思想，bukets存储secret和guess中所有数字出现次数，如果出现在secret该数字出现次数++，如果出现在guess该数字出现次数--
        //当bukets[guess[i]-'0']>0说明该数字在secret中出现过，guess[i]又出现过，所以countB++
        //当bukets[secret[i]-'0']<0说明该数字在guess中出现过，secret[i]又出现过，所以countB++
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
                //bukets[guess[i]-'0']>0说明数字guess[i]在secret中出现过，guess[i]又出现过，所以countB++
                if(bukets[guess[i]-'0']>0)  countB++;
                //bukets[secret[i]-'0']<0说明数字secret[i]在guess中出现过，secret[i]又出现过，所以countB++
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
