#include "ds/hashmap.h"
#include "munit/munit.h"

int main(int argc, char *argv[]) {

    MunitTest tests[] = {
        {
            "/a_test",
            a_test,
            NULL, /* setup fn */
            NULL, /* teardown fn */
            MUNIT_TEST_OPTION_NONE,
            NULL /* params */
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
    };
}

MunitResult a_test(const MunitParameter params[], void* fixture) {

}