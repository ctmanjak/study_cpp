#include <iostream>
#include <cstring>
#include "jstring.h"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

String::String() : str(NULL), len(0) {}
String::String(const char * str) : len(strlen(str))
{
	this->str = new char[strlen(str)+1];
	strcpy(this->str, str);
}
String::String(const String& str) : len(str.len)
{
	this->str = new char[len];
	strcpy(this->str, str.str);
}
String& String::operator=(const String& str)
{
	if(this->str != NULL) delete []this->str;
	len=str.len;
	this->str = new char[len+1];
	strcpy(this->str, str.str);
	return *this;
}
String String::operator+(const String& str)
{
	char * strtmp = new char[len+str.len];
	strcpy(strtmp, this->str);
	strcat(strtmp, str.str);

	String tmp(strtmp);
	delete []strtmp;
	return tmp;
}
String& String::operator+=(const String& str)
{
	len+=str.len;
	char * tmp = new char[len+1];
	strcpy(tmp, this->str);
	strcat(tmp, str.str);

	if(this->str != NULL) delete []this->str;
	this->str=tmp;
	return *this;
}
bool String::operator==(const String& str)
{
	if(strcmp(this->str, str.str) == true) return true;
	else return false;
}

String::~String()
{
	if(str!=NULL) delete []str;
}

ostream& operator<<(ostream& os, const String& str)
{
	os<<str.str;
	return os;
}

istream& operator>>(istream& is, String& str)
{
	char tmp[100];
	is>>tmp;
	str=String(tmp);
	return is;
}
