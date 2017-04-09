#pragma once
#include <random>

namespace ED
{
	template <typename Tipo, typename Size> class Ordem
	{
		static void heapify(Tipo *vet, Size pai, Size heapsize);
	public:
		static void InsertSort(Tipo* vet, Size length);
		static void HeapSort(Tipo *vet, Size length);
		static void BubbleSort(Tipo *vet, Size length);
		static void QuickSort(Tipo *vet, Size l, Size r);
		static void QuickSortCentral(Tipo *vet, Size l, Size r);
		static void QuickSortRandom(Tipo *vet, Size l, Size r);

	};


	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::heapify(Tipo * vet, Size pai, Size heapsize)
	{
		Size fl, fr, imaior;
		fl = (pai << 1) + 1;
		fr = fl + 1;
		while (true)
		{
			if ((fl < heapsize) && (vet[fl] > vet[pai])) imaior = fl;
			else imaior = pai;
			if ((fr < heapsize) && (vet[fr] > vet[imaior])) imaior = fr;
			if (imaior != pai)
			{
				Tipo aux = vet[pai];
				vet[pai] = vet[imaior];
				vet[imaior] = aux;
				pai = imaior;
				fl = (pai << 1) + 1;
				fr = fl + 1;
			}
			else break;
		}
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::InsertSort(Tipo * vet, Size length)
	{
		Tipo aux;
		Size i = 0, j = 0;
		for (j = 1; j < length; j++)
		{
			aux = vet[j];
			i = j - 1;
			while ((i >= 0) && (vet[i] > aux))
			{
				vet[i + 1] = vet[i];
				i--;
			}
			vet[i + 1] = aux;
		}
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::HeapSort(Tipo * vet, Size length)
	{
		Size i;
		for (i = (length >> 1) - 1; i >= 0; i--) heapify(vet, i, length);
		for (i = length - 1; i > 0; i--)
		{
			Tipo aux = vet[0];
			vet[0] = vet[i];
			vet[i] = aux;
			heapify(vet, 0, i);
		}
	}
	
	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::BubbleSort(Tipo * vet, Size length)
	{
		for (Size i = length - 1; i > 0; i--)
		{
			for (Size j = 0; j < i; j++)
			{
				if (vet[j] > vet[j + 1])
				{
					Tipo a = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = a;
				}
			}
		}
	}
	
	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSort(Tipo * vet, Size l, Size r)
	{
		if (r <= l) return;

		Size i = l, j = r;
		Tipo pivo = vet[l];
		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;

		QuickSort(vet, l, i - 1); // ordena a primeira partição
		QuickSort(vet, i + 1, r); // ordena a segunda partição
	}
	
	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSortCentral(Tipo * vet, Size l, Size r) {
		if (r <= l) return;
		Size i, j;

		i = (l + r) / 2; // Troca a posição l com a posição central
		Tipo pivo = vet[i];
		vet[i] = vet[l];
		vet[l] = pivo;

		i = l;
		j = r;

		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;
		QuickSortCentral(vet, l, i - 1);
		QuickSortCentral(vet, i + 1, r);
	}
	
	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSortRandom(Tipo * vet, Size l, Size r) {
		if (r <= l) return;
		Size i, j;
		// Troca a posição l com uma posição aleatória entre l+1 e r
		i = rand() % (r - l) + l + 1;
		Tipo pivo = vet[i];
		vet[i] = vet[l];
		vet[l] = pivo;

		i = l;
		j = r;

		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;
		QuickSortRandom(vet, l, i - 1);
		QuickSortRandom(vet, i + 1, r);
	}
}