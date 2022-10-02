#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// teste de arquivos

/* - Escreva um programa que tem 1 vetores bidimensional nome_musica[3][30]
 e 1 vetores bidimensional nome_autor[3][20] declarados como variáveis globais.

Na função main()  faça um menu com as seguintes funções:

   1 – entrada de dados.
   2 – lista todos os dados na tela.
   3 – pesquisa um nome_musica com o nome completo e mostra na tela
   4 – pesquisa o nome_autor pela 1. letra e mostra todos na tela.
   5 – altera dados. Pesquisa pelo nome_musica completo.
   6 – exclui dados. Pesquisa pelo nome_musica completo.
   7 - saída

OBS: Os 2 vetores devem ser escritos e lidos de um arquivo. */

// funcao para loop

/* int endGame() {
    int optionContinue;
    do{
        printf("\nDigite 0 para sair ou 1 para MENU: ");
        scanf("%d", &optionContinue);
    }while(optionContinue != 0 && optionContinue != 1);

    return optionContinue;
} */



//  vetores globais

char nome_musica[3][31], nome_autor[3][21];

FILE *arquivo;

// prototipos das funcoes

void Entry_DATA();
void List();
int Search_Music();
int Search_author();
void update_register();
void Limpa_STR();



int main(){

    setlocale(LC_ALL, "");

    int opcao;


    while(1){

        printf("\t MENU\n\n");
        printf("\t 1 - entrada de dados.\n");
        printf("\t 2 - lista todos os dados na tela.\n");
        printf("\t 3 - pesquisa um nome_musica com o nome completo e mostra na tela\n");
        printf("\t 4 - pesquisa o nome_autor pela 1. letra e mostra todos na tela.\n");
        printf("\t 5 - altera dados. Pesquisa pelo nome_musica completo.\n");
        printf("\t 6 - exclui dados. Pesquisa pelo nome_musica completo.\n");
        printf("\t 7 - Exit\n");

        scanf("%d",&opcao);


        switch (opcao)
        {
            case 1:{
                system("cls");
                getchar();

                Entry_DATA();

                break;

            }
            case 2:{
                system("cls");

                List();

                break;

            }
            case 3:{

                system("cls");
                getchar();

                Search_Music();

                break;

            }
            case 4:{

                system("cls");
                getchar();

                Search_author();



                break;

            }
            case 5:{
                system("cls");
                update_register();
                break;

            }
            case 6:{
                system("cls");
                delete_register();
                break;
            }
            case 7:{
                exit(0);
            }


            default:
            printf("\t Invalid Option");
                break;
        }

        /* if(endGame() == 0) break; */
        printf("\n\n");
        system("pause");
        Limpa_STR();
        system("cls");
    }




    return 0;
}

// funcao de entrada de dados

void Entry_DATA(){


    printf("\t Digite as Musicas e Seus Autores \n");
    printf("\t ================================ \n\n");

    arquivo = fopen("musicas.dat","wb");
        if (arquivo == NULL){

        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(1);
        }


    for(int i = 0; i < 3; i++){


        printf("\t Digite o nome da musica: \n");


         scanf(" %30[^\n]", nome_musica[i]); // leitura da string ate apertar enter
         scanf("%*[^\n]");  // limpeza do buffer do teclado
         fwrite(&nome_musica[i],sizeof(nome_musica[i]),1,arquivo);



         printf("\t Digite o nome do autor: \n\n");

         scanf(" %20[^\n]", nome_autor[i]); // leitura da string ate apertar enter
         scanf("%*[^\n]");  // limpeza do buffer do teclado
         fwrite(&nome_autor[i],sizeof(nome_autor[i]),1,arquivo);



    }

    fclose(arquivo);
}

// funcao listagem de todos os dados

void List()
{

    printf("\t Musicas e Autores \n\n");
    printf("\t ================= \n\n");

    printf("\t leitura do arquivo\n\n");

    arquivo = fopen("musicas.dat", "rb");
    if (arquivo == NULL)
    {

        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {

        fread(nome_musica[i], sizeof(nome_musica[i]), 1, arquivo);

        fread(nome_autor[i], sizeof(nome_autor[i]), 1, arquivo);
    }

    fclose(arquivo);

    for (int i = 0; i < 3; i++)
    {
        if(nome_musica[i][0] != '#')
        printf("\t Musica : %-30s - Autor: %-20s\n", nome_musica[i], nome_autor[i]);
    }
}

// funcao de pesquisar nome de musica

int Search_Music()
{
    printf("\t Pesquisa Musica \n\n");
    printf("\t ================= \n\n");

    char music[31];

    printf("\t Digite o nome da musica por completo:\n");
    scanf(" %30[^\n]", music); // leitura da string ate apertar enter
    getchar();

    system("cls");

    printf("\t\n\n Pesquisando por %s.....:\n", music);
    printf("\t ===================================\n\n");

    // Abertura do arquivo
    arquivo = fopen("musicas.dat", "rb");
    if (arquivo == NULL)
    {

        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(0);
    }

    // leitura do arquivo

    if (arquivo)
    {
        for (int i = 0; i < 3; i++)
        {
            fread(nome_musica[i], sizeof(nome_musica[i]), 1, arquivo);
            fread(nome_autor[i], sizeof(nome_autor[i]), 1, arquivo);
        }
    }
    else
    {
        printf("\t Erro ao Abrir Arquivo");
    }

    fclose(arquivo);

    // pesquisa no vetor

    int i,j;


    for (i = 0; i < 3; i++)
    {
        for (j = 0; music[j] != '\0'; j++)
        {

             if (music[j] != nome_musica[i][j])
            { //  da um break e retorna 1 por serem strings diferentes

                break;
            }

        }

        if (music[j] == '\0' && nome_musica[i][j] == '\0' && nome_musica[i][0] != '#')
            {

                printf("\t Musica(as) encontrada(as): \n\n");
                printf("\t Musica : %-30s - Autor: %-20s\n", nome_musica[i], nome_autor[i]);
                return i;
            }
    }
    printf("\t A musica nao existe\n");
    return -1;

}

// funcao pesquisa autor pela primeira letra

int Search_author(){
    printf("\t Pesquisa Autor \n\n");
    printf("\t ================= \n\n");

    char letra;

    printf("\t Digite a primeira letra:\n");
    letra = getchar();

    system("cls");

    printf("\t\n\n Pesquisando autores começando pela letra: %c ...\n", letra);
    printf("\t ==================================================\n\n");

    // Abertura do arquivo
    arquivo = fopen("musicas.dat", "rb");
    if (arquivo == NULL)
    {

        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(0);
    }

    // leitura do arquivo

    if (arquivo)
    {
        for (int i = 0; i < 3; i++)
        {
            fread(nome_musica[i], sizeof(nome_musica[i]), 1, arquivo);
            fread(nome_autor[i], sizeof(nome_autor[i]), 1, arquivo);
        }
    }
    else
    {
        printf("\t Erro ao Abrir Arquivo");
    }

    fclose(arquivo);

    // pesquisa no vetor

    int k = 0;

    for (int i = 0; i < 3; i++)
    {

       if (letra == nome_autor[i][0] && nome_musica[i][0] != '#')
        {
            printf("\t Autor(es) encontrado(os): \n\n");
            printf("\t Autor: %-20s - Musica: %-30s \n",  nome_autor[i], nome_musica[i]);
            k = 1;

        }

    }

    if(k == 0){
        printf("\t Não Encontrado autor\n");
    }
}


void update_register()
{
    int index = Search_Music();
    if(index < 0) return;

    printf("\t\n Alterar Musica/Autor \n\n");
    printf("\t ====================== \n\n");

    printf("\nDigite o novo nome da musica: ");
    scanf(" %30[^\n]", nome_musica[index]);
    scanf("%*[^\n]");

    printf("\nDigite o novo nome do autor: ");
    scanf(" %30[^\n]", nome_autor[index]);
    getchar();

    printf("\nDeseja realmente alterar para: \n"
    "\n\t Musica : %-30s - Autor: %-20s\n",
    nome_musica[index], nome_autor[index]);

    char confirm;
    while(confirm != 's' && confirm != 'n'){
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if(confirm == 'n') {
        printf("\nAlteracao cancelada!.....\n");
        getchar();
        return;
    }

    arquivo = fopen("musicas.dat","wb");
    if (arquivo == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(1);
    }

    for(int i = 0; i < 3; i++){
         fwrite(&nome_musica[i],sizeof(nome_musica[i]),1,arquivo);
         fwrite(&nome_autor[i],sizeof(nome_autor[i]),1,arquivo);
    }

    fclose(arquivo);

    printf("\nAlteracao realizada com sucesso!.....");
    getchar();
}


void delete_register()
{
    int index = Search_Music();
    if(index < 0) return;

    printf("\t\n Excluir Musica/Autor \n\n");
    printf("\t ====================== \n\n");

    printf("\t\n Musica : %-30s - Autor: %-20s\n",
    nome_musica[index], nome_autor[index]);

    char confirm;
    while(confirm != 's' && confirm != 'n'){
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if(confirm == 'n') {
        printf("\nAlteracao cancelada!.....\n");
        getchar();
        return;
    }

    char strNull = '#';

    nome_musica[index][0] = strNull;
    nome_autor[index][0] = strNull;

    arquivo = fopen("musicas.dat","wb");
    if (arquivo == NULL){
        printf("Problemas na CRIACAO do arquivo\n");
        system("PAUSE");
        exit(1);
    }

    for(int i = 0; i < 3; i++){
         fwrite(&nome_musica[i],sizeof(nome_musica[i]),1,arquivo);
         fwrite(&nome_autor[i],sizeof(nome_autor[i]),1,arquivo);
    }

    fclose(arquivo);

    printf("\n Operacao realizada com sucesso!.....");
    getchar();
}

// limpa o conteudo das matrizes, para somente ter leitura do arquivo como pedido no desafio.

void Limpa_STR() {
    nome_musica[0][0] = '\0';
    nome_autor[0][0] = '\0';
}


