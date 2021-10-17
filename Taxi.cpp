#include "iostream"
using namespace std;

void qsort(int* mas, int* mas_index, int size) {
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];
	do {
		while (mas[i] < mid) {
			i++;
		}
		while (mas[j] > mid) {
			j--;
		}
		if (i <= j) {
			swap(mas[i], mas[j]);
			swap(mas_index[i], mas_index[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		qsort(mas, mas_index, j + 1);
	}
	if (i < size) {
		qsort(&mas[i], &mas_index[i], size - i);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	int N;
	cout << "Введите количество сотрудников фирмы (целое число 1<= N <=1000): ";
	cin >> N;
	int* mas1 = new int[N];
	int* mas2 = new int[N];
	int* mas1_index = new int[N];
	int* mas2_index = new int[N];
	cout << "\nВведите расстояния от работы до домов всех сотрудников (N положительных целых чисел, не превышающих 1000): ";
	for (int i = 0; i < N; i++) {
		cin >> mas1[i];
		mas1_index[i] = i;
		mas2_index[i] = i;
	}
	cout << "\nВведите тарифы за проезд одного километра каждого такси (N положительных целых чисел, не превышающих 1000): ";
	for (int i = 0; i < N; i++) {
		cin >> mas2[i];
	}

	qsort(mas1, mas1_index, N);
	qsort(mas2, mas2_index, N);
	for (int i = 0; i < N / 2; i++) {
		swap(mas2[i], mas2[N - i - 1]);
		swap(mas2_index[i], mas2_index[N - i - 1]);
	}
	qsort(mas1_index, mas2_index, N);

	for (int i = 0; i < N; i++) {
		cout << "\nСотрудник №" << i + 1 << " уедет на такси №" << mas2_index[i] + 1 << ";";
	}

	cout << "\n\n";
	delete[] mas1, mas1_index, mas2, mas2_index;
	return 0;
}

