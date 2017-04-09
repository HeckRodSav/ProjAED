#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <cstdlib>
#include <string>
#include "Ordem.cpp"

//#define DEBUG

using namespace std;

typedef long int li;
typedef unsigned int ui;
typedef unsigned long int uli;

ui seeed[] = { 4, 81, 151, 1601, 2307, 4207 };
//uli sizee[] = { 1000,30000,90000,270000,810000,243000,7290000,21870000,65610000 };
uli sizee[] = { 10, 30, 90, 270, 810, 2430, 729, 2187, 6561 };
string tipe_name[] = { "heapsort", "quicksort", "Mergesort", "S c++", "Qs C" };
ui time_name_size = 5;

int main()
{
	double start = 0, end = 0;
	int *V = new int[sizee[8]];

	uniform_int_distribution<int32_t> seq;
	mt19937 rnd;

#ifdef DEBUG
	uniform_int_distribution<int32_t> sqn(0,50);
	rnd.seed(clock());
	int teste[10];
	for (int i = 0; i < 10; i++) teste[i] = sqn(rnd);
	for (int i = 0; i < 10; i++) cout << teste[i] << ' ';
	cout << endl;

	ED::Ordem<int, int>::HeapSort(teste, 10);

	for (int i = 0; i < 10; i++) cout << teste[i] << ' ';
	cout << endl;
#endif


	for (ui i = 0; i < time_name_size; i++) //Select algorithm
	{
		cout << setfill(' ') << setw(15) << left << tipe_name[i] << "  "; //Show name
		for (ui k = 0; k < sizeof(seeed) / sizeof(seeed[0]); k++) cout << seeed[k] << '\t'; //Show index
		cout << endl;

		for (ui j = 0; j < sizeof(sizee) / sizeof(sizee[0]); j++) //Select size of vector
		{
			for (uli l = 0; l < sizee[j]; l++) V[l] = 0; //Clean the vector in the used space

			cout << "size: " << setfill(' ') << setw(9) << left << sizee[j] << ": "; //Show size

			for (ui k = 0; k < sizeof(seeed) / sizeof(seeed[0]); k++) //Select current seed
			{
				rnd.seed(seeed[k]); //Set random seed
				for (uli l = 0; l < sizee[j]; l++) V[l] = seq(rnd); //Set random vector

				start = clock();
				switch (i)
				{
				case 0:	//HeapSort
					ED::Ordem<int, li>::HeapSort(V, sizee[j]);
					break;
				case 1: //QuickSort
					ED::Ordem<int, uli>::QuickSort(V, sizee[j]);
					break;
				case 2:	//MergeSort
					//cout << 'c';
					break;
				case 3:	//S C++
					//cout << 'd';
					break;
				case 4: //Qs C
					//cout << 'e';
					break;
				}
				end = clock();
				cout << 1000.0 * (end - start) / (CLOCKS_PER_SEC) << '\t';
			}
			cout << endl;

		}
		cout << endl; //Break line after a algorithm
	}
	return 0;
}

