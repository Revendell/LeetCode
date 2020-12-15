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
        //�����߶�������numsֵ����tree�������ΪҶ�ӽڵ㣬Ȼ�󲻶ϸ��¸��ڵ�����ӽڵ�ֵ֮��tree[i]=tree[2*i]+tree[2*i+1]
        if(nums.size()==0)  return;
        n=nums.size();
        tree.resize(2*n);
        for(int i=0,j=n;i<nums.size();i++,j++)
            tree[j]=nums[i];
        for(int i=n-1;i>0;i--)
            tree[i]=tree[2*i]+tree[2*i+1];
    }

    void update(int i, int val) {
        //�����߶�������Ҷ�ӽڵ㼰�����ϵĽڵ�ֱ�����ڵ㶼Ҫ���£�ʱ�临�Ӷ�O(logn)
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
        //���Ҽ����߶����������߽������ӽڵ㣬���ýڵ���뵽sum�������ϲ����丸�ڵ�ֵ��
        //����ұ߽������ӽڵ㣬���ýڵ���뵽sum�������ϲ����丸�ڵ�ֵ�������������ϲ���ֱ�����ұ߽�������ʱ�临�Ӷ�O(logn)
        int sum=0;
        i+=n;
        j+=n;
        while(i<=j)
        {
            //�����߽������ӽڵ㣬���ýڵ���뵽sum��������������ӽڵ�ֵ
            if(i%2==1)
            {
                sum+=tree[i];
                i++;
            }
            //����ұ߽������ӽڵ㣬���ýڵ���뵽sum��������������ӽڵ�ֵ
            if(j%2==0)
            {
                sum+=tree[j];
                j--;
            }
            //֮��͸��±߽絽�丸�ڵ�ͨ�����丸�ڵ�ֵ�ͼ��������ӽڵ�ֵ������ʱ�临�Ӷ�ֻ��O(logn)
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
