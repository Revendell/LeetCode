#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		//����˼�룺̰�ķ�������һ����˾��ҵ���߼����鷳��û��̫����ϰ��ֵ����
		vector<string> res;
		//words_len��¼��ǰ��cur�����е��ʳ��ȣ�space_len��¼maxWidth�г�ȥ���ʳ��Ⱥ�ʣ�µĿո񳤶�
		//q��r������ʾÿ�������ʼ���Ҫ���Ŀո�����cnt��ʾcur�����е��ʵĳ�����ÿ���������ٿ�һ��
		int i, words_len, space_len, cnt, k, q, r;
		i = 0;
		//cur��ʾ�ڵ�ǰmaxWidth�����ﱣ�����󵥴���
		vector<string> cur;
		cnt = 0;
		//����words����ÿ������
		while (i < words.size())
		{
			//�����ǰcur�����е��ʳ��ȼ��ϵ�ǰwords[i]����cntС�ڵ���maxWidth������i����cur��
			if (cnt + words[i].size() <= maxWidth)
			{
				cnt += words[i].size();
				//ÿ�����ʼ����ٿ�һ��
				cnt++;
				cur.push_back(words[i]);
				//������������words[i]��words�����һ�����ʣ���ô����cntС��maxWidth��ҲҪ��cur�е��ʱ�����res
				if (i == words.size() - 1)
				{
					string str;
					for (k = 0; k < cur.size() - 1; k++)
					{
						str += cur[k];
						str.append(" ");
					}
					str += cur[cur.size() - 1];
					//����maxWidth��ȫ����ո�
					str.append(maxWidth - str.size(), ' ');
					res.push_back(str);
				}
			}
			//�����ǰcur�����е��ʳ��ȼ��ϵ�ǰwords[i]����cnt����maxWidth��cur�е���������Ҫ������res
			else
			{
				//����cur�����е��ʳ���words_len
				words_len = 0;
				for (k = 0; k < cur.size(); k++)
				{
					words_len += cur[k].size();
				}
				//������Ҫ���Ŀո���space_len
				space_len = maxWidth - words_len;
				string str;
				//���������cur��ֻ��һ������
				if (cur.size() == 1)
				{
					str += cur[0];
					//����maxWidth��ȫ����ո�
					str.append(maxWidth - str.size(), ' ');
					res.push_back(str);
					cur.clear();
					cnt = 0;
					continue;
				}
				//cur���ж�����ʣ�����ÿ�������ʼ����Ŀո���q���Լ�ǰr�����ʼ�����1���ո�ʹ��space_len���ո���ȷ����ڵ��ʼ�
				q = space_len / (cur.size() - 1);
				r = space_len % (cur.size() - 1);
				for (k = 0; k < cur.size() - 1; k++)
				{

					str += cur[k];
					str.append(q, ' ');
					if (r)
					{
						str.append(" ");
						r--;
					}
				}
				str.append(cur[cur.size() - 1]);
				res.push_back(str);
				cur.clear();
				cnt = 0;
				continue;
			}
			i++;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<string> words = {
		"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"
	};
	int maxWidth = 16;
	vector<string> res = solute.fullJustify(words, maxWidth);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}