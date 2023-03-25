#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
using namespace std;

void mergesort(vector<int>& s, size_t start, size_t end)
{
	if (end - start < 2)
	{
		return;
	}
	if (end - start == 2)
	{
		if (s[start] > s[start + 1])
		{
			swap(s[start], s[start + 1]);
		}
		return;
	}
	mergesort(s, start, start + (end - start) / 2);
	mergesort(s, start + (end - start) / 2, end);
	vector<int> b;
	size_t bl = start;
	size_t el = start + (end - start) / 2;
	size_t b2 = el;
	while (b.size() < end - start) {
		if (bl >= el || (b2 < end && s[b2] <= s[bl]))
		{
			b.push_back(s[b2]);
			++b2;
		}
		else
		{
			b.push_back(s[bl]);
			++bl;
		}
	}
	for (size_t i = start; i < end; ++i)
	{
		s[i] = b[i - start];
	}
}

int main()
{
	int t = 1000;
	cout << "MergeSort" << endl;
	while (--t)
	{
		srand(time(0));

		int n = 1000000;
		int k = 10000;

		vector<int> s(n);
		for (int i = 0; i < n; ++i)
		{
			s[i] = rand();
		}

		auto start = chrono::steady_clock::now();
		mergesort(s, 0, s.size());
		auto end = chrono::steady_clock::now();

		cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;
		for (int i = 0; i < n; ++i)
		{
			s[i] = rand();
		}
	}
}