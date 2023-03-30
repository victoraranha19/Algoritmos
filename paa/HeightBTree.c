#include <stdio.h>
#include <stdlib.h>

// Arvore Binaria
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Criar um novo nó com o valor especificado
Node* newNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Inserir um novo valor na árvore
Node* insert(Node* node, int value) {
    if (node == NULL) {
        return newNode(value);
    } else {
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
    }
    return node;
}

// Imprimir árvore Center-Left-Right
void preorderTransversal(Node* node) {
    if (node != NULL) {
        printf("%d ", node->value);
        preorderTransversal(node->left);
        preorderTransversal(node->right);
    }
}
// Imprimir árvore Left-Center-Right
void inorderTransversal(Node* node) {
    if (node != NULL) {
        inorderTransversal(node->left);
        printf("%d ", node->value);
        inorderTransversal(node->right);
    }
}
// Imprimir árvore Left-Right-Center
void postorderTransversal(Node* node) {
    if (node != NULL) {
        postorderTransversal(node->left);
        postorderTransversal(node->right);
        printf("%d ", node->value);
    }
}

// Altura da arvore
int Height(Node* node) {
    if(node==NULL) return -1;
    int lheight = Height(node->left);
    int rheight = Height(node->right);
    if(lheight>rheight) return lheight + 1;
    else return rheight + 1;
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 20);

    printf("Valores em ordem crescente: ");
    inorderTransversal(root);
    int h = Height(root);
    printf("\n%d", h);
    return 0;
}