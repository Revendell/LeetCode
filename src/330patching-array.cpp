#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    set<int> s;
    int minPatches(vector<int>& nums, int n) {
        //基本思想：暴力，超时，先递归将nums中能组成的数字保存至s，然后遍历1到n如果s中中缺少该数字，则res++并更新s的数字。
        int res=0;
        Recursion(nums,n,0,0);
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                cout<<i<<endl;
                res++;
                set<int> s1;
                for(auto iter=s.begin();iter!=s.end();iter++)
                {
                    if(*iter+i<=n)
                        s1.insert(*iter+i);
                }
                s.insert(s1.begin(),s1.end());
                s.insert(i);
            }
        }
        return res;
    }
    void Recursion(vector<int>& nums, int n,int cur,int pos)
    {
        if(cur<=n)
            s.insert(cur);
        else
            return;
        for(int i=pos;i<nums.size();i++)
        {
            Recursion(nums,n,cur+nums[i],i+1);
        }
        return;
    }
};
class Solution1 {
public:
    int minPatches(vector<int>& nums, int n) {
        //基本思想：贪心算法
        //当nums为空，求覆盖[1,n]的最小元素之和就是[1,2,4,8,16,32...]
        //当nums不为空，nums=[1,2,31]，n=1000，此时添加的元素就是[4,8,16]覆盖范围[1,32)，
        //此时因为有元素31所以之前的覆盖范围是[1,32)所以添加31后多[1,32)+31覆盖的范围就是[32,63)与之前的[1,32)并集就是[1,63)，就不需要添加元素32了
        //所以只要nums中的元素在最大覆盖范围[1,cur)以内即nums[i] <= cur，就可以对[1,cur)表示范围扩充至[1,cur+nums[i])；
        //否则就需要添加新元素，res++，添加的新元素值是cur，之前的表示范围[1,cur)添加cur之后多覆盖的范围是[1,cur)+cur=[cur+1,cur*2)和之前的范围[1,cur)并集得到最新覆盖范围[1,cur)U[cur+1,cur*2)Ucur本身=[1,cur*2)
        int res = 0, i = 0;  //res为最少添加的数字个数，i为nums的下标
		long long cur = 1;  //cur表示nums能表示的范围[1,cur)
		while (cur <= n) {
			if (i >= nums.size() || nums[i] > cur) {
				res++;
				cur *= 2;
			} else {
				cur += nums[i++];
			}
		}
		return res;
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums{1,2,31,33};
    int n=2147483647;
    cout<<solute.minPatches(nums,n)<<endl;
    return 0;
}
