#include <iostream>

using namespace std;

int main() {

    int firstProgram();
    int secondProgram();
    int thirdProgram();

    //firstProgram();
    //secondProgram();
    thirdProgram();
}

int firstProgram() {
    int k, x;
    int power(int, int);

    cin >> x;

    for(int i = 0; i < 10; i++) {
        k = power(x, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
    return 0;
}

int power(int x, int n) {
    int p = 1;
    for(int i = 1; i < n; i++) p *= x;
    return p;
}