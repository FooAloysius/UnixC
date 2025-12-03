#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*listFunc)(void* data);

typedef struct {
    void* data;
    struct Node* next;
} Node;

typedef struct
#endif