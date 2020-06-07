#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
	unordered_set<int> nums;
	bool isHappy(int n) {
		//����˼�룺��ϣ��ʱ�临�Ӷ�O(logn)�ռ临�Ӷ�O(logn)
		if (n == 1)
			return true;
		else if (nums.find(n) != nums.end())
			return false;
		nums.insert(n);
		int res = 0;
		while (n)
		{
			int r = n % 10;
			res += r * r;
			n /= 10;
		}
		return isHappy(res);
	}
};
class Solution1 {
public:
	bool isHappy(int n) {
		//����˼�룺����ָ�룬����ķ���ͨ����ϣ����ѭ���ĵ㣬Ҳ����ͨ������ָ����
		//ʱ�临�Ӷ�O(logn)�ռ临�Ӷ�O(1)�����Ե�ʱ��Ӧ���뵽���ַ���
		int slow = n, fast = n;
		while (fast != 1)
		{
			slow = get_next(slow);
			fast = get_next(get_next(fast));
			//�������ָ��������˵���������ɻ�����false
			if (fast != 1 && slow == fast)
				return false;
		}
		return true;
	}
	int get_next(int n)
	{
		int res = 0;
		while (n)
		{
			int r = n % 10;
			res += r * r;
			n /= 10;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	int n = 10;
	cout << solute.isHappy(n) << endl;
	return 0;
}