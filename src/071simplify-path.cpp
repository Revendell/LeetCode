#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		//基本思想：栈，因为C++中string没有split成员函数，所以导致这道题有点复杂
		//循环遍历path每个字符，遇到/../栈弹出一个元素，遇到/.../入栈，遇到/./直接跳过，遇到/.a/入栈，其他情况/a/入栈
		vector<string> vec;
		string res;
		int i, flag, pos;
		if (path.size() == 0)
			return path;
		if (path[path.size() - 1] != '/')
			path.append("/");
		i = 0;
		while (i < path.size() - 1)
		{
			pos = i;
			if (path[i] == '.')
			{
				//遇到/../栈弹出一个元素；遇到/.../入栈
				if (path[i + 1] == '.')
				{
					i = i + 2;
					flag = 0;
					while (path[i] != '/')
					{
						flag = 1;
						i++;
					}
					//遇到/.../入栈
					if (flag == 1)
					{
						vec.push_back(path.substr(pos, i - pos));
					}
					//遇到/../栈弹出一个元素
					else
					{
						if (!vec.empty())
							vec.pop_back();	
					}
					continue;
				}
				//遇到/./直接跳过
				else if (path[i + 1] == '/')
				{
					i++;
					continue;
				}
				//遇到/.a/入栈
				else
				{
					while (path[i] != '/')
						i++;
					vec.push_back(path.substr(pos, i - pos));
				}
			}
			//其他情况/a/入栈
			else if(path[i]!='/')
			{
				while (path[i] != '/')
					i++;
				vec.push_back(path.substr(pos, i - pos));
			}
			i++;
		}
		//将栈中所有元素拼接到res返回最终结果
		res = "/";
		for (i = 0; i < vec.size(); i++)
		{
			res += vec[i];
			res += "/";
		}
		if (res != "/")
			res.erase(res.size() - 1, 1);
		return res;
	}
};
class Solution1 {
public:
	string simplifyPath(string path) {
		//基本思想：暴力模拟，先去除多余/和/./并且将/...a/中连续大于两个.的替换成*，因为此时.算是路径名了
		//然后从末尾往前遍历path，对/../处理，cnt计数.数，cnt数表示需要删除/的数量，这样/../就删除此级以及上一级
		string res;
		int i, j, cnt, pos, flag = 0;
		if (path.size() == 0)
			return path;
		if (path[path.size() - 1] != '/')
			path.append("/");
		i = 0;
		while (i < path.size() - 1)
		{
			//删除多余/
			while (path[i] == '/' && path[i + 1] == '/')
			{
				path.erase(i, 1);
			}
			if (path[i] == '.')
			{
				//对/../和/.../情况处理，对/.../情况点替换成*
				if (path[i + 1] == '.')
				{
					pos = i;
					i = i + 2;
					flag = 0;
					while (path[i] != '/')
					{
						flag = 1;
						i++;
					}
					if (flag == 1)
					{
						for (j = pos; j < i; j++)
						{
							if (path[j] == '.')
								path[j] = '*';
						}
					}
					continue;
				}
				//对/./情况处理，删除
				else if (path[i + 1] == '/')
				{
					path.erase(i, 2);
					while (i < path.size() && path[i] == '/')
					{
						path.erase(i, 1);
					}
					continue;
				}
				//对/.hiden/情况处理，点替换成*
				else
				{
					path[i] = '*';
				}
			}	
			++i;
		}
		i = path.size() - 1;
		//从末尾往前遍历path，对/../处理，cnt计数.数，cnt数表示需要删除/的数量，这样/../就删除此级以及上一级
		while (i >= 0)
		{
			if (path[i] == '.')
			{
				cnt = 1;
				pos = i;
				i--;
				while (i >= 0 && cnt > 0)
				{
					if (path[i] == '.')
						cnt++;
					if (path[i] == '/')
						cnt--;
					i--;
				}
				//从下标i+1开始删除pos-i个元素
				if (cnt == 0)
					path.erase(i + 1, pos - i);
				//i已经到0了，所以从下标0开始删除pos-i个元素
				else
					path.erase(0, pos - i);
				continue;
			}
			i--;
		}
		//删除path最后面的/
		if(path!="/")
		    path.erase(path.size() - 1, 1);
		//如果path中存在*替换回.
		for (auto& v : path)
		{
			if (v == '*')
				v = '.';
		}
		return path;
	}
};
int main()
{
	Solution solute;
	string path = "/a//b////c/d//././/..";
	cout << solute.simplifyPath(path) << endl;
	return 0;
}