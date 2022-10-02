#include <stdio.h>
#include <stdlib.h>
/** Fila */

#define ex01

#ifdef ex01

#define MAX 10
int
    fila[MAX],
    end_fila = 0,
    start_file = 0;

void insertNumber(int value)
{
    if (end_fila == MAX) { // fila is full
        printf("Você chegou no fim da fila.");
        return;
    }

    fila[end_fila] = value;
    end_fila++;
    printf("incrementa valor %d na fila.\n", value);
}

int removeNumber()
{
    if (start_file == end_fila) { // Initial value is equal the end fila
        printf("Fila vazia.");
        return NULL;
    }

    start_file++;
    printf("decrementa valor %d na fila.\n", fila[start_file - 1]);

    return fila[start_file - 1];
}

int main ()
{
    insertNumber(12);
    insertNumber(23);
    insertNumber(45);
    insertNumber(34);
    insertNumber(76);
    insertNumber(54);
    insertNumber(98);

    printf("\n");

    removeNumber();
    removeNumber();
    removeNumber();
    removeNumber();

    printf("\nValores restantes: \n");
    for ( int i = start_file; i < end_fila; i++  ) {
        printf("%d\n", fila[i]);
    }


    return 0;
}
#endif // ex0ex011