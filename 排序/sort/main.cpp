// �����㷨
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
    cout << "��ǰ���ݹ�ģ��" << n << endl;
    srand(time(NULL));
    vector<int> v, vToSort;
    while (n--)
        v.push_back(rand() % 1000);  // �����������v  
    vector<int> vSorted(v);

    cout << "ϵͳ����";
    start = clock();
    std::sort(vSorted.begin(), vSorted.end());  // ����algorithm���������ڼ�������ܶԱ�
    finish = clock();
    cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;


    vToSort = v;  // ���¿���ԭ����v
    cout << "ѡ������";
    start = clock();
    selectSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ "<< (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }


    vToSort = v;  // ���¿���ԭ����v
    cout << "ð������";
    start = clock();
    bubbleSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }


    vToSort = v;  // ���¿���ԭ����v
    cout << "��������";
    start = clock();
    insertSort(vToSort);
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }


    vToSort = v;  // ���¿���ԭ����v
    cout << "�鲢����";
    start = clock();
    mergeSort(vToSort,0,vToSort.size() - 1);  // ע���ұ߽�Ϊsize-1
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }


    vToSort = v;  // ���¿���ԭ����v
    cout << "��������";
    start = clock();
    quickSort(vToSort, 0, vToSort.size() - 1);  // ע���ұ߽�Ϊsize-1
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }
    /////// �����������
    //for (auto& i : vToSort)
    //    cout << i << " ";
    /////////////////////


    vToSort = v;  // ���¿���ԭ����v
    cout << "��������";
    start = clock();
    radixSort(vToSort);  // ע���ұ߽�Ϊsize-1
    finish = clock();
    if (vToSort == vSorted) {  // ����
        cout << "�ɹ���" << "��ʱ " << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
    }
}
