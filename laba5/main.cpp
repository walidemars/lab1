#include <cstdio>
#include <cstring>
#include "iostream"

int main() {

    void countSymbols(FILE*);
    void hasSubstring(FILE *source, char *target);
    void movePageNumbers(FILE *source, FILE *out);
    void encryptFile(FILE *source, FILE *out);

    char substring[50];
    char *p = substring;

    char name[50];
    FILE *in;
    FILE *out;
    FILE *encrypt;

    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL )
        printf("Файл %s не открыт", name);
    else {
        while (!feof(in)) {
            char ch = getc(in);
            putchar(ch);
        }
        countSymbols(in);
    }

    printf("\nВведите искомую подстроку: ");
    scanf("%s", substring);


    hasSubstring(in, substring);
    if ((in = fopen("file.txt", "r")) == NULL )
        printf("Файл %s не открыт", name);
    else {
        while (!feof(in)) {
            char ch = getc(in);
            putchar(ch);
        }
    }


    if ((out = fopen("out.txt", "w")) == NULL )
        printf("Файл %s не открыт", name);
    else {
        movePageNumbers(in, out);
        fclose(out);
    }

    printf("Введите имя файла для шифрования: ");
    scanf("%s", name);

    in = fopen(name, "r");
    encrypt = fopen("encrypt1.txt", "w");

    if (in == NULL || encrypt == NULL )
        printf("Файл %s или encrypt.txt не открыт", name);
    else {
        encryptFile(in, encrypt);
        fclose(out);
    }


    fclose(in);
    fclose(out);
    fclose(encrypt);
    return 0;
}

void encryptFile(FILE *source, FILE *out) {

    char key[50];
    printf("Введите ключ для шифрования: ");
    scanf("%s", key);

    int keyLen = strlen(key);
    int keyIndex = 0;
    int ch;

    while ((ch = fgetc(source)) != EOF) {
        char decrypted = ch ^ key[keyIndex];
        fputc(decrypted, out);
        keyIndex = (keyIndex + 1) % keyLen;
    }
}

void hasSubstring(FILE *source, char *target) {
    rewind(source);

    FILE *out;
    int countFound = 0;
    bool found = false;

    while (!feof(source)) {
        int sourceCh = getc(source);
        if (sourceCh == target[0]) {
            int i = 1;
            int next;

            while (target[i] != '\0') {
                next = getc(source);

                if (next != target[i] || next == EOF) {
                    break;
                }
                i++;
            }
            if (target[i] == '\0') {
                countFound++;
                found = true;
            }
        }
    }

    char result[100];
    sprintf(result, "Строка найдена %d раз\n", countFound);

    if (found) {
        if ((out = fopen("file.txt", "w")) == NULL)
            printf("Файл file.txt не открыт\n");
        else {
            fputs(result, out);
            fputs(target, out);
            fclose(out);
        }
    }
}

void movePageNumbers(FILE *source, FILE *out) {
    rewind(source);

    char line[256];
    int pageNumber = -1;
    int waitingForNumber = 0;

    while (fgets(line, sizeof(line), source) != NULL) {

        if (line[0] == '\f') {
            waitingForNumber = 1;
            if (pageNumber > 1) {
                fprintf(out, "%d\n", pageNumber);
                pageNumber = -1;
            }
            continue;
        }
        if (waitingForNumber) {
            int num;

            if (sscanf(line, " %*c %d %*c", &num) == 1) {
                pageNumber = num;
                waitingForNumber = 0;
                continue;
            }
        }
        fputs(line, out);
    }
    fprintf(out, "\n\n%d\n", pageNumber);
    fclose(out);
}

void countSymbols(FILE *in) {
    int emptySymbolsCount = 0;
    int symbolsCount = 0;

    rewind(in);
    while (!feof(in)) {
        char ch = getc(in);
        if (isspace(ch) || iscntrl(ch))
            emptySymbolsCount++;
        else
            symbolsCount++;
    }

    std::cout << std::endl;
    std::cout << "Пустых символов: " << emptySymbolsCount << std::endl;
    std::cout << "Непустых символов: " << symbolsCount << std::endl;
}
