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

void heapify(vector <int>& s, int n, int i) // функция для пирамидальной
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && s[l] > s[largest])
		largest = l;
	if (r < n && s[r] > s[largest])
		largest = r;
	if (largest != i)
	{
		swap(s[i], s[largest]);
		heapify(s, n, largest);
	}
}

void heapsort(vector <int>& s, int& n) //Пирамидальная
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(s, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(s[0], s[i]);
		heapify(s, i, 0);
	}
}



int main()
{
	int t = 1000; // Количество тестов
	cout << "HeapSort" << endl;
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
		heapsort(s, n); //Пирамидальная
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";

		
	}
}