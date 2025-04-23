#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void troca(int *vetor, int valor1, int valor2)
{
  int auxiliar = vetor[valor1];
  vetor[valor1] = vetor[valor2];
  vetor[valor2] = auxiliar;
}

int particionar(int *vetor, int inicio, int fim)
{
  int pivo = 0;
  int pivoIndice = 0;
  int i = 0;

  pivo = vetor[fim];
  pivoIndice = inicio;
  for (i = inicio; i < fim; i++)
  {

    if (vetor[i] <= pivo)
    {

      troca(vetor, i, pivoIndice);
      pivoIndice++;
    }
  }

  troca(vetor, pivoIndice, fim);

  return pivoIndice;
}

int particionamentoAleatorio(int *vetor, int inicio, int fim)
{
  int pivoIndice = (rand() % (fim - inicio + 1)) + inicio;

  troca(vetor, pivoIndice, fim);

  return particionar(vetor, inicio, fim);
}

void quickSort(int *vetor, int inicio, int fim)
{
  if (inicio < fim)
  {

    int pivoIndice = particionamentoAleatorio(vetor, inicio, fim);

    quickSort(vetor, inicio, pivoIndice - 1);
    quickSort(vetor, pivoIndice + 1, fim);
  }
}

void bubbleSort(int *vetor, int tamanho)
{
  int atual = 0;
  int proximo = 0;
  ;
  int auxiliar = 0;

  for (atual = 1; atual < tamanho; atual++)
  {

    for (proximo = 0; proximo < tamanho - 1; proximo++)
    {

      if (vetor[proximo] > vetor[proximo + 1])
      {
        auxiliar = vetor[proximo];
        vetor[proximo] = vetor[proximo + 1];
        vetor[proximo + 1] = auxiliar;
      }
    }
  }
}

void merge(int *vetor, int tamanho)
{
  int meio = tamanho / 2;
  int i = 0, j = meio, k = 0;
  int auxiliar[tamanho];
  while (i < meio && j < tamanho)
  {
    if (vetor[i] <= vetor[j])
      auxiliar[k] = vetor[i++];
    else
      auxiliar[k] = vetor[j++];
    k++;
  }
  if (i == meio)
    while (j < tamanho)
      auxiliar[k++] = vetor[j++];
  else
    while (i < meio)
      auxiliar[k++] = vetor[i++];
  for (i = 0; i < tamanho; i++)
    vetor[i] = auxiliar[i];
}

void mergeSort(int *vetor, int tamanho)
{
  int meio = tamanho / 2;
  if (tamanho > 1)
  {
    mergeSort(vetor, meio);
    mergeSort(vetor + meio, tamanho - meio);
    merge(vetor, tamanho);
  }
}

void vetorAleatorio(int arr[], int n) 
{
  for(int i = 0; i < n; i++)
    arr[i] = rand() % 20000;
}

void medidaDeTempoFuncao(const char *funcao, int *vetor, int n)
{
  int i;

  int *vetor_tmp = malloc(n * sizeof(int));
  memcpy(vetor_tmp, vetor, n * sizeof(int));

  clock_t inicio = clock();

  if (strcmp(funcao, "BubbleSort") == 0)
  {
    bubbleSort(vetor_tmp, n);
  }
  if (strcmp(funcao, "QuickSort") == 0)
  {
    quickSort(vetor_tmp, 0, n-1);
  }
  if (strcmp(funcao, "MergeSort") == 0)
  {
    mergeSort(vetor_tmp, n);
  }
  
  clock_t fim = clock();
  double elapsed_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;

  printf("\n\nVetor ordenado com %s - Tempo Decorrido: %8.3f ms\n", funcao, elapsed_ms);
  printf("Vetor depois da ordenação (10 primeiros elementos): \n");
  for (int i = 0; i < 10; i++)
  {
    printf("[%d] ", vetor_tmp[i]);
  }
}

int main()
{
  srand((unsigned) time(NULL));

  int vetor[10] = {1, 3, 2, 8, 3, 4, 6, 5, 9, 10};
  int i = 0;

  printf("\n=== Vetor inicial de 10 elementos ===\n");
  printf("\nVetor antes da ordenação:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("[%d] ", vetor[i]);
  }

  medidaDeTempoFuncao("BubbleSort", vetor, 10);
  medidaDeTempoFuncao("QuickSort", vetor, 10);
  medidaDeTempoFuncao("MergeSort", vetor, 10);

  int sizes[] = {100, 300, 500, 1000, 10000};
  int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

  for (int i = 0; i < num_sizes; i++) 
  {
    int n = sizes[i];
    printf("\n\n=== Vetor de %d elementos ===\n", n);

    int *vetor_random = malloc(n * sizeof(int));
    vetorAleatorio(vetor_random, n);

    printf("\nVetor antes da ordenação (10 primeiros elementos)\n");
    for (int i = 0; i < 10; i++)
    {
      printf("[%d] ", vetor_random[i]);
    }

    medidaDeTempoFuncao("BubbleSort", vetor_random, n);
    medidaDeTempoFuncao("QuickSort",  vetor_random, n);
    medidaDeTempoFuncao("MergeSort",  vetor_random, n);

    free(vetor_random);
  }

  return 0;
}
