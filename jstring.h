#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
using std::istream;
using std::ostream;
class String
{
	char * str;
	int len;
public:
	String();
	String(const char * str);
	String(const String& str);
	String& operator=(const String& str);
	String operator+(const String& str);
	String& operator+=(const String& str);
	bool operator==(const String& str);
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& str);

	~String();
};
#endif
