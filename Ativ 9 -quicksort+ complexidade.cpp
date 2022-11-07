#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

int dividireita(int vet[],int esquerda, int direita){
    int aux;
    int cont = esquerda;

    for(int i=esquerda+1 ; i<=direita ; i++){ // O (N)

        if( vet[i] < vet[esquerda] ){
            cont++;
            aux=vet[i];
            vet[i]=vet[cont];
            vet[cont]=aux;
        }
    }

    aux=vet[esquerda];
    vet[esquerda]=vet[cont];
    vet[cont]=aux;

    return cont;
}

void quicksort(int vet[],int esquerda, int direita){
    int pos;
    if(esquerda < direita){
        pos = dividireita(vet,esquerda,direita);
        quicksort(vet,esquerda,pos-1);
        quicksort(vet,pos+1,direita);
    }
}

int main(){

    int vet[]={5,7,2,9,3,1,6,0,4,8};
    int n=10;
	int list[10]={5,7,2,9,3,1,6,0,4,8};
    quicksort(vet,0,n);

   cout <<"Lista aleatoria:\n";
   for(int i = 0; i<10; i++) { // O(N)
      cout <<list[i]<<"\t";
   }

	cout<<endl;
	cout <<"\n--------------------------------------------------------------------------------------\n";

	cout <<"\nLista ordenada QuickSort:\n";
    cout <<"Lista aleatoria:\n";
    for(int i = 0; i<10; i++) { // O(N)
      cout <<vet[i]<<"\t";
    }
	cout<<endl;

	return 0;
}

//Complexidade:
// O(N)+ O(N) + O(N)
// Melhor Caso: O(N)
// Pior Caso: O(N)
