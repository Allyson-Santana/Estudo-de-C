#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex05

//================================================================================
// OBS.: Todos os programa devem ser finalizados pelo usuario.

// funcao para o loop

int endGame()
{
    int optionContinue;
    do
    {
        printf("\nDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &optionContinue);
    } while (optionContinue != 0 && optionContinue != 1);

    return optionContinue;
}

/*

 estrutura para o loop na main()

 if (endGame() == 0) break;
        system("cls");
 */
 // ================================================================================

 /** 1 - Escreva um programa que contenha uma estrutura representando uma data
    valida. Essa estrutura deve conter os campos dia, mes e ano. Em seguida,
    leia duas datas e armazene nessa estrutura usando ponteiros. Calcule e exiba o
    numero de dias que decorreram entre as duas datas usando ponteiros. */

#ifdef ex01

#define FALSE 0
#define TRUE 1

typedef struct {
    int day;
    int month;
    int year;
} data_struct;

int fixed_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
data_struct *dates_p[2], dates[2];

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
        dates_p[i] = &dates[i];
        do {
            printf("Informe o dia da %d° data: ", i+1);
            scanf("%d", &(*dates_p[i]).day);

            printf("Informe o mes da %d° data: ", i+1);
            scanf("%d", &(*dates_p[i]).month);

            printf("Informe o ano da %d° data: ", i+1);
            scanf("%d", &(*dates_p[i]).year);

        } while( !validated_date( (*dates_p[i]).day, (*dates_p[i]).month, (*dates_p[i]).year) );
    }
}

int calcs_days() {
        int days = 0;
        /************Calc Years****************/
        int years = (*dates_p[0]).year > (*dates_p[1]).year
        ? (*dates_p[0]).year - (*dates_p[1]).year
        : (*dates_p[1]).year - (*dates_p[0]).year;

        if(years == 1) years - 1;
        days += years * 365 + years / 4;
        printf("\nQtd dias: %d ", days);

        /************Calc Months***************/
        int daysA = 0, daysB = 0;
        for (int j = ((*dates_p[0]).month-1); j < 12 ; j++) {
            daysA += fixed_month[j];
        }
        for (int j = ((*dates_p[1]).month-1); j < 12 ; j++) {
            daysB += fixed_month[j];
        }

        days += daysA > daysB
        ? daysA - daysB
        : daysB - daysA;

        printf("\nQtd dias: %d ", days);

        /************Calc days*****************/
        days += (*dates_p[0]).day > (*dates_p[1]).day
        ? (*dates_p[0]).day - (*dates_p[1]).day
        : (*dates_p[1]).day - (*dates_p[0]).day;

        printf("\nQtd dias: %d ", days);
        return days;
}

int main ()
{
    while(1) {

        inputDates();
        int days = calcs_days();

        printf("\nQUANDIDADE DE DIAS: %d", days);

        if (endGame() == 0) break;
        system("cls"); system("clear");
    }

    return 0;
}
#endif // ex01

// ================================================================================

/* 2 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
    usando ponteiros. Mostre como resultado se EXISTE ou NAO EXISTE.
    vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y */

#ifdef ex02
int main()
{

    // vetor
    char caracteres[] = {'b', 'd', 'f', 'h', 'j', 'l', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

    char letra, *pvet = caracteres;
    char *p = &letra;

    while (1)
    {
        printf("\t Digite uma letra: ");
        scanf("%c", p);
        getchar();

        int i,k = 0;
        for (i = 0; i < 13; i++)
        {
            if (*(pvet + i) == *p)
            {
                printf("\t\n Letra-> %c EXISTE dentro do vetor\n", *p);
                k = 1;
                break;
            }
        }

        if(k != 1)
        {
            printf("\t\n Letra-> %c NAO EXISTE dentro do vetor\n", *p);
        }

        // finaliza o loop
        if (endGame() == 0)
        break;
        getchar();
        system("cls");
    }

    return 0;
}

#endif // ex02

// ================================================================================

#ifdef ex03

/* 3 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados pelo teclado usando ponteiros e imprima-os no video
    também usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
    nome, end, cidade, estado, cep */

typedef struct
{
    char name[21];
    char anddress[30];
    char city[15];
    char state[3];
    char cep[9];
} Data;

void entryDate(Data *dados);
void display(Data *dados);

int main()
{
    // declara um vetor struct Date chamado dados com 4 elementos
    Data dados[4];


    // declara um ponteiro do tipo struct Data recebendo o endereço de memoria do vetor struct Date de nome dados

    struct Data *pd = &dados[0];

    while (1)
    {

        entryDate(pd);
        display(pd);

        printf("\t\nFIM DOS DADOS\n");

        if (endGame() == 0)
            break;
        scanf("%*[^\n]");
        system("cls");
    }

    return 0;
}

// funcao de entrada de dados na estrutura usando ponteiros

void entryDate(Data *dados)
{
    printf("\tCADASTRO DOS DADOS:\n ");

    for (int i = 0; i < 4; i++)
    {

        printf("\n\t===================\n");
        printf("\t= Dados numero 0%d =\n", i + 1);
        printf("\t===================\n\n");

        printf("\tEntre com o nome: ");
        scanf(" %20[^\n]", dados[i].name); // leitura da string limitado ate 20 caracteres ate apertar enter
        scanf("%*[^\n]");                  // limpeza do buffer do teclado

        printf("\n\tEntre com o endereco: ");
        scanf(" %30[^\n]", dados[i].anddress);
        scanf("%*[^\n]");

        printf("\n\tEntre com a cidade: ");
        scanf(" %15[^\n]", dados[i].city);
        scanf("%*[^\n]");

        printf("\n\tEntre com o estado: ");
        scanf(" %2[^\n]", dados[i].state);
        scanf("%*[^\n]");

        printf("\n\tEntre com o cep: ");
        scanf(" %8[^\n]", dados[i].cep);
        scanf("%*[^\n]");
    }
}

// funcao para exibir os dados da estrutura usando ponteiros
void display(Data *dados)
{

    printf("\t\n\n EXIBINDO DADOS CADASTRADOS:\n");
    system("pause");
    for (int i = 0; i < 4; i++)
    {
        printf("\n\t===================\n");
        printf("\t= Dados numero 0%d =\n", i + 1);
        printf("\t===================\n\n");

        printf("\tNome: %s \n", (dados + i)->name);
        printf("\tEndereco: %s \n", (dados + i)->anddress);
        printf("\tCidade: %s \n", (dados + i)->city);
        printf("\tEstado ex.sp : %s \n", (dados + i)->state);
        printf("\tCep: %s \n", (dados + i)->cep);
    }
}

#endif // ex03

// ================================================================================

#ifdef ex04
/** 4 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
e mostre como resultado se são IGUAIS ou DIFERENTES.
**/

int comparacaoStrings(char *a, char *b), resultado;

main()
{
    setlocale(LC_ALL, "Portuguese");

    int cont, option;
    char string_1[10], *a;
    char string_2[10], *b;

    for(cont = 0; ; cont++)
    {
        a = &string_1[0];
        b = &string_2[0];


        printf("\n Digite uma palavra (1): ");
        scanf("%s", a);
        printf("\n Digite uma palavra (2): ");
        scanf("%s", b);


        resultado = comparacaoStrings(a, b);

        if(resultado == 0)
        {
            printf("\n IGUAIS.");
        }
        else if (resultado == 1)
        {
            printf("\n DIFERENTES.");
        }
        else
        {
            printf("\n TENTA DE NOVO, please...");
        }




        do
        {
            printf("\n\nDigite: ");
            printf("\n1 - para continuar \n0 - para Sair\n\nSua escolha: ");
            scanf("%d", &option);
        }
        while(option != 0 && option != 1);

        if(option == 1)
        {
            printf("\n Vamos mais uma ...\n");
        }
        else if(option == 0)
        {
            break;
        }
        getchar();
    }
}

int comparacaoStrings(char *a, char *b)
{

    int i=0, df=0, cont_a=0, cont_b=0;

    for(i=0; a[i]!='\0'; i++)
    {
        cont_a++;
    }

    for(i=0; b[i]!='\0'; i++)
    {
        cont_b++;
    }

    if(cont_a <11 && cont_b<11)
    {

        if(cont_a == cont_b)
        {

            for(i=0; a[i]!='\0'; i++)
            {

                if(a[i]!=b[i])
                {
                    df=1;
                }

            }

        }
        else
        {
            df=1;
        }


    }
    else
    {
        printf("\n\nOpa, o máximo é de 10 caracter, colega\n\n");
        df=2;
    }

    return df;

}

#endif // ex04

// ================================================================================

#ifdef ex05

/** 5 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned,float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros e o operador de conteudo *
    no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
  **/



main()
{
    char c, *p_c;
    int i, *p_i, option;
    long l, *p_l;
    unsigned u, *p_u;
    float f, *p_f;
    double doub, *p_doub;
    unsigned long ul, *p_ul;
    unsigned char uc, *p_uc;


    for(int cont = 0; ; cont++)
    {

        p_i = &i;
        p_l = &l;
        p_u = &u;
        p_f = &f;
        p_doub = &doub;
        p_ul = &ul;
        p_c = &c;
        p_uc = &uc;


        printf("\n Digite um valor char: ");
        scanf("%c", p_c);
        getchar();

        printf("\n Digite um valor inteiro : ");
        scanf("%d", p_i);

        printf("\n Digite um valor long: ");
        scanf("%ld", p_l);

        printf("\n Digite um valor unsigned: ");
        scanf("%u", p_u);

        printf("\n Digite um valor float: ");
        scanf("%f", p_f);

        printf("\n Digite um valor double: ");
        scanf("%lf", p_doub);

        printf("\n Digite um valor unsigned char: ");
        scanf("%u", p_uc);

        printf("\n Digite um valor unsigned long: \n");
        scanf("%lu", p_ul);
        getchar();



        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-6d              %-11ld         %-5u\n", *p_i, *p_l, *p_u);
        printf("              %-8.1f            %-9.1e           %-1c\n", *p_f, *p_doub, *p_c);
        printf("         %-10lu          %-5u", *p_ul, *p_uc);

        do
        {
            printf("\n\n1 - Continua \n0 - Sair\n\nSua escolha: ");
            scanf("%d", &option);
        }
        while(option != 0 && option != 1);

        if(option == 0) {break;}
        else {printf("\n Vamos mais umaa...\n");}

        getchar();
    }
}
#endif // ex05

// ================================================================================

#ifdef ex06
/** 6 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.  */

int main ()
{
    while(1) {

        int
            number = 0,
            sun = 0,
            avg = 0,
            i
        ;
        int
            *number_p = &number,
            *sun_p = &sun,
            *avg_p = &avg
        ;

        for( i = 0 ; ; i++) {
            printf("Informe um numero inteiro: ");
            scanf("%d", number_p);
            if(*number_p >= 0) *sun_p += *number_p;
            else break;
        }

        *avg_p = *sun_p / i;
        printf("Media: %d", *avg_p);

        if (endGame() == 0) break;
        system("cls"); system("clear");
    }

    return 0;
}
#endif // ex06





