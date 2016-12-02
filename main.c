#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Función que inserta números aleatorios en una lista*/
void inserta_datos_de_prueba(Lista lista);

int main()
{
    // Se crea la lista
    Lista lista = crea_lista();
    printf("La lista tiene %d elementos\n",(int) longitud(lista));

    // Se insertan datos de prueba
    inserta_datos_de_prueba(lista);
    printf("La lista tiene %d elementos\n",(int) longitud(lista));
    imprime_lista_int(lista);
    // Se remueve un elemento de la lista
    Elemento *borrado = quita_elemento(lista, 0);
    if (borrado != NULL) {free(borrado->valor);}
    free(borrado);
    printf("La lista tiene %d elementos\n", (int)longitud(lista));

    // Se remueve un elemento que no existe en la lista
    quita_elemento(lista, longitud(lista));
    printf("La lista tiene %d elementos\n",(int) longitud(lista));

    //Se imprime la lista antes de ordenar
    imprime_lista_int(lista);
    ordena_lista(lista, &cmp_int);

    //Se imprime la lista después de ordenar
    imprime_lista_int(lista);

    //Se libera la memoria ocupada
    borra_lista(lista);

}

void swap(void * a, void * b, size_t size){
	void * temporal = malloc(size);
	memcpy(temporal,a,size);//Funcion mempcy que sirve para copiar un cierto numero de bytes desde una posicion incial a una final
	memcpy(a,b,size);
	memcpy(b,temporal,size);
	free(temporal); // Funcion free que se usa para liberar memoria reservada en este caso con malloc 
}

void bsort(void* base, size_t num, size_t size,int (*compar)(const void*, const void*)){
	for (int i = 0; (i <num); i++){ //Con este primer for recorremos todos los elementos del arreglo
		for (int j = i+1; j < num; j++){ //Con el segundo for recorremos los elementos posteriores al elemento al que apunte i 
			char * mom1 = (char*)base + size*i; 
			char *mom2 = (char*)base + size*j;
			if(compar(mom1,mom2)>0){//Realiza las comparaciones necesarias y con ayuda del metodo swap intercambia los elementos
				swap(mom1,mom2,size);
			}
		}
	}
}

int cmp_int(const void *a, const void *b){; //Funcion que compara dos numeros enteros
    int comp1 = *(int *)a;
    int comp2 = *(int *)b;
    if (comp1<comp2) { // Si el primero de los numeros es menor al segundo nos devuelve -1
        return -1;
    } else if (comp1>comp2){ // De no ser así nos devuelve -1
        return 1;
    }
    return 0;   
}//Termino de la funcion cmp_int


Lista crea_lista(){ // Función que crea una lista vacia
	Elemento* nodo = (Elemento*) malloc(sizeof(Elemento));
	Lista empty = (Lista) malloc(sizeof(Elemento*));
	nodo->valor = NULL;
	nodo->next = NULL;
	*empty = nodo;
	return empty;
}//Fin de la funcion que crea la lista vacia 

void borra_lista(Lista lista){ //Funcion que libera la memoria ocupada al crear una lista  
	Elemento* nodo = (*lista);
	while(nodo->valor != NULL){
		Elemento* aux = nodo;
		nodo = nodo->next;
		free(aux);
	}
	free(lista);
}//Termino de la funcion borra_lista


int inserta_elemento(Lista lista, void *valor){ //Funcion que inserta un nuevo elemento y regresa el nuevo tamaño de la lista
	Elemento* nodo = (Elemento*) malloc(sizeof(Elemento));
	nodo->valor = valor;
	nodo->next = (*lista);
	(*lista) = nodo; 
	return 0;
}

void imprime_lista_int(Lista lista){// Funcion que nos imprime una lista
	Elemento* nodo = (*lista);
	printf("[");
	while(nodo->valor!= NULL){
		int * actual =(int*) nodo->valor;
		printf("%d ", *actual);
		nodo = nodo->next;
	}
	printf("]\n");
}

size_t longitud(Lista lista){ // Función que nos devuelve el numero de elementos de la lista
	Elemento* nodo = (*lista);
	int size1 = 0;
	while(nodo->valor!= NULL){
		nodo = nodo->next;
		size1++;
	}
	return size1;
}//Fin de la funcion size_t

void ordena_lista(Lista lista, int(*cmp)(const void*, const void*)){//Funcion que ordena una lista auxiliandose del metodo que compara 2 numeros enteros

}

Elemento *quita_elemento(Lista lista , size_t posicion){ //Funcion que quita el elemento de la lista acorde a la posición indicada
	return NULL;
}


void inserta_datos_de_prueba(Lista lista)
{
    srand(time(NULL));
    int *num_a_insertar;
    int indice;
    for (indice = 0; indice < 20; ++indice) {
        num_a_insertar = malloc(sizeof(int));
        *num_a_insertar = rand() % 100;
        inserta_elemento(lista, num_a_insertar);
    }
}