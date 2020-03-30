#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		//����˼�룺����ģ����ʽ�˷�������̣�����ѭ����һ��ѭ����ȡnum2��ĳ������ڶ���ѭ����ȡnum1��������������һ����layer��Ȼ��ÿһ�����ӵ�res��󷵻�res������
		//layerΪnum2��ĳ������num1��������˽��Ҳ����һ��������ÿһ�����ӵ�res������󷵻ؽ��
		string res, layer;
		//cur��num1��ĳ�����ֺ�num2ĳ��������˵õ�����ĸ�λ��
		char cur;
		//temp��ʱnum1��num2ĳ�������ֶ�Ӧ��˽����carry�ǽ����ʮλ��Ҳ���ǽ�λ��
		int i, j, carry, temp, k;
		//���num1��num2����һ����0���������0
		if (num1 == "0" || num2 == "0")
			return "0";
		//��һ��ѭ����ȡnum2��ĳ����
		for (i = num2.size() - 1; i >= 0; i--)
		{
			//ÿһ��layer��ʼ��Ϊ��
			layer = "";
			//����num2�ж�ȡ�����ڵ�λ����layer�����Ӧ������0
			for (k = 0; k < num2.size() - 1 - i; k++)
				layer.push_back('0');
			//��λ��carry��ʼ��Ϊ0
			carry = 0;
			//�ڶ���ѭ����ȡnum1��������num2��ȡ����num2[i]��˵õ���һ����layer
			for (j = num1.size() - 1; j >= 0; j--)
			{
				temp = (num2[i] - '0') * (num1[j] - '0') + carry;
				cur = temp % 10 + '0';
				carry = temp / 10;
				layer.push_back(cur);		
			}
			//���num2[i]��num1��������˺��н�λ���ӵ�layer����
			if (carry > 0)
				layer.push_back(carry + '0');
			carry = 0;
			//Ȼ��ÿһ����layer�ӵ�res��
			for (k = 0; k < res.size() && k < layer.size(); k++)
			{
				temp = (res[k] - '0') + (layer[k] - '0') + carry;
				res[k] = temp % 10 + '0';
				carry = temp / 10;
			}
			//����layer�ĳ��ȴ���res�ĳ��ȣ�layer����res���ȵĲ��ּӵ�res����
			while (k < layer.size())
			{
				temp = layer[k] - '0' + carry;
				res.push_back(temp % 10 + '0');
				carry = temp / 10;
				k++;
			}
			//���ǿ�������н�λ
			if (carry == 1)
				res.push_back('1');
		}
		//��󷵻�res������
		reverse(res.begin(), res.end());
		return res;
	}
};
int main()
{
	Solution solute;
	string nums1 = "23";
	string nums2 = "112";
	cout << solute.multiply(nums1, nums2) << endl;
	return 0;
}