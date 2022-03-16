#include <iostream>
#include <ctime>
using namespace std;

// вывод массива в консоль
void print(int (&arr)[10000]) {
    for (int i = 0; i < 10000; ++i) {
        if (i % 20 == 0) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

// нахождение среднего значения в массиве
void meanValue(int(&arr)[10000]) {
    int sum = 0;
    for (int i = 0; i < 10000; ++i) {
        sum += arr[i];
    }
    cout << endl << "meanValue: " << (sum * 1.0) / (10 * 1.0);
}

int main()
{
    const int SIZE = 10000;
    int Array[SIZE]{};
    srand(time(NULL));

    for (int i = 0; i < SIZE; ++i) {
        Array[i] = rand() % 201 - 100;
    }

    print(Array);
    meanValue(Array);
}