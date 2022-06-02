// �����㷨
// @Time 2022-5-30 0:09
// @Author HJL
#pragma once
#include<vector>
#include<list>
#include<string>
using std::vector;
using std::list;
using std::to_string;


template<class T>
inline void swap(T& a, T& b) {  // �Զ���������������
	T temp = a;
	a = b;
	b = temp;
}


template<class T>
void selectSort(vector<T>& v) {  // ѡ������
	if (v.size() <= 1)
		return;
	for (size_t i = 0; i < v.size(); i++) {
		T min = v[i];
		size_t pos = i;
		for (int j = i; j < v.size(); j++) {
			if (v[j] < min) {  // ��¼��Сλ��
				min = v[j];
				pos = j;
			}
		}
		swap(v[i], v[pos]);
	}
}


template<class T>
void bubbleSort(vector<T>& v) {  // ð������
	if (v.size() <= 1)
		return;
	for (size_t i = 0; i < v.size(); i++) {
		bool flag = 1;
		for (size_t j = 0; j < v.size() - i - 1; j++) {
			if (v[j] > v[j + 1]) {  // ��Ľ��������ұ�
				swap(v[j], v[j + 1]);
				flag = 0;
			}
		}
		if (flag)  // һ���������޽�������ǰ����
			return;
	}
}


template<class T>
void insertSort(vector<T>& v) {  // ��������
	if (v.size() <= 1)
		return;
	for (size_t i = 1; i < v.size(); i++) {
		for (size_t j = i; j > 0 && v[j] < v[j - 1]; j--) {
			swap(v[j], v[j - 1]);
		}
	}
}


template<class T>
void merge(vector<T>& arr, int l, int mid, int r) {
	vector<T> data;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (arr[i] <= arr[j])  // ���ʱ�ȶ���
			data.push_back(arr[i++]);
		else
			data.push_back(arr[j++]);
	}
	// �ϲ����ಿ�֣�������ұ�֤����
	while (i <= mid)
		data.push_back(arr[i++]);
	while (j <= r) {
		data.push_back(arr[j++]);
	}
	// ������ȥ
	for (size_t i = 0; i < data.size(); i++)
		arr[i + l] = data[i];
}

template<class T>
void mergeSort(vector<T>& arr, int l, int r) {  // ��·�鲢����
	if (l == r)
		return;
	int mid = (l + r) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
}


template<class T>
void quickSort(vector<T>& arr, int l, int r) {  // ��������(�Ľ�)
	if (l >= r)
		return;
	// �������ֹ��ջ���
	swap(arr[l], arr[rand() % (r - l + 1) + l]);
	// �ȱ�������
	int pivot = arr[l];
	int left = l, right = r;
	while (left < right) {
		while (arr[right] >= pivot && left < right)  // ���Ҳ����
			right--;
		arr[left] = arr[right];
		while (arr[left] <= pivot && left < right)  // ���Ҳ����
			left++;
		arr[right] = arr[left];
		
	}
	arr[right] = pivot;
	quickSort(arr, l, right - 1);
	quickSort(arr, right + 1, r);
}


template<class T>
void radixSort(vector<T>& arr) {  // ��������(��������)
	vector<list<T>> buckets(10);
	T max = *max_element(arr.begin(), arr.end());
	unsigned digits = to_string(max).size();
	for (char i = 1; i <= digits; i++) {
		for (size_t j = 0; j < arr.size(); j++) {
			char digit = i;
			T num = arr[j];
			// �������digitλ
			while (--digit) {
				num /= 10;
			}
			num %= 10;
			buckets[num].push_back(arr[j]);  // ��Ͱ

		}
		// һ�δ�����ٷŻ�arr����
		int pos = 0;
		for (auto& bucket:buckets) {
			for (auto& e : bucket) {
				arr[pos++] = e;
			}
		}
		// ���buckets
		buckets.clear();
		buckets.resize(10);
	}
}