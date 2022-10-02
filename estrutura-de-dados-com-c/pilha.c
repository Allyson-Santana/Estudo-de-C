#include <stdio.h>
#include <stdlib.h>

#define ex01

#ifdef ex01
/** - Ler uma pilha e grave outra pilha sem os valores repetidos */
int main() {
    printf("Hello world!\n");

    int
        value,
        arrFilter[10],
        positionValue = 0,
        isAlreadyExists; // 0 or 1

    for (int i = 0; i < 10; i++) {
        isAlreadyExists = 0;
        printf("Informe o %d° valor: ", (i + 1));
        scanf("%d", &value);

        for (int j = 0; j <= positionValue; j++) {
            if (arrFilter[j] == value) {
                isAlreadyExists = 1;
            }
        }

        if (!isAlreadyExists) {
            arrFilter[positionValue] = value;
            positionValue++;
        }

    }

    printf("Result: \n");

    for (int i = 0; i < positionValue; i++) {
        printf("%d ", arrFilter[i]);
    }

    return 0;
}
#endif // ex01