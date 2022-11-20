#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*********************************************** ATENÇÂO ********************************************************
    Para que o script funcione, irá precisar de um arquivo chamada "text.txt" com todos os 3000 elementos (Números Inteiros);
    Use o site: https://www.invertexto.com/numeros-aleatorios para gerar os 3000 números.
    Copie todos os 3000 elementos e crie/grave num arquivo chamado "text.txt" como está na linha 105 do código.
    Lembre-se de salvar o arquivo "text.txt" na mesma raiz do arquivo com o código =)
*/ 

#ifdef ex01

#define TAM 3000

int item[TAM];
int n = sizeof(item)/sizeof(item[0]);

void ordenacaoBolha() {
    printf("\n\n");
    double time_spent = 0.0;
    clock_t begin = clock();

    for (int a = 1; a < n; a++) {
        for (int b = n-1; b>=1; b--) {
            if (item[b-1] > item[b]) {
                int t =item[b-1];
                item[b-1] = item[b];
                item[b] = t;
            }
        }
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de processamento: %f segundos com %d elementos", time_spent, n );
    printf("\n\nA função não retorna o tempo real decorrido, mas retorna o tempo gasto pelo sistema operacional subjacente para executar o processo. Em outras palavras, o tempo real do relógio de parede pode ser muito maior.");

    // https://www.techiedelight.com/pt/find-execution-time-c-program/
}

void shellSort() {
    printf("\n\n");
    double time_spent = 0.0;
    clock_t begin = clock();

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

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de processamento: %f segundos com %d elementos", time_spent, n );
    printf("\n\nA função não retorna o tempo real decorrido, mas retorna o tempo gasto pelo sistema operacional subjacente para executar o processo. Em outras palavras, o tempo real do relógio de parede pode ser muito maior.");

    // https://www.techiedelight.com/pt/find-execution-time-c-program/
}

// Function para teste
void calcTimeExec() {
    printf("\n\n");

    // para armazenar o tempo de execução do código
    double time_spent = 0.0;

    clock_t begin = clock();

    ordenacaoBolha();
    shellSort();

    clock_t end = clock();

    // calcula o tempo decorrido encontrando a diferença (end - begin) e
    // dividindo a diferença por CLOCKS_PER_SEC para converter em segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Tempo de processamento: %f segundos com %d elementos", time_spent, n );

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
    int option;

    readFile();

    printf("\n1 - Ordenacao Bolha\n2 - Ordenacao Shell Sort\n3 - Sair");

    printf("\n\nMenu: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            ordenacaoBolha();
            break;
        case 2:
            shellSort();
            break;
        default:
            printf("Opcao não suportada!");
    }

}
#endif // ex01