#include <stdio.h>
#include <locale.h>

#define BR * setlocale(LC_ALL, ""); //  apenas para facilitar setar o setlocale com  "BR" nos exercÃ­cios.

#define ex05

// OBS.: Todos os programa devem ser finalizados pelo usuario.


// ==============================================================================================

int endGame() {
    int optionContinue;
    do{
        printf("\nDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &optionContinue);
    }while(optionContinue != 0 && optionContinue != 1);

    return optionContinue;
}

// Ex 01

/*1 - Escreva um programa que receba um vetor de tamanho 10 e o decomponha em dois
    outros vetores. Um contera' as componentes de ordem ï¿½mpar e o outro contera'
    as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3}.*/

#ifdef ex01

void cria_vet_par(int v[10]);
void cria_vet_imp(int v[10]);
int cria_vet(int vet[10]);

int main(void)
{
    BR; //setlocale

    int vet[10], menu;

    printf("\t Este programa cria 2 vetores separando números pares e ímpares\n\n ");

    while(1)  {

        cria_vet(vet);

        cria_vet_par(vet);

        cria_vet_imp(vet);

        if(endGame() == 0) break;
        system("cls");
    }

    printf("\t\n\n Fim do Programa\n\n");

    return 0;
}

void cria_vet_par(int v[10]){

    int vet[10], i;

    printf("\t\n Conteudo do vetor com números pares: ");

        for(i = 0; i <= 9;i++){

            if(v[i] % 2 == 0){
            vet[i] = v[i];
            printf("%d,", vet[i]);

            }


    }

}

void cria_vet_imp(int v[10]){

    int vet[10], i;

    printf("\t\n\n Conteudo do vetor com números ímpares: ");

        for(i = 0; i <= 9;i++){

            if(v[i] % 2 != 0){
            vet[i] = v[i];
            printf("%d,", vet[i]);

            }


    }

}

int cria_vet(int vet[10]){

    printf("\t Digite 10 números inteiros\n\n");

    for (int i = 0; i <= 9; i++)
    {
        printf("\t\n Digite o %dº número:", i + 1);
        scanf("%d", &vet[i]);
    }

}

#endif // ex01

// ==============================================================================================

// Ex 02

#ifdef ex02

/* 2 - Receba via teclado valores do tipo int para uma matriz 5 x 5. Receba via
    teclado um valor x. O programa dever fazer a busca desse valor x na matriz
    e, ao final escrever a localizacao (linha e coluna) ou uma mensagem de
    ”nao encontrado”. */

void cria_matriz(int vet[5][5]);
void busca(int vet[5][5],int x);

int main(){

BR; // setlocale

int vet[5][5],x;

    while(1)
    {
        printf("\t Digite valores inteiros para as seguintes linhas e colunas \n\n");

            cria_matriz(vet);

            printf("\t\n Digite um valor para pesquisa na matriz\n");
            scanf("%d", &x);

            busca(vet,x);

            if(endGame() == 0) break;
            system("cls");

    }


printf("\t\n\n Fim do Programa\n\n");
return 0;

}

void cria_matriz(int vet[5][5]){

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("\t Linha [%d], coluna [%d] : ",i ,j);
            scanf("%d", &vet[i][j]);
        }
    }

}

void busca(int vet[5][5], int x)
{

    int z = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (vet[i][j] == x)
            {

                printf("\t O valor digitado %d, foi encontrado na linha [%d], coluna [%d] \n", x, i, j);
                z = 1;
            }
        }
    }

    if (z == 0)
    {
        printf("\t valor não encontrado\n");
    }
}

#endif // ex02

// ==============================================================================================

// Ex 03

#ifdef ex03


/* 3 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double */



int main(){

    BR; // setlocale

    int inteiro[3];
    long int longo[3];
    unsigned int u_inteiro[3];
    float real[3];
    double dobro[3];


    while (1)
    {

        printf("\t Digite valores para os seguintes vetores:\n\n\n");

        printf("\t\n 3 valores para um Vetor do tipo inteiro\n");

        for (int i = 0; i < 3; i++)
        {
            printf("\t\n Digite o %dÂº valor:", i + 1);
            scanf("%d", &inteiro[i]);
        }
        system("cls");

        printf("\t\n 3 valores de 10 digitos para um Vetor do tipo inteiro longo\n");

        for (int i = 0; i < 3; i++)
        {
            printf("\t\n Digite o %dÂº valor:", i + 1);
            scanf("%d", &longo[i]);
        }
        system("cls");

        printf("\t\n 3 valores para um Vetor do tipo inteiro unsigned \n");

        for (int i = 0; i < 3; i++)
        {
            printf("\t\n Digite o %dÂº valor:", i + 1);
            scanf("%u", &u_inteiro[i]);
        }
        system("cls");

        printf("\t\n Digite 3 valores do tipo float \n");

        for (int i = 0; i < 3; i++)
        {
            printf("\t\n Digite o %dÂº valor:", i + 1);
            scanf("%f", &real[i]);
        }
        system("cls");

        printf("\t\n 3 valores altos para um Vetor do tipo Double \n");

        for (int i = 0; i < 3; i++)
        {
            printf("\t\n Digite o %dÂº valor:", i + 1);
            scanf("%f", &dobro[i]);
        }
        system("cls");

        printf("\t        10        20        30        40        50\n");
        printf("\t12345678901234567890123456789012345678901234567890\n");

        printf("\t  %-11d         %-11ld         %-10u\n", inteiro[0], longo[0], u_inteiro[0]);
        printf("\t            %-8.1e            %-8g\n", real[0], dobro[0]);
        printf("\t  %-11d         %-11ld         %-10u\n", inteiro[1], longo[1], u_inteiro[1]);
        printf("\t            %-8.1e            %-8g\n", real[1], dobro[1]);
        printf("\t  %-11d         %-11ld         %-10u\n", inteiro[2], longo[2], u_inteiro[2]);
        printf("\t            %-8.1e            %-8g\n", real[2], dobro[2]);

        if (endGame() == 0)
            break;
        system("cls");
    }




    return 0;
}


#endif // ex03


// ==============================================================================================

// Ex 04

#ifdef ex04

/* 4 - Receba via teclado dez valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores ordenados. */

#define TAM 10
int main()
{
    while(1) {
        int vet[TAM], i, j, k, aux;
        printf("Digite 10 numeros inteiros\n");
        for (i = 0; i < 10; i++) {
            printf("\nDigite o %d numero: ", i + 1);
            scanf("%d", &vet[i]);

             for (j = 1; j < TAM; j++) {
               for (k = 0; k < i ; k++) {
                 if (vet[k] > vet[k + 1]) {
                   aux = vet[k];
                   vet[k] = vet[k + 1];
                   vet[k + 1] = aux;
                 }
               }
             }

        }

        printf("\nOrdem \n");
        for(i = 0; i < 10; i++) {
            printf("%d, " , vet[i]);
        }

        if(endGame() == 0) break;
        system("cls");

    }
    return 0;
}

#endif // ex04

// ==============================================================================================

// Ex 05

#ifdef ex05

/* 5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    subtracao "-", subtraia os elementos de mesmo indice dos 2 vetores
    e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
    o resultado dos 6 elementos dos vetores. */

void cria_matrizes(int matriz_a[2][3],int matriz_b[2][3]);
void sub_matriz(int matriz_a[2][3],int matriz_b[2][3],int matriz_sub[2][3]);

int main(){

    BR; // setlocale

    int matriz_a[2][3], matriz_b[2][3],matriz_sub[2][3];

    printf("\t Este programa faz a subtração entre duas matrizes [2][3]:\n\n");

    while(1) {

       cria_matrizes(matriz_a,matriz_b);

       printf("\n");

       sub_matriz(matriz_a,matriz_b,matriz_sub);

        if(endGame() == 0) break;
        system("cls");
    }

    printf("\t\n\n Fim do Programa\n\n");

return 0;

}

void cria_matrizes(int matriz_a[2][3],int matriz_b[2][3]){

    int i = 0;
    int j = 0;

printf("\t Digite os valores para o primeira matriz\n");

    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("\t Linha [%d], coluna [%d] : ",i ,j);
            scanf("%d", &matriz_a[i][j]);
        }
    }

    system("cls");

    printf("\t Digite os valores para a segunda matriz\n");



    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("\t Linha [%d], coluna [%d] : ",i ,j);
            scanf("%d", &matriz_b[i][j]);
        }
    }

    system("cls");

    // exibe as matrizes


    printf("\n A Matriz 1 eh: \n");
    for (int i = 0; i < 2; i++)
    {
        printf("| ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d | ", matriz_a[i][j]);
        }
        printf("\n");
    }

    printf("\n A Matriz 2 eh: \n");
    for (int i = 0; i < 2; i++)
    {
        printf("| ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d | ", matriz_b[i][j]);
        }
        printf("\n");
    }
}

// subtração das matrizes

void sub_matriz(int matriz_a[2][3],int matriz_b[2][3],int matriz_sub[2][3]){

    int i = 0;
    int j = 0;


    // subtrai

     for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            matriz_sub[i][j] = matriz_a[i][j] - matriz_b[i][j];

        }
    }

    printf("\t\n O resultado da subtracao eh : \n ");
    for (int i = 0; i < 2; i++)
    {
        printf("| ");
        for (int j = 0; j < 3; j++)
        {
            printf("%d | ", matriz_sub[i][j]);
        }
        printf("\n");
    }
}



#endif //ex05





