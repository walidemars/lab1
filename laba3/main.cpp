#include "iostream"
#include "conio.h"

using namespace std;

void printArr(int arr[], int size);
void minMaxSort(int mas[], int size);
void bubbleSort(int arr[], int size);
void quickSort(int arr[], int left, int right);

int main() {
    int mas1[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas2[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int mas3[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
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

    return 0;
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void quickSort(int arr[], int left, int right) {
    int pivot, index;
    int lHold = left;
    int rHold = right;

    pivot = arr[left];

    while (left < right) {
        while ((arr[right] > pivot) && (left < right))
            right--;

        if (left != right) {
            arr[left] = arr[right];
            left++;
        }

        while ((arr[left] < pivot) && (left < right))
            left++;

        if (left != right) {
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;
    index = left;
    left = lHold; right = rHold;

    if (left < index)
        quickSort(arr, left, index - 1);

    if (right > index)
        quickSort(arr, index + 1, right);
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
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}
