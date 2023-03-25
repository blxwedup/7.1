#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void outvector(vector<int>& s, int& n) //Вывод вектора
{
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}
}


void qsort(vector<int>& s, int n) //быстрая сортировка
{
	int i = 0;
	int j = n - 1;
	int mid = s[n / 2];
	do
	{
		while (s[i] < mid)
		{
			++i;
		}
		while (s[j] > mid)
		{
			--j;
		}
		if (i <= j)
		{
			int tmp = s[i]; s[i] = s[j]; s[j] = tmp;
			++i;
			--j;
		}
	} while (i <= j);
	if (j > 0)
	{
		qsort(s, j + 1);
	}
	if (i < n)
	{
		qsort(s, n - i);
	}
}

int main()
{
	int t = 1000; // Количество тестов
	cout << "QuickSort" << endl;
	while (--t)
	{
		srand(time(0));

		int n = 1000000; // Количество элементов для всех сортировок

		vector<int> s(n);
		for (int i = 0; i < n; ++i) //Заполнение вектора
		{
			s[i] = rand();
		}

		auto start = chrono::steady_clock::now();
		qsort(s, n); // Быстрая сортировка
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      " << endl;
	}
}