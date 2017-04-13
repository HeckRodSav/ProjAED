#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <cstdlib>
#include <string>
#include "Ordem.cpp"
#include <cstdio>

#include <vector>

#define DEBUG
#define DEBUGnumber 0

#define sizeofV(X) sizeof(X) / sizeof(X[0])

using namespace std;

typedef long int li;
typedef unsigned int ui;
typedef unsigned long int uli;

ui seeed[] = { 4, 81, 151, 1601, 2307, 4207 };
//uli sizee[] = { 1000,30000,90000,270000,810000,243000,7290000,21870000,65610000 };
uli sizee[] = { 10, 30, 90, 270, 810, 2430, 729, 2187, 6561 };
//uli sizee[] = { 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000 };
//uli sizee[] = { 50, 100, 150, 200, 250, 300, 350, 400, 450, 500 };
string tipe_name[] = {
	"HeapSort",			//0
	"QuickSort",		//1
	"MergeSort",		//2
	"S c++",			//3
	"Qs C",				//4
	"InsertSort",		//5
	"BeadSort",			//6
	"QuickSortCentral",	//7
	"QuickSortRandom",	//8
	"SelectSort",		//9
	"BubbleSort" };		//10


int main()
{
#ifdef DEBUG

#if DEBUGnumber == 0
	/*ui ini, fim;
	cout << "Inicio do intervalo: ";
	cin >> ini;
	cout << endl << "Fim do intervalo: ";
	cin >> fim;
	cout << endl;
	uniform_int_distribution<int> sqn(ini, fim);
	*/

	uniform_int_distribution<int> sqn(0, 500);
	mt19937 rad;
	rad.seed(clock());
	int teste[50];
	for (ui i = 0; i < 50; i++) teste[i] = sqn(rad);
	for (ui i = 0; i < 50; i++) cout << teste[i] << ' ';
	cout << endl;

	//ED::Ordem<int, int>::BeadSort(teste, 10);
	ED::Ordem<int, int>::BeadSort(teste, sizeofV(teste), 500);


	for (ui i = 0; i < 50; i++) cout << teste[i] << ' ';
	cout << endl;

#elif DEBUGnumber == 1

	auto n = 10;
	auto m = 5;
	for (int i = 0; i < n; i++) cout << ((int)(rand() / (double)(RAND_MAX + 1.0) * m) + 1) << ' '; cout << endl;

#else
	cout << "Nothing" << endl;
#endif

#else
	double start = 0, end = 0;
	int *V = new int[sizee[8]];

	uniform_int_distribution<int32_t> seq;
	mt19937 rnd;

	for (ui i = 0; i < sizeofV(tipe_name); i++) //Select algorithm
	{
		cout << setfill(' ') << setw(15) << left << tipe_name[i] << "  "; //Show name
		for (ui k = 0; k < sizeofV(seeed); k++) cout << seeed[k] << '\t'; //Show index
		cout << endl;

		for (ui j = 0; j < sizeofV(sizee); j++) //Select size of vector
		{
			for (uli l = 0; l < sizee[j]; l++) V[l] = 0; //Clean the vector in the used space

			cout << "size: " << setfill(' ') << setw(9) << left << sizee[j] << ": "; //Show size

			for (ui k = 0; k < sizeofV(seeed); k++) //Select current seed
			{
				rnd.seed(seeed[k]); //Set random seed
				for (uli l = 0; l < sizee[j]; l++) V[l] = seq(rnd) % (i == 6 ? 1000 : 1); //Set random vector

				start = clock();
				switch (i)
				{
				case 0:	//HeapSort
					ED::Ordem<int, li>::HeapSort(V, sizee[j]);
					break;
				case 1: //QuickSort
					ED::Ordem<int, li>::QuickSort(V, 0, sizee[j]);
					break;
				case 2:	//MergeSort
					ED::Ordem<int, uli>::MergeSort(V, sizee[j]);
					break;
				case 3:	//S C++
					//cout << 'd';
					break;
				case 4: //Qs C
						//cout << 'e';
					break;
				case 5: //InsertSort
					ED::Ordem<int, uli>::InsertSort(V, sizee[j]);
					break;
				case 6: //InsertSort
					ED::Ordem<int, int>::BeadSort(V, sizee[j]);
					break;
				case 7: //QuickSortCentral
					ED::Ordem<int, li>::QuickSortCentral(V, 0, sizee[j]);
					break;
				case 8: //QuickSortRandom
					ED::Ordem<int, li>::QuickSortRandom(V, 0, sizee[j]);
					break;
				case 9: //SelectSort
					ED::Ordem<int, uli>::SelectSort(V, sizee[j]);
					break;
				case 10: //BubbleSort
					ED::Ordem<int, uli>::BubbleSort(V, sizee[j]);
					break;
				default:
					cout << '?';
					break;
				}
				end = clock();
				cout << 1000.0 * (end - start) / (CLOCKS_PER_SEC) << '\t';
			}
			cout << endl;

		}
		cout << endl; //Break line after a algorithm
	}
#endif
	return 0;
}

