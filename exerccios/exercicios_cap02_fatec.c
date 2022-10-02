#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BR * setlocale(LC_ALL, ""); //  apenas para facilitar setar o setlocale com  BR nos exercicios.

#define ex04




// funcão para o loop

int func_loop(){
    int a;
    printf("\t\n Gostaria de rodar o programa novamente?\n");
    printf("\t Digite 1 para sim ou 2 para finalizar\n");
        scanf("%d",&a);
            if( a == 1)
                system("cls");
                else
                    printf("\t=================\n");
                    printf("\t=FIM DO PROGRAMA=\n");
                    printf("\t=================\n");

    return a;
}


//*****************************************************************************************************
//OBS.: Faça um loop infinito e defina uma saida em todos os exercicios.

//exercicio01

#ifdef ex01

/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/


pesquisa(int menor, int maior, int media, char ch);

int main (){

    BR; //setlocale


char ch;

int k;

while(k != 2 ){

    int menor = 1, maior = 99, media = 50;

    printf("\t Pense em um nÃºmero de 1 a 99, este programa tentara encontra-lo com sua ajuda.\n");
    printf("\t===============================================================================\n");
    printf("\t  Para MAIOR Use a tecla '>', MENOR a tecla '<' e nÃºmero CORRETO a tecla '=' \n\n");


    pesquisa(menor,maior,media,ch);

    k = func_loop();
    getchar();

}

return 0;
}

pesquisa(int menor, int maior, int media, char ch){

    int cont = 0;
    while(ch != '='){



        if(media < 1) {
            media = 1;
            printf("\t===============================\n");
            printf("\t O numero deve ser entre 1 a 99 \n\n");
        }


        printf("\t O numero que voce pensou eh: %d ?\n", media);
        ch = getchar();
        getchar();

        if(ch == '='){

            printf("\t Achei !!! Depois de %d tentativas, O numero correto eh %d \n",cont, media);
        }
        if(ch == '>'){

            menor = media + 1;
            media = (menor+maior)/2;
            cont+= 1;
        }
        if(ch == '<'){

            maior = media - 1;
            media = (menor+maior)/2;
            cont+= 1;
        }



    }
}

#endif // ex01



//*****************************************************************************************************

//exercicio02

#ifdef ex02

/* 2 - Resecreva o programa do execicio anterior agora utilizando o comando switch.
 *     Conte o n. de tentativas e imprima o resultado no video.
 */



pesquisa(int menor, int maior, int media, char ch);

int main (){

    BR; //setlocale

;
char ch;
int k;

    while(k != 2){
        int menor = 1, maior = 99, media = 50;

        printf("\t Pense em um numero de 1 a 99, este programa tentara encontra-lo com sua ajuda.\n");
        printf("\t===============================================================================\n");
        printf("\t  Para MAIOR Use a tecla '>', MENOR a tecla '<' e numero CORRETO a tecla '=' \n\n");


        pesquisa(menor,maior,media,ch);

        k = func_loop();
        getchar();
    }



return 0;
}

pesquisa(int menor, int maior, int media, char ch) {

    int cont = 0;
    while(ch != '=') {


        if(media < 1) {
            media = 1;
            printf("\t===============================\n");
            printf("\t O numero deve ser entre 1 a 99 \n\n");
        }

        printf("\t O numero que voce pensoueh: %d ?\n", media);
        ch = getchar();
        getchar();

        switch (ch){

            case '=':
            {

                printf("\t Achei !!! Depois de %d tentativas, O numero correto Ã© %d \n",cont, media);
                 break;
            }
            case '>':
            {

                menor = media + 1;
                media = (menor+maior)/2;
                cont+= 1;
                break;
            }
            case '<':
            {

                maior = media - 1;
                media = (menor+maior)/2;
                cont+= 1;
                 break;
            }

            default:
            {
                printf("\t  Para MAIOR Use a tecla '>', MENOR a tecla '<' e numero CORRETO a tecla '=' \n\n");
            }
        }


    }

}

#endif // ex02

//*****************************************************************************************************

//exercicio03

#ifdef ex03

/*3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/



int main() {

    BR; // setlocale
    int k;

while(k != 2){

    int num[50];
    float media = 0;
    int i = 0; // primeira posicao do vetor

    for(i;; i++) {

        printf("\t\n Digite um numero: ");
        scanf("%d",&num[i]);
        if(num[i] < 0) {
            break;
        }

        media += num[i];
    }

    i+1; // para corrigir a quantidade de numeros digitados pelo usuario, pois a variavel foi iniciada com zero.

    media = media / i;

    printf("\t A meda dos numeros positivos digitados eh: %.2f ", media);

     k = func_loop();
     getchar();
}

    return 0;
}


#endif // ex03


//*****************************************************************************************************

//exercicio04

#ifdef ex04


/*4 - As ligacoes telefonicas sÃ£o cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.*/

int timecalc_ini();
int timecalc_fim();
void calc_horas(int sec);

int main() {

    BR; // setlocale


    printf("\t Programa para calcular o tempo decorrido de uma ligação\n");
    printf("\t =======================================================\n\n\n");

    int decorrido,ini,fim;

    int k;


    while( k!= 2) {

        printf("\t Programa para calcular o tempo decorrido de uma ligacao\n");
        printf("\t =======================================================\n\n\n");

        int decorrido,ini,fim;

        ini = timecalc_ini();
        fim = timecalc_fim();

        decorrido = fim - ini;

        calc_horas(decorrido);

        k = func_loop();
        getchar();

    }


    calc_horas(decorrido);

    return 0;

}


int timecalc_ini() {

    int ho = 24;
    int mi = 59;
    int sec = 59;

    do {

        printf("\t Digite a hora do inicio da ligacao, ex. 20, para 20 horas...: ");
        scanf("%d",&ho);
        if(ho < 1 || ho > 24) {

            printf("\t utilize o sistema de 24 horas 1 a 24 para horas\n");
            system("pause");
            system("cls");
        }
    } while(ho < 1 || ho > 24);

    do {

        printf("\t Digite os minutos, ex. 59, para 59 minutos...: ");
        scanf("%d",&mi);
        if(mi < 0 || mi > 59) {

            printf("\t minutos de 1 a 59 \n");
            system("pause");
            system("cls");
        }
    } while(mi < 0 || mi > 59);

    do {

        printf("\t Digite os segundos, ex. 59, para 59 segundos...: ");
        scanf("%d",&sec);
        if(sec < 0 || sec > 59) {

            printf("\t segundos de 1 a 59 \n");
            system("pause");
            system("cls");
        }
    } while(sec < 0 || sec > 59);

    system("cls");


    if( mi < 10 && sec < 10  ) {

        printf("\t Horário  inicial: %d:0%d:0%d \n", ho,mi,sec);

    } else if (sec < 10) {

        printf("\t Horário  inicial: %d:%d:0%d \n", ho,mi,sec);

    } else if(mi < 10) {

        printf("\t Horário  inicial: %d:0%d:%d \n", ho,mi,sec);

    } else {
        printf("\t Horário  inicial: %d:%d:%d \n", ho,mi,sec);

    }

    int time_ini = (ho * 3600) + (mi * 60) + sec;

    return time_ini;

}


int timecalc_fim() {

    int ho = 24;
    int mi = 59;
    int sec = 59;

    do {

        printf("\t Digite a hora do fim da ligacao, ex. 20, para 20 horas...: ");
        scanf("%d",&ho);
        if(ho < 1 || ho > 24) {

            printf("\t utilize o sistema de 24 horas 1 a 24 para horas\n");
            system("pause");
            system("cls");
        }
    } while(ho < 1 || ho > 24);

    do {

        printf("\t Digite os minutos, ex. 59, para 59 minutos...: ");
        scanf("%d",&mi);
        if(mi < 0 || mi > 59) {

            printf("\t minutos de 1 a 59 \n");
            system("pause");
            system("cls");
        }
    } while(mi < 0 || mi > 59);

    do {

        printf("\t Digite os segundos, ex. 59, para 59 segundos...: ");
        scanf("%d",&sec);
        if(sec < 0 || sec > 59) {

            printf("\t segundos de 1 a 59 \n");
            system("pause");
            system("cls");
        }
    } while(sec < 0 || sec > 59);

    system("cls");

// formatacao das horas no printf
    if( mi < 10 && sec < 10  ) {

        printf("\t Horario final: %d:0%d:0%d \n", ho,mi,sec);

    } else if (sec < 10) {

        printf("\t Horario final: %d:%d:0%d \n", ho,mi,sec);

    } else if(mi < 10) {

        printf("\t Horario final: %d:0%d:%d \n", ho,mi,sec);

    } else {
        printf("\t Horario final: %d:%d:%d \n", ho,mi,sec);

    }

    int time_fim = (ho * 3600) + (mi * 60) + sec;

    return time_fim;
}


    void calc_horas(int sec) {

        int h,m,s,resto;

        h = sec / 3600;
        resto = sec % 3600;
        m = resto / 60;
        s = resto % 60;


        printf("\t\n Tempo decorrido %d horas %d minutos e %d segundos.\n",h,m,s);

    }

#endif // ex04


#ifdef ex5
/**
     Um posto está vendendo combustíveis com a seguinte tabela de descontos:
     Álcool
         até 20 litros, desconto de 3% por litro
         acima de 20 litros, desconto de 5% por litro
     Gasolina
          até 20 litros, desconto de 4% por litro
          acima de 20 litros, desconto de 6% por litro
     Escreva um programa que leia o número de litros vendidos e o tipo de
     combustível (codificado da seguinte forma: A-álcool, G-gasolina). Calcule e
     imprima o valor a ser pago pelo cliente sabendo-se que o preço do litro da
     gasolina é R$ 5,88 e o preço do litro do álcool é R$ 4,18.
**/
float calcGasolina(litros) // cada litro aqui é 5,88
{
    float valuePorLitro = 5.88;
    if(litros <= 20)
        valuePorLitro -= 5.88 * 0.04;
    else
        valuePorLitro -= 5.88 * 0.06;

    return (litros * valuePorLitro);
}

float calcAlchool(litros) // cada litro aqui é 4,18
{
    float valuePorLitro = 4.18;
    if(litros <= 20)
        valuePorLitro -= 4.18 * 0.03;
    else
        valuePorLitro -= 4.18 * 0.05;

    return (litros * valuePorLitro);
}

int main()
{
    char type;
    int litros;
    printf("(A) para alchool\n");
    printf("(G) para gasolina\n");

    printf("Achool ou Gasolina meu bem? ");
    scanf("%s", &type);

    printf("Quantos litros guerreiro? ");
    scanf("%i", &litros);

    type = toupper(type); // converter wm maiúsculo.
    switch(type) {
        case 'G'  :
        case 'g'  :
            printf("Valor total: %.2f", calcGasolina(litros));
            break;

        case 'A' :
        case 'a' :
            printf("Valor total: %.2f", calcAlchool(litros));
            break;

        default :
            printf("Valor não compreendido...");
    }
    return 0;
}
#endif // ex5
