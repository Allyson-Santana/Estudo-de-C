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

/* 1 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
    video na funcao main(). O vetor é uma variavel local na função main().Passe
    como parametro para a funcao o vetor e a letra digitada usando ponteiros.
    Pesquise usando ponteiros. (utilize o comando return)
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */

#ifdef ex01
int pesquisaLetrar(char *letra, char *vet);

int main()
{

    // vetor
    char caracteres[] = {'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};

    char letra, *pvet = caracteres;
    char *p = &letra;

    while (1)
    {

        printf("\t Digite uma letra: ");
        scanf("%c", p);
        getchar();

        if (pesquisaLetrar(p, pvet))
        {
            printf("\t\n Letra-> %c EXISTE dentro do vetor\n", *p);
        }
        else
        {
            printf("\t\n Letra-> %c NAO EXISTE dentro do vetor\n", *p);
        }

        // fim do loop
        if (endGame() == 0)
            break;
        getchar();
        system("cls");
    }

    return 0;
}

int pesquisaLetrar(char *letra, char *vet)
{
    int i;
    for (i = 0; i < 13; i++)
    {
        if (*(vet + i) == *letra)
        {
            return 1;
        }
    }
    return 0;
}

#endif // ex01

#ifdef ex02
/** 2 - Escreva um programa que receba em 1 funcao 2 strings de ate' 10 caracteres.
    Os vetores sao declaradas como variavel local na função main().
    Escreva uma funcao que recebe as 2 strings como parametros usando ponteiros,
    compare estas 2 strings e retorno 1 se iguais ou 0 se diferentes. */

int setStrings(char *strOne_p, char *strTwo_p) {
    int equalBoll = 1;

    printf("\nDigite a primeira string de ate 10 caracteres: ");
    scanf(" %10[^\n]", strOne_p); // leitura da string ate apertar enter
    scanf("%*[^\n]"); // limpeza do buffer do teclado

    printf("\nDigite a segunda string de ate 10 caracteres: ");
    scanf(" %10[^\n]", strTwo_p); // leitura da string ate apertar enter
    scanf("%*[^\n]"); // limpeza do buffer do teclado

    /** COMPARE STRINGS */
    while (*strOne_p != '\0') {
        if( *strOne_p != *strTwo_p ) {
            equalBoll = 0;
            break;
        }
        strOne_p++;
        strTwo_p++;
    }

    return equalBoll;
}

int main()
{
    while(1) {
        static char stringOne[10+1], stringTwo[10+1];
        static char *stringOne_p = &stringOne, *stringTwo_p = &stringTwo;
        char equal_str[2][11] = {"diferentes","iguais"};

        int result = setStrings(stringOne_p, stringTwo_p);

        printf("\nValores informados");
        printf("\nString01 => %s \nString02 => %s \n", stringOne, stringTwo);

        printf("\nResultado do retorno: %d => %s \n", result, equal_str[result]);

        *stringOne_p = '\0';
        *stringTwo_p = '\0';

        if (endGame() == 0) break;
        system("cls");
    }

    return 0;
}
#endif // ex02

// ================================================================================

#ifdef ex3

/* Escreva um programa que receba n valores via teclado, receba também a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funções que recebe os valores usando ponteiros.*/

int a, b, c, r, x, k = 1, *px, *py;
char resp, operador;


main()
{
    setlocale(LC_ALL,"pt-br");

    int n;
    entrada();
    do
    {
        entrada();
    }
    while(k <= n);
}

//*****************************************
//inicio --> operações

//operação: somar
int soma(int *x, int *y)
{
    int calc;
    calc = *x + *y;
    return calc;
}

//opração: subttrair
int subtracao(int *x, int *y)
{
    int calc;
    calc = *x - *y;
    return calc;
}

//operação: multiplicar
int multiplicacao(int *x, int *y)
{
    int calc;
    calc = *x * *y;
    return calc;
}

//operação: dividir
int divisao(int *x, int *y)
{
    int calc = 0;
    if(*y == 0)
    {
        printf("\nEssa operacao nao pode ser realizada, pois nao e possivel dividir por 0\n");
    }
    else
    {
        calc = *x / *y;
    }
    return calc;
}
//fim de operações
//*****************************************

//entrada de dados via teclado
int entrada()
{
    if(k == 1)
    {
        printf("Digite o primeiro número: ");
        scanf("%i",&a);
        k++;
        px = &a;
    }
    else
    {
        do
        {
            printf("Digite o operador (+ - * / =): ");
            scanf("%s", &operador);
            if(operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '=')
                printf("\nEntrada invalida\n");
        }
        while(operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '=');
        if(operador != '=')
        {
            printf("Digite o segundo número: ", k);
            scanf("%i",&b);
            py = &b;
            k++;
        }
        switch (operador)
        {
        case '+':
            r = soma(&a, &b);
            printf("\nAdicao: %i + %i = %i\n", *px, *py, r);
            break;
        case '-':
            r = subtracao(&a, &b);
            printf("\nSubtracao: %i - %i = %i\n", *px, *py, r);
            break;
        case '*':
            r = multiplicacao(&a, &b);
            printf("\nMultiplicacao: %i * %i = %i\n", *px, *py, r);
            break;
        case '/':
            if(&b == 0)
            {
                printf("\nDivisao: %i / %i = ERRO\n", *px, *py);
                printf("\nOPERAÇÃO NÃO REALIZADA !! Número digitado não pode ser dividido por 0\n");
                break;
            }
            else
            {
                r = divisao(&a, &b);
                printf("\nDivisao: %i / %i = %i\n", *px, *py, r);
                break;
            }
        case '=':
            printf("\nO sinal digitado foi '=', então sera exibido o valor acumulado\n");
            printf("\nValor acumulado: %i\n", r);
            break;
        }
        a = r;
    }
}


#endif // ex3

// ================================================================================

#ifdef ex04
/** 4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura é uma variavel local na função main().Receba via teclado o
    conteudo de cada um dos membros numa função e imprima-os no video no
    seguinte formato(também numa função).

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long  */

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

void entryDate(data_struct *content_p) {

    printf("\n Digite um caracter do tipo (char): ");
    (*content_p).c = getchar(); getchar();
    printf("\n Digite um numero do tipo (int): ");
    scanf("%i",&(*content_p).i);
    printf("\n Digite um numero do tipo (long): ");
    scanf("%ld",&(*content_p).l);
    printf("\n Digite um numero do tipo (float): ");
    scanf("%f",&(*content_p).f);
    printf("\n Digite um numero do tipo (double): ");
    scanf("%g",&(*content_p).d);
    printf("\n Digite um caracter do tipo (unsigned char): ");
    (*content_p).uc = getchar(); getchar();
    printf("\n Digite um numero do tipo (unsigned int): ");
    scanf("%u",&(*content_p).ui);
    printf("\n Digite um numero do tipo (unsigned long): ");
    scanf("%lu",&(*content_p).ul);

}

void previewData(data_struct *content_p) {

        printf("\n        10        20        30        40        50        60        70");
        printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");

        printf("\n    %-1c         %-8i  %-8ld            %-8f            %-8g",
        (*content_p).c, (*content_p).i, (*content_p).l, (*content_p).f, (*content_p).d );

        printf("\n          %-1u                  %-10u          %-10lu",
        (*content_p).uc, (*content_p).ui, (*content_p).ul );
}

int main() {
    while(1) {
        data_struct content, *content_p;
        content_p = &content;

        entryDate(content_p);
        previewData(content_p);

        if (endGame() == 0) break;
        system("cls");
    }

    return 0;
}

#endif // ex04

// ================================================================================

/* 5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel local na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
                nome, end, cidade, estado, cep */

#ifdef ex05

typedef struct
{
    char name[21];
    char address[30];
    char city[15];
    char state[3];
    char cep[9];
} Data;

void entryDate(Data *dados);
void display(Data *dados);

int main(int argc, char const *argv[])
{
    // declara um vetor struct Date chamado dados com 4 elementos
    Data dados[4];

    // declara um ponteiro do tipo struct Data recebendo o endereço de memoria do vetor struct Date de nome dados
    struct Data *pd = &dados[0];

    while (1)
    {
        int option;
        printf("\t\nDigite a opcao Desejada\n");
        printf("\t 1 - Cadastro de Dados:\n");
        printf("\t 2 - Exibir os Dados:\n");
        printf("\t 3 - Exit:\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            system("cls");
            entryDate(dados);
            printf("\t\nFIM DOS CADASTROS\n");

            break;
        }
        case 2:
        {
            system("cls");
            display(dados);
            printf("\t\nFIM DOS DADOS\n");

            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("\tOpcao invalida \n");
            break;
        }
        }
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
        scanf(" %30[^\n]", dados[i].address);
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
    for (int i = 0; i < 4; i++)
    {
        printf("\n\t===================\n");
        printf("\t= Dados numero 0%d =\n", i + 1);
        printf("\t===================\n\n");

        printf("\tNome: %s \n", (dados + i)->name);
        printf("\tEndereco: %s \n", (dados + i)->address);
        printf("\tCidade: %s \n", (dados + i)->city);
        printf("\tEstado ex.sp : %s \n", (dados + i)->state);
        printf("\tCep: %s \n", (dados + i)->cep);
    }
}

#endif // ex05

// ================================================================================

/* 6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro.*/

#ifdef ex06

typedef struct
{
    char name[21];
    char address[30];
    char city[15];
    char state[3];
    char cep[9];
} Data;

void entryDate(Data *dados);
void display(Data *dados);

int main(int argc, char const *argv[])
{
    // declara um vetor struct Date chamado dados com 4 elementos
    Data dados[4];

    // declara um ponteiro do tipo struct Data recebendo o endereço de memoria do vetor struct Date de nome dados
    struct Data *pd = &dados[0];

    while (1)
    {
        int option;
        printf("\t\nDigite a opcao Desejada\n");
        printf("\t 1 - Cadastro de Dados:\n");
        printf("\t 2 - Exibir os Dados:\n");
        printf("\t 3 - Pesquisa de Dados:\n");
        printf("\t 4 - Alterar Dados:\n");
        printf("\t 5 - Excluir Dados:\n");
        printf("\t 6 - Exit:\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            system("cls");
            entryDate(pd);
            printf("\t\nFIM DOS CADASTROS\n");

            break;
        }
        case 2:
        {
            system("cls");
            display(pd);
            printf("\t\nFIM DOS DADOS\n");

            break;
        }
        case 3:
        {
            system("cls");
            searchData(pd);

            break;
        }
        case 4:
        {

            changeData(pd);
            break;
        }
        case 5:
        {
            deleteData(dados);
            break;
        }
        case 6:
        {
            exit(0);
            break;
        }
        default:
        {
            printf("\tOpcao invalida \n");
            break;
        }
        }
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
        scanf(" %30[^\n]", dados[i].address);
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

    printf("\t\n EXIBINDO DADOS CADASTRADOS:\n");
    printf("\t\n===========================\n\n");
    for (int i = 0; i < 4; i++)
    {
        if ((dados + i)->name[0] != '#')
        {

            printf("\n\t===================\n");
            printf("\t= Dados numero 0%d =\n", i + 1);
            printf("\t===================\n\n");

            printf("\tNome: %s \n", (dados + i)->name);
            printf("\tEndereco: %s \n", (dados + i)->address);
            printf("\tCidade: %s \n", (dados + i)->city);
            printf("\tEstado ex.sp : %s \n", (dados + i)->state);
            printf("\tCep: %s \n", (dados + i)->cep);
        }
        else
        {
            printf("\t\n\n NAO EXISTE DADOS CADASTRADOS:\n");
        }
    }
}

// funcao pesquisa dados

int searchData(Data *dados)
{

    char findName[21];
    printf("\t Pesquisa por NOME: \n");
    printf("\t ================= \n\n");
    printf("\t Digite um nome completo para pesquisar:\n");
    scanf(" %20[^\n]", findName);
    getchar();

    system("cls");
    printf("\t\n\n Pesquisando por %s...:\n", findName);
    printf("\t ===================================\n\n");

    // pesquisa no vetor

    int i, k;
    for (int j = 0; j < 4; j++)
    {

        for (i = 0; i < findName[i] != '\0'; i++)
        {
            // printf("\t exibir nome: %c \n",(dados + j)->name[i]);

            if (findName[i] != (dados + j)->name[i])
            {
                k = -1;
                break;
            }
        }

        if ((dados + j)->name[i] == '\0' && findName[i] == '\0' && (dados + j)->name[0] != '#')
        {

            printf("\t Dados encontrado pelo nome: \n\n");
            printf("\tNome: %s \n", (dados + j)->name);
            printf("\tEndereco: %s \n", (dados + j)->address);
            printf("\tCidade: %s \n", (dados + j)->city);
            printf("\tEstado ex.sp : %s \n", (dados + j)->state);
            printf("\tCep: %s \n", (dados + j)->cep);
            return j;
        }
    }

    if (k == -1)
    {
        printf("\t\n Nome nao encontado:\n");
        return -1;
    }
}

// funcao altera dados

int changeData(Data *dados)
{
    int index = searchData(dados);
    if (index < 0)
        return;

    printf("\t\n Deseja realmente ALTERAR esses dados? \n\n");

    char confirm;
    while (confirm != 's' && confirm != 'n')
    {
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if (confirm == 'n')
    {
        printf("\nAlteracao cancelada!.....\n");
        getchar();
        return;
    }

    system("cls");
    printf("\t\n Alterar Dados: \n\n");
    printf("\t ====================== \n\n");

    printf("\tEntre com o nome: ");
    scanf(" %20[^\n]", dados[index].name); // leitura da string limitado ate 20 caracteres ate apertar enter
    scanf("%*[^\n]");                      // limpeza do buffer do teclado

    printf("\n\tEntre com o endereco: ");
    scanf(" %30[^\n]", dados[index].address);
    scanf("%*[^\n]");

    printf("\n\tEntre com a cidade: ");
    scanf(" %15[^\n]", dados[index].city);
    scanf("%*[^\n]");

    printf("\n\tEntre com o estado: ");
    scanf(" %2[^\n]", dados[index].state);
    scanf("%*[^\n]");

    printf("\n\tEntre com o cep: ");
    scanf(" %8[^\n]", dados[index].cep);
    scanf("%*[^\n]");

    printf("\nDados alterarados para:\n");
    printf("\tNome: %s \n", (dados + index)->name);
    printf("\tEndereco: %s \n", (dados + index)->address);
    printf("\tCidade: %s \n", (dados + index)->city);
    printf("\tEstado ex.sp : %s \n", (dados + index)->state);
    printf("\tCep: %s \n", (dados + index)->cep);
}

// funcao excluir dados

int deleteData(Data *dados)
{
    int index = searchData(dados);
    if (index < 0)
        return;

    printf("\t\n Deseja realmente EXCLUIR esses dados? \n\n");

    char confirm;
    while (confirm != 's' && confirm != 'n')
    {
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if (confirm == 'n')
    {
        printf("\nAlteracao cancelada!.....\n");
        getchar();
        return;
    }

    char strNull = '#';

    (dados + index)->name[0] = strNull;

    printf("\n Operacao realizada com sucesso!.....\n");
    getchar();
}

#endif // ex06
