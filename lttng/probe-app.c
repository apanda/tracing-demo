#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE
#include "lttng-tp.h"

const char* TEMP = "temp";

static void delete_file() {
    tracepoint(probe, unlink_file, TEMP); 
    unlink(TEMP);
}

static void create_and_write_big() {
    tracepoint(probe, create_and_write_big, TEMP); 
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop bloop bloop bloop bloop", 29);
    close(file);
}

static void create_and_write_small() {    
    tracepoint(probe, create_and_write_small, TEMP); 
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop", 5);
    close(file);
}

static void choose_and_execute() {
    int option = random() % 6;
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
