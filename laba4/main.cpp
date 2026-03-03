#include "iostream"
#include "string.h"
#include <conio.h>


using namespace std;

int dlina1(char*);
int dlina2(char*);
int dlina3(char*);

void kopir(char*, char*);
int sravn(char*, char*);
void konkat(char*, char*);
void konkat(char*, char*);
void enterString(char*, int);

int main() {
    char *strings[5];
    int numStrings = 5;
    char buffer[300] = "";
    char temp[100];

    for (int i = 0; i < numStrings; i++) {
        strings[i] = (char*)calloc(100, sizeof(char));
        cout << "введите строку" << endl;
        enterString(strings[i], 100);
    }

    cout << "длины строк первым способом" << endl;
    for (int i = 0; i < numStrings; i++) {
        cout << "длина строки " << i << " = " << dlina1(strings[i]) << endl;
    }

    cout << "длины строк вторым способом" << endl;
    for (int i = 0; i < numStrings; i++) {
        cout << "длина строки " << i << " = " << dlina2(strings[i]) << endl;
    }

    cout << "длины строк третьим способом" << endl;
    for (int i = 0; i < numStrings; i++) {
        cout << "длина строки " << i << " = " << dlina3(strings[i]) << endl;
    }

    cout << "до копирования strings[0]: " << strings[0] << endl;
    kopir(strings[0], strings[1]);
    cout << "после копирования strings[1] в strings[0]: " << strings[0] << endl;

    cout << "результат сравнения strings[0] и strings[1]: " << sravn(strings[0], strings[1]) << endl;
    cout << "результат сравнения strings[2] и strings[1]: " << sravn(strings[2], strings[1]) << endl;

    konkat(strings[1], strings[2]);
    cout << "результат сцепления strings[1] и strings[2]: " << strings[1] << endl;

    for (int i = 0; i < numStrings; i++) {
        free(strings[i]);
    }


    return 0;
}

void enterString(char* str, int maxLength) {
    char ch;
    int i = 0;

    while (i < maxLength - 1) {
        ch = getche();
        if (ch == '\r') break;
        str[i++] = ch;
    }
    str[i] = '\0';
    cout << endl;
}

int dlina1(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int dlina2(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int dlina3(char* str) {
    if (*str == '\0')
        return 0;
    return 1 + dlina3(str + 1);
}

void kopir(char* str1, char* str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int sravn(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    int result = *str2 - *str1;

    if (result == 0)
        return 0;
    else if(result < 0)
        return -1;
    else
        return 1;
}

void konkat(char* str1, char* str2) {
    while (*str1 != '\0')
        str1++;

    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}