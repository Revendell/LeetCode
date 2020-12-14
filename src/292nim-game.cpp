
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool canWinNim(int n) {
		return !(n % 4 == 0);
	}
};
int main()
{
	int n = 50;
	Solution solute;
	cout << solute.canWinNim(n) << endl;
	return 0;
}
