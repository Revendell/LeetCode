#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		//����˼�룺ʹ��HashMap��HashMap��¼��ǰ������Ԫ�ش���res�е��±꣬������������������res���±�cnt++
		//ѭ������strs������Ԫ�أ���ÿ��Ԫ��str�����temp���Ƿ����HashMap��
		//��������ڼ���res��HashMap�У�HashMap[temp]=cnt��cnt++��cnt��¼�����Ԫ��λ��res�е�λ���±�
		//������ھ���ͨ��cnt�ܿ��ҵ���Ԫ�ط���res��λ��
		vector<vector<string>> res;
		int cnt = 0;
		string temp;
		map<string, int> HashMap;
		//ѭ������strs������Ԫ��
		for (auto& str : strs)
		{
			temp = str;
			sort(temp.begin(), temp.end());
			//�������HashMap�о���ͨ��cnt�ܿ��ҵ���Ԫ�ط���res��λ��
			if (HashMap.find(temp) != HashMap.end())
			{
				res[HashMap[temp]].push_back(str);
			}
			//���������HashMap�������res��HashMap�У�HashMap[temp]=cnt��cnt++
			else
			{
				res.push_back({ str });
				HashMap[temp] = cnt++;
			}				
		}
		return res;
	}
};
int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution solute;
	vector<vector<string>> res;
	res = solute.groupAnagrams(strs);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}