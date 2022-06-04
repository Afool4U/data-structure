#pragma once
#include <ostream>

// �Զ����װ��String
class String {
public:
	String(const char* const s);
	String();
	String(const String& other);
	String& operator=(const String& other);
	int find(const String& p);  // ʹ����kmp�㷨��ʱ�临�Ӷ�O(M+N)
	const int size() const;
	const int length() const;
	const char operator[] (int i) const;
	char& operator[] (int i);
	String operator+ (const String& other) const;
	friend std::ostream& operator<<(std::ostream& out, String& s);
	char* const c_str();
	~String();
private:
	char* data = nullptr;
	int len = 0;
	unsigned* pmt() const;
};
