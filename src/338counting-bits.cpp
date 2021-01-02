#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        //����˼�룺�ҹ��ɷ��֣�0��1�ı���λ��+1,2-3��0-1��Ӧ����λ��+1��4-7��0-3��Ӧ����λ��+1��8-15��0-7��Ӧ����λ��+1
        //���Ե�ǰ����j�ı���λ��res[j]=res[j-i]+1;����i�Ǳ�jС�����2�Ĵ���
        vector<int> res(num+1,0);
        int i=1;
        while(true)
        {
            for(int j=i;j<i<<1;j++)
            {
                if(j==num+1)
                    return res;
                res[j]=res[j-i]+1;
            }
            i=i<<1;
        }
    }
};
class Solution1 {
public:
    vector<int> countBits(int num) {
        //����˼�룺λ���㶯̬�滮,i&(i-1)����ȥ��i���ұߵ�һ��1������У������i&(i-1���Ǳ�iС�ģ�
        //����i&(i-1)��1�ĸ����Ѿ���ǰ������ˣ�����i��1�ĸ�������i&(i-1)��1�ĸ�������1
        vector<int> res(num+1, 0);
        for(int i = 1; i <= num; ++ i) {
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};
int main()
{
    Solution solute;
    int num=3652;
    vector<int> res=solute.countBits(num);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<endl;});
    return 0;
}
