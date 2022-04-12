#include <stdio.h>
#include <stdlib.h>
#include "chd.h"

int handle_read_file(FILE **fp, char *path) 
{
    *fp = fopen(path, "rb");
    if (!fp) {
        return -1;
    } 
    else {
        return 0;
    }
}

void read_binary(FILE *fp)
{
    unsigned char buffer_byte;
    while (fread(&buffer_byte, sizeof(char), 1, fp) > 0) {
        printf("%X", buffer_byte);
    }
}


int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc == 2) {
        char* path = argv[1];
        if (handle_read_file(&fp, path)) {
            printf("Cannot find file %s\n", path);
            exit(2);
        }
        read_binary(fp);
    }
    else {
        printf("Usage: \n");
        printf("chd [file] \n");
        exit(1);
    }
    return 0;
}