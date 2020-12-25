#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //����˼�룺��С�ѣ���nums�ֳ������ִ󶥶Ѻ�С���ѣ�С���ѵ�����Ԫ�ش��ڴ󶥶�����Ԫ��
        //Ȼ�󽫴󶥶Ѻ�С���������ֵ����ݴ�����nums���󶥶���Ԫ�ش�0��ʼ���μ��һλ����nums
        //С������Ԫ�ش����һ��Ԫ�ؿ�ʼ���μ��һλ����nums
        //ʱ�临�Ӷ�O(nlogk) �ռ临�Ӷ�O(n)
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto num:nums)
        {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
            if(min_heap.size()>max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        int left=0;
        int right=nums.size()%2==0?nums.size()-1:nums.size()-2;
        while(!min_heap.empty()||!max_heap.empty())
        {
            if(left<nums.size())
            {
                nums[left]=max_heap.top();
                max_heap.pop();
                left+=2;
            }
            if(right>=0)
            {
                nums[right]=min_heap.top();
                min_heap.pop();
                right-=2;
            }
        }
    }
};
class Solution1 {
public:
    void wiggleSort(vector<int>& nums) {
        //����˼�룺����ѡ���㷨+�������㷨��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
        //��һ������ѡ���㷨nth_element���n/2��Ԫ��ֵ����λ����ʱ�临�Ӷ�O(n)
        //�ڶ����������㷨��ָ�뽫����λ��С�ķ���λ����ߣ�����λ����ķ���λ���ұߣ�ʱ�临�Ӷ�O(n)
        //����������С���ֵ�Ԫ�ؼ������nums�У��ռ临�Ӷ�O(n)

        //��һ���ҳ���λ��
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        int midnum=*(nums.begin()+nums.size()/2);
        //�ڶ�����ָ�뽫����λ��С�ķ���λ����ߣ�����λ����ķ���λ���ұ�
        int left=0,right=nums.size()-1,cur=0;
        while(cur<=right)
        {
            if(nums[cur]==midnum)
                cur++;
            else if(nums[cur]<midnum)
            {
                swap(nums[left],nums[cur]);
                left++;
                cur++;
            }
            else
            {
                swap(nums[right],nums[cur]);
                right--;
            }
        }
        //����������С���ֵ�Ԫ�ؼ������nums������Ҫע���С���ֵ�Ԫ�ص��������뵽nums
        //����nums={4,5,5,6}���õ�minnums={4,5} maxnums={5,6}
        //������������뵽nums�ͳ���{4,5,5,6}������Ȼ��׼ȷ��Ӧ�õ������μ������{5,6,4,5}
        vector<int> minnums(nums.begin(),nums.begin()+(nums.size()+1)/2);
        vector<int> maxnums(nums.begin()+(nums.size()+1)/2,nums.end());
        for(int i=0;i<nums.size();i++)
            nums[i]=i%2==0?minnums[minnums.size()-1-i/2]:maxnums[maxnums.size()-1-i/2];
    }
};
int main()
{
    Solution1 solute;
    vector<int> nums={4,5,5,6};
    solute.wiggleSort(nums);
    for_each(nums.begin(),nums.end(),[](auto v){cout<<v<<" ";});
    cout<<endl;
    return 0;
}
