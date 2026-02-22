#include "iostream"
#include "iomanip"
#include <cstdlib>
#include "conio.h"

#define N 5

using namespace std;

int main() {

    float m[N][N];
    int i, j;

    float findMinMatrix(float*, int);
    float findMaxMatrix(float*, int);

    float findMaxLowerPartOfMatrix(float*, int);
    float findMaxHigherPartOfMatrix(float*, int);

    float findMinLowerPartOfMatrix(float*, int);
    float findMinHigherPartOfMatrix(float*, int);

    float findMinMainDiag(float*, int);
    float findMaxMainDiag(float*, int);

    float findMinSecDiag(float*, int);
    float findMaxSecDiag(float*, int);

    float averageOfMatrix(float*, int);

    float averageLowerPartOfMatrix(float*, int);
    float averageHigherPartOfMatrix(float*, int);

    float* sumOfRow(float*, int);
    float* sumOfColumn(float*, int);

    float* minOfRow(float*, int);
    float* minOfColumn(float*, int);

    float* maxOfRow(float*, int);
    float* maxOfColumn(float*, int);

    float* averageOfRow(float*, int);
    float* averageOfColumn(float*, int);

    float sumLowerPartOfMatrix(float*, int);
    float sumHigherPartOfMatrix(float*, int);

    //srand(time(0));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand()/10;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl;
    }

    float min = findMinMatrix(&m[0][0], N);
    float max = findMaxMatrix(&m[0][0], N);

    float maxLowerPart = findMaxLowerPartOfMatrix(&m[0][0], N);
    float maxHigherPart = findMaxHigherPartOfMatrix(&m[0][0], N);

    float minLowerPart = findMinLowerPartOfMatrix(&m[0][0], N);
    float minHigherPart = findMinHigherPartOfMatrix(&m[0][0], N);

    float minMainDiag = findMinMainDiag(&m[0][0], N);
    float maxMainDiag = findMaxMainDiag(&m[0][0], N);

    float minSecDiag = findMinSecDiag(&m[0][0], N);
    float maxSecDiag = findMaxSecDiag(&m[0][0], N);

    float average = averageOfMatrix(&m[0][0], N);

    float averageLower = averageLowerPartOfMatrix(&m[0][0], N);
    float averageHigher = averageHigherPartOfMatrix(&m[0][0], N);

    float* sumRow = sumOfRow(&m[0][0], N);
    float* sumColumn = sumOfColumn(&m[0][0], N);

    float* minRow = minOfRow(&m[0][0], N);
    float* minColumn = minOfColumn(&m[0][0], N);

    float* maxRow = maxOfRow(&m[0][0], N);
    float* maxColumn = maxOfColumn(&m[0][0], N);

    float* averageRow = averageOfRow(&m[0][0], N);
    float* averageColumn = averageOfColumn(&m[0][0], N);

    float sumLower = sumLowerPartOfMatrix(&m[0][0], N);
    float sumHigher = sumHigherPartOfMatrix(&m[0][0], N);

    cout << "Минимум " << min << endl;
    cout << "Максимум " << max << endl;

    cout << "Максимум нижнетреугольной части " << maxLowerPart << endl;
    cout << "Максимум верхнетреугольной части " << maxHigherPart << endl;

    cout << "Минимум нижнетреугольной части " << minLowerPart << endl;
    cout << "Минимум верхнетреугольной части " << minHigherPart << endl;

    cout << "Минимум главной диагонали " << minMainDiag << endl;
    cout << "Максимум главной диагонали " << maxMainDiag << endl;

    cout << "Минимум второстепенной диагонали " << minSecDiag << endl;
    cout << "Максимум второстепенной диагонали " << maxSecDiag << endl;

    cout << "Среднеарифметическое значение элементов матрицы " << average << endl;

    cout << "Среднеарифметическое значение элементов нижнетреугольной части матрицы " << averageLower << endl;
    cout << "Среднеарифметическое значение элементов верхнетреугольной части матрицы " << averageHigher << endl;

    cout << "Сумма значений элементов нижнетреугольной части матрицы " << sumLower << endl;
    cout << "Сумма значений значение элементов верхнетреугольной части матрицы " << sumHigher << endl;

    cout << "Суммы по строкам " << endl;
    for(i = 0; i < N; i++) {
        cout << "Строка " << i + 1 << ": " << sumRow[i] << endl;
    }
    delete[] sumRow;
    cout << "Суммы по столбцам " << endl;
    for(i = 0; i < N; i++) {
        cout << "Столбец " << i + 1 << ": " << sumColumn[i] << endl;
    }
    delete[] sumColumn;

    cout << "Минимальные значения строк " << endl;
    for(i = 0; i < N; i++) {
        cout << "Строка " << i + 1 << ": " << minRow[i] << endl;
    }
    delete[] minRow;
    cout << "Минимальные значения столбцов " << endl;
    for(i = 0; i < N; i++) {
        cout << "Столбец " << i + 1 << ": " << minColumn[i] << endl;
    }
    delete[] minColumn;

    cout << "Максимальные значения строк " << endl;
    for(i = 0; i < N; i++) {
        cout << "Строка " << i + 1 << ": " << maxRow[i] << endl;
    }
    delete[] maxRow;
    cout << "Максимальные значения столбцов " << endl;
    for(i = 0; i < N; i++) {
        cout << "Столбец " << i + 1 << ": " << maxColumn[i] << endl;
    }
    delete[] maxColumn;

    cout << "Среднеарифметические значения строк " << endl;
    for(i = 0; i < N; i++) {
        cout << "Строка " << i + 1 << ": " << averageRow[i] << endl;
    }
    delete[] averageRow;
    cout << "Среднеарифметические значения столбцов " << endl;
    for(i = 0; i < N; i++) {
        cout << "Столбец " << i + 1 << ": " << averageColumn[i] << endl;
    }
    delete[] averageColumn;

    getch();
    return 0;
}

float findMinMatrix(float* matrix, int size) {

    float minValue = matrix[0];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue < minValue) {
                minValue = currentValue;
            }
        }
    }
    return minValue;
}

float findMaxMatrix(float* matrix, int size) {

    float maxValue = matrix[0];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
    }
    return maxValue;
}

float findMaxLowerPartOfMatrix(float* matrix, int size) {
    float maxValue = matrix[size];

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            int currentValue = matrix[i * size + j];
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
    }
    return maxValue;
}

float findMaxHigherPartOfMatrix(float* matrix, int size) {
    float maxValue = matrix[size];

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int currentValue = matrix[i * size + j];
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
    }
    return maxValue;
}

float findMinLowerPartOfMatrix(float* matrix, int size) {
    float minValue = matrix[size];

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            int currentValue = matrix[i * size + j];
            if (currentValue < minValue) {
                minValue = currentValue;
            }
        }
    }
    return minValue;
}

float findMinHigherPartOfMatrix(float* matrix, int size) {
    float minValue = matrix[size];

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int currentValue = matrix[i * size + j];
            if (currentValue < minValue) {
                minValue = currentValue;
            }
        }
    }
    return minValue;
}

float findMinMainDiag(float* matrix, int size) {
    float minValue = matrix[0];

    for (int i = 0; i < size; i++) {
        for (int j = i; j == i; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue < minValue) {
                minValue = currentValue;
            }
        }
    }
    return minValue;
}

float findMaxMainDiag(float* matrix, int size) {
    float maxValue = matrix[0];

    for (int i = 0; i < size; i++) {
        for (int j = i; j == i; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
    }
    return maxValue;
}

float findMinSecDiag(float* matrix, int size) {
    float minValue = matrix[size - 1];

    for (int i = 0; i < size; i++) {
        for (int j = size - 1 - i; j == size - 1 - i; j--) {
            int currentValue = matrix[i * size + j];
            if (currentValue < minValue) {
                minValue = currentValue;
            }
        }
    }
    return minValue;
}

float findMaxSecDiag(float* matrix, int size) {
    float maxValue = matrix[size - 1];

    for (int i = 0; i < size; i++) {
        for (int j = size - 1 - i; j == size - 1 - i; j--) {
            int currentValue = matrix[i * size + j];
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
    }
    return maxValue;
}

float averageOfMatrix(float* matrix, int size) {
    float sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i * size + j];
        }
    }
    return sum/(size*size);
}

float averageLowerPartOfMatrix(float* matrix, int size) {
    float sum = 0;
    int count = 0;

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += matrix[i * size + j];
            count++;
        }
    }
    return sum/count;

}

float averageHigherPartOfMatrix(float* matrix, int size) {
    float sum = 0;
    int count = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            sum += matrix[i * size + j];
            count++;
        }
    }
    return sum/count;
}

float* sumOfRow(float* matrix, int size) {
    float* sumOfRow = new float[size];

    for (int i = 0; i < size; i++) {
        float sum = 0;
        for (int j = 0; j < size; j++) {
            sum += matrix[i * size + j];
        }
        sumOfRow[i] = sum;
    }
    return sumOfRow;
}

float* sumOfColumn(float* matrix, int size) {
    float* sumOfColumn = new float[size];
    int j = 0;

    for (int i = 0; j < size; j++) {
        float sum = 0;
        i = 0;
        for (; i < size; i++) {
            sum += matrix[i * size + j];
        }
        sumOfColumn[j] = sum;
    }
    return sumOfColumn;
}

float* minOfRow(float* matrix, int size) {
    float* minOfRow = new float[size];

    for (int i = 0; i < size; i++) {
        float min = matrix[i];
        for (int j = 0; j < size; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue < min) {
                min = currentValue;
            }
        }
        minOfRow[i] = min;
    }
    return minOfRow;
}

float* minOfColumn(float* matrix, int size) {
    float* minOfColumn = new float[size];
    int j = 0;

    for (; j < size; j++) {
        float min = matrix[j];
        for (int i = 0; i < size; i++) {
            int currentValue = matrix[i * size + j];
            if (currentValue < min) {
                min = currentValue;
            }
        }
        minOfColumn[j] = min;
    }
    return minOfColumn;
}

float* maxOfRow(float* matrix, int size) {
    float* maxOfRow = new float[size];

    for (int i = 0; i < size; i++) {
        float max = matrix[size * i];
        for (int j = 0; j < size; j++) {
            int currentValue = matrix[i * size + j];
            if (currentValue > max) {
                max = currentValue;
            }
        }
        maxOfRow[i] = max;
    }
    return maxOfRow;
}

float* maxOfColumn(float* matrix, int size) {
    float* maxOfColumn = new float[size];
    int j = 0;

    for (; j < size; j++) {
        float max = matrix[j];
        for (int i = 0; i < size; i++) {
            int currentValue = matrix[i * size + j];
            if (currentValue > max) {
                max = currentValue;
            }
        }
        maxOfColumn[j] = max;
    }
    return maxOfColumn;
}

float* averageOfRow(float* matrix, int size) {
    float* averageOfRow = new float[size];

    for (int i = 0; i < size; i++) {
        float average = 0;
        for (int j = 0; j < size; j++) {
            average += matrix[i * size + j];
        }
        averageOfRow[i] = average/size;
    }
    return averageOfRow;
}

float* averageOfColumn(float* matrix, int size) {
    float* averageOfColumn = new float[size];
    int j = 0;

    for (; j < size; j++) {
        float average = matrix[j];
        for (int i = 0; i < size; i++) {
            average += matrix[i * size + j];
        }
        averageOfColumn[j] = average/size;
    }
    return averageOfColumn;
}

float sumLowerPartOfMatrix(float* matrix, int size) {
    float sum = 0;

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            sum += matrix[i * size + j];
        }
    }
    return sum;
}

float sumHigherPartOfMatrix(float* matrix, int size) {
    float sum = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            sum += matrix[i * size + j];
        }
    }
    return sum;
}