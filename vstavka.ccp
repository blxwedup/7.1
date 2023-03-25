#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void outvector(vector<int>& s, int &n) //Вывод вектора
{
	for (int i = 0; i < n; ++i) 
	{
		cout << s[i] << endl;
	}
}

void vstavka(vector<int> &s, int &n) // сортировка вставками
{
	int indexlast, element, j, i;
	for (i = 1; i < n; ++i)
	{
		element = s[i];
		indexlast = i - 1;
		for (j = indexlast; j >= 0 && element < s[j]; j--)
		{
			s[j + 1] = s[j];
		}
		s[j + 1] = element;
	}
}


int main() 
{
	int t = 1000; // Количество тестов
	cout << "MergeSort   HeapSort   InsertionSort   ShellSort   QuickSort" << endl;
	while (--t)
	{
		srand(time(0));

		int n = 1000000; // Количество элементов для всех сортировок
		int k = 10000; // кол-во элементов для сортировки вставками

		vector<int> s(n);
		for (int i = 0; i < n; ++i) //Заполнение вектора
		{
			s[i] = rand();
		}

		auto start = chrono::steady_clock::now();
		mergesort(s, 0, s.size()); //Сортировка слиянием
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";

		//outVector(s, n); //Вывод вектора

		for (int i = 0; i < n; ++i) 
		{
			s[i] = rand(); //Переопределение вектора рандомными числами
		}

		start = chrono::steady_clock::now();
		heapsort(s, n); //Пирамидальная
		end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";

		vector<int> v(k); //Вектор для сортировки вставками
		for (int i = 0; i < k; ++i) 
		{
			v[i] = rand();
		}

		start = chrono::steady_clock::now();
		vstavka(v, k); // Вызов сортировки вставками
		end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";

		for (int i = 0; i < n; ++i) 
		{
			s[i] = rand(); //Переопределение вектора рандомными числами
		}

		start = chrono::steady_clock::now();
		shell(s, n); // сортировка Шелла
		end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";

		for (int i = 0; i < n; ++i) 
		{
			s[i] = rand(); //Переопределение вектора рандомными числами
		}

		start = chrono::steady_clock::now();
		qsort(s, n); // Быстрая сортировка
		end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      " << endl;
	}
}