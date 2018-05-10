#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <math.h>

using namespace std;

void przesiewanie(vector <int> &viktor, int ilosc)
{
	viktor.clear();
	int dokad = floor(sqrt(ilosc));

	int tablica[10000];

	for (int i = 1; i <= ilosc; i++) tablica[i] = 1;

	for (int i = 2; i <= dokad; i++)
	{
		if (tablica[i] != 0)
		{
			int j = i + i;
			while (j <= ilosc)
			{
				tablica[j] = 0;
				j += i;
			}
		}
	}

	for (int i = 2; i <= ilosc; i++)
	{
		if (tablica[i] != 0)
		{
			viktor.push_back(i);
		}
	}

}


class sito
{
	int m = 0, mp = 0, r = 0, rp = 1, nwdw = 0;
	int a = 1, b = 1;
	int ilosc;
	vector <int> viktor;
public:
	void UstawDane(int ilosc, int a, int b);
	void ZabawyZVektorem();
	void RozszerzonyEuclides(int a, int b);
};

void sito::UstawDane(int ilosc, int a, int b)
{
	this->ilosc = ilosc;
	this->a = a;
	this->b = b;
}

void sito::ZabawyZVektorem()
{
	vector <int> viktor;
	for (int i = 0; i <= ilosc - 2; i++)
	{
		viktor.push_back(i + 2);
	}

	przesiewanie(viktor,ilosc);

	cout << "Po przesianiu: ";
	for (int i = 0; i < viktor.size(); i++)
	{
		cout << viktor[i] << " ";
	}
	cout << "\nKoniec przesiania";
	cout << "\n\n" << "Rozszerzony Euclides: ";

	RozszerzonyEuclides(a, b);
	cout << nwdw << " = " << mp /*Y*/ << "*" << m << " + " << rp /*X*/ << "*" << r << "\n";
	cout << "Koniec Euclidesa\n\n";
}

void sito::RozszerzonyEuclides(int a, int b)
{
	if (b == 0)
	{
		nwdw = a;
		r = a;
		return;
	}
	else
		RozszerzonyEuclides(b, a%b);

	cout << mp << "*" << m << " + " << rp << "*" << r << "\n";
	int t = mp;
	mp = (rp - floor(a / b)*mp);
	m = b;
	rp = t;
	r = a;
}


int main()
{
	sito *eras = new sito;

	eras->UstawDane(30,1920,162);
	eras->ZabawyZVektorem();


	system("pause");
	return 0;
}

//sito erastotenesa
//liczba jest pierwsza, jezeli nie istnieje liczba (pierwsza) 2 <= q <= sqrt(n) która dzieli n