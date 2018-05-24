#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void swap_vec(vector<int> &a)
{
	vector<int> toswap;
	for (int i = a.size() - 1;i >= 0;i--) toswap.push_back(a[i]);
	a = toswap;
}
vector<int> dec_to_bin(int a)
{
	vector<int> wynik;
	while (a > 0)
	{
		wynik.push_back(a % 2);
		a /= 2;
	}
	for (int i = wynik.size(); i < 4;i++) wynik.push_back(0);
	swap_vec(wynik);
	return wynik;
}
int bin_to_dec(vector<int> a)
{
	int liczba = 0;
	swap_vec(a);
	for (int i = 0;i < a.size();i++) if (a[i] == 1) liczba += pow(2, i);
	return liczba;
}

//vector który zapamiêtuje iloœæ wyst¹pieñ danej liczby ca³kowitej
struct Counting_vec {
	Counting_vec() {};
	Counting_vec(Counting_vec &ref) { data = ref.data; repeating = ref.repeating; };
	void sort();
	void add(int a);
	void print();
	int num_of_elements() { return data.size(); };
	int get(int i) { if (i < 0 || i >= data.size()) return 0; else return data[i]; };
private:
	vector<int> data;
	vector<int> repeating;
};
void Counting_vec::add(int a)
{
	bool exist = false;
	for (int i = 0;i < data.size();i++)
	{
		if (data[i] == a)
		{
			repeating[i]++;
			exist = true;
		}
	}
	if (!exist)
	{
		data.push_back(a);
		repeating.push_back(1);
	}
}
void Counting_vec::print()
{
	for (int i = 0;i < data.size();i++)
	{
		cout << data[i] << " appeared " << repeating[i] << " time/s in task\n";
	}
}
void Counting_vec::sort()
{
	
	if (data.size() >= 2)
	{
		for (int i = 0;i < data.size();i++)
		{
			if (i == data.size()) break;
			int swapper[3] = { data[i], repeating[i], i };

			for (int j = i;j < data.size();j++)
			{
				if (j == data.size()) break;
				if (swapper[0] > data[j])
				{
					swapper[0] = data[j];
					swapper[1] = repeating[j];
					swapper[2] = j;
				}
			}

			if (swapper[2] != i)
			{
				data[swapper[2]] = data[i]; //data[j] = data[i]
				repeating[swapper[2]] = repeating[i]; //repeating[j] = repeating[i]
				data[i] = swapper[0]; //data[i] = data[j]
				repeating[i] = swapper[1]; //repeating[i] = reapeating[j]
			}
		}
	}
	else std::cout << "There is nothing to sort!\n";

}
