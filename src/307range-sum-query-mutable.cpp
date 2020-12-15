#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size()==0)  return;
        sum.resize(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            sum[i]=sum[i-1]+nums[i];
    }

    void update(int i, int val) {
        int diffval=i==0?val-sum[i]:val-(sum[i]-sum[i-1]);
        if(diffval==0)  return;
        for(int j=i;j<sum.size();j++)
            sum[j]+=diffval;
    }

    int sumRange(int i, int j) {
        return i==0?sum[j]:sum[j]-sum[i-1];
    }
private:
    vector<int> sum;
};
class NumArray1 {
public:
    NumArray1(vector<int>& nums) {
        //建立线段树：将nums值放入tree最后面作为叶子节点，然后不断更新父节点等于子节点值之和tree[i]=tree[2*i]+tree[2*i+1]
        if(nums.size()==0)  return;
        n=nums.size();
        tree.resize(2*n);
        for(int i=0,j=n;i<nums.size();i++,j++)
            tree[j]=nums[i];
        for(int i=n-1;i>0;i--)
            tree[i]=tree[2*i]+tree[2*i+1];
    }

    void update(int i, int val) {
        //更新线段树：将叶子节点及其往上的节点直到根节点都要更新，时间复杂度O(logn)
        int pos=i+n;
        int diffval=val-tree[pos];
        if(diffval==0)  return;
        while(pos>0)
        {
            tree[pos]+=diffval;
            pos/=2;
        }
    }

    int sumRange(int i, int j) {
        //查找检索线段树：如果左边界是右子节点，将该节点加入到sum否则往上查找其父节点值，
        //如果右边界是左子节点，将该节点加入到sum否则往上查找其父节点值，这样不断往上查找直到左右边界相遇，时间复杂度O(logn)
        int sum=0;
        i+=n;
        j+=n;
        while(i<=j)
        {
            //如果左边界是右子节点，将该节点加入到sum这样避免误加左子节点值
            if(i%2==1)
            {
                sum+=tree[i];
                i++;
            }
            //如果右边界是左子节点，将该节点加入到sum这样避免误加右子节点值
            if(j%2==0)
            {
                sum+=tree[j];
                j--;
            }
            //之后就更新边界到其父节点通过加其父节点值就加了两个子节点值，这样时间复杂度只有O(logn)
            i/=2;
            j/=2;
        }
        return sum;
    }
private:
    vector<int> tree;
    int n;
};
int main()
{
    vector<int> nums={1,3,5};
    NumArray1* obj = new NumArray1(nums);
    cout<<obj->sumRange(0,2)<<endl;
    obj->update(1,2);
    cout<<obj->sumRange(0,2)<<endl;
    return 0;
}
