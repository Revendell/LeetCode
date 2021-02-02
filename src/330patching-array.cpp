#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    set<int> s;
    int minPatches(vector<int>& nums, int n) {
        //����˼�룺��������ʱ���ȵݹ齫nums������ɵ����ֱ�����s��Ȼ�����1��n���s����ȱ�ٸ����֣���res++������s�����֡�
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
        //����˼�룺̰���㷨
        //��numsΪ�գ��󸲸�[1,n]����СԪ��֮�;���[1,2,4,8,16,32...]
        //��nums��Ϊ�գ�nums=[1,2,31]��n=1000����ʱ��ӵ�Ԫ�ؾ���[4,8,16]���Ƿ�Χ[1,32)��
        //��ʱ��Ϊ��Ԫ��31����֮ǰ�ĸ��Ƿ�Χ��[1,32)�������31���[1,32)+31���ǵķ�Χ����[32,63)��֮ǰ��[1,32)��������[1,63)���Ͳ���Ҫ���Ԫ��32��
        //����ֻҪnums�е�Ԫ������󸲸Ƿ�Χ[1,cur)���ڼ�nums[i] <= cur���Ϳ��Զ�[1,cur)��ʾ��Χ������[1,cur+nums[i])��
        //�������Ҫ�����Ԫ�أ�res++����ӵ���Ԫ��ֵ��cur��֮ǰ�ı�ʾ��Χ[1,cur)���cur֮��า�ǵķ�Χ��[1,cur)+cur=[cur+1,cur*2)��֮ǰ�ķ�Χ[1,cur)�����õ����¸��Ƿ�Χ[1,cur)U[cur+1,cur*2)Ucur����=[1,cur*2)
        int res = 0, i = 0;  //resΪ������ӵ����ָ�����iΪnums���±�
		long long cur = 1;  //cur��ʾnums�ܱ�ʾ�ķ�Χ[1,cur)
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
