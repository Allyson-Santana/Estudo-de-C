#include <stdio.h>
#include <locale.h>
#define ex03
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


// EX 01
#ifdef ex01 // operações aritiméticas

/* 1 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas. */

int num, num2, soma, sub, multi, Continue;
float divs;

int main()
{
    setlocale(LC_ALL,"");
    system("color 7C");

    printf("\t\t*******************************************************************************\n");
    printf("\t\t***** ESSE PROGRAMA TEM COMO OBJETIVO REALIZAR AS 4 OPREAÇÕES ARITMÉTICAS *****\n");
    printf("\t\t*******************************************************************************\n");
    operacoes();

    for ( ; ; )
    {
        printf("\n\tDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &Continue);
        system("cls");

        if ( Continue == 1)
            operacoes();
        else
        {
            break;
        }
    }
}
int operacoes()
{

    printf("\n\t\t Digite o primeiro valor: ");
    scanf("%d", &num);
    printf("\t\t Digite o segundo valor: ");
    scanf("%d", &num2);

    soma =  num + num2;
    sub =   num - num2;
    multi = num * num2;
    divs =  (float)num / num2;

    printf("\n\tO resultado das operaçoes aritméticas são:\n\n ");
    printf("\t\t SOMA: %d \n\t\t SUBTRAÇÃO: %d\n\t\t MULTIPLICAÇÃO: %d\n\t\t DIVISÃO: %.1f\n\n", soma, sub, multi, divs);
}
#endif // ex01


//***************************************************************************************************************************************


// EX 02
#ifdef ex02 // operações de atribuição composta

int num, Continue;

int main()
{
    setlocale(LC_ALL,"");
    system("color 7C");

    printf("\t\t********************************************************************************\n");
    printf("\t\t**ESSE PROGRAMA TEM COMO OBJETIVO REALIZAR AS OPREAÇÕES DE ATRIBUIÇÃO COMPOSTA**\n");
    printf("\t\t********************************************************************************\n");
    operacoes();

    for ( ; ; )
    {
        printf("\n\tDigite 0 para sair ou 1 para continuar: ");
        scanf("%d", &Continue);
        system("cls");

        if ( Continue == 1)
            operacoes();
        else
        {
            break;
        }
    }
}
int operacoes()
{
    printf("\n\t\t Digite um valor: ");
    scanf("%d", &num);

    float aux;
    printf("\n\tResultado das operaçoes de atrinuição composta \n\n ");
    aux = num;
    printf("\t\t SOMANDO 5 AO VALOR INICIAL         = %.2f \n", (aux += 5) );
    aux = num;
    printf("\t\t SUBTRAINDO 5 AO VALOR INICIAL      = %.2f \n", (aux -= 5) );
    aux = num;
    printf("\t\t MULTIPLICANDO 5 AO VALOR INICIAL   = %.2f \n", (aux *= 5) );
    aux = num;
    printf("\t\t DIVIDINDO 5 AO VALOR INICIAL       = %.2f \n", ((float)(aux /= 5)) );
}
#endif // ex02

//***************************************************************************************************************************************

// ex03

#ifdef ex03
/**3 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/

int validar(int dia, int mes, int anoNasc, int anoHoje) {
    if(dia <= 0 || dia > 31) {
        printf("Dia invalido! \n");
        return 1;
    }
    if(mes <= 0 || mes > 12) {
        printf("Mes invalido! \n");
        return 1;
    }
    if(anoNasc < 1900 || anoNasc > anoHoje) {
        printf("Ano invalido ou menor que 1900 (Dinossauro?)! \n");
        return 1;
    }
    return 0;
}

int main()
{
    while(1) {
        int diaNascimento, diaHoje, mesNascimento, mesHoje, anoNascimento, anoHoje, dias = 0;
        int idade[3] = {0,0,0}, contaMes_hoje, contaMes_nasc;
        int tabelaDeMeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        do {
            printf("Digite o dia que voce nasceu:\n");
            scanf("%d", &diaNascimento);
            printf("Digite o mes que voce nasceu:\n");
            scanf("%d", &mesNascimento);
            printf("Digite o ano que voce nasceu:\n");
            scanf("%d", &anoNascimento);
        }while( validar(diaNascimento, mesNascimento, anoNascimento, anoNascimento) );
        do{
            printf("Digite o dia (data de hoje):\n");
            scanf("%d", &diaHoje);
            printf("Digite o mes (data de hoje):\n");
            scanf("%d", &mesHoje);
            printf("Digite o ano (data de hoje):\n");
            scanf("%d", &anoHoje);
        }while( validar(diaHoje, mesHoje, anoNascimento, anoHoje) );

        // converte os anos em dias e soma
        int anos = anoHoje - anoNascimento;
        idade[2] = anos - 1;
        dias += (anos-1) * 365 + anos / 4;

        // converte os meses em dias e soma
        for (contaMes_hoje = 0; contaMes_hoje < mesHoje - 1; contaMes_hoje++) {
            dias += tabelaDeMeses[contaMes_hoje];
        }

        int diasNaoVividoAindaDoAno = 0;
        for (contaMes_nasc = 0; contaMes_nasc< mesNascimento - 1; contaMes_nasc++) {
            diasNaoVividoAindaDoAno += tabelaDeMeses[contaMes_nasc];
        }
        idade[1] = contaMes_hoje + 12 - contaMes_nasc;
        dias += 365 - diasNaoVividoAindaDoAno;

        // soma os dias
        if(diaHoje > diaNascimento) {
           dias += diaHoje - diaNascimento;
           idade[0] =  diaHoje - diaNascimento;
        }
        if (diaNascimento > diaHoje) {
            int diasMeses = 0, rest = 0;
            diasMeses = tabelaDeMeses[mesNascimento-1];
            rest = diasMeses - (diaNascimento - diaHoje);
            dias += rest - diasMeses;
            idade[1] -= 1;
            idade[0] = tabelaDeMeses[mesHoje - 1] - (diaNascimento - diaHoje);
        }

        printf("\nIdade: %i anos, %i meses e %i dias. \n", idade[2], idade[1], idade[0]); //resultado final
        printf("\nBonus");
        printf("\nPassou por %i anos bissextos:", (anos / 4) );
        printf("\nBonus: vc viveu %i dias\n", dias); //resultado fina

        if (endGame() == 0) break;
        system("cls"); system("clear");
    }
    return 0;
}
#endif // ex03

//***************************************************************************************************************************************

// Ex 04

#ifdef ex04

/* 4 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal. */



int main(){

    setlocale(LC_ALL, "");

    int n1, n2;

    while(1){

        printf("\t Digite o primeiro número: ");
        scanf("%d",&n1);

        printf("\t Digite o segundo número: ");
        scanf("%d",&n2);

        printf("\t Operações logicas Bit a Bit\n\n");
        printf("\tO valor inteiro %d e %d --> Operador AND -- Decimal: %d e Hexadecimal : 0x%x\n",n1, n2, n1 & n2, n1 & n2);

        printf("\tO valor inteiro %d e %d --> Operador OU -- Decimal: %d e Hexadecimal : 0x%x\n",n1, n2, n1 | n2, n1 | n2);

        printf("\tO valor inteiro %d e %d --> Operador AND -- Decimal: %d e Hexadecimal : 0x%x\n",n1, n2, n1 ^ n2, n1 ^ n2);



        if(endGame() == 0) break;
        system("cls");
    }

    return 0;
}

#endif // ex04


// ================================================================================

// Ex 05

#ifdef ex05

float C_to_F(float g);
float C_to_K(float g);
float F_to_C(float g);
float F_to_K(float g);
float K_to_C(float g);
float K_to_F(float g);

/* 5 - Escreva um programa que receba via teclado um valor e tenha o menu abaixo.
       1 - transforma graus Celsius em Fahrenheit e Kelvin
       2 - transforma graus Fahrenheit em Celsius e Kelvin
       3 - transforma graus Kelvin em Celsius e Fahrenheit
    Cada opcao de menu deve chamar uma funcao que retorna o resultado da
    conversao. O resultado deve ser mostrado na funcao main(). */



int main(){

    setlocale(LC_ALL, "");

    int opcao;
    float graus, result[2];

    while(1){

        printf("\t Digite a opção desejada\n");
        printf("\t =======================\n");

        printf("\t 1 - transforma graus Celsius em Fahrenheit e Kelvin\n");
        printf("\t 2 - transforma graus Fahrenheit em Celsius e Kelvin\n");
        printf("\t 3 - transforma graus Kelvin em Celsius e Fahrenheit\n\n");
        scanf("%d",&opcao);


        switch (opcao)
        {
        case 1:

            printf("\t Digite o grau Celsius: ");
            scanf("%f",&graus);

             result[0] = C_to_F(graus);
             result[1] = C_to_K(graus);

            printf("\t%.1f Graus Celsius  para Fahrenheit: %g\n",graus,result[0]);
            printf("\t%.1f Graus Celsius  para Kelvin: %g\n",graus,result[1]);

            break;

        case 2:

            printf("\t Digite o grau Fahrenheit: ");
            scanf("%f",&graus);

             result[0] = F_to_C(graus);
             result[1] = F_to_K(graus);

            printf("\t%.2f Graus Fahrenheit  para Celsius: %g\n",graus,result[0]);
            printf("\t%.2f Graus Fahrenheit  para Kelvin: %g\n",graus,result[1]);

            break;

        case 3:

            printf("\t Digite o grau Kelvin: ");
            scanf("%f",&graus);

            result[0] = K_to_C(graus);
            result[1] = K_to_F(graus);

            printf("\t%.2f Graus Kelvin  para Celsius: %g\n",graus,result[0]);
            printf("\t%.2f Graus Kelvin  para Fahrenheit: %g\n",graus,result[1]);


            break;

        default:
            printf("\t Opção Inválida\n");

        }

        if(endGame() == 0) break;
        system("cls");

    }

    return 0;
}

float C_to_F(float g){

    float r = (g * 9/5) + 32; // celsius para Fahrenheit
    return r;


}

float C_to_K(float g){

    float r = g + 273.15;     // celsius para Kelvin
    return r;

}

float F_to_C(float g){

    float r = (g - 32) * 5/9 ;  //Fahrenheit para Celsius
    return r;


}

float F_to_K(float g){

    float r = (g - 32) * 5/9 + 273.15; //Fahrenheit para Kelvin
    return r;

}

float K_to_C(float g){

    float r = g - 273.15;  // Kelvin apra Celsius
    return r;


}

float K_to_F(float g){

    float r = (g - 273.15) * 9/5 + 32; // Kelvin para Fahrenheit
    return r;

}

#endif // ex05

