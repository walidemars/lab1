#ifndef LAB1_MYSTRING_H
#define LAB1_MYSTRING_H

#include "iostream"

class MyString {
private:
    char* str;
    int size;

public:
    MyString(const char* string);
    MyString();
    MyString(const MyString& s);
    MyString(int _size);

    ~MyString();

    MyString& operator=(const MyString& s);
    MyString& operator=(const char* string);
    MyString operator+(const MyString& s) const;
    int operator==(const MyString& s) const;

    int length() const;
    void enterStr();
    void printStr() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    friend std::istream& operator>>(std::istream& is, MyString& s);
};

#endif
