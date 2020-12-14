
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class NumArray {
public:
	NumArray(vector<int>& nums) {
		//����˼�룺��Ϊ���ε���sumRange����������ÿ�ζ������Ӽ���������ĺͲ������������
		//����ʹ��partisum[i]�洢partisumǰi��Ԫ�صĺ͡���ɵõ�i-j ������ĺ�Ϊpartisum[j]-partisum[i-1]
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			partisum.push_back(sum);
		}
	}
	int sumRange(int i, int j) {
		if (i == 0)
			return partisum[j];
		else
			return partisum[j] - partisum[i - 1];
	}
private:
	vector<int> partisum;
};
int main()
{
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray* obj = new NumArray(nums);
	int i = 2, j = 5;
	cout << obj->sumRange(i, j) << endl;
	return 0;
}
