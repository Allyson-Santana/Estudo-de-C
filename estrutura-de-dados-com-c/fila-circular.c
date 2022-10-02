#include <stdio.h>
#include <stdlib.h>

#define ex01

/** Fila Circular*/

#ifdef ex01 

/**
    3) Escreva um algoritmo para implementar uma Fila Circular. O algoritmo irá realizar as seguintes ações:

    a) aceitar 5 elementos na Fila

    b) imprimir os 5 elementos inseridos em A

    c) remover da Fila 2 elementos

    d) imprimir os elementos restantes da opção C

    e) Inserir 2 novos elementos na Fila

    f) Imprimir os elementos da Fila, após a operação E
*/

#define MAX 5
int
    fila[5+1], // mais 1 para soma o total de 5 elementos
    end_fila = 0,
    start_file = 0;

void insertNumber(int value)
{
    if (end_fila == MAX) {
        end_fila = 0;
    }

    // fila is full
    if (  (end_fila + 1) > MAX && !start_file ) {
        printf("Você chegou no fim da fila Circular.\n");
        return;
    }

    fila[end_fila] = value;
    end_fila++;

    printf("incrementa valor %d na fila.\n", value);
}

int removeNumber()
{
    if (start_file == MAX) {
        start_file = 0;
    }

    if (start_file == end_fila) {
        printf("Fila Circular vazia.\n");
        return NULL;
    }

    printf("decrementa valor %d na fila.\n", fila[start_file]);
    fila[start_file] = NULL;
    start_file++;

    return fila[start_file - 1];
}

void printNumbers()
{
    printf("\nValores restantes: \n");
    for ( int i = start_file; i < 5; i++  ) {
        if (fila[i] != NULL) {
            printf("%d\n", fila[i]);
        }
    }
    for ( int i = 0; i < start_file; i++  ) {
        if (fila[i] != NULL) {
        printf("%d\n", fila[i]);
       }
    }

}

int main ()
{

    printf("\n");
    insertNumber(10);
    insertNumber(20);
    insertNumber(30);
    insertNumber(40);
    insertNumber(50);

    printf("\n");
    printNumbers();

    printf("\n");
    removeNumber();
    removeNumber();

    printf("\n");
    printNumbers();

    printf("\n");
    insertNumber(100);
    insertNumber(150);

    printf("\n");
    printNumbers();

    return 0;
}
#endif // ex01