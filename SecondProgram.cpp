#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#include <cstdio>

void secondProgram() {
    int mas[] = {100, 200, 300};
    int *ptr1, *ptr2;

    ptr1 = mas;
    ptr2 = &mas[2];

    PR(ptr1);
    ptr1++;

    PR(ptr1);
    PR(ptr2);
    ++ptr2;

    printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1);


    double arr1[] = { 1.1, 2.2, 3.3 };
    double *ptr3, *ptr4;

    ptr3 = arr1;
    ptr4 = &arr1[2];

    PR(ptr3);
    ptr3++;

    PR(ptr3);
    PR(ptr4);
    ++ptr4;

    printf("ptr4 - ptr3 = %u\n", ptr4 - ptr3);

    char arr2[] = { 'a', 'b', 'c' };
    char *ptr5, *ptr6;

    ptr5 = arr2;
    ptr6 = &arr2[2];

    PR(ptr5);
    ptr5++;

    PR(ptr5);
    PR(ptr6);
    ++ptr6;

    printf("ptr6 - ptr5 = %u\n", ptr6 - ptr5);
}
