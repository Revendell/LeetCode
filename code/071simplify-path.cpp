#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		//����˼�룺ջ����ΪC++��stringû��split��Ա���������Ե���������е㸴��
		//ѭ������pathÿ���ַ�������/../ջ����һ��Ԫ�أ�����/.../��ջ������/./ֱ������������/.a/��ջ���������/a/��ջ
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
				//����/../ջ����һ��Ԫ�أ�����/.../��ջ
				if (path[i + 1] == '.')
				{
					i = i + 2;
					flag = 0;
					while (path[i] != '/')
					{
						flag = 1;
						i++;
					}
					//����/.../��ջ
					if (flag == 1)
					{
						vec.push_back(path.substr(pos, i - pos));
					}
					//����/../ջ����һ��Ԫ��
					else
					{
						if (!vec.empty())
							vec.pop_back();	
					}
					continue;
				}
				//����/./ֱ������
				else if (path[i + 1] == '/')
				{
					i++;
					continue;
				}
				//����/.a/��ջ
				else
				{
					while (path[i] != '/')
						i++;
					vec.push_back(path.substr(pos, i - pos));
				}
			}
			//�������/a/��ջ
			else if(path[i]!='/')
			{
				while (path[i] != '/')
					i++;
				vec.push_back(path.substr(pos, i - pos));
			}
			i++;
		}
		//��ջ������Ԫ��ƴ�ӵ�res�������ս��
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
		//����˼�룺����ģ�⣬��ȥ������/��/./���ҽ�/...a/��������������.���滻��*����Ϊ��ʱ.����·������
		//Ȼ���ĩβ��ǰ����path����/../����cnt����.����cnt����ʾ��Ҫɾ��/������������/../��ɾ���˼��Լ���һ��
		string res;
		int i, j, cnt, pos, flag = 0;
		if (path.size() == 0)
			return path;
		if (path[path.size() - 1] != '/')
			path.append("/");
		i = 0;
		while (i < path.size() - 1)
		{
			//ɾ������/
			while (path[i] == '/' && path[i + 1] == '/')
			{
				path.erase(i, 1);
			}
			if (path[i] == '.')
			{
				//��/../��/.../���������/.../������滻��*
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
				//��/./�������ɾ��
				else if (path[i + 1] == '/')
				{
					path.erase(i, 2);
					while (i < path.size() && path[i] == '/')
					{
						path.erase(i, 1);
					}
					continue;
				}
				//��/.hiden/����������滻��*
				else
				{
					path[i] = '*';
				}
			}	
			++i;
		}
		i = path.size() - 1;
		//��ĩβ��ǰ����path����/../����cnt����.����cnt����ʾ��Ҫɾ��/������������/../��ɾ���˼��Լ���һ��
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
				//���±�i+1��ʼɾ��pos-i��Ԫ��
				if (cnt == 0)
					path.erase(i + 1, pos - i);
				//i�Ѿ���0�ˣ����Դ��±�0��ʼɾ��pos-i��Ԫ��
				else
					path.erase(0, pos - i);
				continue;
			}
			i--;
		}
		//ɾ��path������/
		if(path!="/")
		    path.erase(path.size() - 1, 1);
		//���path�д���*�滻��.
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