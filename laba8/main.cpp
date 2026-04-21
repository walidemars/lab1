#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Stroka {
private:
    char* str;
    size_t length;

public:
    Stroka() : str(nullptr), length(0) {}

    Stroka(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    Stroka(const Stroka& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    ~Stroka() {
        delete[] str;
    }

    Stroka& operator=(const Stroka& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    Stroka& operator+=(const Stroka& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        length += other.length;
        return *this;
    }

    friend Stroka operator+(const Stroka& s1, const Stroka& s2) {
        Stroka result(s1);
        result += s2;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Stroka& s);
    friend istream& operator>>(istream& is, Stroka& s);

    size_t getLength() const { return length; }

    const char* c_str() const { return str; }
};

ostream& operator<<(ostream& os, const Stroka& s) {
    if (s.str != nullptr) {
        os << s.str;
    }
    return os;
}

istream& operator>>(istream& is, Stroka& s) {
    char buffer[1024];
    is >> buffer;

    delete[] s.str;
    s.length = strlen(buffer);
    s.str = new char[s.length + 1];
    strcpy(s.str, buffer);

    return is;
}

// oткрытие файла через конструктор
void openWithConstructor() {

    char fname[50];
    cout << "Введите имя входного файла: ";
    cin >> fname;

    ifstream ifs(fname);
    if (!ifs) {
        cout << "Не открыт входной файл " << fname << endl;
        return;
    }

    cout << "Введите имя выходного файла: ";
    cin >> fname;

    ofstream ofs(fname);
    if (!ofs) {
        cout << "Не открыт выходной файл " << fname << endl;
        return;
    }

    char c;
    while (ifs && ofs) {
        ifs.get(c);
        if (ifs.eof()) break;
        c = toupper(c);
        ofs.put(c);
    }

    cout << "Файл скопирован с переводом в верхний регистр.\n";
    ifs.close();
    ofs.close();
}

// oткрытие файла через метод open()
void openWithMethod() {

    char name[50];
    fstream fin;

    cout << "Введите имя файла: ";
    cin >> name;

    fin.open(name, ios::in);
    if (fin) {
        cout << "Файл открыт: " << name << endl;
        fin.close();
    } else {
        cout << "Не открыт входной файл " << name << endl;
    }
}

void encryptFileWithThread(ifstream& source, ofstream& out) {

    char key[50];
    cout << "Введите ключ для шифрования: ";
    cin >> key;

    int keyLen = strlen(key);
    int keyIndex = 0;
    char ch;

    while (source.get(ch)) {
        char encrypted = ch ^ key[keyIndex];
        out.put(encrypted);
        keyIndex = (keyIndex + 1) % keyLen;
    }
}

void demoStroka() {

    Stroka s1("Hello");
    Stroka s2("World");
    Stroka s3;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s3 = s1 + Stroka(", ") + s2 + Stroka("!");
    cout << "Конкатенация: " << s3 << endl;

    cout << "Введите строку: ";
    cin >> s1;
    cout << "Вы ввели: " << s1 << endl;
}

void cryptoDemo() {

    const char* original = "original.txt";
    const char* encrypted = "encrypted.txt";
    const char* decrypted = "decrypted.txt";

    ofstream orig(original);
    if (orig) {
        orig << "Это секретное сообщение!\n";
        orig << "Вторая строка с важной информацией.\n";
        orig << "Третья строка для проверки.\n";
        orig.close();
        cout << "Создан исходный файл: " << original << endl;
    }

    ifstream inFile(original, ios::binary);
    ofstream outFile(encrypted, ios::binary);

    if (inFile && outFile) {
        encryptFileWithThread(inFile, outFile);
        cout << "Файл зашифрован: " << encrypted << endl;
    }
    inFile.close();
    outFile.close();

    ifstream encFile(encrypted, ios::binary);
    ofstream decFile(decrypted, ios::binary);

    if (encFile && decFile) {
        encryptFileWithThread(encFile, decFile);  // XOR с тем же ключом = дешифровка
        cout << "Файл дешифрован: " << decrypted << endl;
    }
    encFile.close();
    decFile.close();

    cout << "\nСодержимое дешифрованного файла:\n";
    ifstream result(decrypted);
    if (result) {
        char line[256];
        while (result.getline(line, sizeof(line))) {
            cout << line << endl;
        }
        result.close();
    }
}

int main() {

    demoStroka();
    openWithConstructor();
    openWithMethod();
    cryptoDemo();

    return 0;
}
