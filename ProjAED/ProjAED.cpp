#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include "Ordem.cpp"

//#define DEBUG
#define DEBUGnumber 0

#define sizeofV(X) sizeof(X) / sizeof(X[0])
#define SIZEx 1048576

using namespace std;

typedef short int si;
typedef unsigned short int usi;
typedef unsigned int ui;
typedef long int li;
typedef unsigned long int uli;

fstream fout;

ui seeed[] = { 4, 81, 151, 1601, 2307, 4207 };
uli sizee[] = { 10000, 30000, 90000, 270000, 810000, 2430000, 7290000, 21870000, 65610000 };
//uli sizee[] = { 10, 30, 90, 270, 810, 2430, 729, 2187, 6561 };
//uli sizee[] = { 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000 };
//uli sizee[] = { 50, 100, 150, 200, 250, 300, 350, 400, 450, 500 };
string algorithm_name[] = {
	"HeapSort",			//0
	"QuickSort",		//1
	"MergeSort",		//2
	"S c++",			//3
	"Qs C",				//4
	"InsertSort",		//5
	"QuickSortCentral",	//6
	"QuickSortRandom",	//7
	"SelectSort",		//8
	"RadixSort",		//9
	"BubbleSort",		//10
	"BeadSort" };		//11

string file_name = "results.txt";

void pause()
{
	system("pause");
}

int main()
{
	cout << '\a';
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

	typedef unsigned int type;
#define LEN 20

	uniform_int_distribution<type> sqn(0, SIZEx);
	mt19937 rad;
	rad.seed(clock());
	type *teste = new type[LEN];
	//type teste[LEN];
	for (ui i = 0; i < LEN; i++) teste[i] = sqn(rad);
	for (ui i = 0; i < LEN; i++) cout << teste[i] << ' ';
	cout << endl;


	ED::Ordem<type, int>::QuickSortCentral(teste, 0, LEN);

	cout << endl;

	for (ui i = 0; i < LEN; i++) cout << teste[i] << ' ';
	cout << endl;

#elif DEBUGnumber == 1

	auto n = 10;
	auto m = 5;
	for (int i = 0; i < n; i++) cout << ((int)(rand() / (double)(RAND_MAX + 1.0) * m) + 1) << ' '; cout << endl;

#else
	unsigned int a = 0;
	cout << "Nothing" << endl << --a << endl;
#endif

#else

	double start = 0, end = 0;
	ui *V = new ui[sizee[sizeofV(sizee)-1]];

	fout.open(file_name, ios::app);
	uniform_int_distribution<ui> seq(0,SIZEx);
	mt19937 rnd;

	for (ui i = 0; i < sizeofV(algorithm_name); i++) //Select algorithm
	{
		cout << setfill(' ') << setw(15) << left << algorithm_name[i] << "  "; //Show name
		fout << setfill(' ') << setw(15) << left << algorithm_name[i] << "  ";
		for (ui k = 0; k < sizeofV(seeed); k++)
		{
			cout << seeed[k] << '\t'; //Show index
			fout << seeed[k] << '\t';
		}
		cout << endl;
		fout << endl;

		for (ui j = 0; j < sizeofV(sizee); j++) //Select size of vector
		{
			for (uli l = 0; l < sizee[j]; l++) V[l] = 0; //Clean the vector in the used space

			cout << "size: " << setfill(' ') << setw(9) << left << sizee[j] << ": "; //Show size
			fout << "size: " << setfill(' ') << setw(9) << left << sizee[j] << ": "; //Show size

			for (ui k = 0; k < sizeofV(seeed); k++) //Select current seed
			{
				rnd.seed(seeed[k]); //Set random seed
				for (uli l = 0; l < sizee[j]; l++) V[l] = seq(rnd); //Set random vector

				start = clock();
				switch (i)
				{
				case 0:	 ED :: Ordem<ui, li>  :: HeapSort(V, sizee[j]);				break; /* HeapSort			*/
				case 1:	 ED :: Ordem<ui, li>  :: QuickSort(V, 0, sizee[j]);			break; /* QuickSort			*/
				case 2:	 ED :: Ordem<ui, uli> :: MergeSort(V, sizee[j]);			break; /* MergeSort			*/
				case 3:	 ED :: Ordem<ui, uli> :: Sort(V, sizee[j]);					break; /* S C++				*/
				case 4:	 ED :: Ordem<ui, uli> :: qSort(V, sizee[j]);				break; /* Qs C				*/
				case 5:	 ED :: Ordem<ui, li>  :: InsertSort(V, sizee[j]);			break; /* InsertSort		*/
				case 6:  ED :: Ordem<ui, li>  :: QuickSortCentral(V, 0, sizee[j]);	break; /* QuickSortCentral	*/
				case 7:  ED :: Ordem<ui, li>  :: QuickSortRandom(V, 0, sizee[j]);	break; /* QuickSortRandom	*/
				case 8:	 ED :: Ordem<ui, uli> :: SelectSort(V, sizee[j]);			break; /* SelectSort		*/
				case 9:	 ED :: Ordem<ui, uli> :: RadixSort(V, sizee[j]);			break; /* BubbleSort		*/
				case 10: ED :: Ordem<ui, uli> :: BubbleSort(V, sizee[j]);			break; /* BubbleSort		*/
				case 11: ED :: Ordem<ui, ui>  :: BeadSort(V, sizee[j], SIZEx);		break; /* BeadtSort			*/
				default: cout << '?'; break;
				}
				end = clock();
				cout << 1000.0 * (end - start) / (CLOCKS_PER_SEC) << '\t';
				fout << 1000.0 * (end - start) / (CLOCKS_PER_SEC) << '\t';
			}
			cout << endl;
			fout << endl;

		}
		cout << endl; //Break line after a algorithm
		fout << endl;
	}
	fout.close();
#endif
	cout << '\a';
	pause();
	return 0;
}

