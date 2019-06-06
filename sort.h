#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void quick_sort(int *vetor, int indice_esq, int indice_dir);
void bubble_sort(int *vetor, int nLinhas);
void merge_sort(int init, int end, int *vetor);
void merge(int init, int mid, int end, int *vet);
