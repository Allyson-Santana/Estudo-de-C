#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex04

//================================================================================
// OBS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex01
/**1 -Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e armazene-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes)
**/

  main()
{

FILE *p;
int cont = 0;
char ch;

printf("Abrindo no modo LEITURA -w-) \n");
if((p = fopen("arq.txt","w"))==NULL)
	{
	printf("\nErro na abertura do arquivo arq.txt\n");
	exit(0);
	}

do
{
    printf("\nDigite um caractere no arquivo: arq.txt: ");
    printf("\nAperte '0' para finalizar\n");
    ch = getchar();
    cont++;
    getchar();
    if(ch == '0')
    {
        printf("\n===========Carecter '0' foi clicado, finalizando entrada de dados...================\n");
        cont--;
        break;
    }
    else
    {
        putc(ch,p);
    }
}while(ch != '0');

fclose(p);

printf("\nAbrindo modo de LEITURA -r- \n");
if((p = fopen("arq.txt","r"))==NULL)
	{
	printf("\nErro na abertura do arquivo arq.txt\n");
	exit(0);
	}

printf("\nImprimindo os caracteres do arq.txt:\n\n");
for (int k = 0; k < cont; k++)
{
    putchar(getc(p));
}
printf("\n\n");
}

#endif //ex01

//===============================================================================

#ifdef ex02
/**2 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, end, cidade, estado, cep numa estrutura
    de dados. A unica estrutura de dados e' uma variavel local na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida*/

typedef struct
{
    char name[20];
    char end[30];
    char city[20];
    char state[20];
    char cep[10];
} client_struct;

#define CHAR_IGNORE '#'

FILE *file_p;
int count_client = 0;

void openfileRead(FILE *file_p, client_struct *client_p, char modo[4])
{

    printf("Abrindo arquivo para leitura\n");

    if ((file_p = fopen("file.dat", modo)) != NULL)
    {
        printf("Arquivo aberto com sucesso\n");
        while (fread(client_p, sizeof(client_struct), 1, file_p) != NULL)
            count_client++;
    }
    else
    {
        printf("Erro na abertura do arquivo ou arquivo nao existente\n");
        printf("Deseja criar um arquivo novo?\n");

        char confirm;
        while (confirm != 's' && confirm != 'n')
        {
            printf("\nSim(s) ou Nao(n)?: ");
            confirm = getchar();
        }
        if (confirm == 'n')
        {
            printf("\n FINALIZANDO PROGRAMA\n");
            exit(0);
        }
        if (confirm == 's')
        {
            printf("\n Criando Arquivo --- \n", (file_p = fopen("file.dat", "wb")));
        }
    }
}

void insert(client_struct *client_p)
{
    printf("\n>>>>>Informe os dados solicidados para o cadastro\n\n");

    printf("=> Nome: ");
    scanf("%20s", &(*client_p).name);
    scanf("%*[^\n]");

    printf("=> Endereco: ");
    scanf("%30s", &(*client_p).end);
    scanf("%*[^\n]");

    printf("=> Cidade: ");
    scanf("%20s", &(*client_p).city);
    scanf("%*[^\n]");

    printf("=> Estado: ");
    scanf("%20s", &(*client_p).state);
    scanf("%*[^\n]");

    printf("=> Cep: ");
    scanf("%10s", &(*client_p).cep);
    scanf("%*[^\n]");

    file_p = fopen("file.dat", "ab");

    if (file_p == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fwrite(client_p, sizeof(client_struct), 1, file_p);
    fclose(file_p);

    printf("\nCadastrado con sucesso!\n");
    getchar();

}

void selectAll()
{
    file_p = fopen("file.dat", "rb");

    if (file_p == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    printf("\n>>>>>Listagem de dados\n");

    client_struct clients, *clients_p;
    clients_p = &clients;

    while (fread(clients_p, sizeof(client_struct), 1, file_p) != NULL)
    {
        if(clients_p->name[0] != CHAR_IGNORE) {
            printf("\n=> Nome: %s", (*clients_p).name);
            printf("\n=> Endereco: %s", (*clients_p).end);
            printf("\n=> Cidade: %s", (*clients_p).city);
            printf("\n=> Estado: %s", (*clients_p).state);
            printf("\n=> Cep: %s", (*clients_p).cep);
            printf("\n");
        }
    }

    printf("\nAperte enter para continua...");

    fclose(file_p);
}

int find(client_struct *client_p)
{
    printf("\n>>>>>Informe um nome para pesquisar\n");

    char name[20];
    int validated = 0;

    file_p = fopen("file.dat", "rb");

    if (file_p == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        return;
    }


    printf("\n=> Informe um nome: ");
    scanf("%20[^\n]", name);
    scanf("%*[^\n]");

    int j, i;

    for (i = 0; fread(client_p, sizeof(client_struct), 1, file_p) != NULL; i++)
    {
        for (j = 0; name[j] != '\0'; j++)
        {
            if (client_p->name[j] != name[j])
            {
                validated = -1;
                break;
            }
        }

        if (client_p->name[j] == '\0' &&
            name[j] == '\0' &&
            client_p->name[j] != CHAR_IGNORE
        ) {
            printf("\n=> Nome: %s", (*client_p).name);
            printf("\n=> Endereco: %s", (*client_p).end);
            printf("\n=> Cidade: %s", (*client_p).city);
            printf("\n=> Estado: %s", (*client_p).state);
            printf("\n=> Cep: %s", (*client_p).cep);
            printf("\n");

            fclose(file_p);
            return i;
        }
    }

    if (validated == -1)
    {
        printf("\nCliente nao encontrado \n");
        return validated;
        getchar();
    }

    fclose(file_p);

}

void update(client_struct *client_p )
{
    int index = find( client_p );
    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }


    printf("\n>>>>>Atualizar registro n°%d \n\n",index);

    printf("Informe os novos dados: \n\n");

    printf("=> Novo Nome: (default -> '%s')", (*client_p).name );
    scanf("%20s", &(*client_p).name);
    scanf("%*[^\n]");

    printf("=> Novo Endereco: (default -> '%s')", (*client_p).end );
    scanf("%30s", &(*client_p).end);
    scanf("%*[^\n]");

    printf("=> Nov Cidade: (default -> '%s')", (*client_p).city );
    scanf("%20s", &(*client_p).city);
    scanf("%*[^\n]");

    printf("=> Novo Estado: (default -> '%s')", (*client_p).state );
    scanf("%20s", &(*client_p).state);
    scanf("%*[^\n]");

    printf("=> Novo Cep: (default -> '%s')", (*client_p).cep );
    scanf("%10s", &(*client_p).cep);
    scanf("%*[^\n]");

    file_p = fopen("file.dat","rb+");

    if(file_p == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( file_p, index*sizeof(client_struct), SEEK_SET );
    fwrite(client_p, sizeof(client_struct), 1, file_p);

    fclose(file_p);

    printf("\nOperação realizada con sucesso!\n");
}

void destroy(client_struct *client_p)
{
    int index = find( client_p );
    if(index == -1) {
        printf("\nAperte enter para continua...");
        getchar();
        return;
    }

    printf("\n>>>>>Excluir registro n°%d \n\n",index);

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

    file_p = fopen("file.dat","rb+");

    if(file_p == NULL) {
        printf("Erro ao abrir o arquivo!");
        return;
    }

    fseek( file_p, index*sizeof(client_struct), SEEK_SET );

    (*client_p).name[0] = CHAR_IGNORE;
    (*client_p).end[0] = CHAR_IGNORE;
    (*client_p).city[0] = CHAR_IGNORE;
    (*client_p).state[0] = CHAR_IGNORE;
    (*client_p).cep[0] = CHAR_IGNORE;

    fwrite(client_p, sizeof(client_struct), 1, file_p);

    fclose(file_p);

    printf("\nOperação realizada con sucesso!\n");

}

int main()
{
    client_struct client, *client_p;
    client_p = &client;


    openfileRead(file_p, client_p, "rb");

    while(1) {
        int option = 0;

        printf("\n=> 1 - inclui registros");
        printf("\n=> 2 - listar todos os registros");
        printf("\n=> 3 - pesquisar registro pelo nome");
        printf("\n=> 4 - altera registro");
        printf("\n=> 5 - exclui registro");
        printf("\n=> 6 - saida");

        printf("\n\n-> Minha Opcao: ");
        scanf("%d", &option);
        getchar();

        switch(option) {
            case 1: {
                insert( client_p );
                getchar();
                system("clear");
                break;
            }
            case 2: {
                selectAll();
                getchar();
                system("clear");
                break;
            }
             case 3: {
                find(client_p);
                printf("\nAperte enter para continua...");
                getchar();getchar();
                system("clear");
                break;
            }

            case 4: {
                update(client_p);
                getchar();
                system("clear");
                break;
            }

            case 5: {
                destroy(client_p);
                getchar();
                system("clear");
                break;
            }

            case 6: {
                printf("\n\n---FIM DO PROGRAMA--- \n");
                exit(0);
                break;
            }
            default: {
                printf("\nOpcao digitada invalida!");
                getchar();
                system("clear");
                break;
            }

        }

    }

    return 0;
}

/* // arquivo
arq = fopen("arquivo.dat", "ab");
fseek(arq, index * sizeof(Agenda), 0);
fwrite((pvet + index), sizeof(Agenda), 1, arq);
fclose(arq); */

#endif // ex02

// ================================================================================

/* 3 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel local na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao e' um funcao)
    1 - inserir contato
    2 - altera contato
    3 - exclui contato
    4 - pesquisar um contato pelo nome
    5 - listar todos os contatos
    6 - listar os contatos cujo nome inicia com uma letra digitada
    7 - imprimir os aniversariantes do mês.
    8 - saida */

#ifdef ex03

// struct da agenda
typedef struct
{
    char nome[31];
    char tel[12];
    char birthday[5];
} Agenda;

// funcoes
void inserirContatos(Agenda *pvet);
void alteraContatos(Agenda *pvet, FILE *arq);
void excluirContatos(Agenda *pvet);
int procurarContatos(Agenda *pvet);
void exibirContatos(Agenda *pvet);
void exibirLetraContatos(Agenda *pvet);
void birthDayContatos(Agenda *pvet);
void openfileRead(FILE *arq, Agenda *pcontato, char modo[4]);
void gravarFile(FILE *arq, Agenda *pcontato, char modo[4]);

int main()
{
    // decalra o vetor struct de 4 elementos
    Agenda contato[4];

    // declara um ponteiro do tipo struct Agenda recebendo o endereço de memoria do vetor struct cadastro
    Agenda *pc = contato;
    FILE *pfile;

    openfileRead(pfile, pc, "rb");

    while (1)
    {

        int option;

        printf("\n\n\t--------------------MENU--------------------\n");
        printf("\tDigite a opcao Desejada\n");
        printf("\t 1 - Inserir Contato:\n");
        printf("\t 2 - Alterar Contato:\n");
        printf("\t 3 - Excluir Contato:\n");
        printf("\t 4 - pesquisar um contato pelo nome:\n");
        printf("\t 5 - listar todos os contatos\n");
        printf("\t 6 - listar os contatos cujo nome inicia com uma letra digitada\n");
        printf("\t 7 - imprimir os aniversariantes do mes.\n");
        printf("\t 8 - Saida\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {
            system("cls");
            inserirContatos(pc);
            printf("\t\nFIM DOS CADASTROS\n");

            break;
        }
        case 2:
        {
            system("cls");
            alteraContatos(pc, pfile);
            printf("\t\nCONTATO ALTERADO\n");

            break;
        }
        case 3:
        {
            system("cls");
            excluirContatos(pc);

            break;
        }
        case 4:
        {
            system("cls");
            procurarContatos(pc);
            break;
        }
        case 5:
        {
            system("cls");
            exibirContatos(pc);
            printf("\t\nFIM DOS CONTATOS CADASTRADOS\n");
            break;
        }
        case 6:
        {
            system("cls");
            exibirLetraContatos(pc);
            printf("\t\nFIM DOS CONTATOS ENCONTRADOS\n");

            break;
        }
        case 7:
        {
            system("cls");
            birthDayContatos(pc);
            break;
        }
        case 8:
        {
            gravarFile(pfile, pc, "wb");

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

// funcoes dos arquivos

void openfileRead(FILE *arq, Agenda *pcontato, char modo[4])
{

    printf("\t Abrindo arquivo para leitura\n");

    if ((arq = fopen("arquivoEx03.dat", modo)) != NULL)
    {
        printf("\t arquivo aberto com sucesso\n");

        for (int i = 0; i < 4; i++)
        {

            fread((pcontato + i), sizeof(Agenda), 1, arq);
        }
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
            printf("\n\t Criando Arquivo --- \n", (arq = fopen("arquivoEx03.dat", "wb")));
        }
    }
}

void gravarFile(FILE *arq, Agenda *pcontato, char modo[4])
{
    arq = fopen("arquivoEx03.dat", modo);

    printf("\n Gravando Agenda no arquivo...\t");

    for (int i = 0; i < 4; i++)
    {

        fwrite((pcontato + i), sizeof(Agenda), 1, arq);
    }

    fclose(arq);
}

// funcoes do programa

void inserirContatos(Agenda *pvet)
{

    printf("\tCADASTRO DOS CONTATOS:\n ");

    for (int i = 0; i < 4; i++)
    {

        printf("\n\t===================\n");
        printf("\t= Contato numero 0%d =\n", i + 1);
        printf("\t===================\n\n");

        printf("\tEntre com o nome ---- ");
        scanf("%30[^\n]", pvet[i].nome); // leitura da string limitado ate 30 caracteres ate apertar enter
        scanf("%*[^\n]");                // limpeza do buffer do teclado

        printf("\n\tEntre com o Telefone: DDD + Numero ex. 11981243232 ---- ");
        scanf(" %11[^\n]", pvet[i].tel);
        scanf("%*[^\n]");

        printf("\tEntre com a data de aniversario: Dia + Mes ex. 2508 para 25/08 ---- ");
        scanf(" %4[^\n]", pvet[i].birthday);
        getchar();
    }
}

void alteraContatos(Agenda *pvet, FILE *arq)
{
    int index = procurarContatos(pvet);
    if (index < 0)
        return;

    printf("\t\n Deseja realmente ALTERAR esse Contato? \n\n");

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
    printf("\t\n ALTERAR CONTATOS: \n\n");
    printf("\t ====================== \n\n");

    printf("\tEntre com o nome: ");
    scanf(" %30[^\n]", pvet[index].nome); // leitura da string limitado ate 20 caracteres ate apertar enter
    scanf("%*[^\n]");                     // limpeza do buffer do teclado

    printf("\n\tEntre com o Telefone: DDD + Numero ex. 11981243232 ---- ");
    scanf(" %11[^\n]", pvet[index].tel);
    scanf("%*[^\n]");

    printf("\tEntre com a data de aniversario: Dia + Mes ex. 2508 para 25/08 ---- ");
    scanf(" %4[^\n]", pvet[index].birthday);
    scanf("%*[^\n]");

    printf("\nCONTATO ALTERADO PARA:\n");
    printf("\tNome: %s \n", (pvet + index)->nome);
    printf("\tTelefone: %s \n", (pvet + index)->tel);
    printf("\tData de Aniversario: %c%c/%c%c \n", (pvet + index)->birthday[0], (pvet + index)->birthday[1], (pvet + index)->birthday[2], (pvet + index)->birthday[3]);
}

void excluirContatos(Agenda *pvet)
{
    int index = procurarContatos(pvet);
    if (index < 0)
        return;

    printf("\t\n Deseja realmente EXCLUIR esses Contatos? \n\n");

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

    (pvet + index)->nome[0] = strNull;

    printf("\n Operacao realizada com sucesso!.....\n");
    getchar();
}

int procurarContatos(Agenda *pvet)
{
    char findName[31];
    printf("\t Pesquisa por NOME: \n");
    printf("\t ================= \n\n");
    printf("\t Digite um nome completo para pesquisar:\n");
    scanf(" %30[^\n]", findName);
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

            if (findName[i] != (pvet + j)->nome[i])
            {
                k = -1;
                break;
            }
        }

        if ((pvet + j)->nome[i] == '\0' && findName[i] == '\0' && (pvet + j)->nome[0] != '#')
        {

            printf("\t CONTATOS ENCONTRADOS PELO NOME: \n\n");
            printf("\tNome: %s \n", (pvet + j)->nome);
            printf("\tTelefone: %s \n", (pvet + j)->tel);
            printf("\tData de Aniversario: %c%c/%c%c \n", (pvet + j)->birthday[0], (pvet + j)->birthday[1], (pvet + j)->birthday[2], (pvet + j)->birthday[3]);

            return j;
        }
    }

    if (k == -1)
    {
        printf("\t\n Nome nao encontado:\n");
        return -1;
    }
}

void exibirContatos(Agenda *pvet)
{

    printf("\t\n EXIBINDO CONTATOS CADASTRADOS:\n");
    printf("\t\n===========================\n\n");
    for (int i = 0; i < 4; i++)
    {
        if ((pvet + i)->nome[0] != '#')
        {

            printf("\n\t===================\n");
            printf("\t= Cadastro numero 0%d =\n", i + 1);
            printf("\t===================\n\n");

            printf("\tNome: %s \n", (pvet + i)->nome);
            printf("\tTelefone: %s \n", (pvet + i)->tel);
            printf("\tData de Aniversario: %c%c/%c%c \n", (pvet + i)->birthday[0], (pvet + i)->birthday[1], (pvet + i)->birthday[2], (pvet + i)->birthday[3]);
        }
        else
        {
            printf("\t\n\n NAO EXISTE CONTATOS CADASTRADOS:\n");
        }
    }
}

void exibirLetraContatos(Agenda *pvet)
{
    system("cls");
    char letra;
    printf("\t Digite uma letra para Pesquisa dos contatos: ");
    letra = getchar();

    int i, k;
    system("cls");
    for (i = 0; i < 4; i++)
    {
        if ((pvet + i)->nome[0] == letra)
        {
            printf("\n\tLISTANDO CONTATO COM NOME INICIANDO EM --> %c \n", letra);
            printf("\tNome: %s \n", (pvet + i)->nome);
            printf("\tTelefone: %s \n", (pvet + i)->tel);
            printf("\tData de Aniversario: %c%c/%c%c \n", (pvet + i)->birthday[0], (pvet + i)->birthday[1], (pvet + i)->birthday[2], (pvet + i)->birthday[3]);

            k = 1;
        }
    }

    if (k != 1)
    {
        system("cls");
        printf("\t\n NAO Encontrado Contatos com nomes iniciando com a letra --> %c \n", letra);
    }
}

void birthDayContatos(Agenda *pvet)
{

    char mes[3];
    printf("\t Digite os dois digitos do MES para listar os aniversariantes: ");
    scanf("%s", mes);

    int i, k;
    system("cls");
    for (i = 0; i < 4; i++)
    {
        if ((pvet + i)->birthday[2] == mes[0] && (pvet + i)->birthday[3] == mes[1] && (pvet + i)->nome[0] != '#')
        {

            printf("\n\tANIVERSARIANTE DO MES --:\n");
            printf("\t===============================\n");
            printf("\tNome: %s \n", (pvet + i)->nome);
            printf("\tTelefone: %s \n", (pvet + i)->tel);
            printf("\tData de Aniversario: %c%c/%c%c \n", (pvet + i)->birthday[0], (pvet + i)->birthday[1], (pvet + i)->birthday[2], (pvet + i)->birthday[3]);

            k = 1;
        }
    }

    if (k != 1)
    {
        system("cls");
        printf("\t\n NAO Encontrado Aniversariantes para este mes --> %s\n", mes);
    }
}

#endif // ex03

// ================================================================================

/* 4 - Escreva um programa para o controle de mercadorias em uma despensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel local na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). Nao pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao e' um funcao)
    1 - inclui produtos
    2 - altera produtos
    3 - exclui produtos
    4 - pesquisar uma mercadoria pela descrição
    5 - listar todos os produtos
    6 - listar os produtos não disponíveis.
    7 - alterar a quantidade atual
    8 - saida */

#ifdef ex04

typedef struct
{
    int codigo;
    char produto[21];
    int quantidade;
} Despensa;

// funcoes
void incluirProdutos(Despensa *pdesp, FILE *arq);
void alteraProduto(Despensa *pdesp, FILE *arq);
void excluirProduto(Despensa *pdesp, FILE *arq);
int pesquisaMercadoria(Despensa *pdesp, FILE *arq);
void listarProdutos(Despensa *pdesp, FILE *arq);
void listarIndisponiveis(Despensa *pdesp, FILE *arq);
void alteraQuantity(Despensa *pdesp, FILE *arq);
void openfileRead(FILE *arq, Despensa *pdesp, char modo[4]);

int main()
{
    Despensa mercadorias;
    Despensa *pd = &mercadorias;
    FILE *pfile;

    openfileRead(pfile, pd, "rb");

    while (1)
    {

        int option;

        printf("\n\n\t--------------------MENU--------------------\n");
        printf("\tDigite a opcao Desejada\n");
        printf("\t 1 - Inserir Produto\n");
        printf("\t 2 - Alterar Produto\n");
        printf("\t 3 - Excluir Produto\n");
        printf("\t 4 - pesquisar uma mercadoria pela descrica\n");
        printf("\t 5 - listar todos os Produto\n");
        printf("\t 6 - listar os Produto nao disponiveis\n");
        printf("\t 7 - Alterar a quantidade atual.\n");
        printf("\t 8 - Saida\n");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
        {
            system("cls");
            incluirProdutos(pd, pfile);

            break;
        }
        case 2:
        {
            system("cls");
            alteraProduto(pd, pfile);
            break;
        }
        case 3:
        {
            system("cls");
            excluirProduto(pd, pfile);
            break;
        }
        case 4:
        {
            system("cls");
            pesquisaMercadoria(pd, pfile);

            break;
        }
        case 5:
        {
            system("cls");
            listarProdutos(pd, pfile);

            break;
        }
        case 6:
        {
            system("cls");
            listarIndisponiveis(pd, pfile);

            break;
        }
        case 7:
        {
            system("cls");
            alteraQuantity(pd, pfile);
            break;
        }
        case 8:
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

// funcoes do programa

void incluirProdutos(Despensa *pdesp, FILE *arq)
{
    char confirm;

    printf("\tCADASTRO DOS PRODUTOS DA DESPENSA:\n ");

    while (1)
    {

        if (pdesp->codigo >= 1)
        {
            pdesp->codigo += 1;
        }
        else
        {
            pdesp->codigo = 1;
        }

        printf("\n\t===================\n");
        printf("\t= Produto --> %d =\n", pdesp->codigo);
        printf("\t===================\n\n");

        printf("\tEntre com o nome do produto ---- ");
        scanf(" %20[^\n]", pdesp->produto); // leitura da string limitado ate 20 caracteres ate apertar enter
        getchar();

        printf("\n\tInsira a quantidade atual do produto ---- ");
        scanf("%d", &(*pdesp).quantidade);
        getchar();

        printf("\n\t-------PRODUTO CADASTRADO------- \n\n");
        printf("\t Produto codigo ---> %d \n", pdesp->codigo);
        printf("\t Nome ---> %s \n", pdesp->produto);
        printf("\t Quatidade ---> %d \n\n", pdesp->quantidade);

        // arquivo
        arq = fopen("arquivoEx04.dat", "ab");
        if (arq == NULL)
        {
            printf("Erro ao abrir o arquivo!");
            system("pause");
        }
        fwrite(pdesp, sizeof(Despensa), 1, arq);
        fclose(arq);

        // confirmar continuar cadastro
        //int k;
        printf("\t\n Deseja inserir outro produto? \n");
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
                printf("\t\n Novo Produto... \n");
                break;
            }
        }
    }
}

void alteraProduto(Despensa *pdesp, FILE *arq)
{
    int index = pesquisaMercadoria(pdesp, arq) - 1;
    if (index < 0)
        return;

    printf("\t\n Deseja realmente ALTERAR esse Produto? \n\n");

    char confirm;
    while (confirm != 's' && confirm != 'n')
    {
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if (confirm == 'n')
    {
        printf("\nALTERACAO CANCELADA!.....\n");
        getchar();
        return;
    }

    system("cls");
    printf("\t\n ALTERAR PRODUTO: \n\n");
    printf("\t ====================== \n\n");

    arq = fopen("arquivoEx04.dat", "rb+");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        system("pause");
    }

    printf("\t=======================\n");
    printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
    printf("\t=======================\n\n");

    printf("\tEntre com o nome do produto ---- ");
    scanf(" %20[^\n]", pdesp->produto); // leitura da string limitado ate 20 caracteres ate apertar enter
    getchar();

    printf("\n\tInsira a quantidade atual do produto ---- ");
    scanf("%d", &(*pdesp).quantidade);
    getchar();

    system("cls");

    // FSEEK - deslocando o index a partir do inicio do arquivo
    fseek(arq, index * sizeof(Despensa), 0);

    // gravando alteracao no arquivo
    fwrite(pdesp, sizeof(Despensa), 1, arq);
    fclose(arq);

    printf("\nCONTATO ALTERADO PARA:\n");
    printf("\t=======================\n");
    printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
    printf("\t=======================\n\n");

    printf("\t Nome ---> %s \n", pdesp->produto);
    printf("\t Quatidade ---> %d \n\n", pdesp->quantidade);
}

void excluirProduto(Despensa *pdesp, FILE *arq)
{

    int index = pesquisaMercadoria(pdesp, arq) - 1;
    if (index < 0)
        return;

    printf("\t\n Deseja realmente EXCLUIR esse Produto? \n\n");

    char confirm;
    while (confirm != 's' && confirm != 'n')
    {
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if (confirm == 'n')
    {
        printf("\nALTERACAO CANCELADA!.....\n");
        getchar();
        return;
    }

    arq = fopen("arquivoEx04.dat", "rb+");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        system("pause");
    }

    // excluindo...    
    pdesp->produto[0] = '#';
    pdesp->quantidade = 0;

    // FSEEK - deslocando o index a partir do inicio do arquivo
    fseek(arq, index * sizeof(Despensa), 0);

    // gravando alteracao no arquivo
    fwrite(pdesp, sizeof(Despensa), 1, arq);
    fclose(arq);

    printf("\n Operacao realizada com sucesso!.....\n");
    getchar();
}
int pesquisaMercadoria(Despensa *pdesp, FILE *arq)
{

    char findName[21];
    printf("\t Pesquisa por NOME: \n");
    printf("\t ================= \n\n");
    printf("\t Digite o nome completo do produto:\n");
    scanf("%20[^\n]", findName);
    getchar();

    system("cls");
    printf("\t\n\n Pesquisando por %s...:\n", findName);
    printf("\t ===================================\n\n");

    // pesquisa

    arq = fopen("arquivoEx04.dat", "rb");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
    }

    int i, j, k;
    for (int i = 0; (fread(pdesp, sizeof(Despensa), 1, arq)) != NULL; i++)
    {
        // printf("strcut n - %d\n",i+1);

        for (j = 0; findName[j] != '\0'; j++)
        {
            // printf("\tnome - %c produto - %c\n",findName[j], pdesp->produto[j]);
            if (findName[j] != pdesp->produto[j])
            {
                k = -1;
                break;
            }
        }

        if (pdesp->produto[j] == '\0' && findName[j] == '\0' && pdesp->produto[0] != '#')
        {

            printf("\t PRODUTOS ENCONTRADOS PELO NOME: \n\n");
            printf("\t=======================\n");
            printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
            printf("\t=======================\n\n");

            printf("\t Nome ---> %s \n", pdesp->produto);
            printf("\t Quatidade ---> %d \n\n", pdesp->quantidade);
            return pdesp->codigo;
        }
    }

    fclose(arq);

    if (k == -1)
    {
        printf("\t\n Nome de produto nao encontado:\n");
        return -1;
    }
}

void listarProdutos(Despensa *pdesp, FILE *arq)
{

    arq = fopen("arquivoEx04.dat", "rb");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        printf("\t\n\n NAO EXISTE PRODUTOS CADASTRADOS:\n");
    }
    else
    {

        printf("\t\n EXIBINDO PRODUTOS CADASTRADOS:\n");
        printf("\t\n===========================\n\n");

        for (int i = 0; (fread(pdesp, sizeof(Despensa), 1, arq)) != NULL; i++)
        {
            if (pdesp->produto[0] != '#')
            {
                printf("\t=======================\n");
                printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
                printf("\t=======================\n\n");

                printf("\t Nome ---> %s \n", pdesp->produto);
                printf("\t Quatidade ---> %d \n\n", pdesp->quantidade);
            }
        }
    }
}

void listarIndisponiveis(Despensa *pdesp, FILE *arq)
{
    arq = fopen("arquivoEx04.dat", "rb");
    int i, k = 0 ;
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        printf("\t\n\n NAO EXISTE PRODUTOS CADASTRADOS:\n");
    }
    else
    {

        printf("\t\n EXIBINDO PRODUTOS INDISPONIVEIS:\n");
        printf("\t\n===========================\n\n");

        for (i = 0; (fread(pdesp, sizeof(Despensa), 1, arq)) != NULL; i++)
        {
            if (pdesp->produto[0] != '#' && pdesp->quantidade <= 0)
            {
                printf("\t=======================\n");
                printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
                printf("\t=======================\n\n");

                printf("\t Nome ---> %s \n", pdesp->produto);
                printf("\t Quantidade ---> %d \n\n", pdesp->quantidade);
                k = 1;
            }

        }
    }
    if(k != 1){

        printf("\t NAO ENCONTRADO PRODUTOS INDISPONIVEIS\n\n");
    }
}

void alteraQuantity(Despensa *pdesp, FILE *arq)
{

    int index = pesquisaMercadoria(pdesp, arq) - 1;
    if (index < 0)
        return;

    printf("\t\n Deseja ALTERAR a QUANTIDADE desse Produto? \n\n");

    char confirm;
    while (confirm != 's' && confirm != 'n')
    {
        printf("\nSim(s) ou Nao(n)?: ");
        confirm = getchar();
    }

    if (confirm == 'n')
    {
        printf("\nALTERACAO CANCELADA!.....\n");
        getchar();
        return;
    }

    system("cls");
    printf("\t\n ALTERAR QUANTIDADE DO PRODUTO: \n\n");
    printf("\t ================================== \n\n");

    arq = fopen("arquivoEx04.dat", "rb+");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!");
        system("pause");
    }

    printf("\t=======================\n");
    printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
    printf("\t=======================\n\n");

    printf("\n\tInsira a quantidade atual do produto ---- ");
    scanf("%d", &(*pdesp).quantidade);
    getchar();

    system("cls");

    // FSEEK - deslocando o index a partir do inicio do arquivo
    fseek(arq, index * sizeof(Despensa), 0);

    // gravando alteracao no arquivo
    fwrite(pdesp, sizeof(Despensa), 1, arq);
    fclose(arq);

    printf("\nQUANTIDADE ALTERADA:\n");
    printf("\t=======================\n");
    printf("\t= Produto Codigo 00%d  =\n", pdesp->codigo);
    printf("\t=======================\n\n");

    printf("\t Nome ---> %s \n", pdesp->produto);
    printf("\t Quatidade ---> %d \n\n", pdesp->quantidade);
}

// funcoes de arquivos

void openfileRead(FILE *arq, Despensa *pdesp, char modo[4])
{

    printf("\t Abrindo arquivo para leitura\n");

    if ((arq = fopen("arquivoEx04.dat", modo)) != NULL)
    {
        printf("\t arquivo aberto com sucesso\n");

        while (!feof(arq)) // While enquanto nao for o FIM DO ARQUIVO
        {

            fread(pdesp, sizeof(Despensa), 1, arq);
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
            printf("\n\t Criando Arquivo --- \n", (arq = fopen("arquivoEx04.dat", "wb")));
        }
    }
}

#endif // ex04
