#include<iostream>
#include<list>
#include<random>
#include<ctime>
#include<vector>
#include<algorithm>

const int SIZE = 1000000;

int main(void)
{
    using std::vector;
    using std::list;
    using std::cout;
    using std::endl;
    using std::cin;

    vector<int> vi0(SIZE, 0);
    for (int i = 0; i < SIZE; i++)
        vi0[i] = rand();
    
    vector<int> vi(vi0);
    list<int> li(SIZE, 0);
    std::copy(vi0.begin(), vi0.end(), li.begin());

    // 计算排序vector时间
    clock_t start = std::clock();           // 开始计时
    std::sort(vi.begin(), vi.end());
    clock_t end = std::clock();             // 结束计时
    cout << "排序vector时间：" << (double) (end - start) / CLOCKS_PER_SEC << endl;

    // 计算排序list时间
    start = std::clock();
    li.sort();
    end = std::clock();
    cout << "排序list时间：" << (double) (end - start) / CLOCKS_PER_SEC << endl;

   // 计算将链表内容复制到数组中进行排序在将排序好内容复制回list时间
   std::copy(vi0.begin(), vi0.end(), li.begin());
   start = std::clock();
   std::copy(li.begin(), li.end(), vi.begin());
   std::sort(vi.begin(), vi.end());
   std::copy(vi.begin(), vi.end(), li.begin());
   end = std::clock();
   cout << "copy+vectorSort+copy 时间：" << (double) (end - start) / CLOCKS_PER_SEC << endl;
    
    return 0;
}