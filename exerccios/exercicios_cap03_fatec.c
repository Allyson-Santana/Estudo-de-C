#include <stdlib.h>
#include <locale.h>

#define BR * setlocale(LC_ALL, ""); //  apenas para facilitar setar o setlocale com  "BR" nos exercícios.

#define ex3

/*==================================================================================================*/

/*OBS.: Todos os programa devem ser finalizados pelo usuario.*/

//Exercicio 01


#ifdef ex01

/*1 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main().*/


    int soma(int x, int y);
    int subtrai(int x, int y);
    int mult(int x, int y);
    float dividir(int x, int y);

int main(){

    BR; // setlocale



    int a,b,fim;

    for(;fim != 2;){

        printf("\t Digite 2 valores inteiros:\n");
        scanf("%d%d",&a,&b);

        int s = soma(a,b);
        printf("\t A Soma dos valores %d e %d é: %d \n",a,b,s);

        int sub = subtrai(a,b);
        printf("\t A Subtração de %d - %d é: %d \n",a,b,sub);

        int m = mult(a,b);
        printf("\t A multiplicação de %d x %d é: %d \n",a,b,m);

        float d = dividir(a,b);
        printf("\t A divisão de %d : %d é: %.2f \n",a,b,d);

        printf("\t ==================================================.\n\n");

        printf("\t Digite 1 para rodar novamente ou 2 para finalizar.\n");
            scanf("%d",&fim);
                if(fim == 2){
                    break;
                }else {
                    system("cls");
                }


    }

printf("\t FIM\n");

return 0;

}

// soma

int soma(int x, int y){

int k;
k = x + y;

return k;
}

// subtração

int subtrai(int x, int y){

int k;
k = x - y;

return k;
}

// multiplicação

int mult(int x, int y){

int k;
k = x * y;

return k;
}

// divisão

float dividir(int x, int y){

float a,b,k;
a = x;
b = y;
k = a / b;

return k;
}

#endif // ex01

/*==================================================================================================*/

//Exercicio 02

#ifdef ex02

/*2 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
    para transforma-lo em uma calculadora. (utilize o comando switch). As operacoes
    aritmeticas devem estar em funcoes. O resultado deve ser mostrado na
    funcao main()*/

    float soma(float x, float y);
    float subtrai(float x, float y);
    float mult(float x, float y);
    float dividir(float x, float y);


int main(){

    BR; //setlocale

float n;
float result;
char c;

printf("\t Calculadora das operações matematicas usando as teclas [+, -, *, /] e para finalizar use [=] :\n\n\n");
//printf("\t Para visualizar o resultado aperta = \n\n");


    printf("\tDigite um número: ");
    scanf("%f",&result);



    for(;c != '=';){

        printf("\t :%.2f", result);
        if(c != 0){
            printf("\t\nEscolha a operação [ +,-,*,/ ] ou [=] ");
        }else{
            printf("\t\nEscolha a operação [ +,-,*,/ ]: ");
        }
        scanf("%c",&c);
        c = getchar();

        switch(c) {
            case '+' : {

                printf("\tProximo número: ");
                scanf("%f",&n);
                result = soma(result,n);

                break;
            }
            case '-' : {
                printf("\tProximo número: ");
                scanf("%f",&n);
                result = subtrai(result,n);

                break;
            }
            case '*' : {
                printf("\tProximo número: ");
                scanf("%f",&n);
                result = mult(result,n);

                break;
            }
            case '/' : {
                printf("\tProximo número: ");
                scanf("%f",&n);
                result = dividir(result,n);

                break;
            }
            case '=' :{

                break;
            }

            default:
            {
            printf ("\nA opcão escolhida é inválida.");
            }


        }

    }
    printf("\t =====================\n", result);
    printf("\t RESULTADO = %.2f\n", result);



return 0;
}

// soma

float soma(float x,float y){

float k;
k = x + y;

return k;
}

// subtração

float subtrai(float x,float y){

float k;
k = x - y;

return k;
}

// multiplicação

float mult(float x,float y){

float k;
k = x * y;

return k;
}

// divisão

float dividir(float x,float y){

float k;

k = x / y;

return k;
}

#endif // ex02


#ifdef ex4
/**
    Faça um programa receba dois números inteiros e execute as seguintes funções:
    - Verificar se o número digitado é positivo ou negativo. Sendo que o valor de
      retorno será 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 números são positivos, retorne a soma dos N números existentes entre
      eles.
    - Se os 2 números são negativos, retorne a multiplicação dos N números existente
      entre eles.
*/
int positivoOuNegativo(int n)
{
    if(n > 0) return 1;
    if(n < 0) return 0;
    if(n == 0) return -1;
    else printf("Algo deu errado...\n");
}
int numerosPositivos(int numeros[2])
{
    int i, soma;
    soma = 0;
    for (i = numeros[0]; i <= numeros[1]; i++) {
        soma += i;
    }
    return soma;
}
int numerosNegativos(int numeros[2])
{
    int i, soma;
    soma = 1;
    for (i = numeros[0]; i <= numeros[1]; i++) {
        soma *= i;
    }
    return soma;
}
int main()
{
    int numeros[2], i, result;
    for( i = 0; i < 2; i++) {
        printf("Digite o %i numero: ", i+1);
        scanf("%i", &numeros[i]);
    }

    for(i = 0; i < 2; i++) {
        result = positivoOuNegativo(numeros[i]);
        printf("Numero %i retornou %i \n", numeros[i], result);
    }

    if (numeros[0] > numeros[1]) {
        numeros[0] = numeros[0] + numeros[1];
        numeros[1] = numeros[0] - numeros[1];
        numeros[0] = numeros[0] - numeros[1];
    }

    if(numeros[0] > 0 && numeros[1] > 0) {
        result = numerosPositivos(numeros);
        printf("soma dos N numeros existentes entre eles: %i \n", result);
    }
    if(numeros[0] < 0 && numeros[1] < 0) {
        result = numerosNegativos(numeros);
        printf("multiplicacao dos N numeros existente entre eles: %i \n", result);
    }

    return 0;
}
#endif // ex4

#ifdef ex5
/**
    Escreva um programa que receba um numero N. Escreva uma função que
    retorne a soma dos algarismos de N!. O resultado deve ser mostrado na funcao
    main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos ´e 2 + 4 = 6.
*/

void somaAlgarismo(int n)
{
    int i, algorismos, soma;
    algorismos = 1;
    for (i = n; i > 1; i--) {
        printf("%i \n", i);
        algorismos *= i;
    }

    printf("algorismos => %i\n", algorismos);

    while (algorismos) {
		soma += algorismos % 10;
		algorismos /= 10;
	}

    printf("soma => %i\n", soma);

}
int main()
{
    int n;

    printf("Informe um numero: ");
    scanf("%i", &n);

    somaAlgarismo(n);

    return 0;
}
#endif // ex5

#ifdef ex3
/**
    Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao a letra
    digitada.(utilize o comando return). O vetor deve ser uma variavel global.
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/
char caracteres[13][1] = {"b","d","f","h","j","k","m","o","q","s","u","w","y"};

int pesquisaLetrar(char letra)
{
    int i, complimento_array;
    complimento_array = sizeof(caracteres)/sizeof(caracteres[0]);
    for(i = 0; i < complimento_array; i++) {
        if(caracteres[i][0] == letra) {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char letra;

    printf("Digite uma letra: ");
    letra = getchar();

    if(pesquisaLetrar(letra)) {
        printf("\nBoaa... Letra '%c' foi encontrada no array!\n", letra);
    } else {
        printf("\nOps... Letra '%c' nao encontrada no array!\n", letra);
    }

    return 0;
}
#endif // ex3



