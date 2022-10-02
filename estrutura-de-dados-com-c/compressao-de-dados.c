#include <stdio.h>
#include <stdlib.h>

#define ex01

/**
  Construar uma compressão por frequência quando a ordem dos valores importa:
  DADOS BRUTOS: 22 23 24 24 24 24 24 24 24 25 27 27 27 27 27 27 25
  RESULTADO ESPERADO: 22 23 AA 24 7 25 AA 27 6 25 
*/
#ifdef ex01
int main() {
    printf("Hello world!\n");

    int arr[] = {22, 23, 24, 24, 24, 24, 24, 24, 24, 25, 27, 27, 27, 27, 27, 27, 25};
    char AA[] = "AA";

    int
        lengthArr = sizeof(arr)/sizeof(int),
        repeatcount = 0;

    for (int i = 1; i <= lengthArr; i++ ) {
        int aux = i - 1;

        if (arr[i] == arr[aux]) {
            repeatcount++;
        }
        else if (repeatcount != 0) {
            repeatcount++;
            printf("%s %d %d ", AA, arr[aux], repeatcount);
            repeatcount = 0;
        }
        else {
            printf("%d ", arr[aux]);
            repeatcount = 0;
        }
    }

    return 0;
}
#endif // ex01

#ifdef ex02
/**  
  Se quiser uma compressão por frequência quando a ordem dos valores não importa, podemos ter um ganho ainda maior. 
  Faça o algoritmo para o exemplo abaixo:
  DADOS BRUTOS: 32 33 34 34 34 34 34 34 34 35 37 37 37 37 37 37 35 34 35
  RESULTADO ESPERADO: 32 33 AA 34 08 AA 35 03 AA 37 06  
*/
int main () {
    printf("Hello world!\n");

    int
        data[] = {32, 33, 34, 34, 34, 34, 34, 34, 34, 35, 37, 37, 37, 37, 37, 37, 35, 34, 35},
        lengthArr = sizeof(data)/sizeof(int),
        repeatcount = 0,
        isAlreadyExists = 0,
        valuesAlreadyExists[lengthArr];

    char
        BB[] = "BB";

    for (int i = 0; i < lengthArr; i++) {
        int value = data[i];

        for (int j = 0; j <= lengthArr; j++) {
            if (valuesAlreadyExists[j] == value) {
                isAlreadyExists = 1;
                break;
            }
            if (value == data[j]) {
                repeatcount++;
            }
        }

        if (repeatcount > 1 && !isAlreadyExists)  {
            printf("%s %i %i ", BB, value, repeatcount);
        }

        else if (!isAlreadyExists) {
            printf("%i ", value);
        }

        valuesAlreadyExists[i] = data[i];
        repeatcount = 0;
        isAlreadyExists= 0;
    }


    return 0;
}
#endif // ex02