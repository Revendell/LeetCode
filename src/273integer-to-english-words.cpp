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
        //1,234,567,891 英文计数都是3个一组分别是Thousand,Million,Billion
        while(num)
        {
            int temp=num%1000;
            string cur;
            //flag标记当前组是否有数字，如果没有数字就不用加Thousand,Million,Billion及空格
            //space标记百位是否有数字，如果没有，防止多余空格出现
            int flag=0,space=0;
            //提取百位转化为字符串
            if(temp/100)
            {
                flag=1;
                space=1;
                cur.append(number[temp/100-1]);
                cur.append(" ");
                cur.append(dict[0]);
                temp%=100;
            }
            //提取十位和个位转化为字符串
            //十位是1开头
            if(temp/10==1)
            {
                flag=1;
                if(space)
                    cur.append(" ");
                cur.append(teen[temp%10]);
            }
            //十位是2-9开头
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
            //十位是0，就只有个位
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
            //3个一组分别是Thousand,Million,Billion，以及该组是否有数字才加上
            if(i>0&&flag)
            {
                cur.append(" ");
                cur.append(dict[i]);
                cur.append(" ");
            }
            //当前组的字符串cur拼接到res
            res=cur+res;
            num/=1000;
            i++;
        }
        //去掉开头和末尾多余的空格
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
