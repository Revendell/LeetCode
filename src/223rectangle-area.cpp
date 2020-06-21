#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		//����˼�룺��ѧ
		int overlap_area = 0;
		int x1, y1, x2, y2;
		//�����ص����ֵ����½�(x1, y1)�����Ͻ�(x2, y2)
		x1 = max(A, E);
		y1 = max(B, F);
		x2 = min(C, G);
		y2 = min(D, H);
		//��������û���غϲ���
		if (x2 < x1 || y2 < y1)
			return (G - E) * (H - F) + (C - A) * (D - B);
		overlap_area = (x2 - x1) * (y2 - y1);
		return (G - E) * (H - F) - overlap_area + (C - A) * (D - B);
	}
};
int main()
{
	Solution solute;
	int a = -3, b = 0, c = 3, d = 4, e = 0, f = -1, g = 9, h = 2;
	cout << solute.computeArea(a, b, c, d, e, f, g, h) << endl;
	return 0;
}