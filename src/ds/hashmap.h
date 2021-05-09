#ifndef hashmap_h
#define hashmap_h

#include <stdlib.h>

typedef struct {
    ll_node_t* next;
    char* key;
    int value;
} ll_node_t;

typedef struct {
    int* array;
    size_t current_size;
    size_t max_size;
} hashmap_t;

hashmap_t* create_hashmap();

int get(hashmap_t*, char[]);
void put(hashmap_t*, char[], int);
int size(hashmap_t*);
void remove(hashmap_t*, char[]);

#endif