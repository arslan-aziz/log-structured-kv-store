#ifndef hashmap_h
#define hashmap_h

#include <stdlib.h>

typedef struct ll_node_t {
    struct ll_node_t* next;
    char* key;
    int value;
} ll_node_t;

typedef struct {
    ll_node_t** array;
    size_t current_size;
    size_t max_size;
} hashmap_t;

hashmap_t* create_hashmap_t();

int hashmap_get(hashmap_t*, char[]);
void hashmap_put(hashmap_t*, char[], int);
int hashmap_size(hashmap_t*);
void hashmap_remove(hashmap_t*, char[]);

#endif