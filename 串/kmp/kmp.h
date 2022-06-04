#pragma once
#include <ostream>

// 自定义封装类String
class String {
public:
	String(const char* const s);
	String();
	String(const String& other);
	String& operator=(const String& other);
	int find(const String& p);  // 使用了kmp算法，时间复杂度O(M+N)
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
