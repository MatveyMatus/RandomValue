#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

// заполнение файла рандомными числами от -100 до 100
void write() {
	srand(time(NULL));
	ofstream num("RandomValue.txt");

	for (int i = 0; i < 1000; ++i) {
		num << rand() % 201 - 100 << endl;
	}
	num.close();
}

// вывод массива в консоль
void print(int (&arr)[1000]) {
	for (int i = 0; i < 1000; ++i) {
		if (i % 20 == 0) {
			cout << endl;
		}
		cout << arr[i] << " ";
	}
	cout << endl;
}

// сортировка массива "Пузырьком"
void sort(int(&arr)[1000]) {
	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 999; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
			}
		}
	}
}

// нахождение среднего значения в массиве
void meanValue(int(&arr)[1000]) {
	int sum = 0;
	for (int i = 0; i < 1000; ++i) {
		sum += arr[i];
	}
	cout << endl << "Среднее значение по массиву:" << (sum * 1.0) / (1000 * 1.0);
}

int main() 
{
	write();

	setlocale(LC_ALL, "ru");
	const int SIZE = 1000;
	int Array[SIZE];

	ifstream value("RandomValue.txt");

	for (int i = 0; !value.eof(); ++i) {
		value >> Array[i];
	}
	value.close();

	cout << endl << "\tНеотсортированный массив";
	print(Array);
	sort(Array);
	cout << endl << "\tОтсортированный массив";
	print(Array);
	meanValue(Array);

}