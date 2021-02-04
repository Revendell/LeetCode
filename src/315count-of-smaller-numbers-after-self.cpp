#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //基本思想：插入排序，时间复杂度O(n^2)超时，空间复杂度O(n)
        vector<int> res;
        vector<int> counts;
        for(int i=nums.size()-1;i>=0;i--)
        {
            vector<int>::iterator iter=lower_bound(counts.begin(),counts.end(),nums[i]);
            res.push_back(iter-counts.begin());
            counts.insert(iter,nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
struct TreeNode {
	int val;
	int cnt;  //记录当前节点的左子树节点个数
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), cnt(0), left(NULL), right(NULL) {}
};
class Solution1 {
public:
    vector<int> res;
    vector<int> countSmaller(vector<int>& nums) {
        //基本思想：二叉搜索树，因为没有平衡操作最坏的情况O(n^2)超时，平均时间复杂度O(nlogn)，空间复杂度O(n)
        TreeNode* root=nullptr;
        res.resize(nums.size(),0);
        for(int i=int(nums.size())-1;i>=0;i--)
        {
            TreeNode* node=new TreeNode(nums[i]);
            insertTreeNode(root,node,i);
        }
        return res;
    }
    void insertTreeNode(TreeNode* &root,TreeNode* &node,int i)
    {
        if(root==nullptr)
        {
            root=node;
            return;
        }
        //当node比当前节点小，node将插入当前节点的左子树
        //因为cnt记录当前节点的左子树节点个数，所以root->cnt+=1
        if(root->val>=node->val)
        {
            root->cnt+=1;
            insertTreeNode(root->left,node,i);
        }
        else
        {
            //当node比当前节点大，则比node小的节点=比当前节点小的节点(左子树节点个数)+当前节点本身
            //因为cnt记录当前节点的左子树节点个数，所以res[i]+=root->cnt+1
            res[i]+=root->cnt+1;
            insertTreeNode(root->right,node,i);
        }
        return;
    }
};
class Solution2 {
public:
    vector<int> res;  //最后返回的结果
    vector<int> index;  //索引数组
    vector<int> temp;  //归并排序中辅助数组
    vector<int> countSmaller(vector<int>& nums) {
        //基本思想：归并排序，时间复杂度O(nlogn)，空间复杂度O(n)
        //归并排序将nums从大到小进行排序，因为最后得到的res是对应nums下标的数字
        //所以使用index索引数组排序结果保存nums的下标在index中，这样方便生成res不改变nums
        //具体原理：合并两个有序数组nums1 = {8,5,2}	nums2 = {9,7,1}
        //i=0,j=0,nums1[0] < nums2[0]: temp = {9}, j++, 此时啥都没发生
        //i=0,j=1,nums1[0] > nums2[1]: temp = {9,8}, i++, 此时可以计算nums2中比nums1中的8小的数字个数就等于nums2中所有数字res[index[i]]+=right-j+1
        //所以只要nums[i]>nums[j]即左边第一个数比右边第一个数大时，那么此时右边所有数都比左边这第一个数小，统计比左边第一个数的数的个数res[index[i]]+=right-j+1
        res.resize(nums.size(),0);
        temp.resize(nums.size(),0);
        index.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++)
            index[i]=i;
        mergeSort(nums,0,nums.size()-1);
        return res;
    }
    void mergeSort(vector<int>& nums,int left,int right)
    {
        if(left>=right)  return;
        int mid=(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        Merge(nums,left,mid,right);
    }
    void Merge(vector<int>& nums,int left,int mid,int right)
    {
        int i=left,j=mid+1,k=left;
        while(i<=mid&&j<=right)
        {
            if(nums[index[i]]>nums[index[j]])
            {
                res[index[i]]+=right-j+1;
                temp[k++]=index[i++];
            }
            else
                temp[k++]=index[j++];
        }
        while(i<=mid)
            temp[k++]=index[i++];
        while(j<=right)
            temp[k++]=index[j++];
        for(int i=left,k=left;i<=right;i++)
            index[i]=temp[k++];
    }
};
int main()
{
    vector<int> nums={5,2,6,1};
    Solution2 solute;
    vector<int> res=solute.countSmaller(nums);
    for_each(res.begin(),res.end(),[](const int &v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
