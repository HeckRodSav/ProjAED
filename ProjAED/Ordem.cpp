#pragma once
#include <cstdlib>
#include <algorithm>
#include <iostream>

namespace ED
{
	template <typename Tipo, typename Size> class Ordem
	{
		static void heapify(Tipo *vet, Size pai, Size heapsize);
		static void merge(Tipo *vet, Tipo *aux, Size esq, Size meio, Size dir);
		static void m_sort(Tipo *vet, Tipo *aux, Size esq, Size dir);
	public:
		static void InsertSort(Tipo* vet, Size length);
		static void HeapSort(Tipo *vet, Size length);
		static void MergeSort(Tipo *vet, Size length);
		static void BubbleSort(Tipo *vet, Size length);
		static void QuickSort(Tipo *vet, Size start, Size end);
		static void QuickSortCentral(Tipo *vet, Size start, Size end);
		static void QuickSortRandom(Tipo *vet, Size start, Size end);
		static void SelectSort(Tipo *vet, Size lenght);
		static void RadixSort(Tipo* vet, Size length);
		static void BeadSort(Tipo * vet, Size length, Tipo Max);
		static void qSort(Tipo * vet, Size length);
		static void Sort(Tipo * vet, Size length);

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

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::merge(Tipo * vet, Tipo * aux, Size esq, Size meio, Size dir) {
		Size i, j, k;
		i = k = esq; j = meio + 1;
		while ((i <= meio) && (j <= dir)) {
			if (vet[i] < vet[j]) aux[k++] = vet[i++];
			else aux[k++] = vet[j++];
		}
		while (i <= meio) aux[k++] = vet[i++];
		while (j <= dir) aux[k++] = vet[j++];
		while (esq <= dir) vet[esq] = aux[esq++];
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::m_sort(Tipo * vet, Tipo * aux, Size esq, Size dir)
	{
		if (dir <= esq) return;
		Size meio = (dir + esq) >> 1;
		m_sort(vet, aux, esq, meio); //First Call
		m_sort(vet, aux, meio + 1, dir); // Second Call
		if (vet[meio] <= vet[meio + 1]) return;
		merge(vet, aux, esq, meio, dir); // Merge 
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

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::MergeSort(Tipo * vet, Size length)
	{
		Tipo *aux = new Tipo[length]; // Alocacao do vetor auxiliar
		m_sort(vet, aux, 0, length - 1);
		delete aux;
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

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSort(Tipo * vet, Size start, Size end)
	{
		if (end <= start) return;

		Size i = start, j = end;
		Tipo pivo = vet[start];
		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;

		QuickSort(vet, start, i - 1);
		QuickSort(vet, i + 1, end);
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSortCentral(Tipo * vet, Size start, Size end)
	{
		if (end <= start) return;
		Size i, j;

		i = (start + end) / 2;
		Tipo pivo = vet[i];
		vet[i] = vet[start];
		vet[start] = pivo;

		i = start;
		j = end;

		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;
		QuickSortCentral(vet, start, i - 1);
		QuickSortCentral(vet, i + 1, end);
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSortRandom(Tipo * vet, Size start, Size end)
	{
		if (end <= start) return;
		Size i, j;
		i = rand() % (end - start) + start + 1;
		Tipo pivo = vet[i];
		vet[i] = vet[start];
		vet[start] = pivo;

		i = start;
		j = end;

		while (true) {
			while ((j > i) && (vet[j] > pivo)) j--;
			if (i == j) break;
			vet[i] = vet[j]; i++;
			while ((i < j) && (vet[i] < pivo)) i++;
			if (i == j) break;
			vet[j] = vet[i]; j--;
		}
		vet[i] = pivo;
		QuickSortRandom(vet, start, i - 1);
		QuickSortRandom(vet, i + 1, end);
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::SelectSort(Tipo * vet, Size length)
	{
		Tipo aux;
		Size imenor, i, j;
		for (i = 0; i < length - 1; i++) {
			imenor = i;
			for (j = i + 1; j < length; j++)
				if (vet[j] < vet[imenor]) imenor = j;
			aux = vet[i];
			vet[i] = vet[imenor];
			vet[imenor] = aux;
		}
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::RadixSort(Tipo * vet, Size length) {
		Size i, j;
		Tipo* temp = new Tipo[length];

		for (Size shift = sizeof(Tipo) * 8 - 1; shift > -1; --shift)
		{
			j = 0;

			for (i = 0; i < length; ++i)
			{
				bool move = (vet[i] << shift) >= 0;

				if (shift == 0 ? !move : move)
					vet[i - j] = vet[i];
				else
					temp[j++] = vet[i];
			}

			for (i = 0; i < j; i++)
			{
				vet[(length - j) + i] = temp[i];
			}
		}	

		delete temp;
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::BeadSort(Tipo * vet, Size length, Tipo Max)
	{
		// initialize
		Tipo *level_count = new Tipo[length + 1];
		Tipo *rod_count = new Tipo[Max + 1];
		for (Size i = 1; i <= length; i++) level_count[i] = 0;
		for (Tipo i = 1; i < Max; i++) rod_count[i] = 0;
		// sort
		for (Size i = 0; i < length; i++)
		{
			for (Tipo j = 1; j <= vet[i]; j++) {
				++level_count[++rod_count[j]];
			}
		}

		//for (int i = 0; i <= length; i++) std::cout << level_count[i] << ' '; std::couc << endl;

		for (Size i = 0; i < length; i++) vet[i] = level_count[length - i];
		delete level_count;
		delete rod_count;
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::qSort(Tipo * vet, Size length)
	{
		qsort(vet, length, sizeof(Tipo), [](const void *A, const void *B) {return *(Tipo*)A > *(Tipo*)B ? 1 : *(Tipo*)A < *(Tipo*)B ? -1 : 0;});
	}

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::Sort(Tipo * vet, Size length)
	{
		sort(vet, vet + length, [](Tipo A, Tipo B) { return A < B;});
	}
}