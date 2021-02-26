#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //基本思想：归并+小顶堆，和373查找和最小的K对数字思想一致
        //维护N维大小的指针表示N行数组的位置，每次都要从N个指针里取最小的pop，然后将加入的值的下一个值入堆
        int res;
        vector<int> index(matrix.size(),0);
        vector<int> min_heap;
        for(int i=0;i<matrix.size();i++)
        {
            min_heap.push_back(i);
            push_heap(min_heap.begin(),min_heap.end(),[matrix,index](int& a,int& b){return matrix[a][index[a]]>matrix[b][index[b]];});
        }
        while(k--)
        {
            res=matrix[min_heap[0]][index[min_heap[0]]];
            index[min_heap[0]]++;
            int temp=min_heap[0];
            pop_heap(min_heap.begin(),min_heap.end(),[matrix,index](int& a,int& b){return matrix[a][index[a]]>matrix[b][index[b]];});
            min_heap.pop_back();
            if(index[temp]<matrix.size())
            {
                min_heap.push_back(temp);
                push_heap(min_heap.begin(),min_heap.end(),[matrix,index](int& a,int& b){return matrix[a][index[a]]>matrix[b][index[b]];});
            }
        }
        return res;
    }
};
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            point(){}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        point res;
        priority_queue<point,vector<point>,greater<point>> min_heap;
        for(int i=0;i<matrix.size();i++)
            min_heap.push(point(matrix[i][0],i,0));
        while(k--)
        {
            res=min_heap.top();
            min_heap.pop();
            if(res.y<matrix.size())
                min_heap.push(point(matrix[res.x][res.y+1],res.x,res.y+1));
        }
        return res.val;
    }
};
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
int main()
{
    Solution1 solute;
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    cout<<solute.kthSmallest(matrix,k)<<endl;
    return 0;
}