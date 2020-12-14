#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        vector<string> dict={"Hundred","Thousand","Million","Billion"};
        vector<string> number={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        vector<string> teen={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> ty={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string res;
        int i=0;
        //1,234,567,891 Ӣ�ļ�������3��һ��ֱ���Thousand,Million,Billion
        while(num)
        {
            int temp=num%1000;
            string cur;
            //flag��ǵ�ǰ���Ƿ������֣����û�����־Ͳ��ü�Thousand,Million,Billion���ո�
            //space��ǰ�λ�Ƿ������֣����û�У���ֹ����ո����
            int flag=0,space=0;
            //��ȡ��λת��Ϊ�ַ���
            if(temp/100)
            {
                flag=1;
                space=1;
                cur.append(number[temp/100-1]);
                cur.append(" ");
                cur.append(dict[0]);
                temp%=100;
            }
            //��ȡʮλ�͸�λת��Ϊ�ַ���
            //ʮλ��1��ͷ
            if(temp/10==1)
            {
                flag=1;
                if(space)
                    cur.append(" ");
                cur.append(teen[temp%10]);
            }
            //ʮλ��2-9��ͷ
            else if(temp/10>1)
            {
                flag=1;
                if(space)
                    cur.append(" ");
                cur.append(ty[temp/10-2]);
                if(temp%10)
                {
                    cur.append(" ");
                    cur.append(number[temp%10-1]);
                }
            }
            //ʮλ��0����ֻ�и�λ
            else
            {
                if(temp%10)
                {
                    flag=1;
                    if(space)
                        cur.append(" ");
                    cur.append(number[temp%10-1]);
                }
            }
            //3��һ��ֱ���Thousand,Million,Billion���Լ������Ƿ������ֲż���
            if(i>0&&flag)
            {
                cur.append(" ");
                cur.append(dict[i]);
                cur.append(" ");
            }
            //��ǰ����ַ���curƴ�ӵ�res
            res=cur+res;
            num/=1000;
            i++;
        }
        //ȥ����ͷ��ĩβ����Ŀո�
        if(res[0]==' ')
            res=res.substr(1,res.size()-1);
        if(res.back()==' ')
            res=res.substr(0,res.size()-1);
        return res;
    }
};
int main()
{
    Solution solute;
    int num=1234567891;
    cout<<solute.numberToWords(num)<<endl;
    return 0;
}
