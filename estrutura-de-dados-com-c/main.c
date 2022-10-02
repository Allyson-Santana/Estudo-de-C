#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex09

#ifdef ex03
/** Exercício 3 - Ler uma pilha e grave outra pilha sem os valores repetidos */
int main() {
    printf("Hello world!\n");

    int
        value,
        arrFilter[10],
        positionValue = 0,
        isAlreadyExists; // 0 or 1

    for (int i = 0; i < 10; i++) {
        isAlreadyExists = 0;
        printf("Informe o %d° valor: ", (i + 1));
        scanf("%d", &value);

        for (int j = 0; j <= positionValue; j++) {
            if (arrFilter[j] == value) {
                isAlreadyExists = 1;
            }
        }

        if (!isAlreadyExists) {
            arrFilter[positionValue] = value;
            positionValue++;
        }

    }

    printf("Result: \n");

    for (int i = 0; i < positionValue; i++) {
        printf("%d ", arrFilter[i]);
    }

    return 0;
}
#endif // ex03

#ifdef ex04
int main() {
    printf("Hello world!\n");

    int arr[] = {22, 23, 24, 24, 24, 24, 24, 24, 24, 25, 27, 27, 27, 27, 27, 27, 25};
    char AA[] = "AA";

    int
        lengthArr = sizeof(arr)/sizeof(int),
        repeatcount = 0;

    for (int i = 1; i <= lengthArr; i++ ) {
        int aux = i - 1;

        if (arr[i] == arr[aux]) {
            repeatcount++;
        }
        else if (repeatcount != 0) {
            repeatcount++;
            printf("%s %d %d ", AA, arr[aux], repeatcount);
            repeatcount = 0;
        }
        else {
            printf("%d ", arr[aux]);
            repeatcount = 0;
        }
    }

    return 0;
}
#endif // ex04

#ifdef ex05
/**  Se quiser uma compressão por frequência quando a ordem dos valores não importa, podemos ter um ganho ainda maior. Faça o algoritmo para o exemplo abaixo:
DADOS BRUTOS: 32 33 34 34 34 34 34 34 34 35 37 37 37 37 37 37 35 34 35
Resposta: 32 33 AA 34 08 AA 35 03 AA 37 06  */
int main () {
    printf("Hello world!\n");

    int
        data[] = {32, 33, 34, 34, 34, 34, 34, 34, 34, 35, 37, 37, 37, 37, 37, 37, 35, 34, 35},
        lengthArr = sizeof(data)/sizeof(int),
        repeatcount = 0,
        isAlreadyExists = 0,
        valuesAlreadyExists[lengthArr];

    char
        BB[] = "BB";

    for (int i = 0; i < lengthArr; i++) {
        int value = data[i];

        for (int j = 0; j <= lengthArr; j++) {
            if (valuesAlreadyExists[j] == value) {
                isAlreadyExists = 1;
                break;
            }
            if (value == data[j]) {
                repeatcount++;
            }
        }

        if (repeatcount > 1 && !isAlreadyExists)  {
            printf("%s %i %i ", BB, value, repeatcount);
        }

        else if (!isAlreadyExists) {
            printf("%i ", value);
        }

        valuesAlreadyExists[i] = data[i];
        repeatcount = 0;
        isAlreadyExists= 0;
    }


    return 0;
}
#endif // ex05

/** Fila */

#ifdef ex06 

#define MAX 10
int
    fila[MAX],
    end_fila = 0,
    start_file = 0;

void insertNumber(int value)
{
    if (end_fila == MAX) { // fila is full
        printf("Você chegou no fim da fila.");
        return;
    }

    fila[end_fila] = value;
    end_fila++;
    printf("incrementa valor %d na fila.\n", value);
}

int removeNumber()
{
    if (start_file == end_fila) { // Initial value is equal the end fila
        printf("Fila vazia.");
        return NULL;
    }

    start_file++;
    printf("decrementa valor %d na fila.\n", fila[start_file - 1]);

    return fila[start_file - 1];
}

int main ()
{
    insertNumber(12);
    insertNumber(23);
    insertNumber(45);
    insertNumber(34);
    insertNumber(76);
    insertNumber(54);
    insertNumber(98);

    printf("\n");

    removeNumber();
    removeNumber();
    removeNumber();
    removeNumber();

    printf("\nValores restantes: \n");
    for ( int i = start_file; i < end_fila; i++  ) {
        printf("%d\n", fila[i]);
    }


    return 0;
}
#endif // ex06


/** Fila Circular*/

#ifdef ex07 

/**
    3) Escreva um algoritmo para implementar uma Fila Circular. O algoritmo irá realizar as seguintes ações:

    a) aceitar 5 elementos na Fila

    b) imprimir os 5 elementos inseridos em A

    c) remover da Fila 2 elementos

    d) imprimir os elementos restantes da opção C

    e) Inserir 2 novos elementos na Fila

    f) Imprimir os elementos da Fila, após a operação E
*/

#define MAX 5
int
    fila[5+1], // mais 1 para soma o total de 5 elementos
    end_fila = 0,
    start_file = 0;

void insertNumber(int value)
{
    if (end_fila == MAX) {
        end_fila = 0;
    }

    // fila is full
    if (  (end_fila + 1) > MAX && !start_file ) {
        printf("Você chegou no fim da fila Circular.\n");
        return;
    }

    fila[end_fila] = value;
    end_fila++;

    printf("incrementa valor %d na fila.\n", value);
}

int removeNumber()
{
    if (start_file == MAX) {
        start_file = 0;
    }

    if (start_file == end_fila) {
        printf("Fila Circular vazia.\n");
        return NULL;
    }

    printf("decrementa valor %d na fila.\n", fila[start_file]);
    fila[start_file] = NULL;
    start_file++;

    return fila[start_file - 1];
}

void printNumbers()
{
    printf("\nValores restantes: \n");
    for ( int i = start_file; i < 5; i++  ) {
        if (fila[i] != NULL) {
            printf("%d\n", fila[i]);
        }
    }
    for ( int i = 0; i < start_file; i++  ) {
        if (fila[i] != NULL) {
        printf("%d\n", fila[i]);
       }
    }

}

int main ()
{

    printf("\n");
    insertNumber(10);
    insertNumber(20);
    insertNumber(30);
    insertNumber(40);
    insertNumber(50);

    printf("\n");
    printNumbers();

    printf("\n");
    removeNumber();
    removeNumber();

    printf("\n");
    printNumbers();

    printf("\n");
    insertNumber(100);
    insertNumber(150);

    printf("\n");
    printNumbers();

    return 0;
}
#endif // ex07


#ifdef ex08
int main()
{
    printf("Hello world!\n");

    int numbers[10], i;

    for (i = 0; i < 10; i++) {
        printf("Informe o %d°: ", (i));
        scanf("%d", &numbers[i]);
    }

    printf("\n");

    printf("PILHA: ");
    while(i > 0) {
        i--;
        printf("%d ", numbers[i]);
    }

    printf("\n");

    printf("FILA: ");
    while(i < 10 ) {
        printf("%d ", numbers[i]);
        i++;
    }

    printf("\n");

    return 0;
}
#endif // ex08

#ifdef ex09
/** 1) Implemente através de um algoritmo o exemplo de Lista Encadeada descrito nos slides de 11 a 16. */


typedef struct {
    char name[10];
    struct Node *next;
} Node ;

typedef struct {
    Node *head;
    int length;
} List;

void removeHead(List *list)
{
    Node *head = (*list).head;
    (*list).head = (*head).next;

    memset(head, 0, sizeof(Node));

    (*list).length--;
}

void removeEnd(List *list)
{
    if ( (*list).head == NULL ) {
         memset((*list).head, 0, sizeof(Node));
    } else {
        Node *auxNode = (*list).head;

        while( (*auxNode).next != NULL ) {
            Node *proxAux = (*auxNode).next;

            if ( (*proxAux).next == NULL) {
                (*auxNode).next = NULL;
            } else {
                auxNode = (*auxNode).next;
            }

        }
    }

    (*list).length--;
}

void insertHead(List *list, char name[10])
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    strcpy((*newNode).name, name);
    (*newNode).next = (*list).head;

    (*list).head = newNode;
    (*list).length++;
}

void insertEnd(List *list, char name[10])
{
    Node
        *newNode = (Node*)malloc(sizeof(Node)),
        *auxNode;

    strcpy((*newNode).name, name);
    (*newNode).next = NULL;

    if ( (*list).head == NULL ) {
        (*list).head = newNode;
    } else {
        auxNode = (*list).head;

        while( (*auxNode).next != NULL ) {
            auxNode = (*auxNode).next;
        }

        (*auxNode).next = newNode;
    }

    (*list).length++;

}

void printMyList(List *list)
{
    Node *head = (*list).head;
    printf("\n----->Tamanho da lista: %d\n", (*list).length);

    while(head != NULL) {
        printf("> %s (%p) => Apontando para %p\n", (*head).name, head, (*head).next);
        head = (*head).next;
    }
    printf("\n");

}

void changeName(List *list, char name[15], char newName[15])
{
    Node *auxNode = (*list).head;
    char oldName[15], currentName[15];
    int nameAlreadyExist = 0;

    strcpy(oldName, name);
    strcpy(currentName, newName);

    if ((*auxNode).next == NULL) {
        strcpy((*auxNode).name, currentName);
    } else {
        while ( (*auxNode).next != NULL ) {
            if ( strcmp((*auxNode).name, oldName) == 0 ) {
                nameAlreadyExist++;
                break;
            } else {
                auxNode = (*auxNode).next;
            }
        }

        printf("\n\n%s\n\n", (*auxNode).name);

        if (nameAlreadyExist == 1 ) {
             strcpy((*auxNode).name, currentName);
        }
        else {
            printf("\n\nNome não encontrado \n\n");
        }


    }
}

void insertTenNomesAuto(List *list)
{
    int i;
    char names[10][10] = {
        {"Ichigo"},
        {"Kirito"},
        {"Naruto"},
        {"Alucard"},
        {"Gon"},
        {"Luffi"},
        {"Tanjiro"},
        {"Alphonse"},
        {"Eren"},
        {"Yumeko"},
        {"Thorfinn"},
    };

    for ( i = 0; i < 10; i++) {
        insertHead(list, names[i]);
        scanf("%*[^\n]");
    }
}

void removeMiddle(List *list, char name[15])
{
    Node *antNode = (*list).head;
    char nameRemove[15];
    strcpy(nameRemove, name);
    int nameAlreadyExist = 0;

    Node *auxNode;
    while ( (*antNode).next != NULL ) {
        auxNode = (*antNode).next;

        if ( strcmp((*auxNode).name, nameRemove) == 0 ) {
            nameAlreadyExist++;
            break;
        } else {
            antNode = (*antNode).next;
        }

    }

    if (nameAlreadyExist == 1 && (*auxNode).next != NULL) {
        (*antNode).next = (*auxNode).next;
        memset(auxNode, 0, sizeof(Node));
    }
    else {
        printf("\n\nNome não encontrado \n\n");
    }

}

int main()
{
    List list;
    int option;
    char name[15];

    list.head = NULL;
    list.length = 0;

    printf("+===========IMPLEMENTACAO==========+");
    printf("\n+++ Exercicio 1 e 2 da atividade +++\n");
    printf("+===========LISTA ENCADEADA========+\n");

    do {
        printf("\n");
        printf("1 - Inserir no head\n");
        printf("2 - Remover do head\n");
        printf("3 - Inserir no fim\n");
        printf("4 - Remover do fim\n");
        printf("5 - Inserir 10 nomes aleatorios\n");
        printf("6 - Alterar nome\n");
        printf("7 - Remover um nome do meio\n");
        printf("8 - Imprimir nomes\n");
        printf("9-  Limpar Tela\n");
        printf("10- Sair\n");

        printf("\nOpcao do menu: ");
        scanf("%d", &option);

        switch (option) {
            printf("\n");
            case 1:
                printf("Informe o nome: ");
                scanf("%s", &name);
                scanf("%*[^\n]");
                insertHead(&list, name);
                break;
            case 2:
                removeHead(&list);
                break;
            case 3:
                printf("Informe o nome: ");
                scanf("%s", &name);
                scanf("%*[^\n]");

                insertEnd(&list, name);
                break;
            case 4:
                removeEnd(&list);
                break;
            case 5:
                insertTenNomesAuto(&list);
                break;
            case 6:
                printf("Informe o nome para pesquisa: ");
                scanf("%s", &name);
                scanf("%*[^\n]");

                char newName[15];
                printf("Informe o nome para substituir: ");
                scanf("%s", &newName);
                scanf("%*[^\n]");

                changeName(&list, name, newName);
                break;
            case 7:
                printf("Informe o nome para pesquisa: ");
                scanf("%s", &name);
                scanf("%*[^\n]");

                removeMiddle(&list, name);
                break;
            case 8:
                printMyList(&list);
                break;
            case 9:
                system("clear");
                break;
            case 10:
                exit(1);
                break;
            default:
                printf("Option not exists.\n");
        }
    } while (option != 10);

    return 0;
}
#endif // ex09

#ifdef ex10
/**
    2) Implemente uma Lista Encadeada contendo nomes de pessoas [ 10 posições]. - DESAFIO
    Em seguida:
    a) remova um nome especifico informado.
    b) insira um novo nome na mesma posição onde o nome anterior foi removido.
*/
main()
{
    char nomes[10][10];
    char pesquisa[10];

    int n, x = 0;
    int o;
    int i = 0, z = 0;

    for(n = 1; n<=10; n++)
    {
    printf("Digite o %d nome: ", n);
    scanf("%s", &nomes[i]);
    i++;
    }
    //system("cls");
    //pesquisa
    printf("\n\nPesquise por um nome:");
    scanf("%s", &pesquisa);

    for(z=0; z<10; z++)
    {
        for(i=0; pesquisa[i]!='\0'; i++)
        {
            if(pesquisa[i] != nomes[z][i])
            {
                break;
            }
        }
        if(pesquisa[i]=='\0' && nomes[z][i]=='\0')
        {

            x=1;
            break;
        }

    }

    if(x==1)
    {
        printf("\nNome encontrado!\n");
        printf("Nome pesquisado: %s\n", pesquisa);
        printf("Escreva um novo nome: ");
        scanf("%s", &nomes[z]);

        i = 0;
        for(n = 1; n<=10; n++)
        {
            printf("\nKey: %d Nome: %s", n, &nomes[i]);
            i++;
        }
    }
    else
    {
        printf("Resultado nao encontrado.\n");
    }

}
#endif // ex10

