#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> cur;
		sort(candidates.begin(),candidates.end());
		//����˼�룺���õݹ���ݵ�˼�룬����condidates��ÿһ������������������Ƿ���ϵõ�targetֵ��������򱣴浽res���������ԭ��״̬��candidates����һ������
		//�������ݹ���ݲ�ͬ�ڽ������ݹ�������⣬����������ֻ��һ�ִ𰸽�����Եݹ麯���ķ���������bool�����������𰸶��ٸ���ȷ�����Է���ֵ������void
		//���õݹ麯����ÿ�δ�candidates��ȡֵ��������ȡֵ�����֮��Ϊtarget������һ�ֽ�
		Recursion(candidates, cur, target, 0);
		//�ȶ�res���������ظ�Ԫ�ؾ�����һ����
		sort(res.begin(), res.end());
		//uniqueֻ�ǰ��ظ���Ԫ�طŵ������ĺ��棨�����ĳ���û�䣬ֻ��Ԫ��˳��ı��ˣ�����������᷵��һ����������ָ����Щ�ظ�Ԫ�صĿ�ʼ���֡�Ȼ�����erase���ظ�Ԫ�صĿ�ʼ���ֵ�β������֮������Ԫ��ɾ��
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
	//���õݹ麯����candidates���ṩ���ֵ�������cur�ǵ�ǰ���ֵ���ϣ������Ϊtarget����һ�ֽⱣ�浽res��target��Ŀ��ֵ��n����Ϊÿ��Ԫ��ֻ����һ�Σ�����ÿ�δ�candidatesȡֵ�������ǰһ���±�֮��ȡֵ
	void Recursion(vector<int>& candidates, vector<int>& cur, int target, int n)
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
				Recursion(candidates, cur, target - candidates[i], i + 1);
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