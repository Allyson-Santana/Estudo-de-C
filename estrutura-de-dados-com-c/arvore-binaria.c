// => https://www.youtube.com/watch?v=owaBsGQheZM
// => https://www.youtube.com/watch?v=dcOCsxiuKeU&list=PLqJK4Oyr5WShBuC5rqt9I0fMVNnaVTpeo PlaylLst

#include <stdio.h>
#include <stdlib.h>


#define ex01

#ifdef ex01
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *source;
    int length;
} BinaryTree;

void insertLeft(Node *node, int newValue) {
    if (node->left == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newValue;
        newNode->left = NULL;
        newNode->right = NULL;
        node->left = newNode;
    } else {
        if (newValue > node->left->data) {
            insertRight(node->left, newValue);
        }
        if (newValue < node->left->data) {
            insertLeft(node->left, newValue);
        }
    }
}

void insertRight(Node *node, int newValue) {
    if (node->right == NULL) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newValue;
        newNode->left = NULL;
        newNode->right = NULL;
        node->right = newNode;
    } else {
        if (newValue > node->right->data) {
            insertRight(node->right, newValue);
        }
        if (newValue < node->right->data) {
            insertLeft(node->right, newValue);
        }
    }
}

void insert(BinaryTree *ab, int newValue) {
    if ( ab->source == NULL ) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = newValue;
        newNode->left = NULL;
        newNode->right = NULL;
        ab->source = newNode;
        ab->length++;
    } else {
        if (newValue > ab->source->data) {
            insertRight(ab->source, newValue);
        }
        if (newValue < ab->source->data) {
            insertLeft(ab->source, newValue);
        }
    }
}

void viewBinaryTree(Node *src) {
    if (src != NULL) {
        viewBinaryTree(src->left);
        printf("%d ", src->data);
        viewBinaryTree(src->right);
    }
}

void menu() {
    printf("Hello World!\n");

    printf("\n0 para sair");
    printf("\n1 para inserir valor");
    printf("\n2 para imprimir valores");
}

int main() {

  int option, value;
  BinaryTree ab;

  ab.source = NULL;

  do {
    menu();
    printf("\n\nOpcao: ");
    scanf("%d", &option);

    switch (option) {
        case 0:
            printf("\nSaindo.....");
            break;
        case 1:
            printf("Informe um valor interiro: ");
            scanf("%d", &value);
            insert(&ab, value);
            break;
        case 2:
            printf("\nValores: ");
            viewBinaryTree(ab.source);
            printf("\nEnter para continua");
            getchar();
            break;
        default:
            printf("\Opcao invalida.....");
            printf("\nEnter para continua...");
            getchar();
            break;
    }

    scanf("%*[^\n]");
    system("clear");
  } while(option != 0);

  return 0;
}

#endif // ex01
