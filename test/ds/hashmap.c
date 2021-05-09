#include "ds/hashmap.h"
#include "munit/munit.h"

int main(int argc, char *argv[]) {

    MunitTest tests[] = {
        {
            "/a_test",
            test_put,
            NULL, /* setup fn */
            NULL, /* teardown fn */
            MUNIT_TEST_OPTION_NONE,
            NULL /* params */
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
    };
}

MunitResult test_put(const MunitParameter params[], void* fixture) {
    hashmap_t* my_hashmap = (hashmap_t*) fixture;

    hashmap_put(my_hashmap, "akey", 3);
    hashmap_put(my_hashmap, "anotherKey", 6);

    munit_assert_int(hashmap_get(my_hashmap, "akey"), ==, 3);
}

void* test_setup(const MunitParameter parmas[], void* user_data) {
    hashmap_t* new_hashmap = malloc(sizeof(hashmap_t));

    size_t array_size = 32;
    new_hashmap->array = malloc(array_size * sizeof(int));
    for (int i=0; i < array_size; i++) {
        new_hashmap->array[i] = NULL;
    }
    new_hashmap->current_size = 0;
    new_hashmap->max_size = array_size;

    return new_hashmap;
}

void test_tear_down(void* fixture) {
    free(fixture);
}