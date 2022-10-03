#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ex01


#ifdef ex01
/** Implemente através de um algoritmo o exemplo de Lista Encadeada */

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

        if (nameAlreadyExist == 1  || strcmp((*auxNode).name, oldName) == 0 ) {
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
        (*list).length--;
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
#endif // ex01
