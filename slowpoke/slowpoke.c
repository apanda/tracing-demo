#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
const char* TEMP = "slowpoke";

static void delete_file() {
    unlink(TEMP);
}

static void create_and_write_big() {
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop bloop bloop bloop bloop", 30);
    close(file);
}

static void create_and_write_small() {    
    int file = open(TEMP, O_CREAT | O_TRUNC | O_SYNC);
    write(file, "bloop", 6);
    close(file);
}

static void choose_and_execute() {
#ifdef __APPLE__
    int option = arc4random() % 6;
#else
    int option = random() % 6;
#endif
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
        sleep(1);
    }
    return 1;
}
