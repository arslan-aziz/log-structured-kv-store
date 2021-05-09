#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ds/hashmap.h"

int main(int argc, char *argv[]) {

    // read filepath
    int opt;
    const char OPTSTRING[] = "p:";

    // set default filepath
    char default_filepath[] = "";
    char *filepath_ptr = &default_filepath;

    while (opt = getopt(argc, argv, OPTSTRING) != -1) {
        switch (opt) {
            // filepath argument
            case 'p':
                filepath_ptr = optarg;
                break;
            default:
                break;
        }
    }

    // set up data file
    int data_fd = create_data_file(filepath_ptr);
    if (data_fd == -1) {
        perror("Error on create data file");
        return -1;
    }

    // set up in memory hashmap for indexing


    // begin main input loop
    int exit = 0;
    char opt_str[50];
    char key_str[100];
    char val_str[1000];

    while (exit == 0) {
        printf("Enter a command");
        scanf("%s %s:%s", opt_str, key_str, val_str);

        if (strcmp(opt_str, "get") == 0) {
            // do get
        }
        else if (strcmp(opt_str, "put") == 0) {
            // do put
        }
        else if (strcmp(opt_str, "delete") == 0) {
            // do delete
        }
        else if (strcmp(opt_str, "size") == 0) {
            // do size
        }
        else {
            // print error
        }

    }

    return 0;

}