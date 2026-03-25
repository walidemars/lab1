#include "MyString.h"
#include <iostream>

using namespace std;

int dlina1(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

void kopir(char* str1, const char* str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int sravn(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    int result = *str2 - *str1;
    if (result == 0) return 0;
    else if(result < 0) return -1;
    else return 1;
}

void konkat(char* str1, const char* str2) {
    while (*str1 != '\0') str1++;
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

MyString::MyString(const char* string) {
    size = dlina1(string) + 1;
    str = new char[size];
    kopir(str, string);
}

MyString::MyString() {
    size = 80;
    str = new char[size];
    str[0] = '\0';
}

MyString::MyString(const MyString& s) {
    size = s.size;
    str = new char[size];
    kopir(str, s.str);
}

MyString::MyString(int _size) {
    if (_size <= 0) {
        size = 1;
    } else {
        size = _size;
    }
    str = new char[size];
    str[0] = '\0';
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& s) {
    if (this != &s) {
        delete[] str;
        size = s.size;
        str = new char[size];
        kopir(str, s.str);
    }
    return *this;
}

MyString& MyString::operator=(const char* string) {
    int newSize = dlina1(string) + 1;
    if (newSize > size) {
        delete[] str;
        size = newSize;
        str = new char[size];
    }
    kopir(str, string);
    return *this;
}

MyString MyString::operator+(const MyString& s) const {
    int newSize = length() + s.length() + 1;
    MyString newString(newSize);
    kopir(newString.str, str);
    konkat(newString.str, s.str);
    return newString;
}

int MyString::operator==(const MyString& s) const {
    return sravn(str, s.str) == 0 ? 1 : 0;
}

int MyString::length() const {
    return dlina1(str);
}

void MyString::enterStr() {
    cout << "Введите строку (макс. " << size - 1 << " символов): ";
    cin.getline(str, size);
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Строка слишком длинная!" << endl;
        str[0] = '\0';
    }
}

void MyString::printStr() const {
    cout << str;
}