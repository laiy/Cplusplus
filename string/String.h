#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class String {
    public:
        String();
        explicit String(const char *src);
        String(const String &src);
        ~String();
        String& operator =(const String& src);
        const char* c_str() const; //return _buff
        inline char& operator[](int i);
        friend ostream& operator <<(ostream& os, const String& src);
    private:
        char *_buff;
        int _size;
};

String::String() : _size(0) {
    _buff = NULL;
}

String::String(const char *src) {
    _size = strlen(src) + 1;
    _buff = new char[_size];
    snprintf(_buff, _size, "%s", src);
}

String::String(const String &src) {
    _size = src._size;
    _buff = new char[_size];
    snprintf(_buff, _size, "%s", src._buff);
}

String::~String() {
    if (_buff)
        delete []_buff;
}

String& String::operator =(const String& src) {
    if (_buff) {
        delete []_buff;
        _buff = NULL;
    }
    _size = src._size;
    _buff = new char[_size];
    snprintf(_buff, _size, "%s", src._buff);
    return *this;
}

const char* String::c_str() const {
    return _buff;
}

inline char& String::operator[](int i) {
    return _buff[i];
}

ostream& operator <<(ostream& os, const String& src) {
    os << src.c_str();
    return os;
}

