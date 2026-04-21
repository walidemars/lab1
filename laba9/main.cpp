#include <iostream>
#include <vector>

using namespace std;

template <class T>
class TStack {
protected:
    int numItem;
    T *item;
    int maxSize;
public:
    TStack(size_t size = 10) {
        maxSize = size;
        numItem = 0;
        item = new T[size];
    }

    ~TStack() {
        delete[] item;
    }

    void push(T t) {
        if (numItem < maxSize) {
            item[numItem++] = t;
        } else {

        }
    }

    T pop() {
        if (numItem > 0) {
            return item[--numItem];
        }
        return T();
    }

    bool isEmpty() {
        return numItem == 0;
    }

    T top() {
        if (!isEmpty())
            return item[numItem - 1];
        return T();
    }
};

void sortTrain(vector<int>& input, vector<int>& output) {

    TStack<int> siding(input.size());

    int expected = 1;
    size_t i = 0;

    while (i < input.size() || !siding.isEmpty()) {

        if (!siding.isEmpty() && siding.top() == expected) {
            int v = siding.pop();
            output.push_back(v);
            cout << "Вагон " << v << " из тупика на выход. Ожидаем " << expected + 1 << endl;
            expected++;
        } else if (i < input.size() && input[i] == expected) {
            output.push_back(input[i]);
            cout << "Вагон " << input[i] << " на выход. Ожидаем " << expected + 1 << endl;

            expected++;
            i++;
        } else if (i < input.size()) {

            if (!siding.isEmpty() && input[i] > siding.top()) {
                cout << "Невозможно отсортировать состав. Вагон " << input[i]
                     << " заблокирует вагон " << siding.top() << " в тупике.\n";
                return;
            }

            cout << "Вагон " << input[i] << " в тупик" << endl;
            siding.push(input[i]);
            i++;
        } else {
            cout << "Невозможно отсорттировать состав" << endl;
            return;
        }
    }
    cout << "Состав отсортирован" << endl;
}

template <class T>
void Sort(T array[], size_t size) {
    int i, j;
    T tmp;

    for (int i = 0; i < (int)size - 1; i++) {
        for (int j = (int)size - 1; i < j; j--) {
            if (array[j] < array[j - 1]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}

class Money {
    long dollars;
    int cents;
public:
    Money() : dollars(0), cents(0) {}
    Money(long d, int c) : dollars(d), cents(c) {}

    bool operator>(const Money& amt) const {
        return (dollars > amt.dollars) || (dollars == amt.dollars && cents > amt.cents);
    }

    bool operator<(const Money& amt) const {
        return (dollars < amt.dollars) || (dollars == amt.dollars && cents < amt.cents);
    }

    friend ostream& operator<<(ostream& os, const Money& amt) {
        os << "$" << amt.dollars << "." << amt.cents;
        return os;
    }
};

int main() {

    // Sort
    Money mas[] = { Money(19, 10), Money(99, 99), Money(99, 95), Money(19, 95) };
    size_t size = sizeof(mas) / sizeof(mas[0]);

    Sort(mas, size);

    for (int i = 0; i < size; i++) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
    cout << "\n";


    // железнодорожный состав
    vector<int> train;
    train.push_back(1);
    train.push_back(3);
    train.push_back(2);
    train.push_back(4);

    vector<int> result;

    sortTrain(train, result);

    cout << "Выходной состав: ";
    for (size_t k = 0; k < result.size(); ++k) {
        cout << result[k] << " ";
    }
    cout << endl;

    return 0;
}

