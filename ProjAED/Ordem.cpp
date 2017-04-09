#pragma once

namespace ED
{
	template <typename Tipo> class Ordem
	{
	public:
		static void QuickSort(Tipo* vet, int length)
		{
			Tipo aux;
			int i = 0, j = 0;
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
	};
}