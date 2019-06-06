#include <stdio.h>
#include <stdlib.h>

// Bibliotecas pessoais
#include "vector.h"
#include "toolsvector.h"
#include "sort.h"

int main(int argc, char** argv) {
  int nlinhas;
  int *vet = NULL;
  FILE *fvet;
  double start_time, end_time;
  int option;
  

  if (argc != 2){
    printf ("ERRO: Numero de parametros %s <filename>", argv[0]);
    exit (1);
  }

  //nlinhas =  atoi(argv[1]);
  fvet = fopen(argv[1],"r");
  if (fvet == NULL) {
    printf("Error: Na abertura dos arquivos.");
    exit(1);
  }

  nlinhas = extrai_nroLine(fvet);
  vet = alocar_vetor(nlinhas);
  filein_vetor (vet, nlinhas, fvet);
  printf("\t\t**** PRINT vetor lido N(%d) **** \n", nlinhas);
  imprimir_vetor(vet, nlinhas);
  

  do{
  printf("#########################################");  
  printf("\n-     Escolha um metodo de ordencao     -\n");
  printf("#########################################");
  printf("\n-            [1] - QuickSort            -\n");  
  printf("-            [2] - BubbleSort           -\n");
  printf("-            [3] - MergeSort            -\n");
  printf("#########################################\n\n");        
  scanf("%d",&option);
  
  if(option < 1 || option>3){
    printf("\n#########################################\n");
    printf("-   Opcao invalida, escolha novamente   -\n");
    printf("#########################################\n\n");
  }  
  if(option == 1){
    start_time = wtime();
    quick_sort(vet, 0, nlinhas - 1);  
    end_time = wtime();
    printf("\tRuntime: %f\n", end_time - start_time);    
    printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n\n", nlinhas);    
    imprimir_vetor(vet, nlinhas);  
  }
  if(option == 2){  
    start_time = wtime();
    bubble_sort(vet, nlinhas);
    end_time = wtime();
    printf("\tRuntime: %f\n", end_time - start_time);    
    printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n\n", nlinhas);    
    imprimir_vetor(vet, nlinhas);
  }    
      
    if(option == 3){  
    start_time = wtime();
    merge_sort(0, nlinhas,vet);
    end_time = wtime();
    printf("\tRuntime: %f\n", end_time - start_time);    
    printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n", nlinhas);    
    imprimir_vetor(vet, nlinhas);  
  }

  }while(option < 1 || option > 3);
    
 //  bubble_sort(vet, nlinhas);
 // printf("\n\n");
 // printf("\t\t**** PRINT vetor Ordenado N(%d) **** \n", nlinhas);
 // imprimir_vetor(vet, nlinhas);
 // printf("\tRuntime: %f\n", end_time - start_time);

  liberar_vetor (vet);
  fclose (fvet);
  return 0;
}
