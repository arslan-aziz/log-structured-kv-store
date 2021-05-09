#include <string.h>
#include "hashmap.h"

int hash_code(char key[], int max_idx) {
    return 1;
}

int hashmap_get(hashmap_t* hm, char key[]) {
    
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
}

void hashmap_remove(hashmap_t* hm, char key[]) {
    
    int idx = hash_code(key, hm->max_size);

    ll_node_t* head = hm->array[idx];
    // traverse LL and stop at reference to previous node to target node
    ll_node_t* prev_node = NULL;
    while (head != NULL && strcmp(head->key, key) != 0) {
        prev_node = head;
        head = head->next;
    }

    // if key exists in hashmap
    if (head != NULL) {
        // if key was found somewhere within LL
        if (prev_node != NULL) {
            prev_node->next = head->next;
        }
        // if key was at the head of the LL
        else {
            hm->array[idx] = head->next;
        }
        free(head);
    }
}   

void hashmap_put(hashmap_t* hm, char key[], int value) {
    
    int idx = hash_code(key, hm->max_size);

    // add to end of LL at pos idx in array
    ll_node_t* head = hm->array[idx];

    if (head == NULL) {
        ll_node_t* new_node = malloc(sizeof(ll_node_t));
        new_node->key = key;
        new_node->value = value;
        hm->array[idx] = new_node;
        return;
    }

    while (head != NULL && strcmp(head->key, key) != 0) {
        head = head->next;
    }

    if (head != NULL) {
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

hashmap_t* create_hashmap_t() {
    hashmap_t* new_hashmap = malloc(sizeof(hashmap_t));

    // init LL node in each pos of array
    size_t array_size = 32;
    new_hashmap->array = malloc(array_size * sizeof(int));
    for (int i=0; i < array_size; i++) {
        new_hashmap->array[i] = NULL;
    }
    new_hashmap->current_size = 0;
    new_hashmap->max_size = array_size;

    return new_hashmap;
}

void destroy_hashmap_t(hashmap_t* hm) {
    free(hm);
}