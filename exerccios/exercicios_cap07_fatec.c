#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex04

//================================================================================
// OBS.: Todos os programa devem ser finalizados pelo usuario.

// funcao para o loop

int endGame() {
    int optionContinue;
    do {
        printf("\nDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &optionContinue);
    } while (optionContinue != 0 && optionContinue != 1);

    return optionContinue;
}

/*

 estrutura para o loop na main()

 if (endGame() == 0) break;
        system("cls"); system("clear");
 */

// ================================================================================

#ifdef ex01
/* 1 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado e imprima-os no
    video. Faça um menu. (vetor de estruturas)
		nome, end, cidade, estado, cep */

     struct Pessoa
    {
        char nome[20];
        char end[20];
        char cidade[20];
        char estado[20];
        int  cep;
    };

     struct Pessoa dados;

int main()
    {

        while(1)
        {
            int opcao;

            printf("\t MENU:\n\n");
            printf("\t 1 - Digite um nome\n");
            printf("\t 2 - Digite um endereço\n");
            printf("\t 3 - Digite uma cidade\n");
            printf("\t 4 - Digite um estado\n");
            printf("\t 5 - Digite um cep\n\n");
            printf("\t 6 - Sair\n\n");
            scanf("%d",&opcao);


            switch (opcao)
            {
            case 1: {

                system("cls");
                printf("\t Digite um Nome: \n");
                scanf("%s", &dados.nome);

                printf("\n-------->Nome: %s\n", dados.nome);

            break;

            }

           case 2:{

                system("cls");
                printf("\t Digite um endereço: \n");
                scanf("%s", &dados.end);

                printf("\n-------->Endereco: %s\n", dados.end);

            break;
           }

          case 3:{

            system("cls");
            printf("\t Digite uma cidade: \n");
            scanf("%s", &dados.cidade);

            printf("\n-------->Cidade: %s\n", dados.cidade);

           break;
           }

         case 4:{

            system("cls");
            printf("\t Digite um estado \n");
            scanf("%s", &dados.estado);
            printf("\n-------->Estado: %s\n", dados.estado);

           break;
          }

        case 5:{

            system("cls");
            printf("\t Digite um cep \n");
            scanf("%i", &dados.cep);

            printf("\n-------->Cep: %d\n", dados.cep);

        break;
        }


        case 6:{
            exit(0);

        break;
        }

        default:{
        printf("\t Opcao escolhida invalida\n");
        system("cls");
    }
   }

   if (endGame() == 0) break;
        system("cls"); system("clear");

    }
    return 0;
   }

// ================================================================================
#endif // ex01

 /** 2 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
        teclado e calculo, o numero de dias entre elas e mostre o resultado no
        video. (vetor de estruturas)
                    dia, mes, ano
 */

#ifdef ex02

#define TRUE 1
#define FALSE 0

int fixed_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct dateStruct {
    int day;
    int month;
    int year;
};
struct dateStruct dates[3];

int validated_date(int day, int month, int year) {

    int dayMax =  fixed_month[month - 1];

    if( day < 1 || day > 31 ) {
        printf("\nDia Invalido Guerreiro! \n");
        return FALSE;
    }
    if( month < 1 || month > 12 ) {
        printf("\nMes Invalido Guerreiro!\n");
        return FALSE;
    }
    if(day > dayMax) {
       printf("verifique se o mes informado contem esse dia)\n");
    }
    if( year < 1 ) {
        printf("\nAno Invalido Guerreiro!\n");
        return FALSE;
    }

    printf("\n");
    return TRUE;
}

void inputDates() {

    for(int i = 0; i < 2; i++) {
        do {

            printf("Informe o dia da %d° data: ", i+1);
            scanf("%d", &dates[i].day);

            printf("Informe o mes da %d° data: ", i+1);
            scanf("%d", &dates[i].month);

            printf("Informe o ano da %d° data: ", i+1);
            scanf("%d", &dates[i].year);

        } while( !validated_date(dates[i].day, dates[i].month, dates[i].year) );
    }
}

int calcs_days() {
        int days = 0;
        /************Calc Years****************/
        int years = dates[0].year > dates[1].year
        ? dates[0].year - dates[1].year
        : dates[1].year - dates[0].year;
        if (years == 1) years -1;
        days += years * 365 + (years / 4);

        /************Calc Months***************/
        int daysA = 0, daysB = 0;
        for (int j = (dates[0].month-1); j < 12 ; j++) {
            daysA += fixed_month[j];
        }
        for (int j = (dates[1].month-1); j < 12 ; j++) {
            daysB += fixed_month[j];
        }
        days += daysA > daysB
        ? daysA - daysB
        : daysB - daysA;

        /************Calc days*****************/
        days += dates[0].day > dates[1].day
        ? dates[0].day - dates[1].day
        : dates[1].day - dates[0].day;

        return days;
}
int main()
{
    while(1) {

        inputDates();
        int days = calcs_days();

        printf("QUANDIDADE DE DIAS: %d", days);

        if (endGame() == 0) break;
        system("cls"); system("clear");
    }

    return 0;
}
#endif // ex02

// ================================================================================

#ifdef ex03

/* 3 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    No menu inclua uma 3. opcao que calcula o IMC da pessoal. Faça um menu.
    (vetor de estruturas)
    Calculo do IMC = peso/(altura*altura).
    estrutura: nome, peso, altura
*/

typedef struct {
    char nome[21];
    float peso;
    float altura;
} Pessoa;

// funcao para Calculo do IMC = peso/(altura*altura)
float calcIMC(Pessoa P) {
    float imc = P.peso / (P.altura * P.altura);

    printf("IMC: %.2f - \n", imc);
    return imc;

}


int main() {

    Pessoa People[4];


    while(1) {
        int opcao;

        printf("\t MENU:\n\n");

        printf("\t Digite 1 para Entrada de dados da Pessoa\n");
        printf("\t Digite 2 para Exibir os dados\n");
        printf("\t Digite 3 para calculo do IMC\n");
        printf("\t Digite 4 para EXIT\n\n");
        scanf("%d",&opcao);


        switch (opcao) {
        case 1: {
            system("cls");

            int i;
            for(i = 0; i < 4; i++) {

                printf("\t Digite o nome da %dnd pessoa max.20 letras\n", i+1);
                scanf(" %20[^\n]", People[i].nome); // leitura da string ate apertar enter
                getchar();

                printf("\t Digite o peso da pessoa Ex. 83\n");
                scanf("%f", &People[i].peso);

                printf("\t Digite a altura da pessoa Ex. 1.78\n");
                scanf("%f", &People[i].altura);

            }

            break;
        }

        case 2: {
            system("cls");

            int i;
            for(i = 0; i < 4; i++) {

                printf("\tA pessoa com nome %s tem peso:\n \t %.2f Kg  e de altura %.2f Metros  \n\n", People[i].nome, People[i].peso, People[i].altura);

            }

            break;
        }

        case 3: {
            system("cls");

            printf("\t o calculo do IMC de cada pessoa:\n\n");

            int i;
            float imc;

            for(i = 0; i < 4; i++) {


                printf("\t O IMC de %s com peso %.2f Kg  e altura %.2f Metros - ", People[i].nome, People[i].peso, People[i].altura);
                imc = calcIMC(People[i]);
                    if (imc < 18.5) {

                        printf("\t Classificacao na tabela IMC : MAGREZA\n\n");
                    }
                    else if (imc >= 18.5 && imc <= 24.9 ) {

                        printf("\t Classificacao na tabela IMC : NORMAL\n\n");
                    }
                    else if (imc >= 25.0 && imc <= 29.9 ) {

                        printf("\t Classificacao na tabela IMC : SOBREPESO\n\n");
                    }
                    else if (imc >= 30 && imc <= 39.9) {

                        printf("\t Classificacao na tabela IMC : OBESIDADE\n\n");
                    }
                    else if (imc >= 40) {

                        printf("\t Classificacao na tabela IMC : OBESIDADE GRAVE\n\n");
                    }

            }

            break;
        }

        case 4: {
            exit(0);

            break;
        }

        default: {
            printf("\t Opcao escolhida invalida\n");
            system("PAUSE");
            system("cls");
        }
        }

        system("pause");
        system("cls");

    }

    return 0;
}

#endif // ex03



#ifdef ex04
/** 4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado e imprima estes conteudos no video no seguinte
    formato.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long     */
    typedef struct {
        char c;
        int i;
        long l;
        float f;
        double d;
        unsigned char uc;
        unsigned int ui;
        unsigned long ul;
    } data_struct;

int main() {

    data_struct content;

        printf("\n Digite um caracter do tipo (char): ");
        content.c = getchar(); getchar();

        printf("\n Digite um numero do tipo (int): ");
        scanf("%i",&content.i);
        printf("\n Digite um numero do tipo (long): ");
        scanf("%ld",&content.l);
        printf("\n Digite um numero do tipo (float): ");
        scanf("%f",&content.f);
        printf("\n Digite um numero do tipo (double): ");
        scanf("%g",&content.d);

        printf("\n Digite um caracter do tipo (unsigned char): ");
        content.uc = getchar(); getchar();

        printf("\n Digite um numero do tipo (unsigned int): ");
        scanf("%u",&content.ui);

        printf("\n Digite um numero do tipo (unsigned long): ");
        scanf("%lu",&content.ul);

        printf("\n        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
        printf("\n    %-1c         %-8i  %-8ld            %-8f            %-8g", content.c, content.i, content.l, content.f, content.d);
        printf("\n          %-1u                  %-10u          %-10lu", content.uc, content.ui, content.ul);

    return 0;
}
#endif // exe04


