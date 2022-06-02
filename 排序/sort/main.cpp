// 排序算法
// @Time 2022-5-30 0:12
// @Author HJL
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "sort.hpp"
using namespace std;


int main()
{
    clock_t start, finish;
    int n = 100000;
    cout << "当前数据规模：" << n << endl;
    srand(time(NULL));
    vector<int> v, vToSort;
    while (n--)
        v.push_back(rand() % 1000);  // 生成随机数组v  
    vector<int> vSorted(v);

    cout << "系统排序：";
    start = clock();
    std::sort(vSorted.begin(), vSorted.end());  // 调用algorithm排序函数用于检验和性能对比
    finish = clock();
    cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;


    vToSort = v;  // 重新拷贝原数组v
    cout << "选择排序：";
    start = clock();
    selectSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 "<< (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }


    vToSort = v;  // 重新拷贝原数组v
    cout << "冒泡排序：";
    start = clock();
    bubbleSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }


    vToSort = v;  // 重新拷贝原数组v
    cout << "插入排序：";
    start = clock();
    insertSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }


    vToSort = v;  // 重新拷贝原数组v
    cout << "归并排序：";
    start = clock();
    mergeSort(vToSort,0,vToSort.size() - 1);  // 注意右边界为size-1
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }


    vToSort = v;  // 重新拷贝原数组v
    cout << "快速排序：";
    start = clock();
    quickSort(vToSort, 0, vToSort.size() - 1);  // 注意右边界为size-1
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }
    /////// 调试输出代码
    //for (auto& i : vToSort)
    //    cout << i << " ";
    /////////////////////


    vToSort = v;  // 重新拷贝原数组v
    cout << "基数排序：";
    start = clock();
    radixSort(vToSort);  // 注意右边界为size-1
    finish = clock();
    if (vToSort == vSorted) {  // 检验
        cout << "成功！" << "用时 " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "秒" << endl;
    }
}
