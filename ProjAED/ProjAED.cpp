#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <cstdlib>
#include <string>
#include "Ordem.cpp"

using namespace std;

unsigned int seeed[] = { 4,81,151,1601,2307,4207 };
unsigned long int sizee[] = { 1000,30000,90000,270000,810000,243000,7290000,21870000,65610000 };
string tipe_name[] = { "heapsort", "quicksort", "Mergesort", "S c++", "Qs C" };
unsigned int time_name_size = 5;

typedef unsigned int ui;

int main()
{

	for (ui i = 0; i < time_name_size; i++) //Select algorithm
	{
		cout << setfill(' ') << setw(15) << left << tipe_name[i] << "  "; //Show name
		for (ui k = 0; k < sizeof(seeed) / sizeof(seeed[0]); k++) cout << seeed[k] << '\t'; //Show index
		cout << endl;

		for (ui j = 0; j < sizeof(sizee) / sizeof(sizee[0]); j++) //Select size of vector
		{
			cout << "size: " << setfill(' ') << setw(9) << left << sizee[j] << ": "; //Show size

			for (ui k = 0; k < sizeof(seeed) / sizeof(seeed[0]); k++) //Select current seed
			{

				/*
				...
				...
				...
				*/

			}
			cout << endl;

		}
		cout << endl; //Break line after a algorithm
	}
    return 0;
}

