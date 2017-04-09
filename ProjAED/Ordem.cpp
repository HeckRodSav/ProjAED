#pragma once

namespace ED
{
	template <typename Tipo, typename Size> class Ordem
	{
		static void heapify(Tipo *vet, Size pai, Size heapsize);
	public:
		static void QuickSort(Tipo* vet, Size length);
		static void HeapSort(Tipo *vet, Size length);
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

	template<typename Tipo, typename Size> inline void Ordem<Tipo, Size>::QuickSort(Tipo * vet, Size length)
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
}