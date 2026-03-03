#include <algorithm>
#include "iostream"

using namespace std;

void printArr(int arr[], int size);
void minMaxSort(int mas[], int size);
void bubbleSort(int arr[], int size);
void quickSort(int arr[], int left, int right);
void evenOddSort(int arr[], int size);
void intervalAsc(int arr[], int N1, int N2);
void intervalDesc(int arr[], int N1, int N2);

int main() {
    int mas1[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas2[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas3[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas4[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas5[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas6[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int iMin, iMax;

    int size = sizeof(mas1) / sizeof(int);
    int i;

    cout << "Сортировка минимакс " << endl;
    printArr(mas1, size);
    minMaxSort(mas1, size);
    printArr(mas1, size);

    cout << "Сортировка пузырьком " << endl;
    printArr(mas2, size);
    bubbleSort(mas2, size);
    printArr(mas2, size);

    cout << "Быстрая сортировка " << endl;
    printArr(mas3, size);
    quickSort(mas3, 0, size-1);
    printArr(mas3, size);

    cout << "Сортировка по возрастанию четных и убыванию нечетных" << endl;
    printArr(mas4, size);
    evenOddSort(mas4, size);
    printArr(mas4, size);

    cout << "Сортировка на интервале по возрастанию" << endl;
    printArr(mas5, size);
    intervalAsc(mas5, 3, 8);
    printArr(mas5, size);

    cout << "Сортировка на интервале по убыванию" << endl;
    printArr(mas6, size);
    intervalDesc(mas6, 3, 8);
    printArr(mas6, size);

    return 0;
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void minMaxSort(int mas[], int size) {
    for (int i = 0; i < size-1; i++) {
        int iMin = i;
        for(int j = i+1; j < size; j++) {
            if (mas[j] < mas[iMin]) {
                iMin = j;
            }
        }
        int t = mas[i];
        mas[i] = mas[iMin];
        mas[iMin] = t;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        bool flag = false;
        for (int j = 0; j < size-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void evenOddSort(int arr[], int size) {

    int* tempArr = new int[size];
    for (int i = 0; i < size; i++) {
        tempArr[i] = arr[i];
    }

    for (int i = 0; i < size-1; i++) {
        bool flag = false;
        for (int j = 0; j < size-1-i; j++) {
            if (tempArr[j] > tempArr[j+1]) {
                swap(tempArr[j], tempArr[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }

    int evenIndex = 0;
    int oddIndex = size - 1;

    for (int i = 0; i < size; i++) {
        if (tempArr[i] % 2 == 0)
            arr[evenIndex++] = tempArr[i];
        else
            arr[oddIndex--] = tempArr[i];
    }

    delete[] tempArr;
}

void intervalAsc(int arr[], int N1, int N2) {
    for (int i = N1; i < N2; i++) {
        bool flag = false;
        for (int j = N1; j < N2-(i-N1); j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void intervalDesc(int arr[], int N1, int N2) {
    for (int i = N1; i < N2; i++) {
        bool flag = false;
        for (int j = N1; j < N2-(i-N1); j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}
