#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void outvector(vector<int>& s, int& n) //����� �������
{
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}
}

void shell(vector <int>& arr, int& n)  // ���������� �����
{
	for (int d = n / 2; d > 0; d /= 2)
	{
		for (int i = d; i < n; ++i)
		{
			int el = arr[i];
			int j;
			for (j = i; j >= d && arr[j - d] > el; j -= d)
			{
				arr[j] = arr[j - d];
			}
			arr[j] = el;
		}
	}
}

int main()
{
	int t = 1000; // ���������� ������
	cout << "ShellSort" << endl;
	while (--t)
	{
		srand(time(0));

		int n = 1000000; // ���������� ��������� ��� ���� ����������


		vector<int> s(n);
		for (int i = 0; i < n; ++i) //���������� �������
		{
			s[i] = rand();
		}

		auto start = chrono::steady_clock::now();
		shell(s, n); // ���������� �����
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << "      ";


	}
}