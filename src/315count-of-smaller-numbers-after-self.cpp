#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //����˼�룺��������ʱ�临�Ӷ�O(n^2)��ʱ���ռ临�Ӷ�O(n)
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
	int cnt;  //��¼��ǰ�ڵ���������ڵ����
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), cnt(0), left(NULL), right(NULL) {}
};
class Solution1 {
public:
    vector<int> res;
    vector<int> countSmaller(vector<int>& nums) {
        //����˼�룺��������������Ϊû��ƽ�����������O(n^2)��ʱ��ƽ��ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)
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
        //��node�ȵ�ǰ�ڵ�С��node�����뵱ǰ�ڵ��������
        //��Ϊcnt��¼��ǰ�ڵ���������ڵ����������root->cnt+=1
        if(root->val>=node->val)
        {
            root->cnt+=1;
            insertTreeNode(root->left,node,i);
        }
        else
        {
            //��node�ȵ�ǰ�ڵ�����nodeС�Ľڵ�=�ȵ�ǰ�ڵ�С�Ľڵ�(�������ڵ����)+��ǰ�ڵ㱾��
            //��Ϊcnt��¼��ǰ�ڵ���������ڵ����������res[i]+=root->cnt+1
            res[i]+=root->cnt+1;
            insertTreeNode(root->right,node,i);
        }
        return;
    }
};
class Solution2 {
public:
    vector<int> res;  //��󷵻صĽ��
    vector<int> index;  //��������
    vector<int> temp;  //�鲢�����и�������
    vector<int> countSmaller(vector<int>& nums) {
        //����˼�룺�鲢����ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)
        //�鲢����nums�Ӵ�С����������Ϊ���õ���res�Ƕ�Ӧnums�±������
        //����ʹ��index������������������nums���±���index�У�������������res���ı�nums
        //����ԭ���ϲ�������������nums1 = {8,5,2}	nums2 = {9,7,1}
        //i=0,j=0,nums1[0] < nums2[0]: temp = {9}, j++, ��ʱɶ��û����
        //i=0,j=1,nums1[0] > nums2[1]: temp = {9,8}, i++, ��ʱ���Լ���nums2�б�nums1�е�8С�����ָ����͵���nums2����������res[index[i]]+=right-j+1
        //����ֻҪnums[i]>nums[j]����ߵ�һ�������ұߵ�һ������ʱ����ô��ʱ�ұ�����������������һ����С��ͳ�Ʊ���ߵ�һ���������ĸ���res[index[i]]+=right-j+1
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
