#include <stdio.h>
#include <locale.h>

#define BR * setlocale(LC_ALL, ""); //  apenas para facilitar setar o setlocale com  "BR" nos exercicios.

#define ex01

//================================================================================
// OBS.: Todos os programa devem ser finalizados pelo usuario.

// funcao para o loop

int endGame() {
    int optionContinue;
    do{
        printf("\nDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &optionContinue);
    }while(optionContinue != 0 && optionContinue != 1);

    return optionContinue;
}

// ================================================================================

// Ex 01

#ifdef ex01

/* 1 - Escreva um programa para receber 5 nomes, com ate 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os vetores como variavel
    global)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3 */


char nomes[5][8];
void inserir();

int main(){

    BR; //setlocale

    while(1){

        inserir();

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890 \n");


        printf("  %-7s                                 %-7s\n",nomes[0],nomes[4]);
        printf("            %-7s             %-7s\n",nomes[1],nomes[3]);
        printf("                      %-7s\n",nomes[2]);

        printf("\n\n");

        printf("\t %s\n",nomes[0]);
        printf("\t %s\n",nomes[1]);
        printf("\t %s\n",nomes[2]);
        printf("\t %s\n",nomes[3]);
        printf("\t %s\n",nomes[4]);

        if(endGame() == 0) break;
            system("cls");
            getchar();

    }

return 0;

}

void inserir(){

    int i;

printf("\t Digite 7 nomes de ate 7 caracteres\n");

    for (i = 0; i < 5; i++)    {

        printf("\t\n Digite o %dº nome -> ", i + 1);

            scanf(" %7[^\n]",nomes[i]); // leitura da string ate apertar enter
            scanf("%*[^\n]");    // limpeza do buffer do teclado
     }
}

#endif // ex01

// ================================================================================

// Ex 02

/* 2 - Receba 2 string de ate 10 caracteres via teclado na funcao main() e noutra
    funcao compare-as mostrando como resultado se s�o IGUAIS ou DIFERENTES na funcao
    main(). (Declare os vetores como variavel global) */

#ifdef ex02

    char str01[11],str02[11]; //  10 caracters + finalizador

    void criaSTR();
    int compara();

int main(){

    BR; // setlocale

    while(1){

        criaSTR();

        if(compara() == 0){
            printf("\t As strings SÂO IGUAIS");
        }

        if(endGame() == 0) break;
        system("cls");
        str01[0] = '\0'; // limpa a string quando user inicia programa novamente
        str02[1] = '\0';

        getchar();
    }

return 0;

}

void criaSTR()
{
    printf("\t Digite a primeira string de ate 10 caracteres\n");

    scanf(" %10[^\n]", str01); // leitura da string ate apertar enter
    scanf("%*[^\n]");            // limpeza do buffer do teclado

    printf("\t Digite a segunda string de ate 10 caracteres\n");

    scanf(" %10[^\n]", str02); // leitura da string ate apertar enter
    scanf("%*[^\n]");            // limpeza do buffer do teclado
}

int compara(){

    for( int i = 0; i < 10; i++){

        if(str01[i] !=  str02[i]){

            printf("\t As strings NÂO SÂO IGUAIS");
            return 1;
            break;
        }
    }
    return 0;
}

#endif //ex02

// ================================================================================

// Ex 03

/* 3 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. */

#ifdef ex03

void str_caps(char str[11]);

int main(){

    BR;

    char str[11];


    while(1){

        printf("\t Digite uma string de ate 10 caracteres\n");
            scanf(" %10[^\n]", str); // leitura da string ate apertar enter
            scanf("%*[^\n]");  // limpeza do buffer do teclado

        printf("\t String digitada foi: %s\n\n", str);

        str_caps(str);

        if(endGame() == 0) break;
        system("cls");
        str[0] = '\0'; // limpa a string quando user inicia programa novamente


    }


    return 0;
}

void str_caps(char str[11]){

    for(int i = 0; i < 10; i++){

        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] = str[i] - 32;

         }
    }

    printf("\t String digitada com letras maiusculas: %s\n",str);
}

#endif //ex03

// ================================================================================

// Ex 04

#ifdef ex04

/* 4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. */

void str_lwr(char str[11]);

int main(){

    BR;

    char str[11];


    while(1){

        printf("\t Digite uma string de ate 10 caracteres\n");
            scanf(" %10[^\n]", str); // leitura da string ate apertar enter
            scanf("%*[^\n]");  // limpeza do buffer do teclado

        printf("\t String digitada foi: %s\n\n", str);

        str_caps(str);

        if(endGame() == 0) break;
        system("cls");
        str[0] = '\0'; // limpa a string quando user inicia programa novamente


    }


    return 0;
}

void str_caps(char str[11]){

    for(int i = 0; i < 10; i++){

        if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            str[i] = str[i] + 32;

         }
    }

    printf("\t String digitada com letras minusculas: %s\n",str);
}
#endif //ex04

// ================================================================================

// Ex 05

/* 5 - Faca um programa que leia uma palavra (maximo de 20 letras) em uma funcao
    e some 1 no valor ASCII de cada caractere da palavra em outra funcao. Na sua
    funcao main() imprima a string resultante. (Declare o vetor como variavel
    global) */

#ifdef ex05

char str[21];

void criaSTR();
void changeSTR();

int main(){

    BR; //setlocale

    while(1){

        criaSTR();

        printf("\t A string sera : %s \n",str);

        changeSTR();

        printf("\t A string com caracteres com valor +1: \n");
        printf("\t %s \n",str);

        if(endGame() == 0) break;
        system("cls");

    }
    return 0;
}

void criaSTR(){

    printf("\t Digite uma string de ate 20 caracteres\n");
        scanf(" %20[^\n]", str); // leitura da string ate apertar enter
        scanf("%*[^\n]");  // limpeza do buffer do teclado

}

void changeSTR(){

     for(int i = 0; str[i] != '\0'; i++){

        str[i] = str[i] + 1;
    }

}

#endif //ex05



