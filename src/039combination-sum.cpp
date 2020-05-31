#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> cur;
		//����˼�룺���õݹ���ݵ�˼�룬����condidates��ÿһ������������������Ƿ���ϵõ�targetֵ��������򱣴浽res���������ԭ��״̬��candidates����һ������
		//�������ݹ���ݲ�ͬ�ڽ������ݹ�������⣬����������ֻ��һ�ִ𰸽�����Եݹ麯���ķ���������bool�����������𰸶��ٸ���ȷ�����Է���ֵ������void
		//���õݹ麯����ÿ�δ�candidates��ȡֵ��������ȡֵ�����֮��Ϊtarget������һ�ֽ�
		Recursion(candidates, cur,target,0);
		return res;
	}
	//���õݹ麯����candidates���ṩ���ֵ�������cur�ǵ�ǰ���ֵ���ϣ������Ϊtarget����һ�ֽⱣ�浽res��target��Ŀ��ֵ��n��Ϊ�˷�ֹ�ظ��⣬ÿ�δ�candidatesȡֵ������ǰһ���±�֮��ȡֵ�������±꣬���ܷ�ֹ�ظ���
	void Recursion(vector<int>& candidates, vector<int>& cur, int target,int n)
	{
		//target���ϼ�ȥ��candidates�е�ȡֵ��������targetΪ0�����ȡֵ���cur��һ�ֽⱣ�浽res
		if (target == 0)
		{
			res.push_back(cur);
			return;
		}
		//���targetС��0��˵����ǰȡֵ��ϳ���target��������⣬ȡֵ��϶���������
		else if (target < 0)
			return;
		//���target����0��˵����ǰȡֵ�����ȻС��target����Ҫ������candidates��ȡֵ��ȡֵ���cur�����ֵ
		else
		{
			//ѭ����ǰһ���±�n����������candidates����ֵ�����浽cur�������ݹ��������
			for (int i = n; i < candidates.size(); i++)
			{
				cur.push_back(candidates[i]);
				Recursion(candidates, cur, target - candidates[i], i);
				//������ȡ���ֲ�֪���ܲ�����ϵõ�target����Ҫ���������������������԰��������ֵ���������ѭ������һ�������Ƿ�����
				cur.pop_back();
			}
			//����������ֶ�����ˣ�����Ͻ���Ѿ����浽res�ˣ�������Ͻ��Ҳû�취�ˣ�����return����
			return;
		}	
	}
};
int main()
{
	Solution solute;
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector<vector<int>> res = solute.combinationSum(candidates, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}