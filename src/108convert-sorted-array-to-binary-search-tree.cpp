#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PreOrderTraverse(TreeNode* T)
{
	if (T == NULL)
		return;
	cout << T->val << " ";
	PreOrderTraverse(T->left);
	PreOrderTraverse(T->right);

}
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		//����˼�룺�ݹ飬���ҵȷֽ��������������м�ڵ���Ϊ�������ڵ㣬���ϵݹ�ι��̣�С���ɴ�nums���ü�С�ڴ�����
		TreeNode* root = NULL;
		Recursion(nums, 0, nums.size() - 1, &root);
		return root;
	}
	void Recursion(vector<int> &nums,int low,int high, TreeNode** root)
	{
		if (low > high)
			return;
		int mid = (low + high) / 2;
		(*root) = new TreeNode(nums[mid]);
		Recursion(nums, low, mid - 1, &(*root)->left);
		Recursion(nums, mid + 1, high, &(*root)->right);
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3 };
	TreeNode* root = solute.sortedArrayToBST(nums);
	PreOrderTraverse(root);
	return 0;
}