#include "sort.h"

int partition(int *vet, int init, int end) {
   int c = vet[end]; 
   int t, j = init;
   
    for (int i = init; i < end; i++)
      if (vet[i] <= c) {
         t = vet[j], vet[j] = vet[i], vet[i] = t;
         j++; 
      }

   t = vet[j]; 
   vet[j] = vet[end];
   vet[end] = t;
   
   return j; 
}



void quick_sort(int *vet, int init, int end) {    
    while(init < end){
    int j = partition(vet, init, end);
        if(j - init < end - j){
            quick_sort(vet, init, j-1);
            init = j + 1;
        }else{
            quick_sort(vet, j+1, end);
            end = j - 1;
        }
   }
     
}

void bubble_sort(int *vet, int size) {
    int aux = 0;   
    int cont;  
   
    do{
        cont = 0;
            for(int i=0; i<size-1; i++){   
                if(vet[i] > vet[i+1]){
                    aux = vet[i+1];
                    vet[i+1] = vet[i];
                    vet[i] = aux;
                    cont = 1;
                }
            }
    }while(cont == 1);
}

void merge(int init, int mid, int end, int *vet){
    int i, j, *vettemp;
    vettemp = malloc ((end - init) * sizeof(int));

    for(i = init; i < mid; ++i) vettemp[i - init] = vet[i];
    for(j = mid; j < end; ++j) vettemp[end-init+mid-j-1] = vet[j];
    i = 0; j = end-init-1;    
    for(int k = init; k < end; ++k)
        if(vettemp[i] <= vettemp[j]) vet[k] = vettemp[i++];
        else vet[k] = vettemp[j--];
     free (vettemp);   
}
void merge_sort(int init, int end, int *vet){
    if(init < end - 1){
        int mid = (init + end) / 2;
        merge_sort(init, mid, vet);
        merge_sort(mid, end, vet);
        merge(init, mid, end,vet);
    }
}

