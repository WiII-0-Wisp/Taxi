#include <iostream>
#include <string>
using namespace std;

void qsort(int* mas, int* mas_index, int size) { // быстрая сортировка
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
	int N, j;
	string s;
	bool f = 1;
	cout << "Введите количество сотрудников фирмы (целое число 1<= N <=1000): ";
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) { // посимвольная проверка
		if ((s[i] < 48) || (s[i] > 57)) {
			f = 0;
			break;
		}
	}
	if (f) { // если всё нормально
		N = stoi(s); // строка в число
		int* mas1 = new int[N];
		int* mas2 = new int[N];
		int* mas1_index = new int[N];
		int* mas2_index = new int[N];
		for (int i = 0; i < N; i++) { // заполняю массив индексов 0, 1, 2, ..., N
			mas1_index[i] = i;
			mas2_index[i] = i;
		}

		cout << "\nВведите расстояния от работы до домов всех сотрудников (N положительных целых чисел, не превышающих 1000, через enter без лишних символов): ";
		bool f1 = 1;
		for (int i = 0; i < N; i++) { // заполняю массив сотрудников
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) { // проверка на вшивость очередного элемента
				if ((s[i] < 48) || (s[i] > 57)) {
					f1 = 0;
				}
			}
			if (f1) { // если всё праивльно
				mas1[i] = stoi(s); // строка в число
			} else {
				cout << "Некорректные данные.\n\n";
				break;
			}
		}
		if (f1) { // если данные были верны
			cout << "\nВведите тарифы за проезд одного километра каждого такси (N положительных целых чисел, не превышающих 1000, через enter без лишних символов): ";
			bool f2 = 1;
			for (int i = 0; i < N; i++) { // всё по аналогии 
				getline(cin, s);
				f2 = 1;
				for (int i = 0; i < s.size(); i++) {
					if ((s[i] < 48) || (s[i] > 57)) {
						f2 = 0;
					}
				}
				if (f2) {
					mas2[i] = stoi(s);
				}
				else {
					cout << "Некорректные данные.\n\n";
					break;
				}
			}
			if (f2) { // если всё правильно
				qsort(mas1, mas1_index, N); // сортировка массива сотрудников и их индексов
				qsort(mas2, mas2_index, N); // сортировка массива такси и их индексов
				for (int i = 0; i < N / 2; i++) { // реверс массива такси и их индексов (не писать же новую сортировку)
					swap(mas2[i], mas2[N - i - 1]);
					swap(mas2_index[i], mas2_index[N - i - 1]);
				}
				qsort(mas1_index, mas2_index, N); // сортировка индексов сотрудников и индексов такси чтобы вывести их по порядку

				for (int i = 0; i < N; i++) { // вывод
					cout << "\nСотрудник №" << i + 1 << " уедет на такси №" << mas2_index[i] + 1 << ";";
				}

				cout << "\n\n";
				delete[] mas1, mas1_index, mas2, mas2_index; // чистка
			}
		}
	} else {
		cout << "Некорректные данные.\n\n";
	}
	return 0;
}

