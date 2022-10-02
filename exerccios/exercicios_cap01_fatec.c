#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BR * setlocale(LC_ALL, ""); //  apenas para facilitar setar o setlocale com  BR nos exercícios.

#define ex05

//exercicio01

#ifdef ex01


/*1 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/


// prototipos das funções

int recebe_num(int num[2]);
void calc_mult(int v[2]);

//-------------------------

int main(){

BR; // para o setlocale

int numeros[2];


    printf("\t Este programa determina o menor múltiplo de um número inteiro\n");
    printf("\t Este múltiplo deve ser maior que o limite mínimo dado pelo usuário.\n");
    printf("\t ---------------------------------------------------------.\n\n");

    recebe_num(numeros);

    calc_mult(numeros);


    return 0;

}

// Funções

int recebe_num(int num[2]){


    do {
        printf("\t Digite um número: ");
        scanf("%d",&num[0]);
        if(num[0] <= 0) {
            printf("\t Favor digite um número maior que ZERO\n");
            system("pause");
            system("cls");
        }


    } while(num[0] <= 0);

     do {
        printf("\t Digite um número para o limite: ");
        scanf("%d",&num[1]);
        if(num[1] <= 0) {
            printf("\t Favor digite um número maior que ZERO\n");
            system("pause");
            system("cls");
        }


    } while(num[1] <= 0);


}

void calc_mult(int v[2]){

int cont = 1;
int mult = v[0];

for ( cont ; mult <= v[1]; cont++){

   mult+= v[0];

}
printf("\t O valor do múltiplo de %d maior que %d é : %d \n", v[0], v[1], mult);

}

#endif // ex01

//*******************************************************************************************

//exercicio02

#ifdef ex02

/*2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/
//------------------------------------------------------------------------------------------------


 int main(){

 BR; // setlocale

 short int curto;
 long int longo;
 int inteiro;
 float real;
 double dobro;
 char c;


    printf("\t Digite um número inteiro short: ");
    scanf("%d",&curto);

    printf("\n \t Digite um número inteiro long: ");
    scanf("%d",&longo);

    printf("\n \t Digite um número inteiro qualquer: ");
    scanf("%d",&inteiro);

    printf("\n \t Digite um número real com casas decimais ex.123,45 : ");
    scanf("%f",&real);

    printf("\n \t Digite um valor alto tipo Double : ");
    scanf("%lf",&dobro);

    printf("\n \t Digite um caracter : \n");
    scanf("%c",&c);
    c = getchar();



    printf("\t        10        20        30        40        50        60     \n");
    printf("\t12345678901234567890123456789012345678901234567890123456789012345\n");

    printf("\t    %-6hd              %-11ld         %-11d\n",curto,longo,inteiro);
    printf("\t              %-8.1e            %-8g            %c\n\n",real,dobro,c);


 return 0;

 }

#endif // ex02

//*******************************************************************************************

//exercicio03


#ifdef ex03

/*3 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.*/


//Protótipos Funções

    void timecalc(float t);

int main(){

BR; //setlocale

float time;

printf("\t Digite um tempo em segundos para converter em horas, minutos e segundos: ");
scanf("%f", &time);

timecalc(time);



return 0;
}

void timecalc(float t){

int h = 0;
int m = 0;
float s = 0;

float div;

div = t / 60;

printf("\t valor de div = %f \n", div );



    if(div >= 60) {

        for( h; div >= 60; h++) {

            div = div - 60;
        }
    }

m = div; // variavel int exclui as casas decimais, mantendo apenas o valor inteiro dos minutos.

s = (div - m)*60;


printf("\t %.0f segundos equivale à %d horas %d minutos e %.0f segundos.",t ,h ,m ,s);


}

#endif // ex03

//*******************************************************************************************

//exercicio04

#ifdef ex04

/*4 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
variável auxiliar. */




int main(void) {

    BR; // setlocale

int var1, var2;

printf("\t Digite um valor inteiro para variavel 1\n");
scanf("%d",&var1);


printf("\t Digite um valor inteiro para variavel 2\n");
scanf("%d",&var2);

printf("\t o valor da variável 1 é: %d\n", var1);

printf("\t o valor da variável 2 é: %d\n", var2);

// apenas consegui achar a solução usando funções aritméticas.

var2 = var1 + var2; // variável 2 terá o valor da soma das 2 variáveis.
var1 = var2 - var1; // variável 1 terá a diferença do novo valor da variavel 2 e ela mesma. criando o valor original da variável 2.
var2 = var2 - var1; // variável 2 terá o valor da diferença entre ela e o novo valor da variável 1, criando o valor original da variável 1.



printf("\t o valor da variável 1 passou a ser é: %d\n", var1);
printf("\t o valor da variável 2 passou a ser é: %d\n", var2);


	return 0;
}


#endif // ex04

//*******************************************************************************************

//exercicio05

#ifdef ex05

int main()
{
    int money, calc, value;
    printf("Informe o valor em Reais: ");
    scanf("%d", &value);

    money = value;

    calc = money / 100; // get 100
    if(calc != 0) printf("-> %d nota(as) de $100\n", calc);
    money += - calc * 100;

    calc = money / 50; // get 50
    if(calc != 0) printf("-> %d nota(as) de $50\n", calc);
    money += - calc * 50;

    calc = money / 20; // get $20
    if(calc != 0) printf("-> %d nota(as) de $20\n", calc);
    money += - calc * 20;

    calc = (money % 20) / 10; // get $10
    if(calc != 0) printf("-> %d nota(as) de $10\n", calc);
    money += - calc * 10;

    calc = money / 5; // get $5
    if(calc != 0) printf("-> %d nota(as) de $5\n", calc);
    money += - calc * 5;

    if(money != 0) printf("-> %d nota(as) de $1\n", money);

    printf("Valor Inicial: %d \n", value);

    return 0;
}



#endif // ex05



