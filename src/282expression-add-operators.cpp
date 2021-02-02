#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> addOperators(string num, int target) {
        //基本思想：递归回溯，暴力遍历所有的可能性，时间复杂度O(4^N)
        string s="";
        Recursion(num,target,0,0,1,s);
        return res;
    }
    void Recursion(string& num,int target,int index,long cur,long prenum,string& s)
    {
        //index表示当前遍历num的下标，cur表示当前计算结果，s表示加上运算符的字符串，prenum表示上一步的操作数
        if(index==num.size())
        {
            if(cur==target)
                res.push_back(s);
            return;
        }
        string temp;
        //以当前下标index为起点，遍历下一个操作数的所有可能情况
	    for (int i = index; i < num.size(); i++)
        {
		    string val = num.substr(index, i - index + 1);
		    long n = stol(val);  //val转化为数字
            //第一个数字，不需要加符号
		    if (index == 0) {
                temp=s+val;
			    Recursion(num,target,i+1,n,n,temp);
		    } else {
			    // +
			    temp=s+"+"+val;
			    Recursion(num,target,i+1,cur+n,n,temp);
			    // -
			    temp=s+"-"+val;
                Recursion(num,target,i+1,cur-n,-n,temp);
			    // *，乘法分配率高于加减，所以将上一步的操作数减去，重新计算
                temp=s+"*"+val;
			    Recursion(num,target,i+1,cur-prenum+prenum*n,prenum*n,temp);
		    }
		    //以0开头的数字只能是0自己这一种情况，其他情况不允许
		    if (val=="0") return;
        }
        return;
    }
};
int main()
{
    Solution solute;
    string num="232";
    int target=8;
    vector<string> res=solute.addOperators(num,target);
    for_each(res.begin(),res.end(),[](string s){cout<<s<<endl;});
    return 0;
}
