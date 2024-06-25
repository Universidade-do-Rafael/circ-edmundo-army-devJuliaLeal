#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista circular
struct Node {
    int data;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* TCircList_create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Inicialmente, o nó aponta para si mesmo
    return newNode;
}

// Função para inserir um nó na lista circular
struct Node* TCircList_insert(struct Node* last, int data) {
    struct Node* newNode = TCircList_create(data);
    if (last == NULL) {
        newNode->next = newNode; // Para o primeiro nó
        return newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        return newNode;
    }
}

// Função para encontrar a posição segura usando a lógica de Josephus
int findSafePosition(int N, int M) {
    struct Node* last = NULL;
    for (int i = 1; i <= N; i++) {
        last = TCircList_insert(last, i);
    }

    struct Node* curr = last->next;
    struct Node* prev = last;
    while (curr->next != curr) {
        for (int count = 1; count < M +1; count++) {
            prev = curr;
            curr = curr->next;
        }
        // Remover o nó corrente
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    int safePosition = curr->data;
    free(curr);
    return safePosition;
}

