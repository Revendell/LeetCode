#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        //����˼�룺��ѧ����i�����ݵķ�ת�����������������ӣ�����1��i���ĸ�����
        //һ��ʼ��״̬����ģ�ֻ�з�ת�����βŻ������ģ�����ֻ�����Ӹ���Ϊ�����ĵ�����ŲŻ�����
        //ֻ��ƽ������������Ϊ����������6=1*6,2*3�����ǵ��������ǳɶԳ��ֵģ���4=1*4,2*2��ֻ��ƽ������ƽ�������ӻ�ֻ����1�Σ���
        //�������մ𰸵���n���ڣ�����n��1����ƽ����������ֻҪ����sqrt(n)����
        return static_cast<int>(sqrt(n));
    }
};
int main()
{
    Solution solute;
    int n=231728;
    cout<<solute.bulbSwitch(n)<<endl;
    return 0;
}
