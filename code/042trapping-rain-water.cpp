#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		//����˼�룺��������ֱ���뷨���ҵ����д���ˮ�İ��ۣ���¼�����ߵ�ǽleft��right�����۴�ˮ��Ϊmin(height[left],height[right])*(right-left-1)��ȥleft��right֮�������ǽռ�ռ�
		int left, right, i, j, k, res = 0, cur;
		//Ԫ�����������Ӳ�����ˮ������0
		if (height.size() < 3)
			return 0;
		i = 0;
		//��һ��ѭ��iȷ��leftλ�ð��۵����
		while (i < height.size() - 2)
		{
			//�ҵ����۵���ߣ�����������ǲ�Ϊ0�Ұ��۵���߽����������߷���治��ˮ
			if (height[i] == 0 || height[i + 1] >= height[i])
			{
				i++;
				continue;
			}
			left = i;
			right = i + 2;
			//�ڶ���ѭ��jȷ��rightλ�ð��۵��ұ�
			for (j = i + 2; j < height.size(); j++)
			{
				//�����ʱj�߶ȴ��ڰ������left�ĸ߶ȣ�ֱ��ȷ��jΪ�ұ߽磬�Ϳ��Դ�ˮ���������Ҹ��ߵĸ߶���
				if (height[j] >= height[left])
				{
					right = j;
					break;
				}
				//�����ʱj�߶�С�ڰ������left�ĸ߶ȣ��Ǿ�Ҫ�����ҵ��ұ���ߵĸ߶ȴ�ˮ
				else
				{
					if (height[j] >= height[right])
					{
						right = j;
					}
				}
			}
			//����ȷ���İ������left���ұ�right����Ҫȷ����ʵ��left����Ϊ����3,2,0,1�����������ʵ����߽�Ӧ����left
			k = left + 1;
			while (k < right)
			{
				//������left���ұ�right�ߣ�һֱ�ҵ���ӽ��ұ�right�߶ȵ����left������ʵ��left���������Ӿ���2
				if (height[k] > height[right])
				{
					left = k;
					k++;
				}
				//������left���ұ�right�Ͳ��õ����������⣬left������ʵ��left
				else
					break;
			}
			//�������ȷ���˰��۵�left��right�����԰��۴�ˮ���Ϊmin(height[left],height[right])*(right-left-1)��ȥleft��right֮���ǽռ���
			cur = min(height[left], height[right]) * (right - left - 1);
			for (k = left + 1; k < right; k++)
				cur -= height[k];
			//���ð�������������������res
			res += cur;
			//��һ�����۵���ߴ���һ�����۵��ұ߿�ʼ
			i = right;;
		}
		return res;
	}
};
class Solution1 {
public:
	int trap(vector<int>& height) {
		//����˼�룺����������������ÿһ�е�ˮ�Ậ����ˮ��ֻ��Ҫ��ע��ǰ�У��Լ������ߵ�ǽ���ұ���ߵ�ǽ�͹���
		//����ϰ���ǽ�ĸ߶ȴ��ڵ�ǰ�е�ǽ�ĸ߶ȣ���ǰ�к�ˮ�����ڽϰ���ǽ�ĸ߶ȼ�ȥ��ǰ�еĸ߶�
		//����ϰ���ǽ�ĸ߶�С�ڵ�ǰ�е�ǽ�ĸ߶ȣ���ǰ�в��ᴢˮ
		//����ϰ���ǽ�ĸ߶ȵ��ڵ�ǰ�е�ǽ�ĸ߶ȣ���ǰ��Ҳ���ᴢˮ
		int max_left, max_right, i, j, k, res = 0, cur;
		//Ԫ�����������Ӳ�����ˮ������0
		if (height.size() < 3)
			return 0;
		//��������в����ܴ�ˮ�����Բ����ǣ�i��1��height.size()-2
		for (i = 1; i < height.size() - 1; i++)
		{
			max_left = 0;
			max_right = height.size() - 1;
			//�ӵ�ǰ������߳������ҵ������ߵ�ǽ
			for (j = i - 1; j >= 0; j--)
			{
				if (height[j] > height[max_left])
					max_left = j;
			}
			//�ӵ�ǰ�г������ҵ��ұ����ǽ
			for (j = i + 1; j < height.size() - 1; j++)
			{
				if (height[j] > height[max_right])
					max_right = j;
			}
			cur = min(height[max_left], height[max_right]);
			//ֻ�нϰ���ǽ�ĸ߶ȴ��ڵ�ǰ�е�ǽ�ĸ߶Ȳ��ܴ�ˮ����ˮ�����ڽϰ���ǽ�ĸ߶ȼ�ȥ��ǰ�еĸ߶�
			if (height[i] < cur)
				res += cur - height[i];
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> height = { 9,6,8,8,5,6,3 };
	cout << solute.trap(height) << endl;
	return 0;
}