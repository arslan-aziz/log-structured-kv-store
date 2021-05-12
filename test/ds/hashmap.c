#include "../../src/ds/hashmap.h"
#include "../../munit/munit.h"

MunitResult test_put(const MunitParameter params[], void* fixture) {
    hashmap_t* my_hashmap = (hashmap_t*) fixture;

    hashmap_put(my_hashmap, "akey", 3);
    hashmap_put(my_hashmap, "anotherKey", 6);

    munit_assert_int(hashmap_get(my_hashmap, "akey"), ==, 3);

    return MUNIT_OK;
}

void* test_setup(const MunitParameter params[], void* user_data) {
    hashmap_t* new_hashmap = create_hashmap_t();

    return new_hashmap;
}

void test_tear_down(void* fixture) {
    free(fixture);
}

MunitTest tests[] = {
    {
        "/test_put",
        test_put,
        test_setup, /* setup fn */
        test_tear_down, /* teardown fn */
        MUNIT_TEST_OPTION_NONE,
        NULL /* params */
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/hashmap-tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}