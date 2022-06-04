#include<cstring>
#include<iostream>
#include"kmp.h"

String::String(const char* const s) {
	if (s) {
		len = strlen(s);
		data = new char[len + 1];
		strcpy(data, s);
	}
}


String::String() {}


String::String(const String& other)
{
	len = other.len;
	data = new char[len + 1];
	strcpy(data, other.data);
}


String& String::operator=(const String& other)
{
	delete[] data;
	len = other.len;
	data = new char[len + 1];
	strcpy(data, other.data);
	return *this;
}


int String::find(const String& other) {
	unsigned* pmt = other.pmt();
	char* p = other.data;
	int lenO = other.len;  // 直接访问lenO加快速度
	for (int i = 0, j = 0; i != len; ++i)
	{
		// 直接访问私有成员p.data[j]而不是p[j]可以加快速度
		while (j && data[i] != p[j]) j = pmt[j - 1];
		if (data[i] == p[j]) ++j;
		if (j == lenO)
		{
			delete[] pmt;
			pmt = nullptr;
			return i - j + 1;
		}
	}
	delete[] pmt;
	pmt = nullptr;
	return -1;
}


const int String::size() const {
	return len;
}


const int String::length() const {
	return len;
}


const char String::operator[] (int i) const {
	return data[i];
}


char& String::operator[] (int i) {
	return data[i];
}


String String::operator+ (const String& other) const {
	String newStr = String();
	newStr.len = len + other.length();
	newStr.data = new char[newStr.len + 1];
	strcpy(newStr.data, data);
	strcat(newStr.data, other.data);
	return newStr;
}


char* const String::c_str() {
	return data;
}


String::~String() {
	delete[] data;
	data = nullptr;
}

unsigned* String::pmt() const {  // 自身匹配自身，时间复杂度O(N)
	unsigned* pmt = new unsigned[len]();  // 注意初始化为0
	for (int i = 1, j = 0; i < len; ++i)
	{
		while (j && data[i] != data[j]) j = pmt[j - 1];
		if (data[i] == data[j]) {
			if (data[i + 1] == data[j + 1])
				pmt[i] = pmt[j++];
			else
				pmt[i] = ++j;
		}
		else
			pmt[i] = j;
	}
	return pmt;
}


std::ostream& operator<<(std::ostream& out, String& s) {
	out << s.data;
	return out;
}
