#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef ex12

#define TAM 3000

int item[TAM];
int n = sizeof(item)/sizeof(item[0]);

void ordenacaoBolha() {
    for (int a = 1; a < n; a++) {
        for (int b = n-1; b>=1; b--) {
            if (item[b-1] > item[b]) {
                int t =item[b-1];
                item[b-1] = item[b];
                item[b] = t;
            }
        }
    }
}

void shellSort() {

    int i , j , value;
    int gap = 1;
    while(gap < n) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = item[i];
            j = i - gap;
            while (j >= 0 && value < item[j]) {
                item [j + gap] = item[j];
                j -= gap;
            }
            item [j + gap] = value;
        }
    }
}

void calcTimeExec() {
    printf("\n\n");

    // para armazenar o tempo de execução do código
    double time_spent = 0.0;

    clock_t begin = clock();

    //faz algumas coisas aqui

    ordenacaoBolha();ordenacaoBolha();ordenacaoBolha(); // 0.023330, 0.024622, 0.025502
    //shellSort();shellSort();shellSort();              // 0.000337, 0.000353, 0.000333

    clock_t end = clock();

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent/3);

    printf("\n\nA função não retorna o tempo real decorrido, mas retorna o tempo gasto pelo sistema operacional subjacente para executar o processo. Em outras palavras, o tempo real do relógio de parede pode ser muito maior.");

    // https://www.techiedelight.com/pt/find-execution-time-c-program/
}

void readFile() {
    int iCont, jCont, aux = 0;

    FILE *f;

    f = fopen("text.txt", "r");

    if(f == NULL){
        printf("Erro! Nao consegui abrir o arquivo...\n");
        exit(1);
    }

    for(iCont = 0; iCont < TAM; iCont++){
        //printf("Lendo posicao %d\n", iCont);
        if(fscanf(f, "%d", &item[iCont]) == EOF){
            setbuf(stdin, NULL);
            printf("Opa, tentei ler alem do final do arquivo...\n");
            break;
        }
    }

    fclose(f);
}

void main()
{
    readFile();

    calcTimeExec();
}
#endif // ex01