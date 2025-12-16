//Nama: Farsya Haikal Lesmana
//Nim: 241011401494
//kelas: 03TPLP023

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct nod {
    struct nod *left;
    char data;
    struct nod *right;
};

typedef struct nod NOD;
typedef NOD POKOK;

NOD *NodBaru(char item) {
    NOD *n;
    n = (NOD*) malloc(sizeof(NOD));
    if(n != NULL) {
        n->data = item;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

void BinaPokok(POKOK **T) {
    *T = NULL;
}

bool PokokKosong(POKOK *T) {
    return (T == NULL);
}

void TambahNod(NOD **p, char item) {
    NOD *n;
    n = NodBaru(item);
    *p = n;
}

void preOrder(POKOK *T) {
    if(!PokokKosong(T)) {
        printf("%c ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(POKOK *T) {
    if(!PokokKosong(T)) {
        inOrder(T->left);
        printf("%c ", T->data);
        inOrder(T->right);
    }
}

void postOrder(POKOK *T) {
    if(!PokokKosong(T)) {
        postOrder(T->left);
        postOrder(T->right);
        printf("%c ", T->data);
    }
}

int main() {
    POKOK *pohon;
    char huruf;
    
    BinaPokok(&pohon);
    
    TambahNod(&pohon, huruf = 'R');
    
    TambahNod(&pohon->left, huruf = 'A');
    
    TambahNod(&pohon->left->right, huruf = 'S');
    
    TambahNod(&pohon->left->right->left, huruf = 'I');
    
    TambahNod(&pohon->left->right->right, huruf = 'T');
    
    TambahNod(&pohon->right, huruf = 'E');
    
    printf("Tampilan secara PreOrder : ");
    preOrder(pohon);
    
    printf("\nTampilan secara InOrder  : ");
    inOrder(pohon);
    
    printf("\nTampilan secara PostOrder: ");
    postOrder(pohon);
    printf("\n");
    
    return 0;
}
