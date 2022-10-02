#include <stdio.h>
#include <stdlib.h>

/* PROGRAMA DESAFIO 2

1 - Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:

   1 – Entra dados da música.
   2 – Lista todas as músicas na tela.
   3 – Pesquisar um registro pela música completa.
   4 – Pesquisar pelo autor completo.
   5 – Pesquisar música por faixa de preço.
   6 – Altera quantidade (entrada e saída) pesquisado pela música completa.
   7 – Altera preço de uma música pesquisado pela música completa.
   8 – Altera dados, pesquisado pela música completa.
   9 – Exclui dados, pesquisado pela música completa.
   10 – Saída pelo usuário

Estrutura: música, autor, preço, quantidade

A única estrutura de dados do programa deve ser uma variável local na função main(). Portanto a passagem da estrutura para as funções utiliza ponteiro.

Cada uma das opções do menu é uma função no programa.

Todas as operações de leitura e escrita devem ser feitas direto no arquivo. (utilize a função fseek quando necessário).

O programa tem um único arquivo de dados. Não pode usar nenhum arquivo auxiliar.

Não pode usar nenhuma função de biblioteca. Somente as funções de manipulação de arquivos. */


typedef struct
{
   char music[21];
   char autor[21];
   float price;
   int quantity;
} Musica_Struct;

//prototipo das funcoes do programa
void openfileRead(FILE *arq, Musica_Struct *pmusic, char modo[4]);
void incluirMusica(Musica_Struct *pmusic, FILE *arq);
void listarMusicas(Musica_Struct *pmusic, FILE *arq);
int pesquisaMusica(Musica_Struct *pmusic, FILE *arq);
void pesquisaAutor(Musica_Struct *pmusic, FILE *arq);
void alterarTodosDados(Musica_Struct *pmusic, FILE *arq);
void alteraPreco(Musica_Struct *pmusic, FILE *arq);
void pesquisaFaixaPreco(Musica_Struct *pmusic, FILE *arq);
void alteraQuantidade(Musica_Struct *pmusic, FILE *arq);






int main()
{
   Musica_Struct music;
   Musica_Struct *pm = &music;
   FILE *pfile;

   //openfileRead(pfile, pm, "rb");

   while (1)
    {

        int option;

        printf("\n\n\t--------------------MENU--------------------\n");
        printf("\tDigite a opcao Desejada\n");
        printf("\t 1 - Inserir Dados de Musicas\n");
        printf("\t 2 - Lista todas as musicas na tela.\n");
        printf("\t 3 - Pesquisar um registro pela musica completa.\n");
        printf("\t 4 - Pesquisar pelo autor.\n");
        printf("\t 5 - Pesquisar musica por faixa de preco.\n");
        printf("\t 6 - Altera quantidade (entrada e saida).\n");
        printf("\t 7 - Altera preco.\n");
        printf("\t 8 - Altera dados.\n");
        printf("\t 9 - Exclui dados.\n");
        printf("\t 10 - Saida\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {
            system("cls");
            incluirMusica(pm, pfile);

            break;
        }
        case 2:
        {
            system("cls");
            listarMusicas(pm, pfile);
            break;
        }
        case 3:
        {
            system("cls");
            pesquisaMusica(pm, pfile);
            break;
        }
        case 4:
        {
            system("cls");
            pesquisaAutor(pm, pfile);

            break;
        }
        case 5:
        {
            system("cls");
            pesquisaFaixaPreco(pm, pfile);
            break;
        }
        case 6:
        {
            system("cls");
            alteraQuantidade(pm,pfile);
            break;
        }
        case 7:
        {
            system("cls");
            alteraPreco(pm, pfile);
            break;
        }
        case 8:
        {
            system("cls");
            alterarTodosDados(pm, pfile);
            break;
        }
        case 9:
        {
            deletar(pm, pfile);
            break;
        }
        case 10:
        {
            printf("\t\n---FIM DO PROGRAMA--- \n");
            exit(0);
            break;
        }
        default:
        {
            printf("\tOpcao digitada invalida \n");
            break;
        }
        }
    }

   return 0;
}

// funcoes
void openfileRead(FILE *arq, Musica_Struct *pmusic, char modo[4])
{

    printf("\t Abrindo arquivo para leitura\n");

    if ((arq = fopen("arquivo_desafioP2.dat", modo)) != NULL)
    {
        printf("\t arquivo aberto com sucesso\n");

        while (!feof(arq)) // While enquanto nao for o FIM DO ARQUIVO
        {

            fread(pmusic, sizeof(Musica_Struct), 1, arq);
        }
        fclose(arq);
    }
    else
    {
        printf("\t Erro na abertura do arquivo ou arquivo nao existente\n");
        printf("\t Deseja criar um arquivo novo?\n");

        char confirm;
        while (confirm != 's' && confirm != 'n')
        {
            printf("\nSim(s) ou Nao(n)?: ");
            confirm = getchar();
        }

        if (confirm == 'n')
        {

            printf("\n\t FINALIZANDO PROGRAMA\n");
            exit(0);
        }
        if (confirm == 's')
        {
            printf("\n\t Criando Arquivo --- \n", (arq = fopen("arquivo_desafioP2.dat", "wb")));
            system("pause");
            system("cls");
        }
    }
}

void alteraQuantidade(Musica_Struct *pmusic, FILE *arq)
{
    int index = pesquisaMusica( pmusic, arq );
    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }

    printf("\n>>>>>Atualizar quantidade da musica n.%d \n\n", index);

   int current, count;

   do {
    current = ((*pmusic).quantity);
    count = 0;

    printf("\tOBS: O valor inserido não pode resulta em quantidade negativa!\n\n ");
    printf("\tEntre com o incremento ou descremento: ");
    scanf("%d", &count);
    getchar();

   } while( (current += count) < 0);

    (*pmusic).quantity += count;

    arq = fopen("arquivo_desafioP2.dat","rb+");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( arq, index*sizeof(Musica_Struct), SEEK_SET );
    fwrite(pmusic, sizeof(Musica_Struct), 1, arq);

    fclose(arq);

    printf("\nOperacao realizada con sucesso!\n");
    getchar();
    system("cls");
}

void deletar(Musica_Struct *pmusic, FILE *arq)
{
    int index = pesquisaMusica( pmusic, arq );

    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }

    printf("\n>>>>>Excluir registro n.%d \n\n",index);

    char confirm;
    while (confirm != 's' && confirm != 'n') {
        printf("\nConfirmara exclusao Sim(s) ou Nao(n)?: ");
        confirm = getchar();
    }
    if (confirm == 'n') {
        printf("\n\nOperaçõa cancelada....\n");
        getchar();
        return;
    };

    arq = fopen("arquivo_desafioP2.dat","rb+");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( arq, index*sizeof(Musica_Struct), SEEK_SET );

    (*pmusic).music[0] = '#';
    (*pmusic).autor[0] = '#';
    (*pmusic).price = 0;
    (*pmusic).quantity = 0;

    fwrite(pmusic, sizeof(Musica_Struct), 1, arq);

    fclose(arq);

    printf("\nOperacao realizada con sucesso!\n");
    getchar();
    system("cls");
}

void alterarTodosDados(Musica_Struct *pmusic, FILE *arq)
{
    int index = pesquisaMusica( pmusic, arq );
    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }

    printf("\n>>>>>Atualizar Registro n°%d \n\n", index);

    printf("\tEntre com o nome da musica ---- ");
    scanf("%20[^\n]", pmusic->music); // leitura da string limitado ate 20 caracteres ate apertar enter
    scanf("%*[^\n]");

    printf("\tEntre com o autor da musica ---- ");
    scanf(" %20[^\n]", pmusic->autor); // leitura da string limitado ate 20 caracteres ate apertar enter
    getchar();

    printf("\tEntre com o valor da musica ---- ");
    scanf("%f", &(*pmusic).price);
    getchar();

    printf("\tEntre com a quantidade da musica ---- ");
    scanf("%d", &(*pmusic).quantity);
    getchar();

    printf("\n\t-------NOVOS DADOS DO RESGITRO------- \n\n");
    printf("\t Nome da musica ---> %s \n", pmusic->music);
    printf("\t Autor da musica ---> %s \n", pmusic->autor);
    printf("\t Preco da musica ---> %.2f \n", pmusic->price);
    printf("\t Quantidade da musica ---> %d \n", pmusic->quantity);

    arq = fopen("arquivo_desafioP2.dat","rb+");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( arq, index*sizeof(Musica_Struct), SEEK_SET );
    fwrite(pmusic, sizeof(Musica_Struct), 1, arq);

    fclose(arq);

    printf("\nOperação realizada con sucesso!\n");
    getchar();
    system("cls");
}

void alteraPreco(Musica_Struct *pmusic, FILE *arq)
{
    int index = pesquisaMusica( pmusic, arq );
    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }

    printf("\n>>>>>Atualizar preco da musica n.%d \n\n", index);

    printf("\tEntre com o valor da musica ---- ");
    scanf("%f", &(*pmusic).price);
    getchar();

    arq = fopen("arquivo_desafioP2.dat","rb+");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( arq, index*sizeof(Musica_Struct), SEEK_SET );
    fwrite(pmusic, sizeof(Musica_Struct), 1, arq);

    fclose(arq);

    printf("\nOperacao realizada con sucesso!\n");
    getchar();
    system("cls");
}

void pesquisaFaixaPreco(Musica_Struct *pmusic, FILE *arq)
{
    printf("\t----------------------------------\n");
    printf("\t- Pesquisar por faixa de valores -\n");
    printf("\t----------------------------------\n");

    float minino, maximo;

    printf("\nValor de faixa minima: ");
    scanf("%f", &minino);

    printf("\nValor de faixa maxima: ");
    scanf("%f", &maximo);

    arq = fopen("arquivo_desafioP2.dat", "rb");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!");
        printf("\t\n\n NAO EXISTE MUSICAS CADASTRADAS:\n");
    }
    else {
        printf("\t\n EXIBINDO LISTA DE MUSICAS:\n");
        printf("\t\n===========================\n\n");

        for (int i = 0; (fread(pmusic, sizeof(Musica_Struct), 1, arq)) != NULL; i++) {
            if (pmusic->music[0] != '#' && pmusic->price >= minino && pmusic->price <= maximo) {
                printf("\n\t===================\n");
                printf("\t= Musica --> 00%d =\n", i+1);
                printf("\t===================\n\n");

                printf("\t Nome da musica ---> %s \n", pmusic->music);
                printf("\t Autor da musica ---> %s \n", pmusic->autor);
                printf("\t Preco da musica ---> %.2f \n", pmusic->price);
                printf("\t Quantidade da musica ---> %d \n\n", pmusic->quantity);
            }
        }

        getchar();

    }

}

void incluirMusica(Musica_Struct *pmusic, FILE *arq)
{
   char confirm;

   printf("\t-----------------------\n ");
   printf("\t- CADASTRO DE MUSICAS -\n ");
   printf("\t-----------------------\n\n ");

   int i;
   while(1)
   {

      printf("\tEntre com o nome da musica ---- ");
      scanf("%20[^\n]", pmusic->music); // leitura da string limitado ate 20 caracteres ate apertar enter
      scanf("%*[^\n]");

      printf("\tEntre com o autor da musica ---- ");
      scanf(" %20[^\n]", pmusic->autor); // leitura da string limitado ate 20 caracteres ate apertar enter
      getchar();

      printf("\tEntre com o valor da musica ---- ");
      scanf("%f", &(*pmusic).price);
      getchar();

      printf("\tEntre com a quantidade da musica ---- ");
      scanf("%d", &(*pmusic).quantity);
      getchar();

      printf("\n\t-------MUSICA CADASTRADA------- \n\n");
      printf("\t Nome da musica ---> %s \n", pmusic->music);
      printf("\t Autor da musica ---> %s \n", pmusic->autor);
      printf("\t Preco da musica ---> %.2f \n", pmusic->price);
      printf("\t Quantidade da musica ---> %d \n", pmusic->quantity);


      // arquivo
      arq = fopen("arquivo_desafioP2.dat", "ab");
      if (arq == NULL)
      {
         printf("Erro ao abrir o arquivo!");
         system("pause");
      }
      fwrite(pmusic, sizeof(Musica_Struct), 1, arq);
      fclose(arq);

      // confirmar continuar cadastro

      printf("\t\n Deseja inserir outra musica? \n");

      while (confirm != 'n' || confirm != 's')
      {
          printf("\nSim(s) ou Nao(n)?: ");
          confirm = getchar();
          getchar();

         if (confirm == 'n')
         {
            printf("\t\n CADASTRO FINALIZADO \n");
            return;
         }
         else if (confirm == 's')
         {
            printf("\t\n Nova Musica... \n");
            getchar();
            break;
         }
      }

   }
}

void listarMusicas(Musica_Struct *pmusic, FILE *arq){

    arq = fopen("arquivo_desafioP2.dat", "rb");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        printf("\t\n\n NAO EXISTE MUSICAS CADASTRADAS:\n");
    }
    else
    {

        printf("\t\n EXIBINDO LISTA DE MUSICAS:\n");
        printf("\t\n===========================\n\n");

        for (int i = 0; (fread(pmusic, sizeof(Musica_Struct), 1, arq)) != NULL; i++)
        {
            if (pmusic->music[0] != '#')
            {
                printf("\n\t===================\n");
                printf("\t= Musica --> 00%d =\n", i+1);
                printf("\t===================\n\n");

                printf("\t Nome da musica ---> %s \n", pmusic->music);
                printf("\t Autor da musica ---> %s \n", pmusic->autor);
                printf("\t Preco da musica ---> %.2f \n", pmusic->price);
                printf("\t Quantidade da musica ---> %d \n\n", pmusic->quantity);
            }
        }
    }
}

int pesquisaMusica(Musica_Struct *pmusic, FILE *arq)
{

    char findName[21];
    printf("\t Pesquisa por NOME: \n");
    printf("\t ================= \n\n");
    printf("\t Digite o nome completo da Musica:\n");
    scanf("%20[^\n]", findName);
    getchar();

    system("cls");
    printf("\t\n\n Pesquisando por %s...:\n", findName);
    printf("\t ===================================\n\n");

    // pesquisa

    arq = fopen("arquivo_desafioP2.dat", "rb");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
    }

    int i, j, k;
    for (int i = 0; (fread(pmusic, sizeof(Musica_Struct), 1, arq)) != NULL; i++)
    {

        for (j = 0; findName[j] != '\0'; j++)
        {

            if (findName[j] != pmusic->music[j])
            {
                k = -1;
                break;
            }
        }

        if (pmusic->music[j] == '\0' && findName[j] == '\0' && pmusic->music[j] != '#')
        {

            printf("\t MUSICAS ENCONTRADAS PELO NOME: \n\n");

            printf("\n\t===================\n");
            printf("\t= Musica --> 00%d =\n", i+1);
            printf("\t===================\n\n");

            printf("\t Nome da musica ---> %s \n", pmusic->music);
            printf("\t Autor da musica ---> %s \n", pmusic->autor);
            printf("\t Preco da musica ---> %.2f \n", pmusic->price);
            printf("\t Quantidade da musica ---> %d \n\n", pmusic->quantity);
            return i;
        }
    }

    fclose(arq);

    if (k == -1)
    {
        printf("\t\n Musica nao encontada:\n");
        return -1;
    }
}

void pesquisaAutor(Musica_Struct *pmusic, FILE *arq){

    char findName[21];
    printf("\t Pesquisa por AUTOR: \n");
    printf("\t ================= \n\n");
    printf("\t Digite o nome completo do Autor:\n");
    scanf("%20[^\n]", findName);
    getchar();

    system("cls");
    printf("\t\n\n Pesquisando pelo autor %s...:\n", findName);
    printf("\t ===================================\n\n");

    //Pesquisa
    arq = fopen("arquivo_desafioP2.dat", "rb");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
    }

    int i = 0, j, k,y = 0;

    while(fread(pmusic, sizeof(Musica_Struct), 1, arq))
    {


        for (j = 0; findName[j] != '\0'; j++)
        {

            //printf("\tnome - %c Pautor - %c\n",findName[j], pmusic->autor[j]);
            if (findName[j] != pmusic->autor[j])
            {
                k = -1;
                break;
            }
        }

        if (pmusic->autor[j] == '\0' && findName[j] == '\0' && pmusic->music[j] != '#')
        {

            printf("\t AUTOR(ES) ENCONTRADO(S) PELO NOME: \n\n");

            printf("\n\t===================\n");
            printf("\t= Musica --> 00%d =\n", i+1);
            printf("\t===================\n\n");

            printf("\t Nome da musica ---> %s \n", pmusic->music);
            printf("\t Autor da musica ---> %s \n", pmusic->autor);
            printf("\t Preco da musica ---> %.2f \n", pmusic->price);
            printf("\t Quantidade da musica ---> %d \n\n", pmusic->quantity);
            i++;
            y = 1; // para nao imprimir o texto de nenhum autor encontrado

        }
    }

    fclose(arq);

    if (k == -1 && y != 1 ) //se nao encontrar nenhuma musica com o nome do autor
    {
        printf("\t\n Autor nao encontado:\n");

    }


}
