#include <string.h>
#include "hashmap.h"

int hash_code(char key[], int max_idx) {
    return 1;
}

int get(hashmap_t* hm, char key[]) {
    
    int idx = hash_code(key, hm->max_size);

    // retrieve from pos by traversing LL
    ll_node_t* head = hm->array[idx];
    while (head != NULL && strcmp(head->key, key) != 0) {
        head = head->next;
    }

    if (head == NULL) {
        // TODO: There's got to be a better way...
        return -1;
    }
    else {
        return head->value;
    }

void remove(hashmap_t* hm, char key[]) {

}

void put(hashmap_t* hm, char key[], int value) {
    
    int idx = hash_code(key, hm->max_size);

    // add to end of LL at pos idx in array
    ll_node_t* head = hm->array[idx];
    while (head->next != NULL && head->value != value) {
        head = head->next;
    }

    if (head->value == value) {
        head->value = value;
    }
    else {
        ll_node_t* new_node = malloc(sizeof(ll_node_t));
        new_node->key = key;
        new_node->value = value;
        head->next = new_node;
    }
}

int size(hashmap_t* hm) {
    return hm->max_size;
}

hashmap_t* create_hashmap() {
    hashmap_t new_hashmap = malloc(sizeof(hashmap_t));

    // init LL node in each pos of array
    size_t array_size = 32;
    new_hashmap->array = malloc(array_size * sizeof(int));
    for (int i=0; i < array_size; i++) {
        new_hashmap->array = malloc(sizeof(ll_node_t));
    }

    return new_hashmap;
}