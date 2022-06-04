// kmp�㷨
// @Time 2022-6-5 4:25
// @Author HJL
#include<iostream>
#include<string>
#include"kmp.h"
using namespace std;

int main() {
	const char* const s1 = "abcdefghijklmn";
	const char* const s2 = "opqrstuvwxyz";
	string str1(s1);
	String str2(s1);
	str1 = str1 + s2;
	str2 = str2 + s2;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str1.find("nop") << endl;
	cout << str2.find("nop") << endl;

	// ����find�����ٶ�
	clock_t start, finish;
	int N = 30;
	const char* toFind = "xyzshgfrtdyufa";
	for (int i = 1; i <= 8; i++, N *= 10) {
		cout << "N=" << N << ": " << endl;
		char* s3 = new char[N];
		memset(s3, 'a', (N - 1) * sizeof(char));
		strcpy(s3 + N - 30, toFind);
		s3[N - 30 + strlen(toFind)] = 'a';
		// s3[N - 30] = 'x';
		str1 = s3;
		str2 = s3;
		start = clock();
		int p1 = str1.find(toFind);
		finish = clock();
		cout << "string��ʱ" << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
		start = clock();
		int p2 = str2.find(toFind);
		finish = clock();
		cout << "String��ʱ" << (finish - start) * 1.0 / CLOCKS_PER_SEC << "��" << endl;
		cout << "���ҽ��" << (p1 == p2 ? "һ��" : "��һ��") << endl << endl;
		delete[] s3;
		s3 = nullptr;
	}

	return 0;
}