#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "probes.h"
const char* TEMP = "temp";

static void delete_file() {
    EXAMPLE_UNLINK_FILE(TEMP);
    unlink(TEMP);
}

static void create_and_write_big() {
    EXAMPLE_CREATE_AND_WRITE_BIG(TEMP);
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop bloop bloop bloop bloop", 6);
    close(file);
}

static void create_and_write_small() {    
    EXAMPLE_CREATE_AND_WRITE_SMALL(TEMP);
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop", 6);
    close(file);
}

static void choose_and_execute() {
    int option = arc4random() % 6;
    switch(option) {
        case 0: delete_file(); break;
        case 1: create_and_write_big(); break;
        default: create_and_write_small(); break;
    }
}

int main(int argc, char* argv[]) {
    printf("Hello\n");
    while(1) {
        choose_and_execute();
    }
    return 1;
}
