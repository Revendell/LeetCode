#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> addOperators(string num, int target) {
        //����˼�룺�ݹ���ݣ������������еĿ����ԣ�ʱ�临�Ӷ�O(4^N)
        string s="";
        Recursion(num,target,0,0,1,s);
        return res;
    }
    void Recursion(string& num,int target,int index,long cur,long prenum,string& s)
    {
        //index��ʾ��ǰ����num���±꣬cur��ʾ��ǰ��������s��ʾ������������ַ�����prenum��ʾ��һ���Ĳ�����
        if(index==num.size())
        {
            if(cur==target)
                res.push_back(s);
            return;
        }
        string temp;
        //�Ե�ǰ�±�indexΪ��㣬������һ�������������п������
	    for (int i = index; i < num.size(); i++)
        {
		    string val = num.substr(index, i - index + 1);
		    long n = stol(val);  //valת��Ϊ����
            //��һ�����֣�����Ҫ�ӷ���
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
			    // *���˷������ʸ��ڼӼ������Խ���һ���Ĳ�������ȥ�����¼���
                temp=s+"*"+val;
			    Recursion(num,target,i+1,cur-prenum+prenum*n,prenum*n,temp);
		    }
		    //��0��ͷ������ֻ����0�Լ���һ��������������������
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
