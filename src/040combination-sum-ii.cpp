#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(auto num:candidates)
        {
            for(int j=target;j>=num;j--)
                dp[j]+=dp[j-num];
        }
        return dp[target];
    }
};
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> cur;
		sort(candidates.begin(),candidates.end());
		//基本思想：采用递归回溯的思想，对于condidates中每一个数字深度搜索，看是否组合得到target值，如果能则保存到res，否则回溯原来状态看candidates中下一个数字
		//这个问题递归回溯不同于解数独递归回溯问题，解数独问题只有一种答案结果所以递归函数的返回类型是bool，而这个问题答案多少个不确定所以返回值类型是void
		//调用递归函数，每次从candidates中取值，如果最后取值的组合之和为target，则是一种解
		Recursion(candidates, cur, target, 0);
		//先对res排序，这样重复元素就排在一起了
		sort(res.begin(), res.end());
		//unique只是把重复的元素放到容器的后面（容器的长度没变，只是元素顺序改变了），而它本身会返回一个迭代器，指向这些重复元素的开始部分。然后调用erase将重复元素的开始部分到尾迭代器之间所有元素删除
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
	//调用递归函数，candidates是提供数字的容器，cur是当前数字的组合，如果和为target则是一种解保存到res，target是目标值，n是因为每个元素只能用一次，所以每次从candidates取值完必须在前一个下标之后取值
	void Recursion(vector<int>& candidates, vector<int>& cur, int target, int n)
	{
		//target不断减去在candidates中的取值，如果最后target为0，则把取值组合cur是一种解保存到res
		if (target == 0)
		{
			res.push_back(cur);
			return;
		}
		//如果target小于0，说明当前取值组合超过target，不满足解，取值组合丢弃，返回
		else if (target < 0)
			return;
		//如果target大于0，说明当前取值组合仍然小于target，需要继续在candidates中取值往取值组合cur中添加值
		else
		{
			//循环从前一个下标n继续往后在candidates中找值，保存到cur，继续递归深度搜索
			for (int i = n; i < candidates.size(); i++)
			{
				cur.push_back(candidates[i]);
				Recursion(candidates, cur, target - candidates[i], i + 1);
				//上诉所取数字不知道能不能组合得到target，还要看其他数字组合情况，所以把上诉数字弹出，继续循环看下一个数字是否满足
				cur.pop_back();
			}
			//最后所有数字都组合了，是组合解的已经保存到res了，不是组合解的也没办法了，丢弃return返回
			return;
		}
	}
};
int main()
{
	Solution solute;
	vector<int> candidates = { 10,1,2,7,6,1,5 };
	int target = 8;
	vector<vector<int>> res = solute.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;

}