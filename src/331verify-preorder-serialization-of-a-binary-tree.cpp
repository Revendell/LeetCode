#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
class Solution {
public:
    int infnum=9999999;
    bool isValidSerialization(string preorder) {
        //基本思想：递归，对preorder解码看能否构建出二叉树
        bool res;
        vector<int> nums;
        int i=0;
        while(i<preorder.size())
        {
            int start=i;
            while(i<preorder.size()&&preorder[i]!=',')
                i++;
            int num=preorder[start]=='#'?infnum:stoi(preorder.substr(start,i-start));
            nums.push_back(num);
            i++;
        }
        int pos=0;
        res=dfs(nums,pos);
        return res&&pos==nums.size()-1;
    }
    bool dfs(vector<int>& vec, int& pos)
	{
	    if(pos>=vec.size())  return false;
		if (vec[pos] == infnum)
			return true;
		else
		{
			bool flag1=dfs(vec, ++pos);
			bool flag2=dfs(vec, ++pos);
			if(flag1&&flag2)
                return true;
            else
                return false;
		}
	}
};
class Solution1 {
public:
    bool isValidSerialization(string preorder) {
        //基本思想：二叉树的性质，叶子节点数目=非叶子节点数目+1
        //这题和括号匹配有点像，标准二叉树#的总数=数字的总数+1，而且在遍历过程中有数字的总数>=#的总数，否则return false
        int leafnum=0,nleafnum=0;
        int i=0;
        while(i<preorder.size())
        {
            if(leafnum>nleafnum) return false;
            if(preorder[i]=='#')
                leafnum++;
            else
                nleafnum++;
            while(i<preorder.size()&&preorder[i]!=',')
                i++;
            i++;
        }
        return leafnum==nleafnum+1;
    }
};
int main()
{
    string preorder="9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution1 solute;
    cout<<solute.isValidSerialization(preorder)<<endl;
    return 0;
}
