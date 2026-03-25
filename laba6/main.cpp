#include "MyString.h"
#include "iostream"

int main() {
    MyString s1("qwert"), s3, s4(s1), s5;
    s3.enterStr();
    s3 = "asdfg";
    s3.printStr();
    s5 = s1 + s3 + s4;
    std::cout << "длина s5 = " << s5.length();
    s5.printStr();
    if (s1 == s5)
        std::cout << "строки s1 и s5 равны";
    else if (s1 == s4)
        std::cout << "строки s1 и s4 равны";

    return 0;
}


