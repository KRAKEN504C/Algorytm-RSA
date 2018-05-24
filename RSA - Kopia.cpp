//#include <iostream>
//#include <vector>
//#include <stdio.h>
//#include <conio.h>
//#include <math.h>
//#include <time.h>
//
//using namespace std;
//
//int odwr_mod(int a, int n)
//{
//	int a0, n0, p0, p1, q, r, t;
//
//	p0 = 0; p1 = 1; a0 = a; n0 = n;
//	q = n0 / a0;
//	r = n0 % a0;
//	while (r > 0)
//	{
//		t = p0 - q * p1;
//		if (t >= 0)
//			t = t % n;
//		else
//			t = n - ((-t) % n);
//		p0 = p1; p1 = t;
//		n0 = a0; a0 = r;
//		q = n0 / a0;
//		r = n0 % a0;
//	}
//	return p1;
//}
//
//int nwd(int a, int b)
//{
//	int t;
//
//	while (b != 0)
//	{
//		t = b;
//		b = a % b;
//		a = t;
//	};
//	return a;
//}
//
//int pot_mod(int a, int w, int n)
//{
//	int pot, wyn, q;
//
//	// wykładnik w rozbieramy na sumę potęg 2
//	// przy pomocy algorytmu Hornera. Dla reszt
//	// niezerowych tworzymy iloczyn potęg a modulo n.
//
//	pot = a; wyn = 1;
//	for (q = w; q > 0; q /= 2)
//	{
//		if (q % 2) wyn = (wyn * pot) % n;
//		pot = (pot * pot) % n; // kolejna potęga
//	}
//	return wyn;
//}
//
////generowanie liczb pierwszych przez sito eratostenesa
//void przesiewanie(vector <int> &viktor, int ilosc)
//{
//	viktor.clear();
//	int dokad = floor(sqrt(ilosc));
//
//	int tablica[10000];
//
//	int *pointer2Array = new int[ilosc];
//
//	for (int i = 1; i <= ilosc; i++) pointer2Array[i] = 1;
//
//	for (int i = 2; i <= dokad; i++)
//	{
//		if (pointer2Array[i] != 0)
//		{
//			int j = i + i;
//			while (j <= ilosc)
//			{
//				pointer2Array[j] = 0;
//				j += i;
//			}
//		}
//	}
//
//	//liczby pierwsze zostaja wprowadzone do vektora
//	for (int i = 2; i <= ilosc; i++)
//	{
//		if (pointer2Array[i] != 0)
//		{
//			viktor.push_back(i);
//		}
//	}
//}
//
//
//class sito
//{
//	int m = 0, mp = 0, r = 0, rp = 1, nwdw = 0;
//	int a = 1, b = 1, p = 0, q = 0, t = 0;
//	long long int e = 1000;
//	long long int s = 0;
//	//powyzsze zmienne sa wykorzystywane do sita eratostenesa
//	int ilosc;
//	vector <int> viktor;
//public:
//	void UstawDane(int ilosc, int a, int b,int t);
//	void ZabawyZVektorem();
//	void RozszerzonyEuclides(int a, int b);
//	void RSA();
//};
//
//void sito::UstawDane(int ilosc, int a, int b,int t)
//{
//	this->ilosc = ilosc;
//	this->a = a;
//	this->b = b;
//	this->t = t;
//}
//
//void sito::ZabawyZVektorem()
//{
//	vector <int> viktor;
//	for (int i = 0; i <= ilosc - 2; i++)
//	{
//		viktor.push_back(i + 2);
//	}
//
//	przesiewanie(viktor, ilosc);
//
//	cout << "Po przesianiu: ";/*
//							  for (int i = 0; i < viktor.size(); i++)
//							  {
//							  cout << viktor[i] << " ";
//							  }*/
//	cout << "Wygenerowano " << viktor.size() << " liczb pierwszych\n";
//	if (viktor.size() >= 78983)
//	{
//		cout << "Liczba o indeksie 78983\t" << viktor[78983 - 1] << endl;
//	}
//	if (viktor.size() >= 100000)
//	{
//		cout << "Liczba o indeksie 100000\t" << viktor[100000 - 1] << endl;
//	}
//	p = viktor[viktor.size() - 1];
//	q = viktor[viktor.size() - 2];
//	cout << "Pierwsza najwieksza wartosc do " << ilosc << " : " << viktor[viktor.size() - 1] << endl;
//	cout << "Druga najwieksza wartosc do " << ilosc << " : " << viktor[viktor.size() - 2] << endl;
//	cout << "\nKoniec przesiania";
//	cout << "\n\n" << "Rozszerzony Euclides: ";
//
//	RozszerzonyEuclides(a, b);
//	cout << nwdw << " = " << mp /*Y*/ << "*" << m << " + " << rp /*X*/ << "*" << r << "\n";
//	cout << "Koniec Euclidesa\n\n";
//
//	cout << "\n\n" << "RSA: ";
//	RSA();
//}
//
//void sito::RozszerzonyEuclides(int a, int b)
//{
//	if (b == 0)
//	{
//		nwdw = a;
//		r = a;
//		return;
//	}
//	else
//		RozszerzonyEuclides(b, a%b);
//
//	//cout << mp << "*" << m << " + " << rp << "*" << r << "\n";
//	int t = mp;
//	mp = (rp - floor(a / b)*mp);
//	m = b;
//	rp = t;
//	r = a;
//	cout << nwdw << " = " << mp /*Y*/ << "*" << m << " + " << rp /*X*/ << "*" << r << "\n";
//}
//
//void sito::RSA()
//{
//	p = 11;
//	q = 13;
//	long long int nRSA = p*q;
//	long long int mRSA = (p - 1)*(q - 1);
//	long double d;
//	/*
//	nwdw = 0;
//	while (nwdw!=1)
//	{
//		e = /*rand() % m - 1 601;
//		RozszerzonyEuclides(e, m);
//	}
//	d = pow(e, -1);
//	d = rp;
//	*/
//
//	for (e = 3; nwd(e, mRSA) != 1; e += 2);
//	d = odwr_mod(e, mRSA);
//
//	/*
//	if (rp < 0) d = -rp;
//	else d = rp;
//	*/
//	//cout << "e : " << e << " d : " << d;
//	//cout << "d*e powinno rownac sie 1 : " << d*e << endl;
//	//cout << "nwdw w RSA: " << nwdw;
//
//	//klucz publiczny (nRSA,e)
//	//klucz prywatny (nRSA,d)
//
//	cout << "Klucz publiczny: \ne = " << e << "\nn = " << nRSA << endl;
//	cout << "Klucz prywatny: \nd = " << d << endl;
//
//	int zakodowane = pot_mod(t, e, nRSA);
//	cout << "t: " << t << "\t e: " << e << "\t n: " << nRSA<<endl;
//	cout << "kodowanie za pomoca powyzszysz danych: " << endl;
//	cout << "Wynik kodowania: " << zakodowane << endl;
//	cout << "Wynik odkodowania: " << pot_mod(zakodowane, d, nRSA);
//	/*
//	s = pow(t, e);
//	cout << s;
//	s %= nRSA;
//	*/
//}
//
//int main()
//{
//	srand(time(NULL));
//	sito *eras = new sito;
//
//	eras->UstawDane(550, 1920, 162, 1410);
//	eras->ZabawyZVektorem();
//
//
//	system("pause");
//	return 0;
//}
//
////sito erastotenesa
////liczba jest pierwsza, jezeli nie istnieje liczba (pierwsza) 2 <= q <= sqrt(n) ktora dzieli n















#include <time.h>
#include "helper_functions.hpp"

vector<int> sito(int n)
{
	if (n <= 1) return{ 0 };
	vector<int> vec;
	for (int i = 2; i < n; i++)
		vec.push_back(i);

	int i = 0;
	while (vec[i] <= sqrt(n))
	{
		vector<int> temp;
		for (int j = 0; j <= i; j++) temp.push_back(vec[j]);
		for (int j = i + 1; j < vec.size(); j++)
			if ((vec[j] % vec[i]) != 0) temp.push_back(vec[j]);
		vec = temp;
		i++;
	}

	return vec;
}

vector<int> euklides(int a, int b, vector<int> &tab_x)
{

	int r0 = a;
	int r1 = b;
	int x1 = 1, x2;
	int y1 = -(r0 / r1), y2;
	int setup = 1;

	while (r1 != 0)
	{
		int q = r0 / r1;
		int rj = r0 - r1 * q;
		r0 = r1;
		r1 = rj;

		if (setup == 2)
		{
			x2 = -(x1*q);
			y2 = 1 - (y1 * q);
		}
		else if (setup >= 3)
		{
			int x = x1 - (x2 * q);
			int y = y1 - (y2 * q);

			x1 = x2;
			x2 = x;

			y1 = y2;
			y2 = y;
		}
		tab_x.push_back(x1);
		setup++;
	}

	//cout << "nwd = " << r0 << " x = " << x1 << " y = " << y1 << endl;

	return{ r0,x1,y1 };
}

int pot_mod(int a, int w, int n)
{
	int pot, wyn, q;

	pot = a; wyn = 1;
	for (q = w; q > 0; q /= 2)
	{
		if (q % 2) wyn = (wyn * pot) % n;
		pot = (pot * pot) % n; // kolejna potęga
	}
	return wyn;
}

void sitko(bool *tab, unsigned int n)
{
	for (int i = 2; i*i <= n; i++) //przeszukujemy kolejnych kandydat�w na pierwsze
	{                           //wystarczy sprawdzi� do pierwiastka z n
								// i<=sqrt(n) - podnosz�c do kwadratu mamy
								// i*i <= n
		if (!tab[i])                //jesli liczba jest pierwsza(ma wartosc 0)
			for (int j = i*i; j <= n; j += i) //to wykreslamy jej wielokrotnosci
				tab[j] = 1;         //ustawiaj�c wartos� na 1
	}
}

unsigned long long int PochodnaSitka(int n)
{
	bool *tab;

	unsigned long  n_kwadrat = 16 * n;
	tab = new bool[n_kwadrat + 1];

	for (long long int i = 2; i <= 16 * n; i++) //zerowanie tablicy
		tab[i] = 0;

	sitko(tab, 16 * n); //przesianie liczb

	int pirwsza;

	int pierwsza = 0;
	for (int i = 2; i <= 16 * n; i++)
	{
		if (!tab[i])
			pierwsza++;
		if (pierwsza == n) { cout << i << endl; pirwsza = i; break; }
	}


	cout << endl;

	return pirwsza;

	delete[]tab;
}

void RSA()
{
	srand(time(NULL));
	vector<int> primary_numbers;
	vector<int> NWD;
	vector<int> X;
	int e;
	int d = 0;
	primary_numbers = sito(20000); //incjalizacja 2200 liczb losowych

	int p = rand() % 1200 + 1000; //wybieranie p i q
	int q = rand() % 1200 + 1000;
	p = PochodnaSitka(10432);//p = primary_numbers[p];
	q = PochodnaSitka(43561);//q = primary_numbers[q];
	cout << "LIczba pierwsza o indeksie: " << primary_numbers.size() << " wynosi: " << primary_numbers[primary_numbers.size() - 1] << endl;
	//int p = primary_numbers[320];
	//int q = primary_numbers[122];
	cout << "p: " << p << " q: " << q << endl;

	unsigned long long int n = p * q; //generacja n i m
	unsigned long long int m = (p - 1) * (q - 1);
	cout << "n: " << n << " m: " << m << endl;

	do                                  //wybieranie e
	{
		vector<int> temp;
		e = (rand() % m) + 1;
		//e = 7;
		NWD = euklides(e, m, temp);
		X = temp;
	} while (NWD[0] != 1);
	cout << "NWD: " << NWD[0] << " e: " << e << endl;

	vector<int> temp;
	NWD = euklides(8280, 990, temp);
	cout << "NWD: " << NWD[0] << " x: " << NWD[1] << " y: " << NWD[2] << endl;

	/*for (int i = X.size() - 1;i >= 0;i--)
	{
	cout << "X" << i << ": " << X[i] << endl;
	if (X[i] > 0)
	{
	d = X[i];
	break;
	}
	}*/
	if (NWD[1] > 0) d = NWD[1];
	else
	{
		NWD[1] += m;
		if (NWD[1] > 0) d = NWD[1];
	}
	cout << "d: " << d << endl;

	cout << "Klucz publiczny (" << n << ", " << e << ")" << endl;
	cout << "Klucz prywatny (" << n << ", " << d << ")" << endl;
	/*
	int liczba;
	cin >> liczba;
	int zakodowane = pot_mod(liczba, e, n);
	cout << "Twoja liczba zakodowana: " << zakodowane << endl;
	cout << "Twoja liczba po odkodowaniu: " << pot_mod(zakodowane, e, d);*/

}



int main()
{
	//vector<int> sitko;
	//sitko = sito(20000);
	//for (auto x : sitko) cout << x << " ";
	//cout << sitko.size() << endl;

	//vector<int> nwd;
	//nwd = euklides(8280, 990);
	//for (auto x : nwd) cout << x << " ";
	//cout << endl;
	int n;
	cout << "Podaj index liczby pierwszej, ktora chcialbys zobaczyc: ";
	cin >> n;

	PochodnaSitka(n);


	RSA();
	system("pause");
	return 0;
}